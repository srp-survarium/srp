void __thiscall vostok::particle::particle_world::stop(
        vostok::particle::particle_world *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> instance,
        float time)
{
  vostok::particle::particle_system_instance_impl *impl; // [esp+10h] [ebp-4h]

  impl = (vostok::particle::particle_system_instance_impl *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&instance);
  vostok::particle::particle_system_instance_impl::stop_impl(impl, time);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&instance);
}
