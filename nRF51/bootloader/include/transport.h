/***********************************************************************************
Copyright (c) Nordic Semiconductor ASA
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

  3. Neither the name of Nordic Semiconductor ASA nor the names of other
  contributors to this software may be used to endorse or promote products
  derived from this software without specific prior written permission.

  4. This software must only be used in a processor manufactured by Nordic
  Semiconductor ASA, or in a processor manufactured by a third party that
  is used in combination with a processor manufactured by Nordic Semiconductor.


THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
************************************************************************************/
#ifndef TRANSPORT_H__
#define TRANSPORT_H__

#include <stdint.h>
#include <stdbool.h>
#include "mesh_packet.h"

#define TX_REPEATS_EXPONENTIAL_MAX      (12)
#define TX_REPEATS_INF                  (0xFF)

#define DFU_PACKET_ADV_OVERHEAD         (1 /* adv_type */ + 2 /* UUID */) /* overhead inside adv data */
#define DFU_PACKET_OVERHEAD             (MESH_PACKET_BLE_OVERHEAD + 1 + DFU_PACKET_ADV_OVERHEAD) /* dfu packet total overhead */

typedef enum
{
    TX_INTERVAL_TYPE_EXPONENTIAL,
    TX_INTERVAL_TYPE_REGULAR
} tx_interval_type_t;


typedef void(*rx_cb_t)(mesh_packet_t* p_packet);

void transport_init(rx_cb_t rx_cb, uint32_t access_addr);
bool transport_tx(mesh_packet_t* p_packet, uint8_t repeats, tx_interval_type_t type);
void transport_tx_reset(mesh_packet_t* p_packet);
void transport_tx_abort(mesh_packet_t* p_packet);
void transport_rtc_irq_handler(void);

#endif /* TRANSPORT_H__ */
