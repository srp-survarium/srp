void __thiscall survarium::lobby_menu::on_render_scenes_ready(
        survarium::lobby_menu *this,
        vostok::resources::queries_result *data)
{
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::particle::particle_system_instance_impl *v4; // esi
  vostok::sound::world *m_sound_world; // ecx
  vostok::sound::world_vtbl *v6; // eax
  vostok::resources::unmanaged_resource *v7; // esi
  vostok::math::half *v8; // ecx
  vostok::sound::atomic_half3 *v9; // ecx
  vostok::math::half *v10; // ecx
  vostok::sound::atomic_half3 *v11; // ecx
  vostok::math::half *v12; // ecx
  vostok::sound::atomic_half3 *v13; // ecx
  vostok::particle::particle_system_instance_impl *p_m_sub_fat; // esi
  survarium::game_effect_player *v15; // ecx
  vostok::particle::particle_system_instance_impl *M_start; // ecx
  vostok::particle::particle_system_instance_impl *M_finish; // eax
  vostok::particle::particle_system_instance_impl *v18; // edi
  vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *v19; // eax
  survarium::game_effect_player *v20; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v21; // ecx
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v22; // eax
  survarium::flash_movie *v23; // ecx
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v24; // eax
  survarium::flash_movie *v25; // ecx
  survarium::flash_movie *v26; // ecx
  survarium::chat_handler *v27; // ecx
  vostok::particle::particle_system_instance_impl *v28; // esi
  vostok::configs::binary_config_value *v29; // eax
  vostok::configs::binary_config_value *v30; // eax
  const vostok::configs::binary_config_value *v31; // eax
  float pointer; // xmm0_4
  vostok::particle::particle_system_instance_impl *v33; // eax
  vostok::configs::binary_config_value *v34; // eax
  vostok::configs::binary_config_value *v35; // eax
  survarium::pure_game_effect_emitter_base *v36; // esi
  survarium::pure_game_effect_emitter_base *v37; // edi
  const vostok::configs::binary_config_value *v38; // eax
  survarium::pure_game_effect_emitter_base *v39; // edi
  survarium::flash_movie_resource *v40; // eax
  Scaleform::GFx::Movie *m_movie; // ecx
  survarium::flash_movie_resource *v42; // eax
  survarium::flash_movie *v43; // ecx
  survarium::flash_value *v44; // ecx
  survarium::flash_value *v45; // ecx
  survarium::flash_value *v46; // ecx
  survarium::flash_value *v47; // ecx
  survarium::flash_value *v48; // ecx
  survarium::flash_value *v49; // ecx
  unsigned int m_player_ammo_bags_count; // eax
  survarium::flash_value *v51; // ecx
  survarium::flash_value *v52; // ecx
  Scaleform::GFx::Movie *v53; // ecx
  Scaleform::GFx::Movie *v54; // ecx
  unsigned int v55; // esi
  Scaleform::GFx::Movie *v56; // ecx
  Scaleform::GFx::Movie *v57; // ecx
  survarium::flash_movie_resource *v58; // eax
  survarium::flash_value *v59; // ecx
  vostok::resources::resource_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base> *p_m_lobby_game_project; // edi
  survarium::simple_game_project *v61; // ecx
  survarium::simple_game_project *v62; // eax
  vostok::configs::binary_config_value *v63; // eax
  boost::detail::function::vtable_base **v64; // esi
  vostok::configs::binary_config_value *m_root; // eax
  vostok::configs::binary_config_value *v66; // eax
  float **v67; // eax
  float *v68; // esi
  survarium::lobby_menu *v69; // ecx
  survarium::lobby_menu *v70; // ecx
  survarium::lobby_menu *v71; // ecx
  survarium::lobby_menu *v72; // ecx
  survarium::lobby_menu *v73; // ecx
  survarium::flash_function_handler_impl *delta_time; // [esp+Ch] [ebp-E8h]
  survarium::game_camera *delta_timea; // [esp+Ch] [ebp-E8h]
  int v76; // [esp+14h] [ebp-E0h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v77; // [esp+20h] [ebp-D4h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v78; // [esp+24h] [ebp-D0h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v79; // [esp+28h] [ebp-CCh] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v80; // [esp+2Ch] [ebp-C8h] BYREF
  int v81; // [esp+30h] [ebp-C4h]
  vostok::math::half3 v82; // [esp+34h] [ebp-C0h] BYREF
  boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> v83; // [esp+3Ch] [ebp-B8h] BYREF
  char *v84; // [esp+60h] [ebp-94h]
  vostok::math::float3 d; // [esp+64h] [ebp-90h] BYREF
  survarium::flash_value value; // [esp+70h] [ebp-84h] BYREF
  vostok::math::float3 v87; // [esp+88h] [ebp-6Ch] BYREF
  Scaleform::GFx::Value pvalue; // [esp+94h] [ebp-60h] BYREF
  Scaleform::GFx::Value pargs; // [esp+ACh] [ebp-48h] BYREF
  Scaleform::GFx::Value v90; // [esp+C4h] [ebp-30h] BYREF
  Scaleform::GFx::Value pval; // [esp+DCh] [ebp-18h] BYREF

  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v77,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v77.m_object;
  v78.m_object = 0;
  if ( v77.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
    v78.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v78,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_scene);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v77);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v77,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[1].m_unmanaged_resource);
  v4 = (vostok::particle::particle_system_instance_impl *)v77.m_object;
  v78.m_object = 0;
  if ( v77.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
    v78.m_object = v4;
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v78,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_scene_view);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v77);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v77,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[2].m_unmanaged_resource);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v78,
    v77.m_object);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v78,
    &this->m_sound_scene);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v77);
  m_sound_world = this->m_game->m_sound_world;
  v6 = m_sound_world->__vftable;
  v83.vtable = 0;
  v83.functor.obj_ptr = 0;
  *(_QWORD *)&d.x = __PAIR64__(LODWORD(FLOAT_N0_22), LODWORD(FLOAT_0_89999998));
  d.z = FLOAT_0_37;
  *(_QWORD *)&v87.x = __PAIR64__(LODWORD(FLOAT_2_9000001), LODWORD(FLOAT_0_31));
  *(float *)&(&v83.vtable)[1] = s_bm_current_air_resistance;
  v87.z = FLOAT_26_07;
  v6->get_logic_world_user(m_sound_world);
  v7 = this->m_sound_scene.m_object;
  BYTE2(v7[2].m_deleter) = 1;
  v78.m_object = (vostok::particle::particle_system_instance_impl *)v7;
  vostok::math::half3::half3(&v82, &v87, v8);
  vostok::sound::atomic_half3::set(v9, (vostok::math::half3 *)&v78.m_object->m_lods[0].m_time_fade_in, (int)&v82);
  vostok::math::half3::half3(&v82, &d, v10);
  vostok::sound::atomic_half3::set(v11, (vostok::math::half3 *)&v78.m_object->m_lods[1], (int)&v82);
  vostok::math::half3::half3(&v82, (const vostok::math::float3 *)&v83, v12);
  vostok::sound::atomic_half3::set(
    v13,
    (vostok::math::half3 *)&v78.m_object->m_lods[1].m_emitter_instance_list.gap4,
    (int)&v82);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v77,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[3].m_unmanaged_resource);
  if ( v77.m_object )
    p_m_sub_fat = (vostok::particle::particle_system_instance_impl *)&v77.m_object[-1].m_sub_fat;
  else
    p_m_sub_fat = 0;
  v78.m_object = 0;
  if ( p_m_sub_fat )
  {
    vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v78);
    v78.m_object = p_m_sub_fat;
    _InterlockedExchangeAdd(
      (volatile signed __int32 *)&p_m_sub_fat->vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::m_flags,
      1u);
  }
  vostok::resources::resource_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base> *)&v78,
    &this->m_lobby_game_project);
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v78);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v77);
  this->m_lobby_game_project.m_object->resolve_links(this->m_lobby_game_project.m_object);
  survarium::game_effect_player::reset(v15, &this->m_effect_player.m_current_time_in_ms, 0);
  M_start = (vostok::particle::particle_system_instance_impl *)this->m_lobby_game_project.m_object->m_game_effects._M_impl._M_start;
  M_finish = (vostok::particle::particle_system_instance_impl *)this->m_lobby_game_project.m_object->m_game_effects._M_impl._M_finish;
  v78.m_object = M_start;
  v80.m_object = M_finish;
  if ( M_start != M_finish )
  {
    do
    {
      LOBYTE(v79.m_object) = 0;
      boost::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>(
        (boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> *)M_start,
        &v83,
        0,
        v76);
      v18 = v78.m_object;
      v19 = (vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)(*((int (__thiscall **)(vostok::particle::particle_system_instance_impl_vtbl *, vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *))v78.m_object->~vostok::particle::particle_system_instance + 8))(v78.m_object->__vftable, &v77);
      survarium::game_effect_player::add(
        v20,
        (const vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)&this->m_effect_player,
        v19,
        0,
        (const boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> *)1,
        &v83);
      vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>::~intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)&v77);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v21,
        (int *)&v83);
      v78.m_object = (vostok::particle::particle_system_instance_impl *)&v18->type;
    }
    while ( &v18->type != (unsigned int *)v80.m_object );
  }
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v78,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[4].m_unmanaged_resource);
  v22 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>((const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v78, &v80);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    v22,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_cursor_ui);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v80);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
  survarium::flash_movie::SetBackgroundAlpha(v23, (int)this->m_cursor_ui.m_object->movie);
  this->m_cursor_ui.m_object->movie->m_priority = 100;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v78,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[5].m_unmanaged_resource);
  v24 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>((const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v78, &v80);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    v24,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_lobby_menu_ui);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v80);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
  survarium::flash_movie::SetBackgroundAlpha(v25, (int)this->m_lobby_menu_ui.m_object->movie);
  this->m_lobby_menu_ui.m_object->movie->m_priority = 10;
  survarium::flash_movie::Advance(v26, (int)this->m_lobby_menu_ui.m_object->movie, 0.0, 0);
  survarium::chat_handler::initialize(
    v27,
    (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)this->m_game->m_chat_handler,
    &this->m_lobby_menu_ui,
    0);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v77,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[6].m_unmanaged_resource);
  v28 = (vostok::particle::particle_system_instance_impl *)v77.m_object;
  v78.m_object = 0;
  if ( v77.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
    v78.m_object = v28;
    _InterlockedExchangeAdd(&v28->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v77);
  v29 = vostok::configs::binary_config_value::operator[](
          (vostok::configs::binary_config_value *)v78.m_object->m_lods[0].m_template.m_object,
          "player");
  v30 = vostok::configs::binary_config_value::operator[](v29, "stamina_params");
  v31 = vostok::configs::binary_config_value::operator[](v30, "max_carried_weight");
  if ( v31->type == 2 )
    pointer = *(float *)&v31->data.pointer;
  else
    pointer = (float)(int)v31->data.pointer;
  v33 = v78.m_object;
  this->m_player_max_carried_weight = pointer;
  v34 = vostok::configs::binary_config_value::operator[](
          (vostok::configs::binary_config_value *)v33->m_lods[0].m_template.m_object,
          "player");
  this->m_player_ammo_bags_count = (unsigned __int8)vostok::configs::binary_config_value::operator[](
                                                      v34,
                                                      "ammo_bags_count")->data.pointer;
  v35 = vostok::configs::binary_config_value::operator[](
          (vostok::configs::binary_config_value *)v78.m_object->m_lods[0].m_template.m_object,
          "player");
  this->m_quick_slot_pocket_size = (unsigned __int8)vostok::configs::binary_config_value::operator[](
                                                      v35,
                                                      "quick_slot_pocket_size")->data.pointer;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v79,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[7].m_unmanaged_resource);
  v36 = v79.m_object;
  v77.m_object = 0;
  if ( v79.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v77);
    v77.m_object = v36;
    _InterlockedExchangeAdd(&v36->m_reference_count, 1u);
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v77,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_static_game_parameters_config);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v77);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v79);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v79,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[8].m_unmanaged_resource);
  v37 = v79.m_object;
  v77.m_object = 0;
  if ( v79.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v77);
    v77.m_object = v37;
    _InterlockedExchangeAdd(&v37->m_reference_count, 1u);
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v77,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_skills_tree_config);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v77);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v79);
  v77.m_object = (survarium::pure_game_effect_emitter_base *)vostok::configs::binary_config_value::operator[](
                                                               this->m_static_game_parameters_config.m_object->m_root,
                                                               "max_prop_vals")->data.pointer;
  v38 = vostok::configs::binary_config_value::operator[](
          this->m_static_game_parameters_config.m_object->m_root,
          "max_prop_vals");
  v39 = (survarium::pure_game_effect_emitter_base *)((char *)v38->data.pointer + 24 * v38->count);
  v40 = this->m_lobby_menu_ui.m_object;
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  m_movie = v40->movie->m_movie;
  *(_DWORD *)&v82.x.data = v39;
  Scaleform::GFx::Movie::CreateArray(m_movie, &pvalue);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  if ( v77.m_object != v39 )
  {
    do
    {
      v80.m_object = (vostok::particle::particle_system_instance_impl *)LOWORD(vostok::configs::binary_config_value::operator[](
                                                                                 (vostok::configs::binary_config_value *)v77.m_object,
                                                                                 "id")->data.max_storage);
      v79.m_object = (survarium::pure_game_effect_emitter_base *)vostok::configs::binary_config_value::operator[](
                                                                   (vostok::configs::binary_config_value *)v77.m_object,
                                                                   "max_value")->data.pointer;
      v84 = (char *)vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)v77.m_object,
                      "min_value")->data.pointer;
      HIBYTE(v81) = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)v77.m_object,
                      "direction")->data.pointer;
      v42 = this->m_lobby_menu_ui.m_object;
      v83.vtable = 0;
      (&v83.vtable)[1] = 0;
      survarium::flash_movie::CreateObject(v43, (survarium::flash_value *)v42->movie, (Scaleform::GFx::Value *)&v83);
      survarium::flash_value::SetUInt(v44, (int)&value, LOWORD(v80.m_object));
      survarium::flash_value::SetMember(v45, &v83, "icon_id", &value);
      survarium::flash_value::SetString(&value, (const char *)v79.m_object);
      survarium::flash_value::SetMember(v46, &v83, "max", &value);
      survarium::flash_value::SetString(&value, v84);
      survarium::flash_value::SetMember(v47, &v83, "min", &value);
      survarium::flash_value::SetUInt(v48, (int)&value, HIBYTE(v81));
      survarium::flash_value::SetMember(v49, &v83, "direction", &value);
      pvalue.pObjectInterface->PushBack(
        pvalue.pObjectInterface,
        (void *)pvalue.mValue.IValue,
        (const Scaleform::GFx::Value *)&v83);
      Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v83);
      v77.m_object = (survarium::pure_game_effect_emitter_base *)((char *)v77.m_object + 24);
    }
    while ( v77.m_object != *(survarium::pure_game_effect_emitter_base **)&v82.x.data );
  }
  Scaleform::GFx::Movie::Invoke(
    this->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.set_item_props_min_max_values",
    0,
    &pvalue,
    1u);
  m_player_ammo_bags_count = this->m_player_ammo_bags_count;
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetUInt(v51, (int)&pargs, m_player_ammo_bags_count);
  Scaleform::GFx::Movie::Invoke(
    this->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.set_ammo_bags_count",
    0,
    &pargs,
    1u);
  survarium::flash_value::SetUInt(v52, (int)&pargs, this->m_quick_slot_pocket_size);
  Scaleform::GFx::Movie::Invoke(
    this->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.set_quick_slot_size",
    0,
    &pargs,
    1u);
  survarium::flash_movie::SetExternalInterface(
    this->m_lobby_menu_ui.m_object->movie,
    &this->survarium::flash_external_handler);
  v53 = this->m_cursor_ui.m_object->movie->m_movie;
  v53->SetViewAlignment(v53, Align_TopLeft);
  v54 = this->m_cursor_ui.m_object->movie->m_movie;
  v55 = 0;
  v54->SetViewScaleMode(v54, SM_NoScale);
  v56 = this->m_lobby_menu_ui.m_object->movie->m_movie;
  v56->SetViewAlignment(v56, Align_TopLeft);
  v57 = this->m_lobby_menu_ui.m_object->movie->m_movie;
  v57->SetViewScaleMode(v57, SM_NoScale);
  v58 = this->m_lobby_menu_ui.m_object;
  pval.pObjectInterface = 0;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(v58->movie->m_movie, &pval, "_root.player_profile");
  delta_time = this->survarium::flash_function_handler::impl;
  v90.pObjectInterface = 0;
  v90.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateFunction(this->m_lobby_menu_ui.m_object->movie->m_movie, &v90, delta_time, 0);
  survarium::flash_value::SetMember(v59, &pval, "_relocateFunction", (survarium::flash_value *)&v90);
  this->show_ui(this, 1);
  p_m_lobby_game_project = &this->m_lobby_game_project;
  survarium::simple_game_project::insert_game_objects(v61, &this->m_lobby_game_project.m_object->__vftable);
  for ( v77.m_object = 0; ; v77.m_object = (survarium::pure_game_effect_emitter_base *)((char *)v77.m_object + 76) )
  {
    v62 = p_m_lobby_game_project->m_object;
    if ( v55 >= p_m_lobby_game_project->m_object->m_static_collision_objects_count )
      break;
    survarium::static_collision::insert(
      (survarium::static_collision *)((char *)v77.m_object + (unsigned int)v62->m_static_collision_objects),
      this->m_physics_world);
    ++v55;
  }
  v63 = vostok::configs::binary_config_value::operator[](v62->m_config.m_object->m_root, "camera");
  v64 = (boost::detail::function::vtable_base **)vostok::configs::binary_config_value::operator[](v63, "position")->data.pointer;
  m_root = this->m_lobby_game_project.m_object->m_config.m_object->m_root;
  v83.vtable = *v64++;
  (&v83.vtable)[1] = *v64;
  v83.functor.obj_ptr = v64[1];
  v66 = vostok::configs::binary_config_value::operator[](m_root, "camera");
  v67 = (float **)vostok::configs::binary_config_value::operator[](v66, "direction");
  v68 = *v67;
  d.x = **v67;
  d.y = *++v68;
  delta_timea = this->m_camera;
  d.z = v68[1];
  survarium::game_camera::set_position_direction(&d, delta_timea, (const vostok::math::float3 *)&v83);
  survarium::lobby_menu::fill_items_dictionary(v69, (unsigned int)this);
  survarium::lobby_menu::fill_inventory_labels(v70, (int)this);
  survarium::lobby_menu::fill_compatibilities_and_restrictions(
    v71,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)this);
  survarium::lobby_menu::fill_skills_tree(
    v72,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)this);
  survarium::game::on_queried_by_network_client_scene_ready(0, this->m_game);
  survarium::lobby_menu::show_disconnected_message(v73, (int)this, 1);
  Scaleform::GFx::Value::~Value(&v90);
  Scaleform::GFx::Value::~Value(&pval);
  Scaleform::GFx::Value::~Value(&pargs);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pvalue);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
}
