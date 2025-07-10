void __thiscall vostok::particle::particle_world::play(
        vostok::particle::particle_world *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> instance,
        const vostok::math::float4x4 *transform,
        bool use_transform,
        bool always_loop)
{
  vostok::particle::particle_system_instance_impl *impl; // [esp+Ch] [ebp-4h]

  impl = (vostok::particle::particle_system_instance_impl *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&instance);
  if ( impl )
  {
    vostok::particle::particle_system_instance_impl::reset(impl);
    if ( use_transform )
      vostok::particle::particle_system_instance_impl::play_impl(impl, this, transform);
    else
      vostok::particle::particle_system_instance_impl::play_impl(impl, this);
    impl->m_always_looping = always_loop;
    this->add_particle_system_instance(this, impl);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&instance);
  }
  else
  {
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&instance);
  }
}
