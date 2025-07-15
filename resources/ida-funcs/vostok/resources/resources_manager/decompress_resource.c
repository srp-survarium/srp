void __thiscall vostok::resources::resources_manager::decompress_resource(
        vostok::resources::resources_manager *this,
        vostok::resources::query_result *query)
{
  vostok::resources::query_result *v3; // ecx
  vostok::resources::query_result_for_cook **v4; // eax
  const char *v5; // esi
  unsigned int v6; // edi
  vostok::resources::query_result_for_cook *v7; // ecx
  vostok::resources::query_result *v8; // ecx
  vostok::threading::mutex *v9; // [esp-4h] [ebp-28h]
  vostok::resources::query_result_for_cook *v10; // [esp+Ch] [ebp-18h] BYREF
  vostok::const_buffer pinned_compressed_data; // [esp+14h] [ebp-10h] BYREF
  int v12; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int raw_file_size; // [esp+2Ch] [ebp+8h]

  vostok::resources::query_result::set_is_unmovable_if_needed(query->m_raw_managed_resource.m_object, 1);
  vostok::resources::query_result::pin_compressed_file(query, &pinned_compressed_data);
  v4 = vostok::resources::query_result::pin_raw_file(v3, &v10, query);
  v5 = (const char *)*v4;
  v6 = (unsigned int)v4[1];
  raw_file_size = vostok::resources::query_result_for_cook::get_raw_file_size(v7, query);
  if ( !((unsigned __int8 (__thiscall *)(vostok::ppmd_compressor *, const char *, unsigned int, const char *, unsigned int, int *))s_resources_manager_buffer.m_compressor.m_variable->decompress)(
          s_resources_manager_buffer.m_compressor.m_variable,
          pinned_compressed_data.m_data,
          pinned_compressed_data.m_size,
          v5,
          v6,
          &v12)
    || v12 != raw_file_size )
  {
    query->m_error_type = error_type_cannot_decompress_file;
  }
  vostok::resources::query_result::unpin_compressed_file(v8, &pinned_compressed_data);
  pinned_compressed_data.m_data = v5;
  pinned_compressed_data.m_size = v6;
  vostok::resources::query_result::unpin_raw_file(
    (vostok::resources::query_result *)&pinned_compressed_data,
    (int)query);
  vostok::resources::query_result::set_is_unmovable_if_needed(query->m_raw_managed_resource.m_object, 0);
  query->m_next_in_device_manager = 0;
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,624,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &s_resources_manager_buffer.m_decompressed_resources,
    query,
    v9);
}
