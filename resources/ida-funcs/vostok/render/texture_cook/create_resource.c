void __thiscall vostok::render::texture_cook::create_resource(
        vostok::render::texture_cook *this,
        vostok::resources::query_result_for_cook *in_out_query,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> in_out_resource,
        unsigned int raw_file_size,
        unsigned int *out_final_resource_size)
{
  unsigned int v5; // ecx
  vostok::resources::query_result_for_cook *v6; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v7[3]; // [esp-4h] [ebp-18h] BYREF
  vostok::resources::pinned_ptr_mutable<vostok::render::texture_data_resource> managed_typed_ptr; // [esp+8h] [ebp-Ch] BYREF

  v7[2].m_object = 0;
  v7[0].m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    v7,
    &in_out_resource);
  vostok::resources::cook_base::pin_for_write<vostok::render::texture_data_resource>(
    (vostok::resources::cook_base *)&managed_typed_ptr,
    &managed_typed_ptr,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v7[0].m_object);
  v5 = raw_file_size;
  if ( managed_typed_ptr.m_data )
    *(_DWORD *)managed_typed_ptr.m_data = raw_file_size;
  v7[0].m_object = 0;
  v6 = (vostok::resources::query_result_for_cook *)(v5 + 4);
  *out_final_resource_size = (unsigned int)v6;
  vostok::resources::query_result_for_cook::finish_query_impl(
    v6,
    result_success,
    assert_on_fail_true,
    (vostok::resources::query_result_for_user::error_type_enum)v7[0].m_object);
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&managed_typed_ptr);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&in_out_resource);
}
