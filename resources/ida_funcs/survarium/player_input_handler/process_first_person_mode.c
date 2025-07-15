void __userpurge survarium::player_input_handler::process_first_person_mode(
        survarium::player_input_handler *this@<ecx>,
        int a2@<edi>,
        const bool use_mouse_move)
{
  const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *v3; // ebx
  const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *v4; // esi
  int v5; // esi
  float *v6; // ebx
  float v7; // xmm0_4
  survarium::player_input_handler *v8; // ecx
  const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *v9; // ebx
  const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *v10; // esi
  const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *v11; // eax
  survarium::player_input_handler::action_state_enum second; // eax
  const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *v13; // eax
  survarium::player_input_handler::action_state_enum v14; // eax
  const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *v15; // eax
  survarium::player_input_handler::action_state_enum v16; // eax
  const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *v17; // eax
  survarium::player_input_handler::action_state_enum v18; // eax
  const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *v19; // eax
  survarium::player_input_handler::action_state_enum v20; // eax
  const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *v21; // eax
  survarium::player_input_handler::action_state_enum v22; // eax
  float horizontal_sensitivity; // [esp+Ch] [ebp-14h]
  _BYTE v24[8]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v25[8]; // [esp+18h] [ebp-8h] BYREF
  float vertical_sensitivity; // [esp+24h] [ebp+4h]

  if ( *(_DWORD *)(a2 + 88) != *(_DWORD *)(a2 + 92)
    || !survarium::player_input::is_empty((survarium::player_input *)(a2 + 356)) )
  {
    v3 = *(const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> **)(a2 + 88);
    v4 = *(const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> **)(a2 + 92);
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v3,
           v4,
           (survarium::first_predicate<enum survarium::game_action_id>)10) != v4 )
      *(_DWORD *)(a2 + 372) |= 1u;
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v3,
           v4,
           (survarium::first_predicate<enum survarium::game_action_id>)11) != v4 )
      *(_DWORD *)(a2 + 372) |= 2u;
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v3,
           v4,
           (survarium::first_predicate<enum survarium::game_action_id>)13) != v4 )
      *(_DWORD *)(a2 + 372) |= 8u;
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v3,
           v4,
           (survarium::first_predicate<enum survarium::game_action_id>)12) != v4 )
      *(_DWORD *)(a2 + 372) |= 4u;
    if ( use_mouse_move )
    {
      v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 352) + 168) + 124);
      horizontal_sensitivity = (float)(*(float *)(a2 + 84) * survarium::g_mouse_sensitivity) * 0.1;
      v6 = (float *)((*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v5 + 24))(v5, v24) + 4);
      v7 = (float)((float)(*v6 / *(float *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v5 + 24))(v5, v25))
                 * horizontal_sensitivity)
         * 0.95492965;
      vertical_sensitivity = v7;
      if ( survarium::g_mouse_invert )
        vertical_sensitivity = -v7;
      v3 = *(const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> **)(a2 + 88);
      v4 = *(const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> **)(a2 + 92);
      if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
             v3,
             v4,
             (survarium::first_predicate<enum survarium::game_action_id>)2) != v4 )
        *(float *)(a2 + 380) = (float)(vertical_sensitivity * 0.017453292) + *(float *)(a2 + 380);
      if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
             v3,
             v4,
             (survarium::first_predicate<enum survarium::game_action_id>)3) != v4 )
        *(float *)(a2 + 380) = *(float *)(a2 + 380) - (float)(vertical_sensitivity * 0.017453292);
      if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
             v3,
             v4,
             (survarium::first_predicate<enum survarium::game_action_id>)1) != v4 )
        *(float *)(a2 + 384) = *(float *)(a2 + 384) - (float)(horizontal_sensitivity * 0.017453292);
      if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
             v3,
             v4,
             0) != v4 )
        *(float *)(a2 + 384) = (float)(horizontal_sensitivity * 0.017453292) + *(float *)(a2 + 384);
    }
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v3,
           v4,
           (survarium::first_predicate<enum survarium::game_action_id>)4) != v4 )
      *(_DWORD *)(a2 + 372) |= 0x10u;
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v3,
           v4,
           (survarium::first_predicate<enum survarium::game_action_id>)30) != v4 )
    {
      if ( survarium::player_input_handler::alt_is_held(v8, a2) )
        vostok::console_commands::execute("remove_player", execution_filter_all);
      else
        *(_DWORD *)(a2 + 372) |= 0x20u;
    }
    v9 = *(const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> **)(a2 + 88);
    v10 = *(const stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> **)(a2 + 92);
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v9,
           v10,
           (survarium::first_predicate<enum survarium::game_action_id>)31) != v10 )
      *(_DWORD *)(a2 + 372) |= 0x40u;
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v9,
           v10,
           (survarium::first_predicate<enum survarium::game_action_id>)32) != v10 )
      *(_DWORD *)(a2 + 372) |= 0x80u;
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v9,
           v10,
           (survarium::first_predicate<enum survarium::game_action_id>)5) != v10 )
      *(_DWORD *)(a2 + 372) |= 0x100u;
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v9,
           v10,
           (survarium::first_predicate<enum survarium::game_action_id>)6) != v10 )
      *(_DWORD *)(a2 + 372) |= 0x200u;
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v9,
           v10,
           (survarium::first_predicate<enum survarium::game_action_id>)8) != v10 )
      *(_DWORD *)(a2 + 372) |= 0x400u;
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v9,
           v10,
           (survarium::first_predicate<enum survarium::game_action_id>)9) != v10 )
      *(_DWORD *)(a2 + 372) |= 0x800u;
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v9,
           v10,
           (survarium::first_predicate<enum survarium::game_action_id>)25) != v10 )
      *(_DWORD *)(a2 + 372) |= 0x1000u;
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v9,
           v10,
           (survarium::first_predicate<enum survarium::game_action_id>)26) != v10 )
      *(_DWORD *)(a2 + 372) |= 0x2000u;
    v11 = stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
            v9,
            v10,
            (survarium::first_predicate<enum survarium::game_action_id>)48);
    if ( v11 != v10 )
    {
      second = v11->second;
      if ( second )
      {
        if ( second == up )
          *(_DWORD *)(a2 + 372) |= 0x8000u;
      }
      else
      {
        *(_DWORD *)(a2 + 372) |= 0x4000u;
      }
    }
    v13 = stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
            v9,
            v10,
            (survarium::first_predicate<enum survarium::game_action_id>)49);
    if ( v13 != v10 )
    {
      v14 = v13->second;
      if ( v14 )
      {
        if ( v14 == up )
          *(_DWORD *)(a2 + 372) |= (unsigned int)&loc_20000;
      }
      else
      {
        *(_DWORD *)(a2 + 372) |= (unsigned int)&_sbh_sizeHeaderList;
      }
    }
    v15 = stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
            v9,
            v10,
            (survarium::first_predicate<enum survarium::game_action_id>)50);
    if ( v15 != v10 )
    {
      v16 = v15->second;
      if ( v16 )
      {
        if ( v16 == up )
          *(_DWORD *)(a2 + 372) |= (unsigned int)&loc_7FFFE + 2;
      }
      else
      {
        *(_DWORD *)(a2 + 372) |= (unsigned int)&loc_3FFFF + 1;
      }
    }
    v17 = stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
            v9,
            v10,
            (survarium::first_predicate<enum survarium::game_action_id>)51);
    if ( v17 != v10 )
    {
      v18 = v17->second;
      if ( v18 )
      {
        if ( v18 == up )
          *(_DWORD *)(a2 + 372) |= (unsigned int)&loc_1FFFFE + 2;
      }
      else
      {
        *(_DWORD *)(a2 + 372) |= (unsigned int)&loc_FFFFF + 1;
      }
    }
    v19 = stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
            v9,
            v10,
            (survarium::first_predicate<enum survarium::game_action_id>)52);
    if ( v19 != v10 )
    {
      v20 = v19->second;
      if ( v20 )
      {
        if ( v20 == up )
          *(_DWORD *)(a2 + 372) |= (unsigned int)&unk_800000;
      }
      else
      {
        *(_DWORD *)(a2 + 372) |= (unsigned int)Scaleform::GFx::AS2::CreateShadow;
      }
    }
    v21 = stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
            v9,
            v10,
            (survarium::first_predicate<enum survarium::game_action_id>)53);
    if ( v21 != v10 )
    {
      v22 = v21->second;
      if ( v22 )
      {
        if ( v22 == up )
          *(_DWORD *)(a2 + 372) |= (unsigned int)&vostok::memory::s_CRT_arena[22351416];
      }
      else
      {
        *(_DWORD *)(a2 + 372) |= (unsigned int)&vostok::memory::s_CRT_arena[5574200];
      }
    }
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v9,
           v10,
           (survarium::first_predicate<enum survarium::game_action_id>)54) != v10 )
      *(_DWORD *)(a2 + 372) |= (unsigned int)&vostok::memory::s_CRT_arena[55905848];
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v9,
           v10,
           (survarium::first_predicate<enum survarium::game_action_id>)33) != v10 )
      *(_DWORD *)(a2 + 372) |= 0x8000000u;
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v9,
           v10,
           (survarium::first_predicate<enum survarium::game_action_id>)44) != v10 )
      *(_DWORD *)(a2 + 372) |= 0x10000000u;
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v9,
           v10,
           (survarium::first_predicate<enum survarium::game_action_id>)45) != v10 )
      *(_DWORD *)(a2 + 372) |= 0x40000000u;
    if ( stlp_std::priv::__find_if<stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> const *,survarium::first_predicate<enum survarium::game_action_id>>(
           v9,
           v10,
           (survarium::first_predicate<enum survarium::game_action_id>)27) != v10 )
      *(_DWORD *)(a2 + 372) |= 0x20000000u;
  }
}
