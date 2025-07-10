void __thiscall vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *this,
        vostok::configs::binary_config *object)
{
  this->m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    this,
    object);
}
