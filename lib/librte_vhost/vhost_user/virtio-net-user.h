/*-
 *   BSD LICENSE
 *
 *   Copyright(c) 2010-2014 Intel Corporation. All rights reserved.
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Intel Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _VIRTIO_NET_USER_H
#define _VIRTIO_NET_USER_H

#include "vhost-net.h"
#include "vhost-net-user.h"

#define VHOST_USER_PROTOCOL_F_MQ	0
#define VHOST_USER_PROTOCOL_F_LOG_SHMFD	1
#define VHOST_USER_PROTOCOL_F_RARP	2

#define VHOST_USER_PROTOCOL_FEATURES	((1ULL << VHOST_USER_PROTOCOL_F_MQ) | \
					 (1ULL << VHOST_USER_PROTOCOL_F_LOG_SHMFD) |\
					 (1ULL << VHOST_USER_PROTOCOL_F_RARP))

int user_set_mem_table(struct vhost_device_ctx, struct VhostUserMsg *);

void user_set_vring_call(struct vhost_device_ctx, struct VhostUserMsg *);

void user_set_vring_kick(struct vhost_device_ctx, struct VhostUserMsg *);

void user_set_protocol_features(struct vhost_device_ctx ctx,
				uint64_t protocol_features);
int user_set_log_base(struct vhost_device_ctx ctx, struct VhostUserMsg *);
int user_send_rarp(struct VhostUserMsg *);

int user_get_vring_base(struct vhost_device_ctx, struct vhost_vring_state *);

int user_set_vring_enable(struct vhost_device_ctx ctx,
			  struct vhost_vring_state *state);

#endif
