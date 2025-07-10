vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base> *__thiscall vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
        vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base> *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base> *object)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this,
    (const vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)object);
  return this;
}
