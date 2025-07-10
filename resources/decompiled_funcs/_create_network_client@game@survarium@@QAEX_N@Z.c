void __thiscall survarium::game::create_network_client(
        survarium::game *this,
        survarium::game *is_spectator,
        bool is_spectatora)
{
  vostok::buffer_string *p_m_network_client_options; // edi
  int v4; // eax
  unsigned int v5; // ebp
  int v6; // esi
  int v7; // esi
  survarium::game *v8; // eax
  survarium::network_client *v9; // ecx
  survarium::base_network_client *v10; // eax
  survarium::base_network_client *v11; // ecx
  char *m_begin; // [esp-8h] [ebp-43Ch]
  vostok::fixed_string<512> host; // [esp+14h] [ebp-420h] BYREF
  vostok::buffer_string out_dest; // [esp+228h] [ebp-20Ch] BYREF
  _BYTE v15[512]; // [esp+234h] [ebp-200h] BYREF
  _UNKNOWN *retaddr; // [esp+434h] [ebp+0h] BYREF

  p_m_network_client_options = &is_spectator->m_network_client_options;
  m_begin = is_spectator->m_network_client_options.m_begin;
  host.m_buffer[0] = 0;
  strchr(m_begin, 0x3Au);
  if ( v4 )
  {
    v5 = v4 - (unsigned int)p_m_network_client_options->m_begin;
    if ( v5 != -1 )
    {
      out_dest.m_end = v15;
      out_dest.m_max_end = (char *)&retaddr;
      out_dest.m_begin = v15;
      v15[0] = 0;
      vostok::buffer_string::substr(p_m_network_client_options, 0, v5, &out_dest);
      host.m_buffer[0] = 0;
      v6 = out_dest.m_end - out_dest.m_begin;
      memcpy((unsigned __int8 *)host.m_buffer, (unsigned __int8 *)out_dest.m_begin, out_dest.m_end - out_dest.m_begin);
      host.m_buffer[v6] = 0;
      v7 = (unsigned __int16)atoi(&p_m_network_client_options->m_begin[v5 + 1]);
      v8 = (survarium::game *)vostok::memory::doug_lea_allocator::malloc_impl(
                                (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                0x4188u);
      if ( v8 )
      {
        survarium::network_client::network_client(v9, v8, (const bool)is_spectator);
        v11 = v10;
      }
      else
      {
        v11 = 0;
      }
      survarium::game::set_network_client(v11, host.m_buffer, is_spectator, v7, is_spectatora);
    }
  }
}
