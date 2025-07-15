void __thiscall survarium::lobby_menu::on_profile_changed(
        survarium::lobby_menu *this,
        int profile_id,
        survarium::factions_enum faction)
{
  int v3; // ebx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  unsigned int v5; // esi
  unsigned __int8 v6; // al
  bool v7; // al
  survarium::lobby_character *v8; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // ecx
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  int v12; // edx
  survarium::flash_value *v13; // ecx
  Scaleform::GFx::Value *v14; // esi
  bool has_passed_filters; // al
  int v16; // eax
  survarium::flash_movie *v17; // ecx
  survarium::inventory_item_descr *slots; // eax
  int id; // esi
  int v20; // eax
  survarium::flash_value *v21; // ecx
  survarium::flash_value *v22; // ecx
  survarium::flash_value *v23; // ecx
  survarium::flash_value *v24; // ecx
  survarium::flash_value *v25; // ecx
  survarium::flash_value *v26; // ecx
  bool v27; // zf
  int v28; // eax
  survarium::flash_value *v29; // ecx
  survarium::flash_value *v30; // ecx
  const survarium::lobby_player_profile *v31; // edi
  survarium::flash_value *v32; // ecx
  survarium::flash_value *v33; // ecx
  survarium::flash_value *v34; // ecx
  survarium::flash_value *v35; // ecx
  survarium::lobby_client *v36; // ecx
  survarium::lobby_client *v37; // ecx
  survarium::lobby_menu *v38; // ecx
  survarium::flash_value *v39; // ecx
  survarium::flash_value *v40; // ecx
  int v41; // edx
  survarium::factions_enum v42; // edi
  survarium::text_translator *v43; // ecx
  Scaleform::GFx::Value *v44; // esi
  int i; // edi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v46; // [esp-4h] [ebp-304h]
  int v47; // [esp-4h] [ebp-304h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v48; // [esp-4h] [ebp-304h]
  char v49[512]; // [esp+10h] [ebp-2F0h] BYREF
  survarium::flash_value v50; // [esp+210h] [ebp-F0h] BYREF
  survarium::flash_value v51; // [esp+228h] [ebp-D8h] BYREF
  survarium::flash_value v52; // [esp+240h] [ebp-C0h] BYREF
  survarium::flash_value v53; // [esp+258h] [ebp-A8h] BYREF
  Scaleform::GFx::Value pvalue; // [esp+270h] [ebp-90h] BYREF
  Scaleform::GFx::Value pargs; // [esp+288h] [ebp-78h] BYREF
  survarium::flash_value value; // [esp+2A0h] [ebp-60h] BYREF
  survarium::flash_value v57; // [esp+2B8h] [ebp-48h] BYREF
  Scaleform::GFx::Value v58; // [esp+2D0h] [ebp-30h] BYREF
  char v59; // [esp+2E8h] [ebp-18h] BYREF
  int condition_or_stack; // [esp+2ECh] [ebp-14h]
  int v61; // [esp+2F0h] [ebp-10h]
  survarium::inventory_item_descr *v62; // [esp+2F4h] [ebp-Ch]
  unsigned int profile_ida; // [esp+2F8h] [ebp-8h]
  survarium::player_profile *profile; // [esp+2FCh] [ebp-4h]

  v3 = profile_id;
  profile_id = 0;
  v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(v3 + 160) + 13912) + 60))(*(_DWORD *)(*(_DWORD *)(v3 + 160) + 13912));
  v6 = faction;
  profile_ida = v5;
  if ( (unsigned __int8)faction < *(_BYTE *)(v5 + 608) )
  {
    v8 = *(survarium::lobby_character **)(v3 + 1608);
    *(_BYTE *)(v3 + 1604) = faction;
    profile = (survarium::player_profile *)(1512 * v6 + v5 + 616);
    survarium::lobby_character::setup_profile(v8, (survarium::lobby_player_profile *)profile);
    if ( *(_BYTE *)(v5 + 13140) )
    {
      HIBYTE(faction) = survarium::calculate_profile_icon(
                          profile,
                          *(const survarium::items_dictionary **)(*(_DWORD *)(v3 + 160) + 13908));
      v10 = &v57;
      do
      {
        survarium::flash_value::flash_value(v10);
        v10 = v11 + 1;
      }
      while ( v12 - 1 >= 0 );
      survarium::flash_value::SetUInt(v10, (int)&v57, 0);
      survarium::flash_value::SetUInt(v13, (int)&v58, HIBYTE(faction));
      Scaleform::GFx::Movie::Invoke(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(v3 + 1600) + 264) + 4),
        "root.set_squad_player_type",
        0,
        (const Scaleform::GFx::Value *)&v57,
        2u);
      v14 = (Scaleform::GFx::Value *)&v59;
      for ( faction = faction_scavengers; faction >= faction_neutral; --faction )
        Scaleform::GFx::Value::~Value(--v14);
    }
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)2),
          v9 = v48,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v9,
        &v57.body[16]);
      profile_id = 2;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v57.body[16],
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\lobby_menu_ui.cpp",
        0x5B5u,
        "void __thiscall survarium::lobby_menu::on_profile_changed(unsigned char)",
        "game",
        error,
        "profile_changed");
    }
    if ( (profile_id & 2) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v9,
        (int *)&v57.body[16]);
    v16 = *(_DWORD *)(v3 + 1600);
    pvalue.pObjectInterface = 0;
    pvalue.Type = VT_Undefined;
    Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v16 + 264) + 4), &pvalue);
    slots = profile->slots;
    HIBYTE(faction) = 0;
    *(_DWORD *)value.body = 0;
    *(_DWORD *)&value.body[4] = 0;
    profile_id = 0;
    v62 = profile->slots;
    v61 = 23;
    do
    {
      id = slots->id;
      if ( id )
      {
        condition_or_stack = slots->condition_or_stack;
        v20 = *(_DWORD *)(v3 + 1600);
        v58.pObjectInterface = 0;
        v58.Type = VT_Undefined;
        survarium::flash_movie::CreateObject(v17, *(survarium::flash_value **)(v20 + 264), &v58);
        survarium::flash_value::SetInt(v21, (int)&value, id);
        survarium::flash_value::SetMember(v22, &v58, "itemId", &value);
        survarium::flash_value::SetInt(v23, (int)&value, profile_id);
        survarium::flash_value::SetMember(v24, &v58, "slotId", &value);
        survarium::flash_value::SetInt(v25, (int)&value, condition_or_stack);
        survarium::flash_value::SetMember(v26, &v58, "condition_or_stack", &value);
        pvalue.pObjectInterface->SetElement(
          pvalue.pObjectInterface,
          (void *)pvalue.mValue.IValue,
          HIBYTE(faction),
          &v58);
        ++HIBYTE(faction);
        Scaleform::GFx::Value::~Value(&v58);
        slots = v62;
      }
      ++profile_id;
      ++slots;
      v27 = v61-- == 1;
      v62 = slots;
    }
    while ( !v27 );
    v28 = *(_DWORD *)(v3 + 1600);
    pargs.pObjectInterface = 0;
    pargs.Type = VT_Undefined;
    survarium::flash_movie::CreateObject(v17, *(survarium::flash_value **)(v28 + 264), &pargs);
    survarium::flash_value::SetMember(v29, &pargs, "items", (survarium::flash_value *)&pvalue);
    *(_DWORD *)v53.body = 0;
    *(_DWORD *)&v53.body[4] = 0;
    survarium::flash_value::SetString(&v53, profile->profile_name);
    survarium::flash_value::SetMember(v30, &pargs, "name", &v53);
    *(_DWORD *)v52.body = 0;
    *(_DWORD *)&v52.body[4] = 0;
    v31 = (const survarium::lobby_player_profile *)profile;
    survarium::flash_value::SetUInt(v32, (int)&v52, profile->profile_id);
    survarium::flash_value::SetMember(v33, &pargs, "profileId", &v52);
    survarium::flash_value::SetUInt(v34, (int)&v53, 1u);
    survarium::flash_value::SetMember(v35, &pargs, "icon", &v53);
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(v3 + 1600) + 264) + 4),
      "root.fill_player_profile_items",
      0,
      &pargs,
      1u);
    survarium::lobby_client::query_profile_leveling(
      v36,
      (const vostok::network_core::tcp_packet *)profile_ida,
      v31->profile_id);
    survarium::lobby_client::set_active_profile(
      v37,
      (const vostok::network_core::tcp_packet *)profile_ida,
      v31->profile_id);
    survarium::lobby_menu::player_parameters_ready(v38, v3, v31);
    survarium::get_profile_faction_affinity(
      v31,
      *(const survarium::items_dictionary **)(*(_DWORD *)(v3 + 160) + 13908),
      &faction,
      (float *)&profile_id);
    v39 = &v50;
    do
    {
      survarium::flash_value::flash_value(v39);
      v39 = v40 + 1;
    }
    while ( v41 - 1 >= 0 );
    v42 = faction;
    survarium::flash_value::SetUInt(v39, (int)&v50, faction);
    survarium::text_translator::translate_text(
      v43,
      *(_DWORD *)(v3 + 160) + 13944,
      (char *)survarium::sellers_names[v42],
      v49);
    survarium::flash_value::SetString(&v51, v49);
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(v3 + 1600) + 264) + 4),
      "root.set_active_faction",
      0,
      (const Scaleform::GFx::Value *)&v50,
      2u);
    v44 = (Scaleform::GFx::Value *)&v52;
    for ( i = 1; i >= 0; --i )
      Scaleform::GFx::Value::~Value(--v44);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v52);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v53);
    Scaleform::GFx::Value::~Value(&pargs);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
    Scaleform::GFx::Value::~Value(&pvalue);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (v7 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2), v4 = v46, v7) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v4,
        &v57.body[16]);
      v47 = *(unsigned __int8 *)(profile_ida + 608);
      profile_id = 1;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v57.body[16],
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\lobby_menu_ui.cpp",
        0x5A2u,
        "void __thiscall survarium::lobby_menu::on_profile_changed(unsigned char)",
        "game",
        error,
        "Wrong change profile id[%d] of [%d]",
        (unsigned __int8)faction,
        v47);
    }
    if ( (profile_id & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
        (int *)&v57.body[16]);
  }
}
