void __thiscall survarium::game_world_ui::initialize_match(
        survarium::game_world_ui *this,
        const survarium::match_options *options,
        survarium::flash_value *a3)
{
  int v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  unsigned __int8 v6; // al
  unsigned __int8 v7; // cl
  int v8; // esi
  __int32 v9; // eax
  _BYTE *v10; // edi
  survarium::dictionary_item *v11; // eax
  int v12; // ecx
  int v13; // eax
  survarium::text_translator *v14; // ecx
  survarium::text_translator *v15; // ecx
  survarium::flash_value *v16; // ecx
  survarium::flash_value *v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  survarium::flash_value *v21; // ecx
  int v22; // eax
  survarium::flash_movie *v23; // ecx
  survarium::flash_value *v24; // edi
  survarium::flash_movie *v25; // ecx
  survarium::flash_value *v26; // ecx
  survarium::flash_value *v27; // ecx
  survarium::flash_value *v28; // ecx
  survarium::flash_value *v29; // ecx
  survarium::flash_value *v30; // ecx
  survarium::flash_value *v31; // ecx
  survarium::flash_value *v32; // ecx
  survarium::flash_value *v33; // ecx
  survarium::flash_value *v34; // ecx
  survarium::flash_value *v35; // ecx
  char *v36; // edi
  survarium::flash_value *v37; // ecx
  survarium::flash_value *v38; // ecx
  survarium::flash_value *v39; // ecx
  survarium::flash_value *v40; // ecx
  survarium::game_world_ui *v41; // ecx
  int v42; // eax
  survarium::game_world_ui *v43; // ecx
  survarium::game_world_ui *v44; // ecx
  survarium::game_world_ui *v45; // ecx
  survarium::game_world_ui *v46; // ecx
  survarium::game_world_ui *v47; // ecx
  survarium::game_world_ui *v48; // ecx
  survarium::flash_value *v49; // [esp+10h] [ebp-2E8h]
  survarium::flash_value *v50; // [esp+14h] [ebp-2E4h]
  char value[512]; // [esp+28h] [ebp-2D0h] BYREF
  Scaleform::GFx::Value v52; // [esp+228h] [ebp-D0h] BYREF
  Scaleform::GFx::Value pargs; // [esp+240h] [ebp-B8h] BYREF
  survarium::flash_value v54; // [esp+258h] [ebp-A0h] BYREF
  Scaleform::GFx::Value v55; // [esp+270h] [ebp-88h] BYREF
  Scaleform::GFx::Value pvalue; // [esp+288h] [ebp-70h] BYREF
  survarium::flash_value v57; // [esp+2A0h] [ebp-58h] BYREF
  int v58[2]; // [esp+2B8h] [ebp-40h] BYREF
  Scaleform::GFx::Value v59; // [esp+2C0h] [ebp-38h] BYREF
  unsigned int v60; // [esp+2D8h] [ebp-20h]
  survarium::flash_value v61; // [esp+2DCh] [ebp-1Ch] BYREF
  unsigned __int8 v62; // [esp+2F7h] [ebp-1h]
  unsigned __int8 v63; // [esp+303h] [ebp+Bh]
  unsigned __int8 i; // [esp+303h] [ebp+Bh]
  unsigned __int8 v65; // [esp+304h] [ebp+Ch]
  unsigned __int8 j; // [esp+304h] [ebp+Ch]
  unsigned __int8 v67; // [esp+304h] [ebp+Ch]

  v59.mValue.IValue = (int)survarium::game_world_ui::on_player_score_changed;
  *((_DWORD *)&v59.mValue.BValue + 1) = 0;
  v59.DataAux = (unsigned int)options;
  *(_DWORD *)&v61.body[8] = survarium::game_world_ui::on_player_score_changed;
  *(_DWORD *)&v61.body[12] = 0;
  *(_DWORD *)&v61.body[16] = options;
  *(_DWORD *)&v61.body[20] = *(&v59.DataAux + 1);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v58[0] = 0;
  }
  else
  {
    v59.pObjectInterface = *(Scaleform::GFx::Value::ObjectInterface **)&v61.body[8];
    v59.Type = *(_DWORD *)&v61.body[12];
    v59.mValue.NValue = *(long double *)&v61.body[16];
    v58[0] = (int)&`boost::function2<void,unsigned char,short>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_world_ui,unsigned char,short>,boost::_bi::list3<boost::_bi::value<survarium::game_world_ui *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable
           + 1;
  }
  v4 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&options->player_profiles.elems[0].profile_name[12] + 160) + 13912);
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v4 + 48))(v4, v58);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, v58);
  *(_DWORD *)&options->player_profiles.elems[0].profile_name[16] = a3;
  v6 = a3[1240].body[12];
  v7 = 0;
  v62 = -1;
  if ( v6 )
  {
    while ( !a3[62 * v7 + 18].body[12] )
    {
      if ( ++v7 >= v6 )
        goto LABEL_14;
    }
    v62 = v7;
    v8 = 93 * v7;
    v63 = 0;
    while ( 1 )
    {
      v9 = 16 * (v8 + quick_slots_0[v63]);
      v10 = (_BYTE *)(v9 + *(_DWORD *)&options->player_profiles.elems[0].profile_name[16] + 72);
      v11 = survarium::items_dictionary::item_by_id(
              *(survarium::items_dictionary **)(*(_DWORD *)(*(_DWORD *)&options->player_profiles.elems[0].profile_name[12]
                                                          + 160)
                                              + 13908),
              (survarium::items_dictionary_vtbl *)*(unsigned __int16 *)(v9
                                                                      + *(_DWORD *)&options->player_profiles.elems[0].profile_name[16]
                                                                      + 84));
      if ( v11 )
      {
        if ( v11->item_category == 11 )
          break;
      }
      if ( ++v63 >= 6u )
        goto LABEL_14;
    }
    BYTE5(options->player_profiles.elems[0].modifiers.m_modifiers.elems[1].m_mutex.m_mutex[1]) = *v10;
  }
LABEL_14:
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)options->player_profiles.elems[0].profile_name + 264) + 4),
    "root.reset",
    0,
    0,
    0);
  v12 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&options->player_profiles.elems[0].profile_name[8] + 264) + 4);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v12 + 88))(v12, 1);
  v13 = *(_DWORD *)&options->player_profiles.elems[0].profile_name[12];
  *(_DWORD *)v57.body = 0;
  *(_DWORD *)&v57.body[4] = 0;
  survarium::text_translator::translate_text(v14, *(_DWORD *)(v13 + 160) + 13944, "st_label_teamA", value);
  survarium::flash_value::SetString(&v57, value);
  Scaleform::GFx::Movie::SetVariable(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)options->player_profiles.elems[0].profile_name + 264) + 4),
    "root.player_list.players.team1.text",
    (const Scaleform::GFx::Value *)&v57,
    SV_Sticky);
  survarium::text_translator::translate_text(
    v15,
    *(_DWORD *)(*(_DWORD *)&options->player_profiles.elems[0].profile_name[12] + 160) + 13944,
    "st_label_teamB",
    value);
  survarium::flash_value::SetString(&v57, value);
  Scaleform::GFx::Movie::SetVariable(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)options->player_profiles.elems[0].profile_name + 264) + 4),
    "root.player_list.players.team2.text",
    (const Scaleform::GFx::Value *)&v57,
    SV_Sticky);
  survarium::flash_value::SetUInt(v16, (int)&v57, 0xFF0000u);
  Scaleform::GFx::Movie::SetVariable(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)options->player_profiles.elems[0].profile_name + 264) + 4),
    "root.player_list.players.team2.textColor",
    (const Scaleform::GFx::Value *)&v57,
    SV_Sticky);
  if ( v62 == 0xFF )
  {
    v18 = 0;
  }
  else
  {
    v17 = a3;
    v18 = *(_DWORD *)&a3[62 * v62 + 18].body[8];
  }
  LODWORD(options->player_profiles.elems[0].modifiers.m_modifiers.elems[1].m_mutex.m_mutex[1]) = v18;
  v19 = *(_DWORD *)&options->player_profiles.elems[0].profile_name[16];
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetUInt(v17, (int)&pargs, *(_DWORD *)(v19 + 29768));
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)options->player_profiles.elems[0].profile_name + 264) + 4),
    "root.set_game_type",
    0,
    &pargs,
    1u);
  v20 = *(_DWORD *)&options->player_profiles.elems[0].profile_name[16];
  v55.pObjectInterface = 0;
  v55.Type = VT_Undefined;
  survarium::flash_value::SetUInt(v21, (int)&v55, *(unsigned __int8 *)(v20 + 29783));
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)options->player_profiles.elems[0].profile_name + 264) + 4),
    "root.set_artifacts_required",
    0,
    &v55,
    1u);
  v22 = *(_DWORD *)options->player_profiles.elems[0].profile_name;
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v22 + 264) + 4), &pvalue);
  for ( i = 0; i < (unsigned int)a3[1240].body[12]; LOBYTE(v23) = i )
  {
    v59.pObjectInterface = 0;
    v59.Type = VT_Undefined;
    v24 = &a3[62 * i];
    v49 = *(survarium::flash_value **)(*(_DWORD *)options->player_profiles.elems[0].profile_name + 264);
    v60 = i;
    survarium::flash_movie::CreateObject(v23, v49, &v59);
    *(_DWORD *)v61.body = 0;
    *(_DWORD *)&v61.body[4] = 0;
    survarium::flash_movie::CreateObject(
      v25,
      *(survarium::flash_value **)(*(_DWORD *)options->player_profiles.elems[0].profile_name + 264),
      (Scaleform::GFx::Value *)&v61);
    survarium::flash_value::SetInt(v26, (int)&v61, i);
    survarium::flash_value::SetMember(v27, &v59, "id", &v61);
    v50 = (survarium::flash_value *)((*(_DWORD *)&v24[18].body[8] != LODWORD(options->player_profiles.elems[0].modifiers.m_modifiers.elems[1].m_mutex.m_mutex[1]))
                                   + 1);
    survarium::flash_value::SetInt(v50, (int)&v61, (int)v50);
    survarium::flash_value::SetMember(v28, &v59, "team", &v61);
    survarium::flash_value::SetString(&v61, &v24->body[8]);
    survarium::flash_value::SetMember(v29, &v59, "name", &v61);
    survarium::flash_value::SetInt(v30, (int)&v61, 66);
    survarium::flash_value::SetMember(v31, &v59, "ping", &v61);
    survarium::flash_value::SetInt(v32, (int)&v61, 0);
    survarium::flash_value::SetMember(v33, &v59, "rank", &v61);
    survarium::flash_value::SetInt(v34, (int)&v61, 0);
    survarium::flash_value::SetMember(v35, &v59, "artifacts", &v61);
    v36 = &a3[1244].body[v60 + 6];
    survarium::flash_value::SetUInt(a3, (int)&v61, *v36 != 0);
    survarium::flash_value::SetMember(v37, &v59, "squad_state", &v61);
    survarium::flash_value::SetUInt(v38, (int)&v61, (unsigned __int8)*v36);
    survarium::flash_value::SetMember(v39, &v59, "squad_id", &v61);
    pvalue.pObjectInterface->SetElement(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, v60, &v59);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v61);
    Scaleform::GFx::Value::~Value(&v59);
    ++i;
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)options->player_profiles.elems[0].profile_name + 264) + 4),
    "root.list_set_players",
    0,
    &pvalue,
    1u);
  v52.pObjectInterface = 0;
  v52.Type = VT_Undefined;
  survarium::flash_value::SetBoolean(v40, (int)&v52, 1);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)options->player_profiles.elems[0].profile_name + 264) + 4),
    "root.show_game_info",
    0,
    &v52,
    1u);
  LODWORD(options->player_profiles.elems[0].modifiers.m_modifiers.elems[1].m_mutex.m_mutex[0]) = -1;
  HIDWORD(options->player_profiles.elems[0].modifiers.m_modifiers.elems[1].m_mutex.m_mutex[0]) = -1;
  v42 = *(unsigned __int8 *)(*(_DWORD *)&options->player_profiles.elems[0].profile_name[16] + 29783) + 22;
  v65 = 22;
  if ( !__OFSUB__(v42, 22) && v42 != 22 )
  {
    do
    {
      survarium::game_world_ui::create_hud_icon(v41, (int)options, v65, 0.0, s_victory_item_icon_size);
      survarium::game_world_ui::set_hud_icon_type(v43, (int)options, v65, 0xDu);
      survarium::game_world_ui::set_hud_icon_color(v44, (int)options, v65++, 0xFFu, 0xFFu, 0xFFu);
      v41 = (survarium::game_world_ui *)v65;
    }
    while ( v65 < *(unsigned __int8 *)(*(_DWORD *)&options->player_profiles.elems[0].profile_name[16] + 29783) + 22 );
  }
  for ( j = 32; j < 0x26u; ++j )
  {
    survarium::game_world_ui::create_hud_icon(v41, (int)options, j, COERCE_FLOAT(1), s_grenade_icon_size);
    survarium::game_world_ui::set_hud_icon_type(v45, (int)options, j, 0);
    survarium::game_world_ui::set_hud_icon_color(v46, (int)options, j, 0xFFu, 0xFFu, 0xFFu);
  }
  v67 = 38;
  if ( !__OFSUB__(BYTE5(options->player_profiles.elems[0].modifiers.m_modifiers.elems[1].m_mutex.m_mutex[1]) + 38, 38)
    && BYTE5(options->player_profiles.elems[0].modifiers.m_modifiers.elems[1].m_mutex.m_mutex[1]) != 0 )
  {
    do
    {
      survarium::game_world_ui::create_hud_icon(v41, (int)options, v67, COERCE_FLOAT(1), s_trap_icon_size);
      survarium::game_world_ui::set_hud_icon_type(v47, (int)options, v67, 1u);
      survarium::game_world_ui::set_hud_icon_color(v48, (int)options, v67++, 0xFFu, 0xFFu, 0xFFu);
      v41 = (survarium::game_world_ui *)v67;
    }
    while ( v67 < BYTE5(options->player_profiles.elems[0].modifiers.m_modifiers.elems[1].m_mutex.m_mutex[1]) + 38 );
  }
  *(_DWORD *)v54.body = 0;
  *(_DWORD *)&v54.body[4] = 0;
  survarium::flash_value::SetString(&v54, uri);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)options->player_profiles.elems[0].profile_name + 264) + 4),
    "root.set_match_time",
    0,
    (const Scaleform::GFx::Value *)&v54,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v54);
  Scaleform::GFx::Value::~Value(&v52);
  Scaleform::GFx::Value::~Value(&pvalue);
  Scaleform::GFx::Value::~Value(&v55);
  Scaleform::GFx::Value::~Value(&pargs);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v57);
}
