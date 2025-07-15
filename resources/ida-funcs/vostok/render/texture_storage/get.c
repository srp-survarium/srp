ID3D11Resource *__userpurge vostok::render::texture_storage::get@<eax>(
        vostok::render::texture_storage *this@<ecx>,
        int a2@<eax>,
        const vostok::render::texture_pool_key *key,
        bool allocate_new_if_all_occupied)
{
  stlp_std::priv::_Rb_tree_node_base *v4; // edi
  stlp_std::priv::_Rb_tree_node_base *v5; // eax
  stlp_std::priv::_Rb_tree_node_base *M_left; // ecx
  stlp_std::priv::_Rb_tree_node_base *M_parent; // eax
  stlp_std::priv::_Rb_tree_node_base *v8; // ecx

  v4 = (stlp_std::priv::_Rb_tree_node_base *)(a2 + 4);
  v5 = stlp_std::priv::_Rb_tree<vostok::render::texture_pool_key,stlp_std::less<vostok::render::texture_pool_key>,stlp_std::pair<vostok::render::texture_pool_key const,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::texture_pool_key const,vostok::render::texture_pool *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::texture_pool_key const,vostok::render::texture_pool *>>,vostok::render::std_allocator<stlp_std::pair<vostok::render::texture_pool_key,vostok::render::texture_pool *>>>::_M_find<vostok::render::texture_pool_key>(
         (stlp_std::priv::_Rb_tree<vostok::render::texture_pool_key,stlp_std::less<vostok::render::texture_pool_key>,stlp_std::pair<vostok::render::texture_pool_key const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::texture_pool_key const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::texture_pool_key const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::texture_pool_key,vostok::render::texture_pool *> > > *)this,
         a2 + 4,
         key);
  if ( v5 != v4 )
  {
    M_left = v5[2]._M_left;
    M_parent = M_left[6]._M_parent;
    v8 = M_left[6]._M_left;
    while ( M_parent != v8 )
    {
      if ( !LOBYTE(M_parent->_M_left) && *(_DWORD *)&M_parent->_M_color )
      {
        LOBYTE(M_parent->_M_left) = 1;
        BYTE2(M_parent->_M_left) = 0;
        return *(ID3D11Resource **)&M_parent->_M_color;
      }
      M_parent = (stlp_std::priv::_Rb_tree_node_base *)((char *)M_parent + 12);
    }
  }
  return 0;
}
