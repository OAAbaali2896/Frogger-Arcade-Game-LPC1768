#include <lpc17xx.h>
#include "type.h"
#include "uart.h"
#define TRUE 0
#define FALSE 1


volatile uint32_t UART0_Status, UART2_Status;
volatile uint8_t UART0_TxEmpty = 1, UART2_TxEmpty = 1;
volatile uint8_t UART0_Buffer[BUFSIZE], UART2_Buffer[BUFSIZE];
volatile uint32_t UART0_Count = 0, UART2_Count = 0;



/*****************************************************************************
** Function name:    UART0_IRQHandler
**
** Descriptions:    UART0 interrupt handler
**
** parameters:      None
** Returned value:  None
** 
*****************************************************************************/
void UART0_IRQHandler (void) 
{
  uint8_t IIRValue, LSRValue;
  uint8_t Dummy = Dummy;

  IIRValue = LPC_UART0->IIR;  /* Interrupt IDentification Register */

  IIRValue >>= 1;             /* skip pending bit in IIR */
  IIRValue &= 0x07;           /* check bit 1~3, interrupt identification */
  if ( IIRValue == IIR_RLS )  /* Receive Line Status */
  {
    LSRValue = LPC_UART0->LSR;
    /* Receive Line Status */
    if ( LSRValue & (LSR_OE|LSR_PE|LSR_FE|LSR_RXFE|LSR_BI) )
    {
      /* There are errors or break interrupt */
      /* Read LSR will clear the interrupt */
      UART0_Status = LSRValue;
      Dummy = LPC_UART0->RBR; /* Dummy read on RX to clear 
                                 interrupt, then bail out */
      return;
    }
    if ( LSRValue & LSR_RDR )    /* Receive Data Ready */            
    {
      /* If no error on RLS, normal ready, save into the data buffer. */
      /* Note: read RBR will clear the interrupt */
      UART0_Buffer[UART0_Count] = LPC_UART0->RBR;
      UART0_Count++;
      if ( UART0_Count == BUFSIZE )
      {
        UART0_Count = 0;      /* buffer overflow */
      }    
    }
  }
  else if ( IIRValue == IIR_RDA )  /* Receive Data Available */
  {
    /* Receive Data Available */
    UART0_Buffer[UART0_Count] = LPC_UART0->RBR;
    UART0_Count++;
    if ( UART0_Count == BUFSIZE )
    {
      UART0_Count = 0;          /* buffer overflow */
    }
  }
  else if ( IIRValue == IIR_CTI )  /* Character timeout indicator */
  {
    /* Character Time-out indicator */
    UART0_Status |= 0x100;        /* Bit 9 as the CTI error */
  }
  else if ( IIRValue == IIR_THRE ) /* THRE, transmit holding register empty */
  {
    /* THRE interrupt */
    LSRValue = LPC_UART0->LSR;  /* Check status in the LSR to see if
                                   valid data in U0THR or not */
    if ( LSRValue & LSR_THRE )
    {
      UART0_TxEmpty = 1;
    }
    else
    {
      UART0_TxEmpty = 0;
    }
  }
  
}


