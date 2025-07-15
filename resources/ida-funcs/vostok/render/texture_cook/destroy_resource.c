void __thiscall vostok::render::texture_cook::destroy_resource(
        vostok::render::texture_cook *this,
        vostok::resources::managed_resource *dying_resource)
{
  vostok::resources::cook_base *v2; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v3; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v4; // [esp-4h] [ebp-18h] BYREF
  vostok::resources::pinned_ptr_mutable<vostok::render::texture_data_resource> result; // [esp+8h] [ebp-Ch] BYREF

  v4.m_object = (vostok::resources::managed_resource *)this;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v4,
    dying_resource);
  vostok::resources::cook_base::pin_for_write<vostok::render::texture_data_resource>(v2, &result, v4);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v3,
    (int)&result);
}
