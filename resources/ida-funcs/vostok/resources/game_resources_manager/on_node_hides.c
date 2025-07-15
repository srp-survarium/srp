void __thiscall vostok::resources::game_resources_manager::on_node_hides(
        vostok::resources::game_resources_manager *this,
        vostok::vfs::vfs_iterator *it)
{
  vostok::resources::resource_flags *m_object; // ecx
  vostok::resources::releasing_functionality *v4; // ecx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v5; // [esp+Ch] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> result; // [esp+10h] [ebp-8h] BYREF
  vostok::resources::game_resources_manager_data *p_m_data; // [esp+14h] [ebp-4h] BYREF

  vostok::resources::get_associated_unmanaged_resource_ptr(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&result,
    *it);
  vostok::resources::get_associated_managed_resource_ptr(&v5, *it);
  m_object = v5.m_object;
  if ( !v5.m_object
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_object = result.m_object;
  }
  if ( m_object )
  {
    if ( (vostok::resources::resource_flags::cast_base_of_intrusive_base(m_object)->m_flags.m_flags & 1) != 0 )
    {
      p_m_data = &this->m_data;
      vostok::resources::releasing_functionality::release_resource(
        v4,
        (vostok::resources::resource_base *)&p_m_data,
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v4);
    }
    vostok::resources::set_associated(*it, 0);
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
}
