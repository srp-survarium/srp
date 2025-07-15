void __thiscall survarium::booby_trap_set::draw(survarium::booby_trap_set *this)
{
  int v2; // eax
  int v3; // ecx
  bool v4; // al
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v5; // eax
  vostok::particle::particle_system_instance_impl *v6; // eax
  vostok::resources::resource_reconstruction_info *v7; // edi
  vostok::particle::particle_system_instance_impl *m_object; // edi
  int m_reconstruction_info_actuality_tick_high; // eax
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> object; // [esp+Ch] [ebp-44h] BYREF
  vostok::math::float4x4 v11; // [esp+10h] [ebp-40h] BYREF

  v2 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&this[-1].m_damage_parameters.m_end[13].body_part[12] + 12))(*(_DWORD *)&this[-1].m_damage_parameters.m_end[13].body_part[12]);
  v4 = 0;
  if ( *((_BYTE *)&this->m_reconstruction_size + 4) )
  {
    if ( LOWORD(this[-1].m_config.max_slope_cos) )
    {
      v3 = *(_DWORD *)(v2 + 320);
      if ( *(_BYTE *)(v3 + 14) )
      {
        if ( *(_BYTE *)(v2 + 764)
          && survarium::base_network_client::is_player_current(
               (survarium::base_network_client *)v3,
               *(_DWORD *)(*(_DWORD *)(this->m_reconstruction_size + 160) + 13912),
               *(_BYTE *)(v2 + 304)) )
        {
          v4 = 1;
        }
      }
    }
  }
  *((_BYTE *)&this->m_reconstruction_size + 4) = v4;
  if ( v4 )
  {
    v7 = (vostok::resources::resource_reconstruction_info *)(&this->vostok::resources::resource_flags + 1);
    if ( !survarium::booby_trap_set_core::get_visible_place_transform(
            (survarium::booby_trap_set_core *)v3,
            (vostok::math::float4x4 *)&this[-1].vostok::uid_object<vostok::resources::resource_children>,
            &v11) )
      v7 = &this->vostok::resources::resource_reconstruction_info;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &object,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v7);
    m_object = object.m_object;
    m_reconstruction_info_actuality_tick_high = HIDWORD(this->m_reconstruction_info_actuality_tick);
    if ( (vostok::particle::particle_system_instance_impl *)m_reconstruction_info_actuality_tick_high == object.m_object )
    {
      vostok::render::scene_renderer::update_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(m_reconstruction_info_actuality_tick_high + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(this->m_reconstruction_size + 160) + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(this->m_reconstruction_size + 4),
        &v11,
        &v11);
    }
    else
    {
      if ( m_reconstruction_info_actuality_tick_high
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        vostok::render::scene_renderer::remove_model(
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(m_reconstruction_info_actuality_tick_high + 264),
          *(vostok::render::scene_renderer **)((char *)&dword_200060
                                             + *(_DWORD *)(*(_DWORD *)(this->m_reconstruction_size + 160) + 172)),
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(this->m_reconstruction_size + 4));
      }
      vostok::render::scene_renderer::add_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)m_object->m_lods,
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(this->m_reconstruction_size + 160) + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(this->m_reconstruction_size + 4),
        &v11,
        &v11);
      vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
        &object,
        (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_reconstruction_info_actuality_tick
      + 1);
    }
  }
  else
  {
    v5 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)HIDWORD(this->m_reconstruction_info_actuality_tick);
    if ( v5
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::render::scene_renderer::remove_model(
        v5 + 66,
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(this->m_reconstruction_size + 160) + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(this->m_reconstruction_size + 4));
    }
    v6 = (vostok::particle::particle_system_instance_impl *)HIDWORD(this->m_reconstruction_info_actuality_tick);
    HIDWORD(this->m_reconstruction_info_actuality_tick) = 0;
    object.m_object = v6;
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&object);
}
