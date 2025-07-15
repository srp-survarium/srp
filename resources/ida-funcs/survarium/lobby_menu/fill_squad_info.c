void __thiscall survarium::lobby_menu::fill_squad_info(
        survarium::lobby_menu *this,
        const vostok::fixed_vector<survarium::squad_member_item,3> *squad,
        int *is_commander,
        bool a4)
{
  const vostok::fixed_vector<survarium::squad_member_item,3> *v4; // edi
  char *v5; // esi
  int v6; // ecx
  char *v7; // esi
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  bool v11; // al
  survarium::lobby_menu *v12; // ecx
  int v13; // esi
  int v14; // ebx
  survarium::flash_value *v15; // ecx
  survarium::flash_value *v16; // ecx
  int v17; // edx
  int v18; // ecx
  int v19; // ebx
  bool has_passed_filters; // al
  const char *v21; // edi
  survarium::flash_value *v22; // ecx
  survarium::flash_value *v23; // ecx
  survarium::lobby_menu *v24; // ecx
  survarium::lobby_menu *v25; // ecx
  int v26; // eax
  survarium::lobby_menu *v27; // ecx
  survarium::lobby_client *v28; // eax
  survarium::lobby_client *v29; // ecx
  unsigned int v30; // eax
  Scaleform::GFx::Value *v31; // esi
  int i; // edi
  bool v33; // [esp-4h] [ebp-C8h]
  int v34; // [esp-4h] [ebp-C8h]
  int v35; // [esp-4h] [ebp-C8h]
  survarium::flash_value v36; // [esp+10h] [ebp-B4h] BYREF
  survarium::flash_value v37; // [esp+28h] [ebp-9Ch] BYREF
  _BYTE v38[24]; // [esp+40h] [ebp-84h] BYREF
  _BYTE v39[24]; // [esp+58h] [ebp-6Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v40; // [esp+70h] [ebp-54h] BYREF
  Scaleform::GFx::Value pargs; // [esp+94h] [ebp-30h] BYREF
  int v42; // [esp+ACh] [ebp-18h]
  char *v43; // [esp+B0h] [ebp-14h]
  unsigned int value; // [esp+B4h] [ebp-10h]
  int v45; // [esp+B8h] [ebp-Ch]
  unsigned __int8 m_profiles_count; // [esp+BFh] [ebp-5h]
  const char *v47; // [esp+D4h] [ebp+10h]
  unsigned __int8 v48; // [esp+D7h] [ebp+13h]

  v33 = *is_commander != is_commander[1];
  v45 = 0;
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetBoolean((survarium::flash_value *)this, (int)&pargs, v33);
  v4 = squad;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&squad[6].m_buffer[0].m_store[76] + 264) + 4),
    "root.show_squad",
    0,
    &pargs,
    1u);
  if ( (unsigned int)((is_commander[1] - *is_commander) / 80) < 3 )
  {
    v5 = &squad[6].m_buffer[1].m_store[12];
    survarium::lobby_character::clear_resources(
      (survarium::lobby_character *)0x50,
      *(vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> **)&squad[6].m_buffer[1].m_store[12]);
    *(_DWORD *)(1512 * *(unsigned __int8 *)(*(_DWORD *)v5 + 4560) + *(_DWORD *)v5 + 1524) = -1;
    *(_DWORD *)(1512 * *(unsigned __int8 *)(*(_DWORD *)v5 + 4560) + *(_DWORD *)v5 + 28) = 0;
  }
  v6 = 80;
  if ( (unsigned int)((is_commander[1] - *is_commander) / 80) < 2 )
  {
    v7 = &squad[6].m_buffer[1].m_store[8];
    survarium::lobby_character::clear_resources(
      (survarium::lobby_character *)0x50,
      *(vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> **)&squad[6].m_buffer[1].m_store[8]);
    v6 = 1512 * *(unsigned __int8 *)(*(_DWORD *)&squad[6].m_buffer[1].m_store[8] + 4560);
    *(_DWORD *)(v6 + *(_DWORD *)v7 + 1524) = -1;
    *(_DWORD *)(1512 * *(unsigned __int8 *)(*(_DWORD *)v7 + 4560) + *(_DWORD *)v7 + 28) = 0;
  }
  survarium::flash_value::SetUInt((survarium::flash_value *)v6, (int)&pargs, 0);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&squad[6].m_buffer[0].m_store[76] + 264) + 4),
    "root.remove_squad_player",
    0,
    &pargs,
    1u);
  survarium::flash_value::SetUInt(v8, (int)&pargs, 1u);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&squad[6].m_buffer[0].m_store[76] + 264) + 4),
    "root.remove_squad_player",
    0,
    &pargs,
    1u);
  survarium::flash_value::SetUInt(v9, (int)&pargs, 2u);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&squad[6].m_buffer[0].m_store[76] + 264) + 4),
    "root.remove_squad_player",
    0,
    &pargs,
    1u);
  v11 = *is_commander == is_commander[1] || a4;
  survarium::flash_value::SetBoolean(v10, (int)&pargs, v11);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&squad[6].m_buffer[0].m_store[76] + 264) + 4),
    "root.set_squad_commander_mode",
    0,
    &pargs,
    1u);
  v13 = *is_commander;
  v14 = is_commander[1];
  if ( *is_commander == v14 )
  {
    survarium::lobby_menu::update_play_button_lock(v12, (int)squad);
  }
  else
  {
    v15 = &v36;
    do
    {
      survarium::flash_value::flash_value(v15);
      v15 = v16 + 1;
    }
    while ( v17 - 1 >= 0 );
    v18 = 80;
    value = 0;
    if ( (v14 - v13) / 80 )
    {
      v42 = 0;
      v43 = &squad[6].m_buffer[1].m_store[8];
      do
      {
        v19 = v42 + v13;
        if ( !vostok::core::g_log_filter_tree
          || (has_passed_filters = vostok::logging::has_passed_filters(
                                     (vostok::logging::filter_tree *)"game",
                                     (const char *)4),
              v18 = v34,
              has_passed_filters) )
        {
          v47 = "ready";
          if ( !*(_BYTE *)(v19 + 78) )
            v47 = "not ready";
          v21 = "online";
          if ( !*(_BYTE *)(v19 + 77) )
            v21 = "offline";
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v18,
            &v40);
          v45 |= 1u;
          vostok::logging::append(
            &v40,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\lobby_menu_ui.cpp",
            0xAEBu,
            "void __thiscall survarium::lobby_menu::fill_squad_info(const class vostok::fixed_vector<struct survarium::sq"
            "uad_member_item,3> &,bool)",
            "game",
            info,
            "squad member[%d] %s | %d | %s | %s",
            value,
            (const char *)(v19 + 12),
            *(_DWORD *)v19,
            v21,
            v47);
        }
        if ( (v45 & 1) != 0 )
        {
          v45 &= ~1u;
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v18,
            (int *)&v40);
        }
        survarium::flash_value::SetUInt((survarium::flash_value *)v18, (int)&v36, value);
        survarium::flash_value::SetString(&v37, (const char *)(v19 + 12));
        survarium::flash_value::SetUInt(v22, (int)v38, *(_DWORD *)v19);
        survarium::flash_value::SetBoolean(v23, (int)v39, *(_BYTE *)(v19 + 78));
        Scaleform::GFx::Movie::Invoke(
          *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&squad[6].m_buffer[0].m_store[76] + 264) + 4),
          "root.set_squad_player",
          0,
          (const Scaleform::GFx::Value *)&v36,
          4u);
        m_profiles_count = survarium::lobby_menu::lobby_client(v24, (int)squad)->m_profiles_count;
        v48 = 0;
        if ( m_profiles_count )
        {
          while ( survarium::lobby_menu::lobby_client(v25, (int)squad)->m_profiles[v48].profile_id != *(_DWORD *)(v19 + 4) )
          {
            LOBYTE(v25) = v48 + 1;
            v48 = (unsigned __int8)v25;
            if ( (unsigned __int8)v25 >= m_profiles_count )
              goto LABEL_26;
          }
        }
        else
        {
LABEL_26:
          if ( m_profiles_count )
          {
            v26 = *(_DWORD *)v43;
            if ( *(_DWORD *)(1512 * *(unsigned __int8 *)(*(_DWORD *)v43 + 4560) + *(_DWORD *)v43 + 1524) != *(_DWORD *)(v19 + 8)
              || *(_DWORD *)(1512 * *(unsigned __int8 *)(v26 + 4560) + v26 + 28) != *(_DWORD *)(v19 + 4) )
            {
              v27 = *(survarium::lobby_menu **)(v19 + 4);
              *(_DWORD *)v26 = v27;
              v35 = *(_DWORD *)(v19 + 4);
              v28 = survarium::lobby_menu::lobby_client(v27, (int)squad);
              survarium::lobby_client::query_squad_member_contents(
                v29,
                (const vostok::network_core::tcp_packet *)v28,
                v35);
            }
            v43 += 4;
          }
        }
        v13 = *is_commander;
        v18 = 80;
        v30 = (is_commander[1] - *is_commander) / 80;
        ++value;
        v42 += 80;
      }
      while ( value < v30 );
      v4 = squad;
    }
    survarium::lobby_menu::update_play_button_lock((survarium::lobby_menu *)0x50, (int)v4);
    v31 = (Scaleform::GFx::Value *)&v40;
    for ( i = 3; i >= 0; --i )
      Scaleform::GFx::Value::~Value(--v31);
  }
  Scaleform::GFx::Value::~Value(&pargs);
}
