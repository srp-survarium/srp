void __thiscall survarium::game_options::on_resources_ready(
        survarium::game_options *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *p_m_options_ui; // ebx
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v4; // eax
  survarium::flash_movie *v5; // ecx
  unsigned int type; // ecx
  unsigned int v7; // ecx
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v8; // esi
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v9; // eax
  survarium::flash_movie *v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  int v13; // edi
  survarium::flash_movie *v14; // ecx
  survarium::game_options *v15; // ecx
  survarium::game_options *v16; // ecx
  survarium::options_tab *v17; // ecx
  int *v18; // esi
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v19; // [esp+24h] [ebp-Ch] BYREF
  int v20; // [esp+28h] [ebp-8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v21; // [esp+2Ch] [ebp-4h] BYREF

  v20 = (int)this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v19,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  p_m_options_ui = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_options_ui;
  v4 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>((const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v19, &v21);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    v4,
    p_m_options_ui);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v21);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19);
  survarium::flash_movie::SetBackgroundAlpha(v5, (int)p_m_options_ui->m_object->m_lods[0].m_template.m_object);
  type = p_m_options_ui->m_object->m_lods[0].m_template.m_object->type;
  (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)type + 60))(type, 5);
  v7 = p_m_options_ui->m_object->m_lods[0].m_template.m_object->type;
  (*(void (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)v7 + 52))(v7, 0);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v19,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[1].m_unmanaged_resource);
  v8 = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(v20 + 16);
  v9 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>((const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v19, &v21);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    v9,
    v8);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v21);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19);
  survarium::flash_movie::SetBackgroundAlpha(v10, (int)v8->m_object->m_lods[0].m_template.m_object);
  v11 = v8->m_object->m_lods[0].m_template.m_object->type;
  (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)v11 + 60))(v11, 5);
  v12 = v8->m_object->m_lods[0].m_template.m_object->type;
  (*(void (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)v12 + 52))(v12, 0);
  v13 = v20;
  survarium::flash_movie::SetExternalInterface(
    (survarium::flash_movie *)p_m_options_ui->m_object->m_lods[0].m_template.m_object,
    (survarium::flash_external_handler *)(v20 + 4));
  survarium::flash_movie::SetExternalInterface(
    (survarium::flash_movie *)v8->m_object->m_lods[0].m_template.m_object,
    (survarium::flash_external_handler *)(v13 + 4));
  survarium::flash_movie::Advance(v14, (int)p_m_options_ui->m_object->m_lods[0].m_template.m_object, 0.1, 0);
  survarium::game_options::fill_labels(v15, v13);
  survarium::game_options::fill_settings_data(v16, v13);
  v18 = (int *)(v13 + 20);
  v20 = 4;
  do
  {
    survarium::options_tab::initialize_data(
      v17,
      *v18++,
      (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)p_m_options_ui);
    --v20;
  }
  while ( v20 );
  survarium::game_options::initialize_bindings((survarium::game_options *)v17, v13);
}
