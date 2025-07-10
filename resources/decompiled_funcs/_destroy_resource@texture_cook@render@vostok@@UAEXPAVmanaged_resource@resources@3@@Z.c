void __thiscall vostok::render::texture_cook::destroy_resource(
        vostok::render::texture_cook *this,
        vostok::resources::managed_resource *dying_resource)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v2; // [esp-4h] [ebp-10h] BYREF
  vostok::resources::pinned_ptr_mutable<vostok::render::texture_data_resource> managed_typed_ptr; // [esp+0h] [ebp-Ch] BYREF

  v2.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v2,
    dying_resource);
  vostok::resources::cook_base::pin_for_write<vostok::render::texture_data_resource>(
    (vostok::resources::cook_base *)&managed_typed_ptr,
    &managed_typed_ptr,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v2.m_object);
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&managed_typed_ptr);
}
