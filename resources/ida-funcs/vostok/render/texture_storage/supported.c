char __thiscall vostok::render::texture_storage::supported(
        vostok::render::texture_storage *this,
        stlp_std::priv::_Rb_tree_node_base *width,
        const unsigned int height,
        stlp_std::priv::_Rb_tree_node_base *array_size,
        stlp_std::priv::_Rb_tree_node_base *format)
{
  stlp_std::priv::_Rb_tree_node_base *M_left; // eax
  vostok::render::map<vostok::render::texture_pool_key,vostok::render::texture_pool *,stlp_std::less<vostok::render::texture_pool_key> > *p_m_pools; // esi
  stlp_std::priv::_Rb_tree_node_base *v7; // ecx

  M_left = this->m_pools._M_t._M_header._M_data._M_left;
  p_m_pools = &this->m_pools;
  while ( 1 )
  {
    if ( M_left == (stlp_std::priv::_Rb_tree_node_base *)p_m_pools )
      return 0;
    v7 = M_left[2]._M_left;
    if ( v7[5]._M_left == format
      && v7[4]._M_right == width
      && *(_DWORD *)&v7[5]._M_color == height
      && v7[5]._M_parent == array_size )
    {
      break;
    }
    M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left);
  }
  return 1;
}
