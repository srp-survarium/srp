vostok::fs_new::path_part_iterator *__thiscall vostok::fs_new::path_string_impl::begin_part(
        vostok::fs_new::path_string_impl *this,
        vostok::fs_new::path_part_iterator *result,
        vostok::fs_new::include_empty_string_in_iteration_bool include)
{
  char m_separator; // [esp+7h] [ebp-9h]
  unsigned int v6; // [esp+8h] [ebp-8h]
  const char *v7; // [esp+Ch] [ebp-4h]

  m_separator = this->m_separator;
  v6 = vostok::fs_new::path_string_impl::length(this);
  v7 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
  result->m_include_empty_string_in_iteration = include;
  result->m_separator = m_separator;
  result->m_path_str = v7;
  result->m_path_end = &v7[v6];
  result->m_cur_str = v7;
  result->m_cur_end = v7;
  vostok::fs_new::path_part_iterator::operator++(result);
  return result;
}
