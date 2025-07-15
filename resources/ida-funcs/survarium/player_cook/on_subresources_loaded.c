void __thiscall survarium::player_cook::on_subresources_loaded(
        survarium::player_cook *this,
        vostok::resources::queries_result *data,
        survarium::player_creation_params *params,
        survarium::inventory_cooker_data *inventory_cook_data)
{
  const vostok::variant<32> **m_parent_query; // eax
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::particle::particle_system_instance_impl *v6; // esi
  survarium::pure_game_effect_emitter_base *v7; // esi
  survarium::pure_game_effect_emitter_base *v8; // esi
  vostok::particle::particle_system_instance_impl *v9; // esi
  survarium::inventory **v10; // eax
  survarium::inventory *v11; // ecx
  survarium::pure_game_effect_emitter_base *v12; // eax
  bool *p_m_pinned; // esi
  const vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v14; // edi
  survarium::empty_hands **v15; // eax
  survarium::empty_hands *v16; // ecx
  const char **v17; // eax
  vostok::buffer_string *v18; // ecx
  vostok::variant<32> *v19; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v20; // ecx
  vostok::variant<32> *v21; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::player_cook,vostok::resources::queries_result &,survarium::player_creation_params *>,boost::_bi::list3<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *> > > v22; // [esp-14h] [ebp-1CCh]
  const char *v23; // [esp+0h] [ebp-1B8h]
  const char *v24; // [esp+4h] [ebp-1B4h]
  unsigned int v25; // [esp+8h] [ebp-1B0h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v26; // [esp+10h] [ebp-1A8h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v27; // [esp+14h] [ebp-1A4h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v28; // [esp+18h] [ebp-1A0h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v29; // [esp+1Ch] [ebp-19Ch] BYREF
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> v30; // [esp+20h] [ebp-198h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v31; // [esp+24h] [ebp-194h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v32; // [esp+28h] [ebp-190h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v33; // [esp+2Ch] [ebp-18Ch] BYREF
  const vostok::variant<32> **v34; // [esp+30h] [ebp-188h]
  survarium::player_cook *v35; // [esp+34h] [ebp-184h]
  const vostok::variant<32> *v36[2]; // [esp+38h] [ebp-180h] BYREF
  vostok::resources::request v37; // [esp+40h] [ebp-178h] BYREF
  const char *v38; // [esp+48h] [ebp-170h]
  int v39; // [esp+4Ch] [ebp-16Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::player_cook,vostok::resources::queries_result &,survarium::player_creation_params *>,boost::_bi::list3<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *> > > f; // [esp+50h] [ebp-168h] BYREF
  _DWORD v41[2]; // [esp+70h] [ebp-148h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v42; // [esp+78h] [ebp-140h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v43; // [esp+7Ch] [ebp-13Ch] BYREF
  _DWORD *v44; // [esp+98h] [ebp-120h]
  int v45; // [esp+9Ch] [ebp-11Ch]
  _DWORD v46[3]; // [esp+A0h] [ebp-118h] BYREF
  _BYTE v47[260]; // [esp+ACh] [ebp-10Ch] BYREF
  char v48; // [esp+1B0h] [ebp-8h] BYREF

  v26.m_object = 0;
  m_parent_query = (const vostok::variant<32> **)data->m_parent_query;
  v35 = this;
  v34 = m_parent_query;
  if ( inventory_cook_data )
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      (char *)inventory_cook_data,
      v23,
      v24,
      v25);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v28,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v28.m_object;
  v26.m_object = 0;
  if ( v28.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
    v26.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v26,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&params->character_model);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&params->character_model.m_object->m_skeleton,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&params->skeleton);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v28,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[1].m_unmanaged_resource);
  v6 = (vostok::particle::particle_system_instance_impl *)v28.m_object;
  v26.m_object = 0;
  if ( v28.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
    v26.m_object = v6;
    _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v26,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&params->server_character_model);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v31,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[2].m_unmanaged_resource);
  v7 = v31.m_object;
  v28.m_object = 0;
  if ( v31.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28);
    v28.m_object = v7;
    _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v27,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[3].m_unmanaged_resource);
  v8 = v27.m_object;
  v31.m_object = 0;
  if ( v27.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31);
    v31.m_object = v8;
    _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v27);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v27,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[4].m_unmanaged_resource);
  v9 = (vostok::particle::particle_system_instance_impl *)v27.m_object;
  v26.m_object = 0;
  if ( v27.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
    v26.m_object = v9;
    _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v29,
    &v26);
  v11 = *v10;
  *v10 = params->inventory.m_object;
  params->inventory.m_object = v11;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v29);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v27);
  v26.m_object = (vostok::particle::particle_system_instance_impl *)params->damage_sounds;
  v27.m_object = (survarium::pure_game_effect_emitter_base *)&data->m_queries[5];
  v29.m_object = (vostok::particle::particle_system_instance_impl *)9;
  do
  {
    v12 = v27.m_object;
    v27.m_object = (survarium::pure_game_effect_emitter_base *)((char *)v27.m_object + 736);
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v32,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v12->m_sub_fat.m_parent);
    vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
      &v33,
      (vostok::particle::particle_system_instance_impl *)v32.m_object);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v33,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v26.m_object);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v33);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v32);
    v26.m_object = (vostok::particle::particle_system_instance_impl *)((char *)v26.m_object + 4);
    --v29.m_object;
  }
  while ( v29.m_object );
  if ( params->initial_info.is_demo_player )
  {
    v26.m_object = (vostok::particle::particle_system_instance_impl *)3;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v29,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[14].m_unmanaged_resource);
    if ( v29.m_object )
      p_m_pinned = &v29.m_object[-1].m_pinned;
    else
      p_m_pinned = 0;
    v27.m_object = 0;
    if ( p_m_pinned )
    {
      vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v27);
      v27.m_object = (survarium::pure_game_effect_emitter_base *)p_m_pinned;
      _InterlockedExchangeAdd((volatile signed __int32 *)p_m_pinned + 56, 1u);
    }
    v14 = (const vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v27;
  }
  else
  {
    v29.m_object = 0;
    v26.m_object = (vostok::particle::particle_system_instance_impl *)4;
    v14 = (const vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v29;
  }
  vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v32,
    v14);
  v16 = *v15;
  *v15 = params->empty_hands.m_object;
  params->empty_hands.m_object = v16;
  vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v32);
  if ( ((int)v26.m_object & 4) != 0 )
  {
    v26.m_object = (vostok::particle::particle_system_instance_impl *)((unsigned int)v26.m_object & 0xFFFFFFFB);
    vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v29);
  }
  if ( ((int)v26.m_object & 2) != 0 )
  {
    v26.m_object = (vostok::particle::particle_system_instance_impl *)((unsigned int)v26.m_object & 0xFFFFFFFD);
    vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v27);
  }
  if ( ((int)v26.m_object & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v29);
  v46[0] = v47;
  v46[1] = v47;
  v46[2] = &v48;
  v47[0] = 0;
  v48 = 47;
  v17 = (const char **)vostok::configs::binary_config_value::operator[](
                         (vostok::configs::binary_config_value *)v31.m_object[1].__vftable,
                         "hit_params");
  vostok::fs_new::path_string_impl::assignf(
    v46,
    v18,
    (vostok::buffer_string *)"resources/gameplay/hit_params/%s.options",
    *v17);
  v29.m_object = 0;
  v30.m_object = 0;
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v28,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v29);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&params->skeleton,
    &v30);
  v44 = 0;
  v45 = 0;
  vostok::variant<32>::destroy_previous_variable_if_needed(v19, (int)v41);
  v45 = vostok::detail::type_to_int<vostok::collision::animated_object_cook_data>::get();
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v42,
    &v29);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v43,
    &v30);
  v44 = v41;
  v37.path = (const char *)v46[0];
  v38 = uri;
  v36[1] = (const vostok::variant<32> *)v41;
  v37.id = damage_model_class;
  LODWORD(f.f_.f_) = survarium::player_cook::on_hit_params_loaded;
  f.l_.a1_.t_ = v35;
  v39 = 122;
  HIDWORD(f.f_.f_) = 0;
  f.l_.a3_.t_ = params;
  HIDWORD(v22.f_.f_) = survarium::player_cook::on_hit_params_loaded;
  v22.l_.a1_.t_ = 0;
  v22.l_.a3_.t_ = (survarium::player_creation_params *)v35;
  LODWORD(v22.f_.f_) = &f;
  v41[0] = &vostok::detail::concrete_type_helper<vostok::collision::animated_object_cook_data>::`vftable';
  v36[0] = 0;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    0,
    v22,
    (int)params);
  vostok::resources::query_resources(&v37, 2u, survarium::g_allocator, v36, v34, assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v20,
    (int *)&f);
  vostok::variant<32>::destroy_previous_variable_if_needed(v21, (int)v41);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v30);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v29);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28);
}
