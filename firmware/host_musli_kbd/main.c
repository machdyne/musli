/* 
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ha Thach (tinyusb.org)
 * Copyright (c) 2022 Lone Dynamics Corporation <info@lonedynamics.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pico/stdlib.h"
#include "hardware/spi.h"
//#include "bsp/board.h"
#include "tusb.h"
#include "musli.h"

//--------------------------------------------------------------------+
// MACRO CONSTANT TYPEDEF PROTYPES
//--------------------------------------------------------------------+

extern void hid_app_task(void);

/*------------- MAIN -------------*/
int main(void)
{
  stdio_init_all();

  printf("Musli Keyboard Bridge\r\n");

  gpio_init(MUSLI_SPI_CSN_PIN);
  gpio_disable_pulls(MUSLI_SPI_CSN_PIN);
  gpio_put(MUSLI_SPI_CSN_PIN, 1);

  gpio_set_function(MUSLI_SPI_RX_PIN, GPIO_FUNC_SPI);
  gpio_set_function(MUSLI_SPI_SCK_PIN, GPIO_FUNC_SPI);
  gpio_set_function(MUSLI_SPI_TX_PIN, GPIO_FUNC_SPI);
  spi_init(spi1, 1000*1000);

  tusb_init();

  while (1)
  {
    tuh_task();
    hid_app_task();
  }

  return 0;
}
