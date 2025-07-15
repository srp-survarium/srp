void __thiscall survarium::game::create_network_client(survarium::game *this, survarium::game *is_spectator, bool a3)
{
  vostok::fixed_string<512> *p_m_network_client_options; // esi
  int v4; // eax
  int v5; // ebx
  vostok::buffer_string *v6; // ecx
  unsigned __int16 v7; // ax
  vostok::memory::doug_lea_allocator *v8; // esi
  unsigned __int16 v9; // di
  char *v10; // eax
  vostok::memory::doug_lea_allocator *v11; // ecx
  char *v12; // eax
  survarium::network_client *v13; // ecx
  survarium::base_network_client *v14; // eax
  char *m_begin; // [esp-8h] [ebp-438h]
  const char *v16; // [esp+0h] [ebp-430h]
  const char *v17; // [esp+4h] [ebp-42Ch]
  unsigned int v18; // [esp+8h] [ebp-428h]
  vostok::buffer_string host; // [esp+10h] [ebp-420h] BYREF
  _BYTE v20[512]; // [esp+1Ch] [ebp-414h] BYREF
  char v21; // [esp+21Ch] [ebp-214h] BYREF
  vostok::buffer_string v22; // [esp+224h] [ebp-20Ch] BYREF
  _BYTE v23[512]; // [esp+230h] [ebp-200h] BYREF
  char vars0; // [esp+430h] [ebp+0h] BYREF

  host.m_begin = v20;
  host.m_end = v20;
  host.m_max_end = &v21;
  p_m_network_client_options = &is_spectator->m_network_client_options;
  m_begin = is_spectator->m_network_client_options.m_begin;
  v20[0] = 0;
  strchr(m_begin, 0x3Au);
  if ( v4 )
    v5 = v4 - (unsigned int)p_m_network_client_options->m_begin;
  else
    v5 = -1;
  if ( v5 != -1 )
  {
    v22.m_begin = v23;
    v22.m_end = v23;
    v22.m_max_end = &vars0;
    v23[0] = 0;
    vostok::buffer_string::substr(0, (char *)v5, &v22, p_m_network_client_options);
    vostok::buffer_string::operator=(v6, &host);
    v7 = atoi(&p_m_network_client_options->m_begin[v5 + 1]);
    v8 = survarium::g_allocator;
    v9 = v7;
    v10 = type_info::raw_name(&survarium::network_client `RTTI Type Descriptor');
    v12 = vostok::memory::doug_lea_allocator::malloc_impl(v11, (int)v8, 0x5100u, v10, v16, v17, v18);
    if ( v12 )
      survarium::network_client::network_client(v13, (survarium::game *)v12, is_spectator, a3);
    else
      v14 = 0;
    survarium::game::set_network_client(is_spectator, v14, v9, host.m_begin, a3);
  }
}
