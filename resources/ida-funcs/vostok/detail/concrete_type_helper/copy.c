void __thiscall vostok::detail::concrete_type_helper<void *>::copy(
        vostok::detail::concrete_type_helper<vostok::physics::world *> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  *(_DWORD *)dest_buffer.m_data = *(_DWORD *)src_buffer.m_data;
}


void __thiscall vostok::detail::concrete_type_helper<vostok::collision::animated_object_cook_data>::copy(
        vostok::detail::concrete_type_helper<vostok::collision::animated_object_cook_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  char *m_data; // eax
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v4; // ebx

  m_data = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    *((_DWORD *)dest_buffer.m_data + 1) = 0;
    m_data = dest_buffer.m_data;
  }
  v4 = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)m_data;
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)src_buffer.m_data,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)m_data);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)src_buffer.m_data
  + 1,
    v4 + 1);
}


void __thiscall vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data>::copy(
        vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *m_data; // eax

  m_data = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *((_DWORD *)dest_buffer.m_data + 1) = 0;
    m_data = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)dest_buffer.m_data;
  }
  m_data->m_object = *(vostok::particle::particle_system_instance_impl **)src_buffer.m_data;
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)src_buffer.m_data
  + 1,
    m_data + 1);
}


void __thiscall vostok::detail::concrete_type_helper<survarium::booby_trap_core_query_data>::copy(
        vostok::detail::concrete_type_helper<survarium::booby_trap_core_query_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  if ( dest_buffer.m_data )
    *(_DWORD *)dest_buffer.m_data = 0;
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)src_buffer.m_data,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)dest_buffer.m_data);
  *((_DWORD *)dest_buffer.m_data + 1) = *((_DWORD *)src_buffer.m_data + 1);
  *((_DWORD *)dest_buffer.m_data + 2) = *((_DWORD *)src_buffer.m_data + 2);
}


void __thiscall vostok::detail::concrete_type_helper<survarium::grenade_cook_data>::copy(
        vostok::detail::concrete_type_helper<survarium::grenade_cook_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  if ( dest_buffer.m_data )
    *(_DWORD *)dest_buffer.m_data = 0;
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)src_buffer.m_data,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)dest_buffer.m_data);
  *((_DWORD *)dest_buffer.m_data + 1) = *((_DWORD *)src_buffer.m_data + 1);
}


void __thiscall vostok::detail::concrete_type_helper<survarium::grenade_set_cook_data>::copy(
        vostok::detail::concrete_type_helper<survarium::anomaly_cook_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  *(_DWORD *)dest_buffer.m_data = *(_DWORD *)src_buffer.m_data;
  *((_DWORD *)dest_buffer.m_data + 1) = *((_DWORD *)src_buffer.m_data + 1);
}


void __thiscall vostok::detail::concrete_type_helper<vostok::render::output_window_configuration>::copy(
        vostok::detail::concrete_type_helper<vostok::render::output_window_configuration> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    *((_DWORD *)dest_buffer.m_data + 1) = 0;
    *((_DWORD *)dest_buffer.m_data + 2) = 0;
    *((_DWORD *)dest_buffer.m_data + 3) = 0;
    dest_buffer.m_data[16] = 0;
    dest_buffer.m_data[17] = 1;
  }
  qmemcpy(dest_buffer.m_data, src_buffer.m_data, 0x14u);
}


void __thiscall vostok::detail::concrete_type_helper<survarium::player_initial_info>::copy(
        vostok::detail::concrete_type_helper<survarium::player_initial_info> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    dest_buffer.m_data[4] = -1;
    *((_DWORD *)dest_buffer.m_data + 2) = 0;
    dest_buffer.m_data[16] = 0;
  }
  qmemcpy(dest_buffer.m_data, src_buffer.m_data, 0x14u);
}


void __thiscall vostok::detail::concrete_type_helper<survarium::player_respawn_rule_query_data>::copy(
        vostok::detail::concrete_type_helper<vostok::sound::sound_scene_creation_params> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  *(_DWORD *)dest_buffer.m_data = *(_DWORD *)src_buffer.m_data;
  *((_DWORD *)dest_buffer.m_data + 1) = *((_DWORD *)src_buffer.m_data + 1);
  *((_DWORD *)dest_buffer.m_data + 2) = *((_DWORD *)src_buffer.m_data + 2);
}


void __thiscall vostok::detail::concrete_type_helper<survarium::pvp_match_core_query_user_data>::copy(
        vostok::detail::concrete_type_helper<survarium::pvp_match_core_query_user_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  qmemcpy(dest_buffer.m_data, src_buffer.m_data, 0x18u);
}


void __thiscall vostok::detail::concrete_type_helper<vostok::render::render_texture_cook_parameters>::copy(
        vostok::detail::concrete_type_helper<vostok::render::render_texture_cook_parameters> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  *(_DWORD *)dest_buffer.m_data = *(_DWORD *)src_buffer.m_data;
  *((_DWORD *)dest_buffer.m_data + 1) = *((_DWORD *)src_buffer.m_data + 1);
  *((_DWORD *)dest_buffer.m_data + 2) = *((_DWORD *)src_buffer.m_data + 2);
  *((_DWORD *)dest_buffer.m_data + 3) = *((_DWORD *)src_buffer.m_data + 3);
}


void __thiscall vostok::detail::concrete_type_helper<vostok::render::scene_configuration>::copy(
        vostok::detail::concrete_type_helper<vostok::render::scene_configuration> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  char *m_data; // eax

  m_data = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *dest_buffer.m_data &= 0xC0u;
    m_data = dest_buffer.m_data;
  }
  *m_data = *src_buffer.m_data;
}


void __thiscall vostok::detail::concrete_type_helper<vostok::render::static_model_instance_user_data>::copy(
        vostok::detail::concrete_type_helper<vostok::render::static_model_instance_user_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_data; // ecx

  m_data = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *((_DWORD *)dest_buffer.m_data + 2) = 0;
    m_data = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)dest_buffer.m_data;
  }
  m_data->m_object = *(vostok::resources::unmanaged_resource **)src_buffer.m_data;
  m_data[1].m_object = *(vostok::resources::unmanaged_resource **)(src_buffer.m_data + 4);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)src_buffer.m_data
  + 2,
    m_data + 2);
}


void __thiscall vostok::detail::concrete_type_helper<survarium::weapon_cook_data>::copy(
        vostok::detail::concrete_type_helper<survarium::weapon_cook_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  char *m_data; // eax

  m_data = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    dest_buffer.m_data[4] = 0;
    m_data = dest_buffer.m_data;
  }
  *(_DWORD *)m_data = *(_DWORD *)src_buffer.m_data;
  *((_DWORD *)dest_buffer.m_data + 1) = *((_DWORD *)src_buffer.m_data + 1);
}


void __thiscall vostok::detail::concrete_type_helper<vostok::configs::binary_config_value>::copy(
        vostok::detail::concrete_type_helper<vostok::configs::binary_config_value> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  if ( dest_buffer.m_data )
    vostok::configs::binary_config_value::binary_config_value(
      (vostok::configs::binary_config_value *)this,
      (int)dest_buffer.m_data);
  vostok::configs::binary_config_value::operator=(
    (vostok::configs::binary_config_value *)src_buffer.m_data,
    (vostok::configs::binary_config_value *)dest_buffer.m_data);
}
