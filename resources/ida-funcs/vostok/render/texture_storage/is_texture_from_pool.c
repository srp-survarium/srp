char __thiscall vostok::render::texture_storage::is_texture_from_pool(
        vostok::render::texture_storage *this,
        ID3D11Resource *in_hw_texture)
{
  stlp_std::priv::_Rb_tree_node_base *M_left; // eax
  vostok::render::map<vostok::render::texture_pool_key,vostok::render::texture_pool *,stlp_std::less<vostok::render::texture_pool_key> > *p_m_pools; // esi
  stlp_std::priv::_Rb_tree_node_base *v4; // ecx
  ID3D11Resource **M_parent; // edx
  ID3D11Resource **v6; // ecx

  M_left = this->m_pools._M_t._M_header._M_data._M_left;
  p_m_pools = &this->m_pools;
LABEL_7:
  if ( M_left == (stlp_std::priv::_Rb_tree_node_base *)p_m_pools )
    return 0;
  v4 = M_left[2]._M_left;
  M_parent = (ID3D11Resource **)v4[6]._M_parent;
  v6 = (ID3D11Resource **)v4[6]._M_left;
  while ( 1 )
  {
    if ( M_parent == v6 )
    {
      M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(M_left);
      goto LABEL_7;
    }
    if ( *M_parent == in_hw_texture )
      return 1;
    M_parent += 3;
  }
}
