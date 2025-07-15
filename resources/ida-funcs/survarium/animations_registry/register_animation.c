void __userpurge survarium::animations_registry::register_animation(
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *first_view@<eax>,
        survarium::animations_registry *this,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *third_view)
{
  vostok::buffer_vector<survarium::animations_registry::animations_tuple> *v3; // ecx
  survarium::animations_registry::animations_tuple v4; // [esp+8h] [ebp-Ch] BYREF

  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v4.first_view,
    first_view);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v4.third_view,
    third_view);
  v4.id = -1;
  vostok::buffer_vector<survarium::animations_registry::animations_tuple>::push_back(v3, (int)this, &v4);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v4.third_view);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v4.first_view);
}
