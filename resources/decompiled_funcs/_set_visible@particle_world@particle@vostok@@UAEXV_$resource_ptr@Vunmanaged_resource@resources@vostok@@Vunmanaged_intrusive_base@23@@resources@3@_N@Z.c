void __thiscall vostok::particle::particle_world::set_visible(
        vostok::particle::particle_world *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> particle_system_instance,
        bool is_visible)
{
  vostok::particle::particle_system_instance_impl *instance; // [esp+Ch] [ebp-4h]

  instance = (vostok::particle::particle_system_instance_impl *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&particle_system_instance);
  vostok::particle::particle_system_instance_impl::set_visible(instance, is_visible);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&particle_system_instance);
}
