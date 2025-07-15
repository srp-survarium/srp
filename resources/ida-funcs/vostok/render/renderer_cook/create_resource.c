void __thiscall vostok::render::renderer_cook::create_resource(
        vostok::render::renderer_cook *this,
        vostok::render::engine::world *in_out_query,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::resources::query_result_for_cook *v4; // edi
  vostok::configs::binary_config *m_data; // esi
  vostok::resources::query_result_for_cook *v6; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp-Ch] [ebp-18h] BYREF
  const vostok::resources::memory_type *v8; // [esp-8h] [ebp-14h]
  unsigned int v9; // [esp-4h] [ebp-10h]
  int v10; // [esp+8h] [ebp-4h]

  v4 = (vostok::resources::query_result_for_cook *)in_out_query;
  v10 = 0;
  vostok::variant<32>::try_get<vostok::render::engine::world *>((vostok::variant<32> *)this, &in_out_query);
  vostok::render::engine::world::reset_renderer(in_out_query, 1);
  m_data = (vostok::configs::binary_config *)in_out_unmanaged_resource_buffer.m_data;
  if ( in_out_unmanaged_resource_buffer.m_data )
  {
    vostok::resources::unmanaged_resource::unmanaged_resource(
      (vostok::resources::unmanaged_resource *)in_out_unmanaged_resource_buffer.m_data,
      1u);
    m_data->__vftable = (vostok::configs::binary_config_vtbl *)&vostok::render::renderer_cook::renderer_resource::`vftable';
  }
  else
  {
    m_data = 0;
  }
  v9 = 264;
  v8 = &vostok::resources::nocache_memory;
  v7.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v7,
    m_data);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v4,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v7.m_object,
    v8,
    v9);
  vostok::resources::query_result_for_cook::finish_query_impl(v6, result_success, assert_on_fail_true, error_type_unset);
}
