vostok::animation::animation_types_enum __thiscall vostok::animation::single_animation::type(
        vostok::animation::single_animation *this)
{
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v1; // ecx
  vostok::animation::animation_types_enum v2; // esi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v4; // [esp-4h] [ebp-18h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+4h] [ebp-10h] BYREF
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> v6; // [esp+8h] [ebp-Ch] BYREF

  object.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &object,
    &this->m_animation);
  v4.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v4,
    &object);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v1,
    &v6.m_resource,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v4.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
  v2 = vostok::animation::cubic_spline_skeleton_animation::animation_type((vostok::animation::cubic_spline_skeleton_animation *)v6.m_data);
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>(&v6);
  return v2;
}
