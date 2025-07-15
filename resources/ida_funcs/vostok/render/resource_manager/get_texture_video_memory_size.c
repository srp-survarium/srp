unsigned int __thiscall vostok::render::resource_manager::get_texture_video_memory_size(
        vostok::render::resource_manager *this)
{
  stlp_std::priv::_Rb_tree_node_base *M_left; // eax
  vostok::render::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred> *p_m_texture_registry; // edi
  unsigned int i; // esi

  M_left = this->m_texture_registry._M_t._M_header._M_data._M_left;
  p_m_texture_registry = &this->m_texture_registry;
  for ( i = 0;
        M_left != (stlp_std::priv::_Rb_tree_node_base *)p_m_texture_registry;
        M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left) )
  {
    i += (unsigned int)M_left[18]._M_parent[3]._M_parent;
  }
  return i >> 20;
}
