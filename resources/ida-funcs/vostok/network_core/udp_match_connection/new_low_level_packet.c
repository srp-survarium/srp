vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *__userpurge vostok::network_core::udp_match_connection::new_low_level_packet@<eax>(
        vostok::network_core::udp_match_connection *this@<ecx>,
        int a2@<esi>,
        unsigned __int8 message_type)
{
  unsigned __int8 v3; // bl
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *matched; // edi
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  unsigned __int8 v8; // [esp+Bh] [ebp-1h] BYREF

  v3 = message_type;
  matched = vostok::network_core::new_udp_match_packet(*(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> **)(a2 + 2784));
  **(_BYTE **)&matched->data[1328] = 1;
  *(_WORD *)&matched->data[104] = *(_WORD *)(a2 + 2848);
  matched->data[102] = v3 - 6;
  v8 = 1;
  vostok::network_core::buffer_writer::w(v5, &matched->data[1340], &v8, 1u);
  vostok::network_core::buffer_writer::w(v6, &matched->data[1340], &message_type, 1u);
  ++*(_DWORD *)(a2 + 2520);
  *(_DWORD *)(a2 + 2524) += *(_DWORD *)&matched->data[1336] + (*(_BYTE *)(a2 + 2850) == 0 ? 66 : 46);
  ++*(_DWORD *)(a2 + 2528);
  *(_DWORD *)(a2 + 2532) += *(_DWORD *)&matched->data[1336];
  ++*(_DWORD *)(a2 + 2536);
  return matched;
}
