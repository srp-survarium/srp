void __thiscall vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>(
        vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr)
{
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v2; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v3; // [esp-4h] [ebp-Ch] BYREF

  v3.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v3,
    &ptr);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v2,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v3.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&ptr);
}
