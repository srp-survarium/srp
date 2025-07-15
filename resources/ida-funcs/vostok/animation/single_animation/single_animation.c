void __thiscall vostok::animation::single_animation::single_animation(
        vostok::animation::single_animation *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> animation,
        vostok::animation::base_interpolator *interpolator,
        unsigned int a4)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, animation.m_object, fs_iterator_class);
  animation.m_object->__vftable = (vostok::resources::managed_resource_vtbl *)&vostok::animation::single_animation::`vftable';
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&animation.m_object[1].m_reconstruction_size,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&interpolator);
  *(&animation.m_object[1].m_reconstruction_size + 1) = a4;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&interpolator);
}
