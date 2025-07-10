void __thiscall survarium::scaleform_movie_cook::on_raw_data_loaded(
        survarium::scaleform_movie_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::resources::unmanaged_resource *v4; // eax
  vostok::resources::resource_base *v5; // ecx
  vostok::configs::binary_config *v6; // esi
  vostok::fs_new::virtual_path_string *v7; // eax
  survarium::flash_movie *v8; // eax
  vostok::resources::query_result_for_cook *v9; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp-Ch] [ebp-140h] BYREF
  const vostok::resources::memory_type *v11; // [esp-8h] [ebp-13Ch]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v12; // [esp-4h] [ebp-138h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+Ch] [ebp-128h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> raw_data; // [esp+10h] [ebp-124h] BYREF
  vostok::resources::pinned_ptr_const<unsigned char> pinned; // [esp+14h] [ebp-120h] BYREF
  vostok::fs_new::virtual_path_string result; // [esp+20h] [ebp-114h] BYREF

  raw_data.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &raw_data,
    &data->m_queries[0].m_managed_resource);
  object.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &object,
    &raw_data);
  v12.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v12,
    &object);
  vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
    &pinned,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v12.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
  v4 = (vostok::resources::unmanaged_resource *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                  (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                                  0x110u);
  v6 = (vostok::configs::binary_config *)v4;
  if ( v4 )
  {
    vostok::resources::unmanaged_resource::unmanaged_resource(v4, 1u);
    v6->__vftable = (vostok::configs::binary_config_vtbl *)&survarium::flash_movie_resource::`vftable';
  }
  else
  {
    v6 = 0;
  }
  v7 = vostok::resources::resource_base::reusable_request_name(v5, &result);
  v8 = survarium::flash_factory::build_movie(
         (survarium::flash_factory *)pinned.m_size,
         &this->m_factory->m_gfx_loader,
         (void *)pinned.m_data,
         pinned.m_size,
         v7->m_string.m_begin);
  v12.m_object = (vostok::resources::managed_resource *)272;
  v11 = &vostok::resources::nocache_memory;
  v6->m_root = (vostok::configs::binary_config_value *)v8;
  v10.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v10,
    v6);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    parent,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v10.m_object,
    v11,
    (unsigned int)v12.m_object);
  vostok::resources::query_result_for_cook::finish_query_impl(v9, result_success, assert_on_fail_true, error_type_unset);
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pinned);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&raw_data);
}
