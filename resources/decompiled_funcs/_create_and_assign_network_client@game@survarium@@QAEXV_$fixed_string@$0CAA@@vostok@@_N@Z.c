void __thiscall survarium::game::create_and_assign_network_client(
        survarium::game *this,
        vostok::fixed_string<512> client_options,
        const bool is_spectator,
        int is_spectatora)
{
  _BYTE *v4; // eax
  int v5; // edi
  survarium::lobby_menu *v6; // ecx
  int v7; // eax
  vostok::memory::doug_lea_allocator *f; // ecx
  survarium::login_menu *v9; // ecx
  int v10; // eax

  if ( (char **)(client_options.m_begin + 1028) != &client_options.m_end )
  {
    v4 = (_BYTE *)*((_DWORD *)client_options.m_begin + 257);
    *((_DWORD *)client_options.m_begin + 258) = v4;
    *v4 = 0;
    v5 = client_options.m_max_end - client_options.m_end;
    memcpy(
      *((unsigned __int8 **)client_options.m_begin + 258),
      (unsigned __int8 *)client_options.m_end,
      client_options.m_max_end - client_options.m_end);
    *((_DWORD *)client_options.m_begin + 258) += v5;
    **((_BYTE **)client_options.m_begin + 258) = 0;
  }
  if ( LOBYTE(STACK[0x224]) )
  {
    survarium::game::create_network_client(this, (survarium::game *)client_options.m_begin, 1);
  }
  else
  {
    v6 = (survarium::lobby_menu *)vostok::memory::doug_lea_allocator::malloc_impl(
                                    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                    0x12Cu);
    if ( v6 )
      survarium::lobby_menu::lobby_menu(v6, (survarium::game *)client_options.m_begin);
    else
      v7 = 0;
    f = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
    *((_DWORD *)client_options.m_begin + 221) = v7;
    v9 = (survarium::login_menu *)vostok::memory::doug_lea_allocator::malloc_impl(f, 0xD0u);
    if ( v9 )
    {
      survarium::login_menu::login_menu(v9, (survarium::game *)client_options.m_begin);
      *((_DWORD *)client_options.m_begin + 222) = v10;
    }
    else
    {
      *((_DWORD *)client_options.m_begin + 222) = 0;
    }
  }
}
