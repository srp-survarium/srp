void __thiscall vostok::render::resource_manager::reload_all_textures(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *thisa)
{
  stlp_std::priv::_Rb_tree_node_base *M_left; // esi
  vostok::fs_new::virtual_path_string *M_start; // ecx
  vostok::fs_new::virtual_path_string *M_finish; // edi
  vostok::resources::query_result_for_cook **v5; // esi
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::vector<vostok::fs_new::virtual_path_string> texture_names_to_load; // [esp+14h] [ebp-Ch] BYREF

  M_left = thisa->m_texture_registry._M_t._M_header._M_data._M_left;
  M_start = 0;
  M_finish = 0;
  memset(&texture_names_to_load, 0, sizeof(texture_names_to_load));
  if ( M_left != (stlp_std::priv::_Rb_tree_node_base *)&thisa->m_texture_registry )
  {
    do
    {
      if ( M_left[1]._M_parent != *(stlp_std::priv::_Rb_tree_node_base **)&M_left[1]._M_color
        && vostok::fs_new::path_string_impl::operator[]((vostok::fs_new::path_string_impl *)&M_left[1], 0) != 36 )
      {
        stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>::push_back(
          (const stlp_std::__false_type *)&M_left[1],
          &texture_names_to_load._M_impl,
          &texture_names_to_load._M_impl);
      }
      M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left);
    }
    while ( M_left != (stlp_std::priv::_Rb_tree_node_base *)&thisa->m_texture_registry );
    M_finish = texture_names_to_load._M_impl._M_finish;
    M_start = texture_names_to_load._M_impl._M_start;
  }
  v5 = (vostok::resources::query_result_for_cook **)M_start;
  if ( M_start != M_finish )
  {
    do
    {
      vostok::render::resource_manager::load_texture(
        (vostok::render::resource_manager *)M_start,
        thisa,
        *v5,
        0,
        0,
        0,
        1,
        1,
        0xFFFFFFFF);
      v5 += 69;
    }
    while ( v5 != (vostok::resources::query_result_for_cook **)M_finish );
    M_start = texture_names_to_load._M_impl._M_start;
  }
  s_reload_all_textures = 0;
  if ( M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
}
