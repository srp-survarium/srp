stlp_std::priv::_Rb_tree_node_base *__userpurge vostok::render::texture_storage::has_free_space@<eax>(
        vostok::render::texture_storage *this@<ecx>,
        int a2@<eax>,
        const vostok::render::texture_pool_key *key)
{
  stlp_std::priv::_Rb_tree_node_base *v3; // edi
  stlp_std::priv::_Rb_tree_node_base *v4; // eax
  stlp_std::priv::_Rb_tree_node_base *M_left; // eax
  stlp_std::priv::_Rb_tree_node_base *M_parent; // ecx
  stlp_std::priv::_Rb_tree_node_base *v7; // eax

  v3 = (stlp_std::priv::_Rb_tree_node_base *)(a2 + 4);
  v4 = stlp_std::priv::_Rb_tree<vostok::render::texture_pool_key,stlp_std::less<vostok::render::texture_pool_key>,stlp_std::pair<vostok::render::texture_pool_key const,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::texture_pool_key const,vostok::render::texture_pool *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::texture_pool_key const,vostok::render::texture_pool *>>,vostok::render::std_allocator<stlp_std::pair<vostok::render::texture_pool_key,vostok::render::texture_pool *>>>::_M_find<vostok::render::texture_pool_key>(
         (stlp_std::priv::_Rb_tree<vostok::render::texture_pool_key,stlp_std::less<vostok::render::texture_pool_key>,stlp_std::pair<vostok::render::texture_pool_key const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::texture_pool_key const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::texture_pool_key const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::texture_pool_key,vostok::render::texture_pool *> > > *)this,
         a2 + 4,
         key);
  if ( v4 != v3 )
  {
    M_left = v4[2]._M_left;
    M_parent = M_left[6]._M_parent;
    v7 = M_left[6]._M_left;
    while ( M_parent != v7 )
    {
      if ( (!LOBYTE(M_parent->_M_left) || BYTE2(M_parent->_M_left)) && !BYTE1(M_parent->_M_left) )
        return M_parent;
      M_parent = (stlp_std::priv::_Rb_tree_node_base *)((char *)M_parent + 12);
    }
  }
  return 0;
}
