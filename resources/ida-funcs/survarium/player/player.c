void __thiscall survarium::player::player(survarium::player *this, survarium::player_creation_params *params, int a3)
{
  vostok::math::float4x4 *v4; // ecx
  survarium::damage_sound_effect *v6; // ecx
  int v7; // xmm1_4
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // esi
  char *v13; // eax
  vostok::memory::doug_lea_allocator *v14; // ecx
  char *v15; // eax
  vostok::memory::doug_lea_allocator *v16; // esi
  char *v17; // eax
  vostok::memory::doug_lea_allocator *v18; // ecx
  char *v19; // eax
  vostok::memory::doug_lea_allocator *v20; // esi
  char *v21; // eax
  vostok::memory::doug_lea_allocator *v22; // ecx
  char *v23; // eax
  vostok::memory::doug_lea_allocator *v24; // esi
  char *v25; // eax
  vostok::memory::doug_lea_allocator *v26; // ecx
  char *v27; // eax
  bool v28; // zf
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v29; // ecx
  const char *v30; // [esp+4h] [ebp-70h]
  const char *v31; // [esp+4h] [ebp-70h]
  const char *v32; // [esp+4h] [ebp-70h]
  const char *v33; // [esp+4h] [ebp-70h]
  const char *v34; // [esp+4h] [ebp-70h]
  const char *v35; // [esp+8h] [ebp-6Ch]
  const char *v36; // [esp+8h] [ebp-6Ch]
  const char *v37; // [esp+8h] [ebp-6Ch]
  const char *v38; // [esp+8h] [ebp-6Ch]
  const char *v39; // [esp+8h] [ebp-6Ch]
  unsigned int v40; // [esp+Ch] [ebp-68h]
  unsigned int v41; // [esp+Ch] [ebp-68h]
  unsigned int v42; // [esp+Ch] [ebp-68h]
  unsigned int v43; // [esp+Ch] [ebp-68h]
  unsigned int v44; // [esp+Ch] [ebp-68h]
  unsigned __int8 v45; // [esp+13h] [ebp-61h]
  vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *__result; // [esp+14h] [ebp-60h] BYREF
  vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *v47; // [esp+18h] [ebp-5Ch]
  vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *v48; // [esp+1Ch] [ebp-58h]
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v49; // [esp+20h] [ebp-54h]
  vostok::math::float4x4 callback; // [esp+24h] [ebp-50h] BYREF
  __int64 v51; // [esp+64h] [ebp-10h] BYREF
  unsigned __int64 v52; // [esp+6Ch] [ebp-8h]

  survarium::base_player::base_player(this, params, (vostok::buffer_vector<float> *)a3);
  params->speed_parameters.m_multipliers.m_begin = (float *)&survarium::player::`vftable'{for `vostok::resources::unmanaged_resource'};
  LODWORD(params->dispersion_skill_influence.low_stamina_skill_influence) = &survarium::player::`vftable'{for `survarium::inventory_holder'};
  LODWORD(params->breath_vibration_params.base_time_to_hold_breath) = &survarium::player::`vftable'{for `survarium::collision_user'};
  LODWORD(params->breath_vibration_params.dispersion_to_time_to_hold_breath_ratio) = &survarium::player::`vftable'{for `survarium::hit_initiator'};
  LODWORD(params->initial_stamina.sprint_spending_speed) = &survarium::player::`vftable'{for `survarium::hit_receiver'};
  LODWORD(params->initial_stamina.regeneration_speed) = &survarium::player::`vftable'{for `survarium::spottable_object'};
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)params + (_DWORD)&loc_1119E + 2),
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a3 + 444));
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&params[115].initial_info.physics_world,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(a3 + 572));
  qmemcpy((char *)&loc_111A8 + (_DWORD)params, vostok::math::float4x4::identity(v4, &callback), 0x40u);
  survarium::stamina_sound_effect::stamina_sound_effect(
    0,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&params[115].dispersion_params.prone_aim_dispersion,
    (const vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *)(a3 + 464),
    (vostok::sound::sound_emitter *)params,
    *(vostok::sound::sound_emitter **)(a3 + 452));
  __result = (vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *)((char *)&loc_11240 + (_DWORD)params + 20);
  __result->m_object = 0;
  *(_DWORD *)((char *)&loc_11240 + (_DWORD)params + 24) = 0;
  *(_DWORD *)((char *)&loc_11240 + (_DWORD)params + 28) = 0;
  v48 = (vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *)((char *)&loc_11240 + (_DWORD)params + 32);
  v48->m_object = 0;
  *(_DWORD *)((char *)&loc_11240 + (_DWORD)params + 36) = 0;
  *(_DWORD *)((char *)&loc_11240 + (_DWORD)params + 40) = 0;
  v47 = (vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *)((char *)&loc_11240 + (_DWORD)params + 44);
  v47->m_object = 0;
  *(_DWORD *)((char *)&loc_11240 + (_DWORD)params + 48) = 0;
  *(_DWORD *)((char *)&loc_11240 + (_DWORD)params + 52) = 0;
  v49 = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)((char *)&loc_11240 + (_DWORD)params + 52);
  stlp_std::priv::__copy_trivial(
    (unsigned __int8 *)(a3 + 576),
    (unsigned __int8 *)(a3 + 596),
    (unsigned __int8 *)&loc_11240 + (_DWORD)params);
  stlp_std::copy<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> const *,vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *>(
    (const vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *)(a3 + 512),
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)__result,
    (const vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *)(a3 + 500));
  __result = (vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *)(a3 + 520);
  stlp_std::copy<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> const *,vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *>(
    (const vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *)(a3 + 520),
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v47,
    (const vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *)(a3 + 512));
  stlp_std::copy<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> const *,vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *>(
    (const vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *)(a3 + 532),
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v48,
    (const vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *)(a3 + 520));
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(a3 + 532),
    v49);
  survarium::damage_sound_effect::damage_sound_effect(
    v6,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)((char *)params + (_DWORD)&loc_11275 + 3),
    (const vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *)(a3 + 536),
    (survarium::player *)9,
    (vostok::sound::sound_emitter *)params,
    *(vostok::sound::sound_emitter **)(a3 + 452),
    *(_WORD *)(a3 + 604),
    *(_WORD *)(a3 + 606));
  v7 = *(_DWORD *)(a3 + 600);
  *(float **)((char *)&params->speed_parameters.m_multipliers.m_begin + (_DWORD)&loc_113F9 + 3) = *(float **)(a3 + 596);
  *(_DWORD *)((char *)&loc_11400 + (_DWORD)params) = v7;
  *(float **)((char *)&params->speed_parameters.m_multipliers.m_begin + (_DWORD)&loc_113F6 + 2) = (float *)((char *)&loc_11240 + (_DWORD)params);
  *(float **)((char *)&params->speed_parameters.m_multipliers.m_begin + (_DWORD)&loc_11403 + 1) = 0;
  *(float **)((char *)&params->speed_parameters.m_multipliers.m_begin + (_DWORD)&loc_11403 + 5) = 0;
  *(float **)((char *)&params->speed_parameters.m_multipliers.m_begin + (_DWORD)&loc_1140A + 2) = 0;
  *(int *)((char *)&dword_11410 + (_DWORD)params) = *(_DWORD *)(a3 + 452);
  *(int *)((char *)&dword_11414 + (_DWORD)params) = *(_DWORD *)(*(_DWORD *)(a3 + 452) + 160);
  vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&dword_11418 + (_DWORD)params),
    (const vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a3 + 460));
  *(int *)((char *)&dword_1141C + (_DWORD)params) = 0;
  v8 = survarium::g_allocator;
  *(float **)((char *)&params->speed_parameters.m_multipliers.m_begin + (_DWORD)&loc_11433 + 1) = (float *)23;
  *((_BYTE *)&params->speed_parameters.m_multipliers.m_begin + (_DWORD)&loc_11437 + 1) = 0;
  *((_BYTE *)&loc_11439 + (_DWORD)params) = 1;
  *((_BYTE *)&params->speed_parameters.m_multipliers.m_begin + (_DWORD)&loc_11439 + 1) = 0;
  *((_BYTE *)&loc_1143B + (_DWORD)params) = *(_BYTE *)(a3 + 136);
  v9 = type_info::raw_name(&vostok::render::material_parameter_host `RTTI Type Descriptor');
  v11 = vostok::memory::doug_lea_allocator::malloc_impl(v10, (int)v8, 0xCu, v9, v30, v35, v40);
  if ( v11 )
  {
    *(_DWORD *)v11 = 0;
    *((_DWORD *)v11 + 1) = "sphere_position";
    *((_DWORD *)v11 + 2) = 2;
  }
  else
  {
    v11 = 0;
  }
  v12 = survarium::g_allocator;
  *(int *)((char *)&dword_11420 + (_DWORD)params) = (int)v11;
  v13 = type_info::raw_name(&vostok::render::material_parameter_host `RTTI Type Descriptor');
  v15 = vostok::memory::doug_lea_allocator::malloc_impl(v14, (int)v12, 0xCu, v13, v31, v36, v41);
  if ( v15 )
  {
    *(_DWORD *)v15 = 0;
    *((_DWORD *)v15 + 1) = "sphere_radius";
    *((_DWORD *)v15 + 2) = 4;
  }
  else
  {
    v15 = 0;
  }
  v16 = survarium::g_allocator;
  *(_DWORD *)((char *)vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>
            + (_DWORD)params) = v15;
  v17 = type_info::raw_name(&vostok::render::material_parameter_host `RTTI Type Descriptor');
  v19 = vostok::memory::doug_lea_allocator::malloc_impl(v18, (int)v16, 0xCu, v17, v32, v37, v42);
  if ( v19 )
  {
    *(_DWORD *)v19 = 0;
    *((_DWORD *)v19 + 1) = "sphere_color";
    *((_DWORD *)v19 + 2) = 1;
  }
  else
  {
    v19 = 0;
  }
  v20 = survarium::g_allocator;
  *(float **)((char *)&params->speed_parameters.m_multipliers.m_begin + (_DWORD)&loc_11427 + 1) = (float *)v19;
  v21 = type_info::raw_name(&vostok::render::material_parameter_host `RTTI Type Descriptor');
  v23 = vostok::memory::doug_lea_allocator::malloc_impl(v22, (int)v20, 0xCu, v21, v33, v38, v43);
  if ( v23 )
  {
    *(_DWORD *)v23 = 0;
    *((_DWORD *)v23 + 1) = "sphere_blend_down";
    *((_DWORD *)v23 + 2) = 4;
  }
  else
  {
    v23 = 0;
  }
  v24 = survarium::g_allocator;
  *(_DWORD *)((char *)&loc_1142C + (_DWORD)params) = v23;
  v25 = type_info::raw_name(&vostok::render::material_parameter_host `RTTI Type Descriptor');
  v27 = vostok::memory::doug_lea_allocator::malloc_impl(v26, (int)v24, 0xCu, v25, v34, v39, v44);
  if ( v27 )
  {
    *(_DWORD *)v27 = 0;
    *((_DWORD *)v27 + 1) = "sphere_blend_up";
    *((_DWORD *)v27 + 2) = 4;
  }
  else
  {
    v27 = 0;
  }
  v28 = *((_BYTE *)&loc_1143B + (_DWORD)params) == 0;
  *(float **)((char *)&params->speed_parameters.m_multipliers.m_begin + (_DWORD)&loc_1142E + 2) = (float *)v27;
  byte_10427[(_DWORD)params] = BYTE1(params->initial_stamina.max_value);
  if ( v28 )
    vostok::strings::copy<64>(
      (char (*)[64])((char *)params + (_DWORD)&loc_1143B + 1),
      (char *)(*(_DWORD *)(a3 + 120) + 8));
  if ( BYTE1(params->initial_stamina.max_value) )
  {
    v45 = 0;
    while ( 1 )
    {
      vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__result,
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(LODWORD(params->breath_vibration_params.max_breath_holding_time) + 4 * quick_slots_2[v45] + 272));
      if ( __result )
      {
        if ( ((int (__thiscall *)(vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *))__result->m_object->m_parent_resources.m_first)(__result) )
          break;
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__result);
      if ( ++v45 >= 6u )
        goto LABEL_25;
    }
    *(survarium::profile_slot_enum *)((char *)&params->speed_parameters.m_multipliers.m_begin + (_DWORD)&loc_11433 + 1) = quick_slots_2[v45];
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__result);
  }
LABEL_25:
  LODWORD(callback.i.x) = survarium::player::on_landing;
  callback.i.y = 0.0;
  LODWORD(callback.i.z) = params;
  LODWORD(v51) = survarium::player::on_landing;
  HIDWORD(v51) = 0;
  v52 = __PAIR64__(LODWORD(callback.i.w), (unsigned int)params);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    callback.i.x = 0.0;
  }
  else
  {
    *(_QWORD *)&callback.lines[0].elements[2] = v51;
    *(_QWORD *)&callback.lines[1].x = v52;
    LODWORD(callback.i.x) = (char *)&`boost::function1<void,float>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::player,float>,boost::_bi::list2<boost::_bi::value<survarium::player *>,boost::arg<1>>>>'::`2'::stored_vtable
                          + 1;
  }
  vostok::physics::bt_character_controller::set_landing_callback(
    (vostok::physics::bt_character_controller *)&v51,
    *(_DWORD **)((char *)&dword_10E74 + (_DWORD)params),
    (boost::function<void __cdecl(float)> *)&callback,
    *(float *)(a3 + 596));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v29,
    (int *)&callback);
}
