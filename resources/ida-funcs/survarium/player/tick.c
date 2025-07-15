void __thiscall survarium::player::tick(
        survarium::player *this,
        float current_time_in_ms,
        vostok::animation::subscribed_channel **current_time_in_msa)
{
  vostok::math::float3 *v3; // edi
  vostok::animation::subscribed_channel ***v4; // eax
  unsigned int v5; // esi
  survarium::client_player_state *v6; // ecx
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  const btTransform *v10; // eax
  btMatrix3x3 *v11; // ecx
  survarium::player **v12; // eax
  survarium::player *v13; // ecx
  int v14; // eax
  int v15; // ecx
  bool v16; // zf
  survarium::player *v17; // eax
  survarium::player_input *v18; // eax
  survarium::player *actions_mask; // ecx
  unsigned int m_seed; // eax
  bool v21; // al
  survarium::damage_model **v22; // eax
  unsigned __int8 total_health; // al
  vostok::animation::subscribed_channel **v24; // esi
  const void *v25; // esi
  const vostok::math::float4x4 *v26; // eax
  vostok::animation::mixing::n_ary_tree *v27; // ecx
  vostok::animation::mixing::n_ary_tree *v28; // ecx
  vostok::animation::animation_player *v29; // ecx
  bool v30; // al
  survarium::player *v31; // ecx
  vostok::animation::animation_player *v32; // ecx
  vostok::animation::animation_player *v33; // ecx
  float v34; // xmm1_4
  survarium::player *v35; // ecx
  survarium::player *v36; // ecx
  survarium::player *v37; // ecx
  survarium::damage_model **v38; // eax
  survarium::player *v39; // ecx
  survarium::game_world_ui *v40; // ecx
  int v41; // ecx
  int v42; // eax
  int v43; // esi
  survarium::base_game_scene *v44; // ecx
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  int v48; // esi
  int v49; // ecx
  long double v50; // st7
  unsigned int *p_time_delta_ms; // eax
  long double v52; // st7
  _DWORD *v53; // esi
  int v54; // ecx
  float *v55; // eax
  unsigned int v56; // xmm0_4
  int v57; // ecx
  int (__thiscall *v58)(int, vostok::math::float2 *); // eax
  int v59; // eax
  survarium::flash_text *v60; // ecx
  int v61; // ecx
  float _X; // [esp+8AEh] [ebp-D4h]
  survarium::player_input *v63; // [esp+8B2h] [ebp-D0h]
  char v64; // [esp+8CDh] [ebp-B5h]
  bool v65; // [esp+8CDh] [ebp-B5h]
  unsigned int time_delta_ms; // [esp+8CEh] [ebp-B4h] BYREF
  float v67; // [esp+8D2h] [ebp-B0h]
  float v68; // [esp+8D6h] [ebp-ACh]
  bool v69; // [esp+8DDh] [ebp-A5h]
  vostok::math::float3 *v70; // [esp+8DEh] [ebp-A4h]
  vostok::math::float2 result; // [esp+8E2h] [ebp-A0h] BYREF
  int v72; // [esp+8EAh] [ebp-98h]
  unsigned __int64 v73; // [esp+906h] [ebp-7Ch] BYREF
  __int64 v74; // [esp+90Eh] [ebp-74h]
  survarium::player *v75; // [esp+916h] [ebp-6Ch]
  survarium::player_input v76; // [esp+92Eh] [ebp-54h] BYREF
  vostok::math::float4x4 v77; // [esp+942h] [ebp-40h] BYREF

  if ( byte_10F37[LODWORD(current_time_in_ms)] )
  {
    byte_10F37[LODWORD(current_time_in_ms)] = 0;
    *(int *)((char *)&dword_10F0C + LODWORD(current_time_in_ms)) = (int)current_time_in_msa;
  }
  if ( *(_BYTE *)(LODWORD(current_time_in_ms) + 53) )
  {
    v3 = *(vostok::math::float3 **)((char *)&dword_10F0C + LODWORD(current_time_in_ms));
    v4 = (vostok::animation::subscribed_channel ***)((char *)&dword_10F0C + LODWORD(current_time_in_ms));
  }
  else if ( *(int *)((char *)&dword_10E28 + LODWORD(current_time_in_ms)) == *(int *)((char *)&dword_10E2C
                                                                                   + LODWORD(current_time_in_ms)) )
  {
    v3 = *(vostok::math::float3 **)((char *)&dword_10F0C + LODWORD(current_time_in_ms));
    v4 = (vostok::animation::subscribed_channel ***)((char *)&dword_10F0C + LODWORD(current_time_in_ms));
  }
  else
  {
    this = (survarium::player *)(96
                               * ((*(int *)((char *)&dword_10E28 + LODWORD(current_time_in_ms))
                                 + *(int *)((char *)&dword_10E24 + LODWORD(current_time_in_ms))
                                 - 1)
                                % *(unsigned int *)((char *)&dword_10E24 + LODWORD(current_time_in_ms)))
                               + *(int *)((char *)&dword_10E1C + LODWORD(current_time_in_ms))
                               + 92);
    v4 = (vostok::animation::subscribed_channel ***)((char *)&dword_10F0C + LODWORD(current_time_in_ms));
    if ( (survarium::player_vtbl *)*(int *)((char *)&dword_10F0C + LODWORD(current_time_in_ms)) >= this->survarium::base_player::survarium::inventory_holder::__vftable )
      this = (survarium::player *)((char *)&dword_10F0C + LODWORD(current_time_in_ms));
    v3 = (vostok::math::float3 *)this->survarium::base_player::survarium::inventory_holder::__vftable;
  }
  v70 = v3;
  *v4 = current_time_in_msa;
  if ( current_time_in_msa <= (vostok::animation::subscribed_channel **)v3 )
    *(float *)&v5 = 0.0;
  else
    v5 = (char *)current_time_in_msa - (char *)v3;
  time_delta_ms = v5;
  survarium::client_player_state::update_transform((survarium::client_player_state *)this);
  if ( byte_10F36[LODWORD(current_time_in_ms)] )
  {
    survarium::client_player_state::update_transform(v6);
    if ( byte_10F36[LODWORD(current_time_in_ms)] )
    {
      if ( *(_BYTE *)(**(_DWORD **)((char *)&dword_10DC8 + LODWORD(current_time_in_ms)) + 261) )
      {
        v7 = *(float *)(LODWORD(current_time_in_ms) + 34724)
           - *(float *)((char *)&dword_10D78 + LODWORD(current_time_in_ms));
        v8 = *(float *)(LODWORD(current_time_in_ms) + 34720)
           - *(float *)((char *)&dword_10D74 + LODWORD(current_time_in_ms));
        v9 = *(float *)(LODWORD(current_time_in_ms) + 34728)
           - *(float *)((char *)&dword_10D7C + LODWORD(current_time_in_ms));
        if ( sqrtf((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9)) > 1.0 )
        {
          qmemcpy((void *)(LODWORD(current_time_in_ms) + 34672), &byte_10D44[LODWORD(current_time_in_ms)], 0x40u);
          v67 = *(float *)(LODWORD(current_time_in_ms) + 34804);
          v10 = vostok::physics::from_vostok((const vostok::math::float4x4 *)(LODWORD(current_time_in_ms) + 34672));
          vostok::physics::bullet_character_controller::set_transform(
            *(vostok::physics::bullet_character_controller **)LODWORD(v67),
            v10,
            v11);
          v3 = v70;
          v5 = time_delta_ms;
        }
      }
    }
  }
  v12 = *(survarium::player ***)((char *)&dword_10DC8 + LODWORD(current_time_in_ms));
  v13 = *v12;
  if ( *(&(*v12)->m_game_world_objects.gap0 + 1) || *(_BYTE *)(**(_DWORD **)(LODWORD(current_time_in_ms) + 34804) + 261) )
  {
    v67 = *(float *)&v5;
    _X = (double)v5 * 0.001;
    survarium::player::smooth(v13, v3, current_time_in_ms, _X);
  }
  v15 = *(int *)((char *)&dword_10F04 + LODWORD(current_time_in_ms));
  v14 = *(_DWORD *)(*(_DWORD *)(v15 + 952) + 8);
  LOBYTE(v15) = *(_BYTE *)(LODWORD(current_time_in_ms) + 52);
  if ( !v14
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    || (v64 = 1, *(_BYTE *)(v14 + 52) != (_BYTE)v15) )
  {
    v64 = 0;
  }
  v16 = *(_BYTE *)(LODWORD(current_time_in_ms) + 281) == 0;
  v17 = *(survarium::player **)((char *)&dword_10EE0 + LODWORD(current_time_in_ms));
  LODWORD(v73) = *(int *)((char *)&dword_10ED0 + LODWORD(current_time_in_ms));
  HIDWORD(v73) = *(int *)((char *)&dword_10ED4 + LODWORD(current_time_in_ms));
  LODWORD(v74) = *(int *)((char *)&dword_10ED8 + LODWORD(current_time_in_ms));
  HIDWORD(v74) = *(int *)((char *)&dword_10EDC + LODWORD(current_time_in_ms));
  v75 = v17;
  if ( v16 )
  {
    survarium::player_input::player_input(&v76);
  }
  else if ( *(_BYTE *)(LODWORD(current_time_in_ms) + 53) )
  {
    v18 = survarium::player::local_input((survarium::player *)v15, v63);
  }
  else
  {
    v18 = survarium::player::remote_input((survarium::player *)LODWORD(current_time_in_ms), v63);
    v3 = v70;
  }
  v16 = *(_BYTE *)(LODWORD(current_time_in_ms) + 53) == 0;
  *(vostok::math::float2 *)(LODWORD(current_time_in_ms) + 69328) = v18->angular_velocity;
  *(vostok::math::float2 *)(LODWORD(current_time_in_ms) + 69336) = v18->angular_acceleration;
  actions_mask = (survarium::player *)v18->actions_mask;
  *(int *)((char *)&dword_10EE0 + LODWORD(current_time_in_ms)) = (int)actions_mask;
  if ( !v16 && (s_is_local_player_random_input_enabled && v64 || s_is_test_players_random_input_enabled && !v64) )
  {
    if ( (_S15_0 & 1) != 0 )
    {
      m_seed = random.m_seed;
    }
    else
    {
      _S15_0 |= 1u;
      m_seed = 0;
    }
    random.m_seed = 134775813 * m_seed + 1;
    *(int *)((char *)&dword_10EE0 + LODWORD(current_time_in_ms)) = (0xFFFFFFFF * (unsigned __int64)random.m_seed) >> 32;
  }
  if ( *(_BYTE *)(LODWORD(current_time_in_ms) + 281) )
  {
    v21 = survarium::player_stamina::can_be_spent((survarium::player_stamina *)((char *)&unk_10E30
                                                                              + LODWORD(current_time_in_ms)))
       && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(current_time_in_ms) + 64) + 64))(*(_DWORD *)(LODWORD(current_time_in_ms) + 64));
    survarium::player_stamina::tick(
      (survarium::player_stamina *)((char *)&unk_10E30 + LODWORD(current_time_in_ms)),
      (unsigned int)current_time_in_msa,
      v21);
  }
  if ( v64 )
  {
    survarium::player::process_quick_slots_for_current_player(actions_mask);
    if ( *(int *)((char *)&dword_10F7C + LODWORD(current_time_in_ms)) )
    {
      v22 = (survarium::damage_model **)(*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(current_time_in_ms) + 12))(COERCE_FLOAT(LODWORD(current_time_in_ms)));
      total_health = survarium::damage_model::get_total_health(*v22);
      survarium::game_world_ui::set_health(
        *(survarium::game_world_ui **)((char *)&dword_10F7C + LODWORD(current_time_in_ms)),
        total_health);
    }
    if ( (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(current_time_in_ms) + 64) + 84))(*(_DWORD *)(LODWORD(current_time_in_ms) + 64)) )
      survarium::weapon::update_dispersion_visual_representation((survarium::weapon *)actions_mask);
  }
  v24 = (vostok::animation::subscribed_channel **)v3;
  v67 = *(float *)&v3;
  do
  {
    if ( v24 != (vostok::animation::subscribed_channel **)v70
      || (actions_mask = v75, *(survarium::player **)((char *)&dword_10EE0 + LODWORD(current_time_in_ms)) != v75)
      || *(_BYTE *)(LODWORD(current_time_in_ms) + 280) )
    {
      *(_BYTE *)(LODWORD(current_time_in_ms) + 280) = 0;
      survarium::player::select_animations(actions_mask, (const unsigned int)v24);
    }
    if ( byte_10F81[LODWORD(current_time_in_ms)] )
    {
      byte_10F81[LODWORD(current_time_in_ms)] = 0;
      survarium::player::compute_bones(actions_mask, (const unsigned int)v24);
    }
    v25 = *(const void **)(LODWORD(current_time_in_ms) + 64);
    if ( v25
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      && v25 != *(const void **)((char *)&dword_10F08 + LODWORD(current_time_in_ms)) )
    {
      v26 = vostok::math::float4x4::identity(&v77);
      vostok::animation::mixing::n_ary_tree::set_object_transform(v27, v25, v26);
    }
    vostok::animation::mixing::n_ary_tree::set_object_transform(
      (vostok::animation::mixing::n_ary_tree *)actions_mask,
      (const void *)LODWORD(current_time_in_ms),
      (const vostok::math::float4x4 *)(LODWORD(current_time_in_ms) + 34672));
    vostok::animation::mixing::n_ary_tree::set_object_transform(
      v28,
      (const void *)LODWORD(current_time_in_ms),
      (const vostok::math::float4x4 *)&byte_10D44[LODWORD(current_time_in_ms)]);
    v30 = vostok::animation::animation_player::tick_to_nearest_user_handled_callback(
            v29,
            LODWORD(current_time_in_ms) + 552,
            current_time_in_msa);
    v24 = *(vostok::animation::subscribed_channel ***)(LODWORD(current_time_in_ms) + 34640);
    v31 = (survarium::player *)((char *)v24 - LODWORD(v67));
    v69 = v30;
    v67 = (double)((unsigned int)v24 - LODWORD(v67)) * 0.001;
    survarium::player::apply_input_before_new_transform(
      v31,
      (survarium::player *)LODWORD(current_time_in_ms),
      (survarium::client_player_state *)(LODWORD(current_time_in_ms) + 552),
      (float *)&v73,
      v67);
    vostok::animation::animation_player::skip_time_if_needed(
      v32,
      (vostok::animation::animation_player *)(LODWORD(current_time_in_ms) + 34812),
      (unsigned int)v24);
    ++*(_WORD *)(LODWORD(current_time_in_ms) + 68928);
    vostok::animation::mixing::n_ary_tree::tick(
      (vostok::animation::mixing::n_ary_tree *)(LODWORD(current_time_in_ms) + 68860),
      LODWORD(current_time_in_ms) + 68860,
      v24,
      (bool *)(LODWORD(current_time_in_ms) + 68912));
    if ( !--*(_WORD *)(LODWORD(current_time_in_ms) + 68928) && !*(_BYTE *)(LODWORD(current_time_in_ms) + 68930) )
      vostok::animation::animation_player::compact_callbacks(
        v33,
        (vostok::animation::animation_player *)(LODWORD(current_time_in_ms) + 34812));
    survarium::player::apply_input_before_new_transform(
      (survarium::player *)v33,
      (survarium::player *)LODWORD(current_time_in_ms),
      (survarium::client_player_state *)(LODWORD(current_time_in_ms) + 34812),
      (float *)&v73,
      v67);
    actions_mask = *(survarium::player **)((char *)&dword_10EE0 + LODWORD(current_time_in_ms));
    v34 = (float)(v67 * *(float *)((char *)&dword_10EDC + LODWORD(current_time_in_ms))) + *((float *)&v73 + 1);
    result.x = (float)(*(float *)((char *)&dword_10ED8 + LODWORD(current_time_in_ms)) * v67) + *(float *)&v73;
    v73 = *(_QWORD *)(LODWORD(current_time_in_ms) + 69328);
    result.y = v34;
    v74 = *(_QWORD *)(LODWORD(current_time_in_ms) + 69336);
    v75 = actions_mask;
    v73 = __PAIR64__(LODWORD(v34), LODWORD(result.x));
    v67 = *(float *)&v24;
  }
  while ( v24 != current_time_in_msa );
  if ( v69 )
    survarium::player::select_animations(actions_mask, (const unsigned int)v24);
  if ( *(_BYTE *)(LODWORD(current_time_in_ms) + 53) && *(_BYTE *)(LODWORD(current_time_in_ms) + 281)
    || (actions_mask = *(survarium::player **)((char *)&dword_10E28 + LODWORD(current_time_in_ms)),
        actions_mask == *(survarium::player **)((char *)&dword_10E2C + LODWORD(current_time_in_ms))) )
  {
    survarium::player::serialize_current_state(actions_mask, LODWORD(current_time_in_ms));
  }
  if ( *(_BYTE *)(LODWORD(current_time_in_ms) + 53) && *(_BYTE *)(LODWORD(current_time_in_ms) + 281) )
    (*(void (__stdcall **)(char *, vostok::animation::subscribed_channel **, char *, _DWORD))(**(_DWORD **)(*(_DWORD *)(*(int *)((char *)&dword_10F00 + LODWORD(current_time_in_ms)) + 168) + 952)
                                                                                            + 28))(
      (char *)&dword_10ED0 + LODWORD(current_time_in_ms),
      current_time_in_msa,
      &byte_10D44[LODWORD(current_time_in_ms)],
      *(float *)(LODWORD(current_time_in_ms) + 69068));
  survarium::player::set_physics_controller_walk_vector(
    actions_mask,
    (survarium::client_player_state *)(LODWORD(current_time_in_ms) + 34812));
  if ( byte_10F36[LODWORD(current_time_in_ms)] )
    survarium::player::set_physics_controller_walk_vector(
      v35,
      (survarium::client_player_state *)(LODWORD(current_time_in_ms) + 552));
  survarium::player::notify_actions_subscribers(v35);
  survarium::player::render(v36, (const unsigned int)current_time_in_msa, (const unsigned int)v63);
  if ( *(_BYTE *)(LODWORD(current_time_in_ms) + 281) )
  {
    v38 = (survarium::damage_model **)(*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(current_time_in_ms) + 12))(COERCE_FLOAT(LODWORD(current_time_in_ms)));
    survarium::damage_model::tick(*v38, time_delta_ms, (const unsigned int)current_time_in_msa);
  }
  if ( *(int *)((char *)&dword_10F7C + LODWORD(current_time_in_ms)) )
  {
    if ( v64 )
    {
      if ( *(_BYTE *)(LODWORD(current_time_in_ms) + 281) )
      {
        survarium::player::update_speed_info(v37);
        survarium::player::detect_usable_objects(v39, (const unsigned int)current_time_in_msa);
        if ( *(_DWORD *)(LODWORD(current_time_in_ms) + 20) )
        {
          if ( *(_DWORD *)(LODWORD(current_time_in_ms) + 32) != -1 )
            survarium::game_world_ui::set_using_progress_message(
              v40,
              *(survarium::game_world_ui **)((char *)&dword_10F7C + LODWORD(current_time_in_ms)),
              *(_DWORD *)(LODWORD(current_time_in_ms) + 32));
        }
      }
    }
  }
  v65 = !byte_10F80[LODWORD(current_time_in_ms)]
     && (!v64 || *(_DWORD *)(*(int *)((char *)&dword_10EF4 + LODWORD(current_time_in_ms)) + 408));
  v41 = *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_10F04 + LODWORD(current_time_in_ms)) + 952) + 8);
  if ( v41 )
    v42 = (*(int (__thiscall **)(int))(*(_DWORD *)v41 + 72))(v41);
  else
    v42 = 2;
  v43 = *(_DWORD *)(*(int *)((char *)&dword_10F04 + LODWORD(current_time_in_ms)) + 312);
  if ( *(_DWORD *)(v43 + 132) != 0
    && v42 == *(int *)((char *)&dword_10F2C + LODWORD(current_time_in_ms))
    && v65
    && (v44 = *(survarium::base_game_scene **)((char *)&dword_10F00 + LODWORD(current_time_in_ms)),
        v67 = SNaN,
        v68 = SNaN,
        result.x = *(float *)(LODWORD(current_time_in_ms) + 120),
        result.y = *(float *)(LODWORD(current_time_in_ms) + 124) + 0.2,
        v72 = *(_DWORD *)(LODWORD(current_time_in_ms) + 128),
        survarium::base_game_scene::point_to_screen(v44, (const vostok::math::float3 *)v44, &result)) )
  {
    v45 = *(float *)(LODWORD(current_time_in_ms) + 120) - *(float *)(v43 + 52);
    v46 = *(float *)(LODWORD(current_time_in_ms) + 128) - *(float *)(v43 + 60);
    v47 = *(float *)(LODWORD(current_time_in_ms) + 124) - *(float *)(v43 + 56);
    v48 = *(_DWORD *)(v43 + 132);
    time_delta_ms = *(unsigned int *)(v48 + 72);
    v50 = sqrtf((float)((float)(v45 * v45) + (float)(v46 * v46)) + (float)(v47 * v47));
    p_time_delta_ms = (unsigned int *)&s_player_name_min_font_size;
    v52 = s_player_name_max_font_size
        - (v50 - *(float *)&time_delta_ms)
        / (*(float *)(v48 + 76) - *(float *)&time_delta_ms)
        * 1000.0
        * s_player_name_decrease_koef;
    *(float *)&time_delta_ms = v52;
    if ( s_player_name_min_font_size <= v52 )
      p_time_delta_ms = &time_delta_ms;
    v16 = *((_BYTE *)&dword_10EEC + LODWORD(current_time_in_ms)) == 1;
    v53 = (int *)((char *)&dword_10EE4 + LODWORD(current_time_in_ms));
    time_delta_ms = *p_time_delta_ms;
    if ( !v16 )
    {
      v54 = *v53;
      *((_BYTE *)v53 + 8) = 1;
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v54 + 152))(v54, 1);
      v49 = v53[1];
      *(_BYTE *)(v49 + 4) = 1;
    }
    survarium::flash_text::set_font_size(
      (survarium::flash_text *)v49,
      (Scaleform::GFx::DrawTextManager ***)((char *)&dword_10EE4 + LODWORD(current_time_in_ms)),
      (Scaleform::GFx::DrawTextManager::TextParams *)LODWORD(current_time_in_ms),
      LODWORD(current_time_in_ms) + 34812,
      *(float *)&v53,
      *(float *)&time_delta_ms);
    v55 = (float *)(*(int (__thiscall **)(_DWORD, vostok::math::float2 *))(*(_DWORD *)*v53 + 76))(*v53, &result);
    *(float *)&v56 = v55[2] - *v55;
    v57 = *v53;
    v58 = *(int (__thiscall **)(int, vostok::math::float2 *))(*(_DWORD *)*v53 + 76);
    time_delta_ms = v56;
    v59 = v58(v57, &result);
    survarium::flash_text::set_position(
      v60,
      v53,
      v67 - (float)(*(float *)&time_delta_ms * 0.5),
      v68 - (float)(*(float *)(v59 + 12) - *(float *)(v59 + 4)));
  }
  else if ( *((_BYTE *)&dword_10EEC + LODWORD(current_time_in_ms)) )
  {
    v61 = *(int *)((char *)&dword_10EE4 + LODWORD(current_time_in_ms));
    *((_BYTE *)&dword_10EEC + LODWORD(current_time_in_ms)) = 0;
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v61 + 152))(v61, 0);
    *(_BYTE *)(*(int *)((char *)&dword_10EE8 + LODWORD(current_time_in_ms)) + 4) = 1;
  }
}
