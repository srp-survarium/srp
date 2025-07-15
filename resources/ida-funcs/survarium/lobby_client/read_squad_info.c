char __thiscall survarium::lobby_client::read_squad_info(
        survarium::lobby_client *this,
        vostok::network_core::buffer_reader *reader,
        unsigned int size)
{
  vostok::network_core::buffer_reader *v3; // eax
  unsigned int *v5; // edx
  unsigned int *v6; // esi
  unsigned int v7; // edi
  int *v8; // esi
  unsigned int v9; // eax
  int *v10; // esi
  vostok::network_core::buffer_reader **v11; // esi
  vostok::network_core::buffer_reader *v12; // ecx
  unsigned int v13; // esi
  bool v14; // al
  bool v15; // zf
  unsigned int *v16; // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v17; // ecx
  bool has_passed_filters; // al
  vostok::network_core::buffer_reader *v19; // edi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v21; // [esp-4h] [ebp-4Ch]
  unsigned int m_buffer_size; // [esp-4h] [ebp-4Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v23; // [esp+10h] [ebp-38h] BYREF
  unsigned int v24; // [esp+30h] [ebp-18h]
  vostok::network_core::buffer_reader *v25; // [esp+34h] [ebp-14h]
  int v26; // [esp+38h] [ebp-10h]
  int v27; // [esp+3Ch] [ebp-Ch]
  int v28; // [esp+40h] [ebp-8h]
  unsigned int v29; // [esp+44h] [ebp-4h]
  unsigned int sizeb; // [esp+54h] [ebp+Ch]
  unsigned int sizea; // [esp+54h] [ebp+Ch]
  unsigned int sizec; // [esp+54h] [ebp+Ch]

  v3 = reader;
  v28 = 0;
  reader[1074].m_buffer = (const unsigned __int8 *)reader[1073].m_buffer_size;
  v5 = *(unsigned int **)(size + 4);
  sizeb = *v5;
  *(_DWORD *)(size + 4) = v5 + 1;
  LOBYTE(reader[1095].m_buffer) = 0;
  if ( sizeb )
  {
    v6 = *(unsigned int **)(size + 4);
    v7 = *v6;
    *(_DWORD *)(size + 4) = v6 + 1;
    vostok::buffer_vector<survarium::squad_member_item>::resize(
      (vostok::buffer_vector<survarium::squad_member_item> *)&reader[1073].m_buffer_size,
      v7);
    if ( v7 )
    {
      sizea = 0;
      v29 = v7;
      do
      {
        v8 = *(int **)(size + 4);
        v9 = sizea + reader[1073].m_buffer_size;
        v27 = *v8;
        *(_DWORD *)(size + 4) = v8 + 1;
        *(_DWORD *)v9 = v27;
        v10 = *(int **)(size + 4);
        v26 = *v10;
        *(_DWORD *)(size + 4) = v10 + 1;
        *(_DWORD *)(v9 + 4) = v26;
        v11 = *(vostok::network_core::buffer_reader ***)(size + 4);
        v25 = *v11;
        *(_DWORD *)(size + 4) = v11 + 1;
        v12 = v25;
        v24 = v9;
        *(_DWORD *)(v9 + 8) = v25;
        vostok::network_core::buffer_reader::r_string(v12, (char *)size, (unsigned __int8 *)(v9 + 12));
        v13 = v24;
        *(_BYTE *)(v24 + 76) = vostok::network_core::buffer_reader::r<bool>((vostok::network_core::buffer_reader *)size);
        *(_BYTE *)(v13 + 77) = vostok::network_core::buffer_reader::r<bool>((vostok::network_core::buffer_reader *)size);
        v14 = vostok::network_core::buffer_reader::r<bool>((vostok::network_core::buffer_reader *)size);
        sizea += 80;
        v15 = v29-- == 1;
        *(_BYTE *)(v13 + 78) = v14;
      }
      while ( !v15 );
    }
    LOBYTE(reader[1095].m_buffer) = vostok::network_core::buffer_reader::r<bool>((vostok::network_core::buffer_reader *)size);
    v3 = reader;
  }
  v16 = *(unsigned int **)(size + 4);
  sizec = *v16;
  *(_DWORD *)(size + 4) = v16 + 1;
  v17 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)sizec;
  v3[1094].m_buffer_size = sizec;
  if ( vostok::core::g_log_filter_tree
    && (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"game",
                               (const char *)4),
        v17 = v21,
        !has_passed_filters) )
  {
    v19 = reader;
  }
  else
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v17,
      &v23);
    v19 = reader;
    m_buffer_size = reader[1094].m_buffer_size;
    v28 = 1;
    vostok::logging::append(
      &v23,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\lobby_client.cpp",
      0x3B2u,
      "bool __thiscall survarium::lobby_client::read_squad_info(class vostok::network_core::buffer_reader &)",
      "game",
      info,
      "squad info arrived rev. %d",
      m_buffer_size);
  }
  if ( (v28 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v17,
      (int *)&v23);
  survarium::lobby_menu::fill_squad_info(
    (survarium::lobby_menu *)v17,
    *((const vostok::fixed_vector<survarium::squad_member_item,3> **)v19[5].m_pointer + 3460),
    (int *)&v19[1073].m_buffer_size,
    (bool)v19[1095].m_buffer);
  return 1;
}
