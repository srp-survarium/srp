void __thiscall survarium::login_menu::on_resources_ready(
        survarium::login_menu *this,
        vostok::resources::queries_result *data)
{
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::particle::particle_system_instance_impl *v4; // esi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_sound_scene; // esi
  vostok::sound::world *m_sound_world; // ecx
  vostok::sound::world_vtbl *v7; // eax
  vostok::resources::unmanaged_resource *v8; // ebx
  vostok::math::half *v9; // ecx
  vostok::sound::atomic_half3 *v10; // ecx
  vostok::math::half *v11; // ecx
  vostok::sound::atomic_half3 *v12; // ecx
  vostok::math::half *v13; // ecx
  vostok::sound::atomic_half3 *v14; // ecx
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *p_m_login_menu_ui; // ebx
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v16; // eax
  survarium::flash_movie *v17; // ecx
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *p_m_cursor_ui; // esi
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v19; // eax
  survarium::flash_movie *v20; // ecx
  vostok::memory::doug_lea_allocator *v21; // esi
  char *v22; // eax
  vostok::memory::doug_lea_allocator *v23; // ecx
  char *v24; // eax
  survarium::flash_external_handler *v25; // ecx
  survarium::login_menu *v26; // edi
  char *v27; // esi
  int v28; // eax
  survarium::flash_external_handler *v29; // edx
  unsigned int type; // ecx
  unsigned int v31; // ecx
  Scaleform::GFx::Movie *m_movie; // ecx
  Scaleform::GFx::Movie *v33; // ecx
  survarium::flash_movie *v34; // ecx
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v35; // edi
  survarium::flash_movie *v36; // ecx
  unsigned int v37; // ecx
  survarium::flash_value *v38; // ecx
  vostok::resources::managed_resource *v39; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v40; // ecx
  unsigned int v41; // esi
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> v42; // eax
  survarium::flash_movie *v43; // ecx
  survarium::text_translator *v44; // ecx
  survarium::flash_value *v45; // ecx
  survarium::flash_value *v46; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v47; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v48[5]; // [esp+14h] [ebp-7FACh] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v49; // [esp+28h] [ebp-7F98h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v50; // [esp+2Ch] [ebp-7F94h] BYREF
  vostok::math::half3 v51; // [esp+30h] [ebp-7F90h] BYREF
  survarium::login_menu *v52; // [esp+38h] [ebp-7F88h]
  survarium::flash_value v53; // [esp+3Ch] [ebp-7F84h] BYREF
  vostok::math::float3 v54; // [esp+54h] [ebp-7F6Ch] BYREF
  vostok::math::float3 v55; // [esp+60h] [ebp-7F60h] BYREF
  char v56[4]; // [esp+6Ch] [ebp-7F54h] BYREF
  unsigned __int8 *src; // [esp+70h] [ebp-7F50h]
  unsigned int count; // [esp+74h] [ebp-7F4Ch]
  Scaleform::GFx::Value pargs; // [esp+78h] [ebp-7F48h] BYREF
  Scaleform::GFx::Value value; // [esp+90h] [ebp-7F30h] BYREF
  survarium::flash_value v61; // [esp+A8h] [ebp-7F18h] BYREF
  char v62[512]; // [esp+C0h] [ebp-7F00h] BYREF
  char dst[32000]; // [esp+2C0h] [ebp-7D00h] BYREF

  v52 = this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v50,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v50.m_object;
  v49.m_object = 0;
  if ( v50.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v49);
    v49.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v49,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_scene);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v49);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v50);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v50,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[1].m_unmanaged_resource);
  v4 = (vostok::particle::particle_system_instance_impl *)v50.m_object;
  v49.m_object = 0;
  if ( v50.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v49);
    v49.m_object = v4;
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v49,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_scene_view);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v49);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v50);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v49,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[2].m_unmanaged_resource);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v50,
    (survarium::pure_game_effect_emitter_base *)v49.m_object);
  p_m_sound_scene = &this->m_sound_scene;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    &v50,
    &this->m_sound_scene);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v50);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v49);
  m_sound_world = this->m_game->m_sound_world;
  v7 = m_sound_world->__vftable;
  *(_DWORD *)v53.body = 0;
  *(_DWORD *)&v53.body[8] = 0;
  *(_QWORD *)&v55.x = __PAIR64__(LODWORD(FLOAT_N0_22), LODWORD(FLOAT_0_89999998));
  v55.z = FLOAT_0_37;
  *(_QWORD *)&v54.x = __PAIR64__(LODWORD(FLOAT_2_9000001), LODWORD(FLOAT_0_31));
  *(float *)&v53.body[4] = s_bm_current_air_resistance;
  v54.z = FLOAT_26_07;
  v7->get_logic_world_user(m_sound_world);
  v8 = this->m_sound_scene.m_object;
  BYTE2(p_m_sound_scene->m_object[2].m_deleter) = 1;
  vostok::math::half3::half3(&v51, &v54, v9);
  vostok::sound::atomic_half3::set(v10, (vostok::math::half3 *)&v8[1].m_reconstruction_size, (int)&v51);
  vostok::math::half3::half3(&v51, &v55, v11);
  vostok::sound::atomic_half3::set(
    v12,
    (vostok::math::half3 *)&v8[1].vostok::uid_object<vostok::resources::resource_children>,
    (int)&v51);
  vostok::math::half3::half3(&v51, (const vostok::math::float3 *)&v53, v13);
  vostok::sound::atomic_half3::set(
    v14,
    (vostok::math::half3 *)&v8[1].m_children_resources.vostok::threading::simple_lock,
    (int)&v51);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v50,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[3].m_unmanaged_resource);
  p_m_login_menu_ui = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v52->m_login_menu_ui;
  v16 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>((const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v50, (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v51);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    v16,
    p_m_login_menu_ui);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v51);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v50);
  survarium::flash_movie::SetBackgroundAlpha(v17, (int)p_m_login_menu_ui->m_object->m_lods[0].m_template.m_object);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v50,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[4].m_unmanaged_resource);
  p_m_cursor_ui = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v52->m_cursor_ui;
  v19 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>((const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v50, (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v51);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    v19,
    p_m_cursor_ui);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v51);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v50);
  survarium::flash_movie::SetBackgroundAlpha(v20, (int)p_m_cursor_ui->m_object->m_lods[0].m_template.m_object);
  v21 = survarium::g_allocator;
  v22 = type_info::raw_name(&survarium::login_menu_external_handler `RTTI Type Descriptor');
  v24 = vostok::memory::doug_lea_allocator::malloc_impl(
          v23,
          (int)v21,
          0x10u,
          v22,
          (const char *const)v48[1].m_object,
          (const char *const)v48[2].m_object,
          (const unsigned int)v48[3].m_object);
  v26 = v52;
  v27 = v24;
  if ( v24 )
  {
    *(_DWORD *)&v51.x.data = v52->m_game;
    survarium::flash_external_handler::flash_external_handler(v25, v24);
    v28 = *(_DWORD *)&v51.x.data;
    *(_DWORD *)v27 = &survarium::login_menu_external_handler::`vftable';
    *((_DWORD *)v27 + 2) = v28;
    *((_DWORD *)v27 + 3) = v26;
    v29 = (survarium::flash_external_handler *)v27;
  }
  else
  {
    v29 = 0;
  }
  survarium::flash_movie::SetExternalInterface(
    (survarium::flash_movie *)p_m_login_menu_ui->m_object->m_lods[0].m_template.m_object,
    v29);
  type = p_m_login_menu_ui->m_object->m_lods[0].m_template.m_object->type;
  (*(void (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)type + 60))(type, 0);
  v31 = p_m_login_menu_ui->m_object->m_lods[0].m_template.m_object->type;
  (*(void (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)v31 + 52))(v31, 0);
  m_movie = v26->m_cursor_ui.m_object->movie->m_movie;
  m_movie->SetViewAlignment(m_movie, Align_TopLeft);
  v33 = v26->m_cursor_ui.m_object->movie->m_movie;
  v33->SetViewScaleMode(v33, SM_NoScale);
  while ( !v26->m_game->m_engine->render_has_been_created(v26->m_game->m_engine) )
    vostok::threading::yield(0xAu);
  survarium::base_game_scene::show_movie(p_m_login_menu_ui, v26);
  survarium::flash_movie::Advance(v34, (int)p_m_login_menu_ui->m_object->m_lods[0].m_template.m_object, 0.0, 1u);
  v48[0].m_object = (vostok::resources::managed_resource *)v26;
  v35 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v26->m_cursor_ui;
  survarium::base_game_scene::show_movie(v35, (survarium::base_game_scene *)v48[0].m_object);
  survarium::flash_movie::Advance(v36, (int)v35->m_object->m_lods[0].m_template.m_object, 0.0, 1u);
  v37 = p_m_login_menu_ui->m_object->m_lods[0].m_template.m_object->type;
  (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)v37 + 192))(v37, 2);
  value.pObjectInterface = 0;
  value.Type = VT_Undefined;
  survarium::flash_value::SetBoolean(v38, (int)&value, survarium::s_store_user_pass);
  Scaleform::GFx::Movie::SetVariable(
    (Scaleform::GFx::Movie *)p_m_login_menu_ui->m_object->m_lods[0].m_template.m_object->type,
    "root.save_checkbox.selected",
    &value,
    SV_Sticky);
  vostok::resources::query_result_for_user::get_managed_resource(
    &data->m_queries[5],
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v51);
  v48[0].m_object = v39;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    v48,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v51);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v40,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v56,
    v48[0]);
  v41 = count;
  memcpy((unsigned __int8 *)dst, src, count);
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  v48[0].m_object = (vostok::resources::managed_resource *)&pargs;
  v42.m_object = p_m_login_menu_ui->m_object;
  dst[v41] = 0;
  survarium::flash_movie::CreateObject(
    v43,
    (survarium::flash_value *)v42.m_object->m_lods[0].m_template.m_object,
    (Scaleform::GFx::Value *)v48[0].m_object);
  v49.m_object = (vostok::particle::particle_system_instance_impl *)survarium::login_labels;
  v50.m_object = (survarium::pure_game_effect_emitter_base *)13;
  do
  {
    *(_DWORD *)v53.body = 0;
    *(_DWORD *)&v53.body[4] = 0;
    survarium::text_translator::translate_text(
      v44,
      (int)&v52->m_game->m_text_translator,
      (char *)v49.m_object->type,
      v62);
    survarium::flash_value::SetString(&v53, v62);
    survarium::flash_value::SetMember(v45, &pargs, (const char *)v49.m_object->__vftable, &v53);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v53);
    v49.m_object = (vostok::particle::particle_system_instance_impl *)((char *)v49.m_object + 8);
    --v50.m_object;
  }
  while ( v50.m_object );
  *(_DWORD *)v61.body = 0;
  *(_DWORD *)&v61.body[4] = 0;
  survarium::flash_value::SetString(&v61, dst);
  survarium::flash_value::SetMember(v46, &pargs, "EULA", &v61);
  Scaleform::GFx::Movie::Invoke(
    (Scaleform::GFx::Movie *)p_m_login_menu_ui->m_object->m_lods[0].m_template.m_object->type,
    "root.set_localization_data",
    0,
    &pargs,
    1u);
  survarium::game::on_queried_by_network_client_scene_ready((survarium::game *)1, v52->m_game);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v61);
  Scaleform::GFx::Value::~Value(&pargs);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v47,
    (int)v56);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v51);
  Scaleform::GFx::Value::~Value(&value);
}
