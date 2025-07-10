void __thiscall survarium::lobby_menu::on_render_scenes_ready(
        survarium::lobby_menu *this,
        vostok::resources::queries_result *data)
{
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config *v4; // eax
  vostok::resources::unmanaged_intrusive_base *v5; // ecx
  vostok::configs::binary_config *v6; // esi
  vostok::configs::binary_config *v7; // eax
  vostok::resources::unmanaged_intrusive_base *v8; // ecx
  vostok::configs::binary_config *v9; // esi
  vostok::configs::binary_config *v10; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_sound_scene; // edi
  vostok::resources::unmanaged_resource *v12; // edx
  vostok::resources::unmanaged_intrusive_base *v13; // ecx
  vostok::sound::world *m_sound_world; // ecx
  vostok::sound::world_user *v15; // eax
  vostok::configs::binary_config *v16; // esi
  vostok::configs::binary_config *v17; // edi
  vostok::configs::binary_config *v18; // eax
  survarium::simple_game_project *v19; // ecx
  survarium::simple_game_project *v20; // eax
  survarium::profile_player_character *v21; // eax
  vostok::configs::binary_config *v22; // esi
  vostok::configs::binary_config *v23; // edi
  vostok::configs::binary_config *v24; // eax
  survarium::flash_movie_resource *v25; // ecx
  survarium::flash_movie_resource *v26; // eax
  vostok::configs::binary_config *v27; // esi
  vostok::configs::binary_config *v28; // edi
  vostok::configs::binary_config *v29; // eax
  survarium::flash_movie_resource *v30; // ecx
  survarium::flash_movie_resource *v31; // eax
  vostok::configs::binary_config *v32; // esi
  vostok::configs::binary_config *v33; // edi
  vostok::configs::binary_config *v34; // eax
  survarium::flash_movie_resource *v35; // ecx
  survarium::flash_movie_resource *v36; // eax
  vostok::configs::binary_config *v37; // esi
  vostok::configs::binary_config *v38; // edi
  vostok::configs::binary_config *v39; // eax
  survarium::flash_movie_resource *v40; // ecx
  survarium::flash_movie_resource *v41; // eax
  vostok::configs::binary_config *v42; // esi
  vostok::configs::binary_config_value *v43; // eax
  vostok::configs::binary_config_value *v44; // eax
  const vostok::configs::binary_config_value *v45; // eax
  float pointer; // xmm0_4
  vostok::memory::doug_lea_allocator *f; // ecx
  survarium::flash_external_handler *v48; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v49; // esi
  survarium::lobby_menu_external_handler *v50; // eax
  survarium::flash_movie_resource *v51; // ecx
  Scaleform::GFx::Movie *m_movie; // ecx
  Scaleform::GFx::Movie *v53; // ecx
  Scaleform::GFx::Movie *v54; // ecx
  Scaleform::GFx::Movie *v55; // ecx
  Scaleform::GFx::Movie *v56; // ecx
  Scaleform::GFx::Movie *v57; // ecx
  Scaleform::GFx::Movie *v58; // ecx
  Scaleform::GFx::Movie *v59; // ecx
  Scaleform::GFx::Movie *v60; // ecx
  Scaleform::GFx::Movie *v61; // ecx
  survarium::flash_movie_resource *v62; // edx
  int *v63; // eax
  survarium::relocate_item_func *v64; // eax
  survarium::flash_movie_resource *v65; // ecx
  survarium::flash_movie_resource *v66; // edx
  survarium::simple_game_project *v67; // eax
  void **M_start; // esi
  void **i; // edi
  unsigned int v70; // edi
  int j; // esi
  survarium::simple_game_project *v72; // eax
  survarium::render_visual *m_render_visuals; // eax
  const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v74; // ecx
  const vostok::math::float4x4 *p_matrix; // eax
  unsigned int v76; // edi
  vostok::physics::bt_collision_shape *k; // esi
  survarium::simple_game_project *v78; // eax
  vostok::configs::binary_config_value *v79; // eax
  float *v80; // eax
  float v81; // ecx
  __int64 v82; // xmm0_8
  vostok::configs::binary_config *v83; // eax
  vostok::configs::binary_config_value *m_root; // ecx
  vostok::configs::binary_config_value *v85; // eax
  const vostok::configs::binary_config_value *v86; // eax
  float v87; // ecx
  vostok::math::float4x4 *v88; // eax
  survarium::lobby_menu *v89; // ecx
  survarium::game *v90; // ecx
  survarium::game *m_game; // eax
  bool v92; // zf
  vostok::configs::binary_config *v93; // eax
  vostok::resources::unmanaged_intrusive_base *v94; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v95; // [esp+7Ch] [ebp-F4h] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> player_config; // [esp+80h] [ebp-F0h] BYREF
  vostok::math::float3 position; // [esp+84h] [ebp-ECh] BYREF
  vostok::math::float3 dir; // [esp+90h] [ebp-E0h] BYREF
  vostok::math::float3 pos; // [esp+9Ch] [ebp-D4h] BYREF
  survarium::flash_value proxy; // [esp+A8h] [ebp-C8h] BYREF
  survarium::flash_value players_count; // [esp+C0h] [ebp-B0h] BYREF
  survarium::flash_value func; // [esp+D8h] [ebp-98h] BYREF
  vostok::math::float4x4 v103; // [esp+F0h] [ebp-80h] BYREF
  __int64 v104[8]; // [esp+130h] [ebp-40h] BYREF

  v95.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v95,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v95.m_object;
  player_config.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &player_config,
    v95.m_object);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_scene,
    (const vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&player_config);
  v4 = player_config.m_object;
  if ( player_config.m_object )
  {
    v5 = &player_config.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&player_config.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v5, v4);
  }
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  v95.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v95,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
  v6 = v95.m_object;
  player_config.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &player_config,
    v95.m_object);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_scene_view,
    (const vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&player_config);
  v7 = player_config.m_object;
  if ( player_config.m_object )
  {
    v8 = &player_config.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&player_config.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v8, v7);
  }
  if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  player_config.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &player_config,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[2].m_unmanaged_resource);
  v95.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v95,
    player_config.m_object);
  v9 = v95.m_object;
  v10 = 0;
  p_m_sound_scene = &this->m_sound_scene;
  if ( v95.m_object )
  {
    v10 = v95.m_object;
    _InterlockedExchangeAdd(&v95.m_object->m_reference_count, 1u);
  }
  v12 = p_m_sound_scene->m_object;
  p_m_sound_scene->m_object = v10;
  if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v12);
  if ( v9 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v9->vostok::resources::unmanaged_intrusive_base, v9);
  if ( player_config.m_object )
  {
    v13 = &player_config.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&player_config.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v13, player_config.m_object);
  }
  m_sound_world = this->m_game->m_sound_world;
  dir.x = 0.0;
  *(_QWORD *)&pos.x = 0xBE6147AE3F666666uLL;
  pos.z = 0.37;
  *(_QWORD *)&position.x = 0x4039999A3E9EB852LL;
  *(_QWORD *)&dir.elements[1] = (unsigned int)clear_value;
  position.z = 26.07;
  v15 = m_sound_world->get_logic_world_user(m_sound_world);
  vostok::sound::world_user::set_listener_properties_interlocked(v15, &this->m_sound_scene, &position, &pos, &dir);
  v16 = 0;
  v95.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v95,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[3].m_unmanaged_resource);
  v17 = v95.m_object;
  if ( v95.m_object )
  {
    v16 = v95.m_object;
    _InterlockedExchangeAdd(&v95.m_object->m_reference_count, 1u);
  }
  v18 = 0;
  if ( v16 )
  {
    v18 = v16;
    _InterlockedExchangeAdd(&v16->m_reference_count, 1u);
  }
  v19 = (survarium::simple_game_project *)v18;
  v20 = this->m_lobby_game_project.m_object;
  this->m_lobby_game_project.m_object = v19;
  if ( v20 && !_InterlockedExchangeAdd(&v20->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v20->vostok::resources::unmanaged_intrusive_base, v20);
  if ( v16 && !_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v16->vostok::resources::unmanaged_intrusive_base, v16);
  if ( v17 && !_InterlockedExchangeAdd(&v17->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v17->vostok::resources::unmanaged_intrusive_base, v17);
  v21 = (survarium::profile_player_character *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                 (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                                 8u);
  if ( v21 )
  {
    v21->m_player.m_object = 0;
    v21->m_lobby_menu = this;
  }
  else
  {
    v21 = 0;
  }
  this->m_character = v21;
  v22 = 0;
  v95.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v95,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[4].m_unmanaged_resource);
  v23 = v95.m_object;
  if ( v95.m_object )
  {
    v22 = v95.m_object;
    _InterlockedExchangeAdd(&v95.m_object->m_reference_count, 1u);
  }
  v24 = 0;
  if ( v22 )
  {
    v24 = v22;
    _InterlockedExchangeAdd(&v22->m_reference_count, 1u);
  }
  v25 = (survarium::flash_movie_resource *)v24;
  v26 = this->m_cursor_ui.m_object;
  this->m_cursor_ui.m_object = v25;
  if ( v26 && !_InterlockedExchangeAdd(&v26->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v26->vostok::resources::unmanaged_intrusive_base, v26);
  if ( v22 && !_InterlockedExchangeAdd(&v22->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v22->vostok::resources::unmanaged_intrusive_base, v22);
  if ( v23 && !_InterlockedExchangeAdd(&v23->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v23->vostok::resources::unmanaged_intrusive_base, v23);
  ((void (__stdcall *)(_DWORD))this->m_cursor_ui.m_object->movie->m_movie->SetBackgroundAlpha)(0.0);
  v27 = 0;
  this->m_cursor_ui.m_object->movie->m_priority = 100;
  v95.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v95,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[5].m_unmanaged_resource);
  v28 = v95.m_object;
  if ( v95.m_object )
  {
    v27 = v95.m_object;
    _InterlockedExchangeAdd(&v95.m_object->m_reference_count, 1u);
  }
  v29 = 0;
  if ( v27 )
  {
    v29 = v27;
    _InterlockedExchangeAdd(&v27->m_reference_count, 1u);
  }
  v30 = (survarium::flash_movie_resource *)v29;
  v31 = this->m_lobby_menu_ui.m_object;
  this->m_lobby_menu_ui.m_object = v30;
  if ( v31 && !_InterlockedExchangeAdd(&v31->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v31->vostok::resources::unmanaged_intrusive_base, v31);
  if ( v27 && !_InterlockedExchangeAdd(&v27->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v27->vostok::resources::unmanaged_intrusive_base, v27);
  if ( v28 && !_InterlockedExchangeAdd(&v28->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v28->vostok::resources::unmanaged_intrusive_base, v28);
  ((void (__stdcall *)(_DWORD))this->m_lobby_menu_ui.m_object->movie->m_movie->SetBackgroundAlpha)(0.0);
  v32 = 0;
  this->m_lobby_menu_ui.m_object->movie->m_priority = 10;
  v95.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v95,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[6].m_unmanaged_resource);
  v33 = v95.m_object;
  if ( v95.m_object )
  {
    v32 = v95.m_object;
    _InterlockedExchangeAdd(&v95.m_object->m_reference_count, 1u);
  }
  v34 = 0;
  if ( v32 )
  {
    v34 = v32;
    _InterlockedExchangeAdd(&v32->m_reference_count, 1u);
  }
  v35 = (survarium::flash_movie_resource *)v34;
  v36 = this->m_message_ui.m_object;
  this->m_message_ui.m_object = v35;
  if ( v36 && !_InterlockedExchangeAdd(&v36->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v36->vostok::resources::unmanaged_intrusive_base, v36);
  if ( v32 && !_InterlockedExchangeAdd(&v32->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v32->vostok::resources::unmanaged_intrusive_base, v32);
  if ( v33 && !_InterlockedExchangeAdd(&v33->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v33->vostok::resources::unmanaged_intrusive_base, v33);
  ((void (__stdcall *)(_DWORD))this->m_message_ui.m_object->movie->m_movie->SetBackgroundAlpha)(0.0);
  v37 = 0;
  this->m_message_ui.m_object->movie->m_priority = 12;
  v95.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v95,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[7].m_unmanaged_resource);
  v38 = v95.m_object;
  if ( v95.m_object )
  {
    v37 = v95.m_object;
    _InterlockedExchangeAdd(&v95.m_object->m_reference_count, 1u);
  }
  v39 = 0;
  if ( v37 )
  {
    v39 = v37;
    _InterlockedExchangeAdd(&v37->m_reference_count, 1u);
  }
  v40 = (survarium::flash_movie_resource *)v39;
  v41 = this->m_match_making_ui.m_object;
  this->m_match_making_ui.m_object = v40;
  if ( v41 && !_InterlockedExchangeAdd(&v41->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v41->vostok::resources::unmanaged_intrusive_base, v41);
  if ( v37 && !_InterlockedExchangeAdd(&v37->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v37->vostok::resources::unmanaged_intrusive_base, v37);
  if ( v38 && !_InterlockedExchangeAdd(&v38->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v38->vostok::resources::unmanaged_intrusive_base, v38);
  ((void (__stdcall *)(_DWORD))this->m_match_making_ui.m_object->movie->m_movie->SetBackgroundAlpha)(0.5);
  this->m_match_making_ui.m_object->movie->m_priority = 15;
  v95.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v95,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[8].m_unmanaged_resource);
  v42 = v95.m_object;
  player_config.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &player_config,
    v95.m_object);
  if ( v42 && !_InterlockedExchangeAdd(&v42->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v42->vostok::resources::unmanaged_intrusive_base, v42);
  v43 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  player_config.m_object->m_root,
                                                  "player");
  v44 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v43, "stamina_params");
  v45 = vostok::configs::binary_config_value::operator[](v44, "max_carried_weight");
  if ( v45->type == 2 )
    pointer = *(float *)&v45->data.pointer;
  else
    pointer = (float)(int)v45->data.pointer;
  f = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  this->m_player_max_carried_weight = pointer;
  v49 = (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::memory::doug_lea_allocator::malloc_impl(f, 0xCu);
  if ( v49 )
  {
    v95.m_object = (vostok::configs::binary_config *)this->m_game;
    survarium::flash_external_handler::flash_external_handler(v48, v49);
    v49[2].m_object = v95.m_object;
    v49->m_object = (vostok::configs::binary_config *)&survarium::lobby_menu_external_handler::`vftable';
    v50 = (survarium::lobby_menu_external_handler *)v49;
  }
  else
  {
    v50 = 0;
  }
  v51 = this->m_lobby_menu_ui.m_object;
  this->m_lobby_menu_external_handler = v50;
  v51->movie->m_movie->SetState(&v51->movie->m_movie->Scaleform::GFx::StateBag, State_ExternalInterface, v50->impl);
  m_movie = this->m_match_making_ui.m_object->movie->m_movie;
  m_movie->SetState(
    &m_movie->Scaleform::GFx::StateBag,
    State_ExternalInterface,
    this->m_lobby_menu_external_handler->impl);
  v53 = this->m_cursor_ui.m_object->movie->m_movie;
  v53->SetViewAlignment(v53, Align_TopLeft);
  v54 = this->m_cursor_ui.m_object->movie->m_movie;
  v54->SetViewScaleMode(v54, SM_NoScale);
  v55 = this->m_lobby_menu_ui.m_object->movie->m_movie;
  v55->SetViewAlignment(v55, Align_TopLeft);
  v56 = this->m_lobby_menu_ui.m_object->movie->m_movie;
  v56->SetViewScaleMode(v56, SM_NoScale);
  v57 = this->m_match_making_ui.m_object->movie->m_movie;
  v57->SetViewAlignment(v57, Align_TopLeft);
  v58 = this->m_match_making_ui.m_object->movie->m_movie;
  v58->SetViewScaleMode(v58, SM_NoScale);
  v59 = this->m_message_ui.m_object->movie->m_movie;
  v59->SetViewAlignment(v59, Align_TopLeft);
  v60 = this->m_message_ui.m_object->movie->m_movie;
  v60->SetViewScaleMode(v60, SM_NoScale);
  v61 = this->m_message_ui.m_object->movie->m_movie;
  v61->SetState(&v61->Scaleform::GFx::StateBag, State_ExternalInterface, this->m_lobby_menu_external_handler->impl);
  v62 = this->m_lobby_menu_ui.m_object;
  *(_DWORD *)proxy.body = 0;
  *(_DWORD *)&proxy.body[4] = 0;
  Scaleform::GFx::Movie::GetVariable(v62->movie->m_movie, (Scaleform::GFx::Value *)&proxy, "_root.player_profile");
  v63 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
          0xCu);
  if ( v63 )
    survarium::relocate_item_func::relocate_item_func((survarium::relocate_item_func *)this->m_game, v63, this->m_game);
  else
    v64 = 0;
  v65 = this->m_lobby_menu_ui.m_object;
  this->m_relocate_item_func = v64;
  *(_DWORD *)func.body = 0;
  *(_DWORD *)&func.body[4] = 0;
  Scaleform::GFx::Movie::CreateFunction(v65->movie->m_movie, (Scaleform::GFx::Value *)&func, v64->impl, 0);
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)proxy.body + 20))(
    *(_DWORD *)proxy.body,
    *(_DWORD *)&proxy.body[8],
    "_relocateFunction",
    &func,
    (proxy.body[4] & 0x8F) == 10);
  ((void (__stdcall *)(_DWORD, _DWORD, int))this->m_lobby_menu_ui.m_object->movie->m_movie->Advance)(0.0, 0, 1);
  this->show_ui(this, 1);
  v66 = this->m_lobby_menu_ui.m_object;
  *(_DWORD *)players_count.body = 0;
  *(_DWORD *)&players_count.body[4] = 4;
  *(_DWORD *)&players_count.body[8] = 5;
  Scaleform::GFx::Movie::Invoke(
    v66->movie->m_movie,
    "root.lobby_menu.set_max_players",
    0,
    (const Scaleform::GFx::Value *)&players_count,
    1u);
  v67 = this->m_lobby_game_project.m_object;
  M_start = v67->m_objects._M_impl._M_start;
  for ( i = v67->m_objects._M_impl._M_finish; M_start != i; ++M_start )
    (*(void (__thiscall **)(void *))(*(_DWORD *)*M_start + 32))(*M_start);
  v70 = 0;
  for ( j = 0; ; ++j )
  {
    v72 = this->m_lobby_game_project.m_object;
    if ( v70 >= v72->m_render_visuals_count )
      break;
    m_render_visuals = v72->m_render_visuals;
    v74 = (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)m_render_visuals[j].model.m_object;
    p_matrix = &m_render_visuals[j].matrix;
    if ( v74 )
      vostok::render::scene_renderer::add_model(
        (vostok::render::scene_renderer *)this->m_game,
        (int)this->m_game->m_renderer->m_scene,
        &this->m_render_scene,
        v74 + 66,
        p_matrix);
    ++v70;
  }
  v76 = 0;
  for ( k = 0; ; k = (vostok::physics::bt_collision_shape *)((char *)k + 76) )
  {
    v78 = this->m_lobby_game_project.m_object;
    if ( v76 >= v78->m_static_collision_objects_count )
      break;
    survarium::static_collision::insert(
      (survarium::static_collision *)((char *)k + (unsigned int)v78->m_static_collision_objects),
      (btRigidBody *)this,
      v76++,
      k,
      this->m_physics_world);
  }
  v79 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  v78->m_config.m_object->m_root,
                                                  (char *)&stru_96A440.m_inverted_view.lines[2]);
  v80 = (float *)vostok::configs::binary_config_value::operator[](v79, "position")->data.pointer;
  v81 = v80[2];
  v82 = *(_QWORD *)v80;
  v83 = this->m_lobby_game_project.m_object->m_config.m_object;
  pos.z = v81;
  m_root = v83->m_root;
  *(_QWORD *)&pos.x = v82;
  v85 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  m_root,
                                                  (char *)&stru_96A440.m_inverted_view.lines[2]);
  v86 = vostok::configs::binary_config_value::operator[](v85, (char *)&stru_96A440.m_inverted_view.lines[2].elements[2]);
  v87 = *((float *)v86->data.pointer + 2);
  *(_QWORD *)&dir.x = *(_QWORD *)v86->data.pointer;
  dir.z = v87;
  position.x = 0.0;
  *(_QWORD *)&position.elements[1] = (unsigned int)clear_value;
  v88 = vostok::math::create_camera_direction(&dir, &position, v104, &pos);
  qmemcpy(
    (void *)&this->m_camera->m_inverted_view_matrix,
    invert_impl(
      v88,
      &v103,
      (float)((float)((float)((float)(v88->j.y * v88->k.z) - (float)(v88->j.z * v88->k.y)) * v88->i.x)
            - (float)((float)((float)(v88->j.x * v88->k.z) - (float)(v88->k.x * v88->j.z)) * v88->i.y))
    + (float)((float)((float)(v88->j.x * v88->k.y) - (float)(v88->k.x * v88->j.y)) * v88->i.z)),
    sizeof(this->m_camera->m_inverted_view_matrix));
  survarium::lobby_menu::fill_items_dictionary(0, this);
  survarium::lobby_menu::fill_inventory_labels(v89, this);
  m_game = this->m_game;
  v92 = !m_game->m_lobby_scene_ready;
  m_game->m_login_scene_ready = 1;
  if ( !v92 )
    survarium::game::create_network_client(v90, m_game, 0);
  survarium::lobby_menu::show_disconnected_message((survarium::lobby_menu *)v90, this, 1);
  if ( (players_count.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)players_count.body + 8))(
      *(_DWORD *)players_count.body,
      &players_count,
      *(_DWORD *)&players_count.body[8]);
    *(_DWORD *)players_count.body = 0;
  }
  *(_DWORD *)&players_count.body[4] = 0;
  if ( (func.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)func.body + 8))(
      *(_DWORD *)func.body,
      &func,
      *(_DWORD *)&func.body[8]);
    *(_DWORD *)func.body = 0;
  }
  *(_DWORD *)&func.body[4] = 0;
  if ( (proxy.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)proxy.body + 8))(
      *(_DWORD *)proxy.body,
      &proxy,
      *(_DWORD *)&proxy.body[8]);
    *(_DWORD *)proxy.body = 0;
  }
  v93 = player_config.m_object;
  v94 = &player_config.m_object->vostok::resources::unmanaged_intrusive_base;
  *(_DWORD *)&proxy.body[4] = 0;
  if ( !_InterlockedExchangeAdd(&player_config.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(v94, v93);
}