/*****************************************************************************
** Function name:         UART2_IRQHandler
**
** Descriptions:          UART2 interrupt handler
**
** parameters:            None
** Returned value:        None
** 
*****************************************************************************/
void UART2_IRQHandler (void) 
{
  uint8_t IIRValue, LSRValue;
  uint8_t Dummy = Dummy;
    
  IIRValue = LPC_UART2->IIR;
    
  IIRValue >>= 1;            /* skip pending bit in IIR */
  IIRValue &= 0x07;            /* check bit 1~3, interrupt identification */
  if ( IIRValue == IIR_RLS )        /* Receive Line Status */
  {
    LSRValue = LPC_UART2->LSR;
    /* Receive Line Status */
    if ( LSRValue & (LSR_OE|LSR_PE|LSR_FE|LSR_RXFE|LSR_BI) )
    {
      /* There are errors or break interrupt */
      /* Read LSR will clear the interrupt */
      UART2_Status = LSRValue;
      Dummy = LPC_UART2->RBR;        /* Dummy read on RX to clear 
                                interrupt, then bail out */
      return;
    }
    if ( LSRValue & LSR_RDR )    /* Receive Data Ready */            
    {
      /* If no error on RLS, normal ready, save into the data buffer. */
      /* Note: read RBR will clear the interrupt */
      UART2_Buffer[UART2_Count] = LPC_UART2->RBR;
      UART2_Count++;
      if ( UART2_Count == BUFSIZE )
      {
        UART2_Count = 0;        /* buffer overflow */
      }    
    }
  }
  else if ( IIRValue == IIR_RDA )    /* Receive Data Available */
  {
    /* Receive Data Available */
    UART2_Buffer[UART2_Count] = LPC_UART2->RBR;
    UART2_Count++;
    if ( UART2_Count == BUFSIZE )
    {
      UART2_Count = 0;        /* buffer overflow */
    }
  }
  else if ( IIRValue == IIR_CTI )    /* Character timeout indicator */
  {
    /* Character Time-out indicator */
    UART2_Status |= 0x100;        /* Bit 9 as the CTI error */
  }
  else if ( IIRValue == IIR_THRE )    /* THRE, transmit holding register empty */
  {
    /* THRE interrupt */
    LSRValue = LPC_UART2->LSR;        /* Check status in the LSR to see if
                                valid data in U0THR or not */
    if ( LSRValue & LSR_THRE )
    {
      UART2_TxEmpty = 1;
    }
    else
    {
      UART2_TxEmpty = 0;
    }
  }

}


