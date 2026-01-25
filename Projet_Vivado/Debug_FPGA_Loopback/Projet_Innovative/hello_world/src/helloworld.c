#include "xparameters.h"
#include "xuartlite.h"
#include "xil_printf.h"
#include "sleep.h"
#include "xstatus.h"
#include "xuartlite_l.h"

#define UART_BASEADDR XPAR_AXI_UARTLITE_0_BASEADDR
#define UART_BAUD     XPAR_AXI_UARTLITE_0_BAUDRATE


#define MODEM_BASEADDR   XPAR_AXI_UARTLITE_0_BASEADDR
#define MODEM_BAUD       XPAR_AXI_UARTLITE_0_BAUDRATE
#define MODEM_USE_PARITY XPAR_AXI_UARTLITE_0_USE_PARITY
#define MODEM_ODD_PARITY XPAR_AXI_UARTLITE_0_ODD_PARITY
#define MODEM_DATABITS   XPAR_AXI_UARTLITE_0_DATA_BITS


static XUartLite Uart;

/* Envoi bloquant */
static void uart_send(const char *s)
{
    XUartLite_Send(&Uart, (u8 *)s, strlen(s));
    while (XUartLite_IsSending(&Uart));
}

int main(void)
{
    xil_printf("\r\n==============================\r\n");
    xil_printf(" UARTLite AT DEBUG TEST\r\n");
    xil_printf(" Baudrate = %d\r\n", UART_BAUD);
    xil_printf("==============================\r\n");


    XUartLite_Config cfg = {
        .RegBaseAddr = MODEM_BASEADDR,
        .BaudRate    = MODEM_BAUD,
        .UseParity   = MODEM_USE_PARITY,
        .ParityOdd   = MODEM_ODD_PARITY,
        .DataBits    = MODEM_DATABITS
    };


    if (XUartLite_CfgInitialize(&Uart, &cfg, cfg.RegBaseAddr) != XST_SUCCESS) {
        xil_printf("ERROR: UART init failed\r\n");
        while (1);
    }

    XUartLite_ResetFifos(&Uart);

    u8 rxbuf[64];

    while (1) {
        xil_printf("\r\n[TX] AT\r\n");
        
        uart_send("AT\r\n");


        xil_printf("[RX] Listening...\r\n");



        for (int t = 0; t < 1000; t++) {   // 200 × 10 ms = 2 s

            if (XUartLite_IsReceiveEmpty(Uart.RegBaseAddress) == 0) {
                xil_printf("FIFO NOT EMPTY!\r\n");
            }

            int n = XUartLite_Recv(&Uart, rxbuf, sizeof(rxbuf));
            if (n > 0) {
                xil_printf("RX %d byte(s):\r\n", n);
                for (int i = 0; i < n; i++) {
                    xil_printf("  0x%02X '%c'\r\n",
                               rxbuf[i],
                               (rxbuf[i] >= 32 && rxbuf[i] <= 126) ? rxbuf[i] : '.');
                }
            }
            usleep(10000); // 10 ms
        }

        xil_printf("[RX] End listen\r\n");

        sleep(2);
    }
}