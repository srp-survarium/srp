// SPDX-License-Identifier: GPL-3.0-or-later
// Replacement for the call to game::set_network_client at VA 0x1ec0e1.
// Original LTO ABI: EDI=game, EAX=network client; stack=(host,port,spectator).
// Both this wrapper and the original routine pop their three stack arguments.
.intel_syntax noprefix
.text
.global _start
_start:
    push ebp
    mov ebp, esp
    pushad
    push dword ptr [ebp+16]
    push dword ptr [ebp+12]
    push dword ptr [ebp+8]
    call 0x1ed6e0
.if WITH_REJOIN
    push dword ptr [ebp+16]
    push dword ptr [ebp+12]
    push dword ptr [ebp+8]
    push edi
    call rejoin_configure
    add esp, 16
.endif
    // The normal player path creates the UI objects required by E4 handling.
    cmp dword ptr [ebp+16], 0
    jne finished
.if WITH_REJOIN
    push 0
    call rejoin_session
    add esp, 4
    test eax, eax
    jz finished
.else
    // QPC's existing KERNEL32 import, also called by retail VA 0x1b7b0.
    // This is a local connection discriminator, not an authentication token.
    sub esp, 8
    mov eax, esp
    push eax
    call dword ptr [0x870158]
    test eax, eax
    pop eax
    pop edx
    jz finished
    xor eax, edx
    or eax, 1                      # nonzero; server rejects active collisions
.endif
    mov ecx, [edi+0x53ac]
    test ecx, ecx
    jz finished
    mov [ecx+0x1ee7ec], eax         # E3 handler reads D9 session from this field
    push eax                       # per-launch development session
    push 1                         # match ID (must differ from the initial ID)
    push dword ptr [ebp+12]         # port from -server=host:port
    push dword ptr [ebp+8]          # host
    call 0x21beb0                   # original network_client::connect_to_match
finished:
    popad
    leave
    ret 12

.if WITH_REJOIN
# Actual input::handler entry, before the native keyboard delegate selection.
# ECX=lobby+0xec; stack=(input world, key, action).
.global rejoin_key
rejoin_key:
    pushfd
    pushad
    push dword ptr [esp+48]
    push dword ptr [esp+48]
    lea eax, [ecx-0xec]
    push eax
    call rejoin_keyboard
    add esp, 12
    test eax, eax
    jz rejoin_original
    popad
    popfd
    mov eax, 1
    ret 12
rejoin_original:
    popad
    popfd
    lea eax, [ecx+0x2fbc]
    jmp 0x26cb66
.endif

.if WITH_SNAPSHOTS
# E2 is unused in retail. Keep stock message semantics for every existing ID.
.global snapshot_length
snapshot_length:
.if WITH_RESULTS
    cmp byte ptr [esp+4], 0xf8
    je result_length
.endif
    cmp byte ptr [esp+4], 0xf7
    je request_length
    cmp byte ptr [esp+4], 0xe2
    jne original_length
    mov eax, [esp+24]
    mov byte ptr [eax], 1
    mov eax, 0xffff
    ret 24
.if WITH_RESULTS
result_length:
    mov eax, [esp+24]
    mov byte ptr [eax], 1
    mov eax, 0xffff
    ret 24
.endif
request_length:
    mov eax, [esp+24]
    mov byte ptr [eax], 1
    mov eax, 4
    ret 24
original_length:
    push ebp
    mov ebp, esp
    and esp, -8
    jmp 0x279676

.global snapshot_delivery
snapshot_delivery:
    cmp ecx, 0xe2
    jne original_delivery
    mov dword ptr [eax], -1
    mov word ptr [eax+4], 500
    mov byte ptr [eax+6], 0x1f  # variable-size, no unique/order ID
    ret
original_delivery:
    sub ecx, 0xd8
    jmp 0x279a66

.global snapshot_server_delivery
snapshot_server_delivery:
.if WITH_RESULTS
    cmp ecx, 0xf8
    jne not_results_delivery
    mov dword ptr [eax], -1
    mov word ptr [eax+4], 250
    mov byte ptr [eax+6], 0x1f
    ret
not_results_delivery:
.endif
    cmp ecx, 0xf7
    jne original_server_delivery
    mov dword ptr [eax], -1
    mov word ptr [eax+4], 500
    mov byte ptr [eax+6], 0x9f  # fixed four-byte request, no unique/order ID
    ret
original_server_delivery:
    sub ecx, 0xe3
    jmp 0x279b16

# ECX=network client, stack=(opcode, buffer_reader*), ret 8.
# F7 requests an exact retained game-state timestamp. If it has aged out,
# consume the request without inventing a replacement at a different time.
.global snapshot_request
snapshot_request:
.if WITH_RESULTS
    cmp byte ptr [esp+4], 0xf8
    jne not_results_message
    pushad
    push dword ptr [esp+40]
    push ecx
    call results_receive
    add esp, 8
    popad
    ret 8
not_results_message:
.endif
    cmp byte ptr [esp+4], 0xf7
    jne original_dispatch
    pushad
    mov ebx, ecx
    mov edi, [esp+40]
    mov edx, [edi+4]
    mov ecx, [edx]
    add dword ptr [edi+4], 4
    mov eax, [ebx+0x1f1c40]
    test eax, eax
    jz request_done
    add eax, 0x1f8
    mov esi, [eax+0x2fc0]
