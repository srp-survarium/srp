int __thiscall vostok::render::texture_storage::total_allocated_memory(vostok::render::texture_storage *this)
{
  stlp_std::priv::_Rb_tree_node_base *M_left; // eax
  vostok::render::map<vostok::render::texture_pool_key,vostok::render::texture_pool *,stlp_std::less<vostok::render::texture_pool_key> > *p_m_pools; // edi
  int i; // ebx
  stlp_std::priv::_Rb_tree_node_base *v4; // ecx
  stlp_std::priv::_Rb_tree_node_base *M_parent; // edx
  stlp_std::priv::_Rb_tree_node_base *v6; // ecx
  int v7; // esi

  M_left = this->m_pools._M_t._M_header._M_data._M_left;
  p_m_pools = &this->m_pools;
  for ( i = 0;
        M_left != (stlp_std::priv::_Rb_tree_node_base *)p_m_pools;
        M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left) )
  {
    v4 = M_left[2]._M_left;
    M_parent = v4[6]._M_parent;
    v6 = v4[6]._M_left;
    v7 = 0;
    while ( M_parent != v6 )
    {
      v7 += (int)M_parent->_M_parent;
      M_parent = (stlp_std::priv::_Rb_tree_node_base *)((char *)M_parent + 12);
    }
    i += v7;
  }
  return i;
}
