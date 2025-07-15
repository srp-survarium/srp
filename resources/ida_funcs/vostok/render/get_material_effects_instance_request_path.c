vostok::fs_new::virtual_path_string *__usercall vostok::render::get_material_effects_instance_request_path@<eax>(
        vostok::fs_new::path_string_impl *a1@<esi>,
        vostok::resources::unmanaged_resource *result)
{
  const char *v2; // eax

  a1->m_string.m_begin = a1->m_string.m_buffer;
  a1->m_string.m_end = a1->m_string.m_buffer;
  a1->m_string.m_max_end = &a1->m_separator;
  a1->m_string.m_buffer[0] = 0;
  a1->m_string.m_buffer[0] = 0;
  a1->m_separator = 47;
  if ( result
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v2 = (const char *)result[1].__vftable;
  }
  else
  {
    v2 = (const char *)&buf;
  }
  vostok::fs_new::path_string_impl::assignf(a1, "%s", v2);
  if ( result && !_InterlockedExchangeAdd(&result->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&result->vostok::resources::unmanaged_intrusive_base, result);
  return (vostok::fs_new::virtual_path_string *)a1;
}