/*****************************************************************************
** Function name:         UARTInit
**
** Descriptions:          Initialize UART port, setup pin select,
**                        clock, parity, stop bits, FIFO, etc.
**
** parameters:            portNum(0 or 2) and UART baudrate
** Returned value:        true or false, return false only if the 
**                        interrupt handler can't be installed to the 
**                        VIC table
** 
*****************************************************************************/
uint32_t UARTInit( uint32_t PortNum, uint32_t baudrate )
{
  uint32_t Fdiv;
  uint32_t pclkdiv, pclk;

  if ( PortNum == 0 )
  {
    // (1) bits 7:4 of PINSEL0 are used to set the function of P0.3 and P0.2 
    // as RX and TX for UART0; see page 117 of the user manual! here, we
    // use the trick with bitwise operators to set bits 7:4 to "0101" which
    // according to the user manual must be set like that;  
    LPC_PINCON->PINSEL0 &= ~0x000000F0;
    LPC_PINCON->PINSEL0 |= 0x00000050;  /* RxD0 is P0.3 and TxD0 is P0.2 */
    
    // (2) By default, the PCLKSELx value is zero, thus, the PCLK for
    // all the peripherals is 1/4 of the SystemCoreClock. 
    // Bits 7:6 are for UART0; see page 57 of the user manual!
    pclkdiv = (LPC_SC->PCLKSEL0 >> 6) & 0x03;
    switch ( pclkdiv )
    {
      case 0x00:
      default:
      // Note to myself: old versions of uVision used "SystemFrequency" 
      // instead of "SystemCoreClock";
      pclk = SystemCoreClock/4;
      break;
      case 0x01:
      pclk = SystemCoreClock;
      break;
      case 0x02:
      pclk = SystemCoreClock/2;
      break;
      case 0x03:
      pclk = SystemCoreClock/8;
      break;
    }

    LPC_UART0->LCR = 0x83;    /* 8 bits, no Parity, 1 Stop bit */
    Fdiv = ( pclk / 16 ) / baudrate ;  /*baud rate */
    LPC_UART0->DLM = Fdiv / 256;
    LPC_UART0->DLL = Fdiv % 256;
    LPC_UART0->LCR = 0x03;    /* DLAB = 0 */
    LPC_UART0->FCR = 0x07;    /* Enable and reset TX and RX FIFO. */

    // (3) enable;
    NVIC_EnableIRQ(UART0_IRQn);

    LPC_UART0->IER = IER_RBR | IER_THRE | IER_RLS;    /* Enable UART0 interrupt */
    return (TRUE);
  }
  else if ( PortNum == 2 )
  {
    // (0) power up the UART2 peripheral;
    // Note: this is the only difference compared to the other branch of
    // this if, i.e., the case of UART0; here we need to power-up the UART2
    // because (as described on page 307 of the user manual) only UART0 is
    // powered by default! so, to be able to use UART2, we need to set to
    // "1" the bit index 24 of the PCONP register, as discussed on page
    // 64 of the user manual!
    LPC_SC->PCONP |= ( 1 << 24 );   
    
    // (1) bits 23:20 of PINSEL0 are used to set the function of P0.11 and P0.10 
    // as RX and TX for UART2; see page 117 of the user manual! here, we
    // use the trick with bitwise operators to set bits 23:24 to "0101" which
    // according to the user manual must be set like that; 
    LPC_PINCON->PINSEL0 &= ~0x00F00000;
    LPC_PINCON->PINSEL0 |= 0x00500000;    /* Enable RxD2 P0.11, TxD2 P0.10 */

    // (2) By default, the PCLKSELx value is zero, thus, the PCLK for
    // all the peripherals is 1/4 of the SystemCoreClock.
    // Bits 17:16 of PCLKSEL1 are for UART2; see page 58 of the user manual!
    pclkdiv = (LPC_SC->PCLKSEL1 >> 16) & 0x03;
    switch ( pclkdiv )
    {
      case 0x00:
      default:
      pclk = SystemCoreClock/4;
      break;
      case 0x01:
      pclk = SystemCoreClock;
      break; 
      case 0x02:
      pclk = SystemCoreClock/2;
      break; 
      case 0x03:
      pclk = SystemCoreClock/8;
      break;
    }

    LPC_UART2->LCR = 0x83;        /* 8 bits, no Parity, 1 Stop bit */
    Fdiv = ( pclk / 16 ) / baudrate ;    /*baud rate */
    LPC_UART2->DLM = Fdiv / 256;                            
    LPC_UART2->DLL = Fdiv % 256;
    LPC_UART2->LCR = 0x03;        /* DLAB = 0 */
    LPC_UART2->FCR = 0x07;        /* Enable and reset TX and RX FIFO. */

    // (3) enable;
    NVIC_EnableIRQ(UART2_IRQn);

    LPC_UART2->IER = IER_RBR | IER_THRE | IER_RLS;    /* Enable UART2 interrupt */
    return (TRUE);
  }
  
  return( FALSE ); 
}


/*****************************************************************************
** Function name:         UARTSend
**
** Descriptions:          Send a block of data to the UART 0 port based
**                        on the data length
**
** parameters:            portNum, buffer pointer, and data length
** Returned value:        None
** 
*****************************************************************************/
void UARTSend( uint32_t portNum, uint8_t *BufferPtr, uint32_t Length )
{
  if ( portNum == 0 )
  {
    while ( Length != 0 )
    {
      // THRE status, contain valid data 
      while ( !(UART0_TxEmpty & 0x01) );    
      LPC_UART0->THR = *BufferPtr;
      UART0_TxEmpty = 0; // not empty in the THR until it shifts out
      BufferPtr++;
      Length--;
    }
  }
  else // portNum == 2
  {
    while ( Length != 0 )
    {
      // THRE status, contain valid data 
      while ( !(UART2_TxEmpty & 0x01) );    
      LPC_UART2->THR = *BufferPtr;
      UART2_TxEmpty = 0; // not empty in the THR until it shifts out
      BufferPtr++;
      Length--;
    }
  }
  return;
}
