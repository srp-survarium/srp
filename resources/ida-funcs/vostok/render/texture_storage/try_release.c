char __thiscall vostok::render::texture_storage::try_release(
        vostok::render::texture_storage *this,
        ID3D11Resource *in_hw_texture)
{
  stlp_std::priv::_Rb_tree_node_base *M_left; // eax
  vostok::render::map<vostok::render::texture_pool_key,vostok::render::texture_pool *,stlp_std::less<vostok::render::texture_pool_key> > *p_m_pools; // esi
  stlp_std::priv::_Rb_tree_node_base *v4; // edx
  stlp_std::priv::_Rb_tree_node_base *M_parent; // ecx
  stlp_std::priv::_Rb_tree_node_base *v6; // edx

  M_left = this->m_pools._M_t._M_header._M_data._M_left;
  p_m_pools = &this->m_pools;
LABEL_8:
  if ( M_left == (stlp_std::priv::_Rb_tree_node_base *)p_m_pools )
    return 0;
  v4 = M_left[2]._M_left;
  M_parent = v4[6]._M_parent;
  v6 = v4[6]._M_left;
  while ( 1 )
  {
    if ( M_parent == v6 )
    {
      M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left);
      goto LABEL_8;
    }
    if ( *(ID3D11Resource **)&M_parent->_M_color == in_hw_texture && LOBYTE(M_parent->_M_left) )
      break;
    M_parent = (stlp_std::priv::_Rb_tree_node_base *)((char *)M_parent + 12);
  }
  LOBYTE(M_parent->_M_left) = 0;
  BYTE1(M_parent->_M_left) = 0;
  BYTE2(M_parent->_M_left) = 0;
  return 1;
}