request_find:
    test esi, esi
    jz request_done
    cmp [esi+0xc0bb0], ecx
    je request_found
    jb request_done
    mov esi, [esi+0xc0ba8]
    jmp request_find
request_found:
    call send_snapshot
request_done:
    popad
    ret 8
original_dispatch:
    push ebp
    mov ebp, esp
    sub esp, 0x64
    jmp 0x27a306

.global snapshot_ready
snapshot_ready:
    pushad
    mov eax, [ebx+0x1f1c40]
    test eax, eax
    jz ready_done
    add eax, 0x1f8
    mov esi, [eax+0x2fc0]         # newest history item
    test esi, esi
    jz ready_done
    call send_snapshot
ready_done:
    popad
    mov byte ptr [ebx+0x1f1c68], 0xff
    jmp 0x27aea1

# EAX=world core, ESI=history item, EBX=network client. Caller saves registers.
# E2 body: time:u32, offset:u16, total:u16, <=480 serialized bytes.
send_snapshot:
    push ebp
    mov ebp, esp
    sub esp, 0x50
    mov [ebp-4], esi
    mov [ebp-8], ebx
    mov [ebp-12], eax
    mov eax, 0x8000
    call 0x424ca0               # original stack allocation/probe helper
    mov [ebp-16], esp
    xor eax, eax
    mov [ebp-0x30], eax         # mutable_buffer allocator
    mov [ebp-0x2c], esp         # data
    mov dword ptr [ebp-0x28], 0x8000
    mov [ebp-0x24], eax         # size
    mov [ebp-0x48], eax         # writer debug metadata
    mov [ebp-0x44], eax
    mov [ebp-0x40], eax
    mov [ebp-0x3c], eax
    mov dword ptr [ebp-0x38], 0xff
    lea ecx, [ebp-0x30]
    mov [ebp-0x34], ecx         # writer mutable_buffer pointer
    mov ecx, [esi+0xc0bb0]
    mov [ebp-0x20], ecx         # snapshot time, separate from serialized body
    mov eax, [ebp-12]
    mov eax, [eax+0x12288]      # mask-history back item
    xor edx, edx
mask_loop:
    test eax, eax
    jz mask_found
    cmp [eax+12], ecx
    jbe mask_use
    mov eax, [eax+4]
    jmp mask_loop
mask_use:
    mov edx, [eax+8]
mask_found:
    push edx
    lea eax, [ebp-0x48]
    push eax
    push esi
    call 0x324be0              # original serializer, ret 12
    mov eax, [ebp-0x24]
    mov [ebp-0x1a], ax         # total size
    mov dword ptr [ebp-0x14], 0
chunk_loop:
    mov esi, [ebp-0x14]
    cmp esi, [ebp-0x24]
    jae snapshot_done
    mov [ebp-0x1c], si         # fragment offset
    mov eax, [ebp-8]
    mov ecx, [eax+0x1f1c48]
    mov edx, [ecx]
    push 0xe2
    call [edx+0x18]            # make message
    mov [ebp-0x18], eax
    mov edi, [ebp-0x24]
    sub edi, esi
    cmp edi, 480
    jbe chunk_size
    mov edi, 480
chunk_size:
    mov eax, [eax+0x2bc]       # message writer's mutable_buffer
    mov edx, [eax+12]          # preserve native framing prefix
    mov [ebp-0x4c], edx
    lea ecx, [edi+8]
    add ecx, edx
    push ecx
    call 0x7ab30               # resize; allocator owns message storage
    mov eax, [ebp-0x18]
    mov eax, [eax+0x2bc]
    mov edx, [eax+4]
    add edx, [ebp-0x4c]
    mov eax, [ebp-0x20]
    mov [edx], eax
    mov eax, [ebp-0x1c]
    mov [edx+4], eax
    mov ecx, edi
    lea edi, [edx+8]
    add esi, [ebp-16]
    rep movsb
    mov eax, [ebp-8]
    mov ecx, [eax+0x1f1c48]
    mov edx, [ecx]
    push dword ptr [ebp-0x18]
    call [edx+0x1c]            # enqueue message
    add dword ptr [ebp-0x14], 480
    jmp chunk_loop
snapshot_done:
    leave
    ret
.endif

.if WITH_RESULTS
.global results_close_native
results_close_native:
    push esi
    mov esi, [esp+8]
    push dword ptr [esp+12]
    call 0x27c690
    pop esi
    ret

# The direct match has no authenticated lobby connection. Retail 0x1ed1e0
# therefore skips switching the active menu, leaving results without input.
# Enter its normal menu-switch tail, with the exact saved-register frame.
# This only runs after a validated F8 has closed the match world.
.global results_activate_native
results_activate_native:
    push esi
    mov esi, [esp+8]
    push edi
    jmp 0x1ed222

# Retail lobby clicks require an authenticated profile before forwarding to
# Scaleform. A presented results window also needs clicks on the direct path.
# ECX points to input::handler at lobby+0xec; +0x313a is the native window flag.
.global results_mouse
results_mouse:
    push ecx
    push esi
    mov esi, ecx
    cmp byte ptr [esi+0x304e], 0
    jne results_mouse_forward
    mov eax, [esi-0x50]
    jmp 0x26cff7
results_mouse_forward:
    jmp 0x26d028

.global results_present_native
results_present_native:
    push esi
    mov esi, [esp+8]
    mov ecx, esi
    push 0
    call 0x29eda0
    mov edx, esi
    xor eax, eax
    call 0x2203a0
    pop esi
    ret
.endif
