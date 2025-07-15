void __thiscall vostok::logging::node::set(
        vostok::logging::node *this,
        char *initiator_path,
        int verbosity,
        unsigned int thread_id,
        vostok::logging::base_allocator *allocator,
        vostok::logging::base_allocator *allocator_to_clean)
{
  const char *v6; // edi
  int v8; // eax
  boost::intrusive::multiset_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0> > *v9; // ecx
  boost::intrusive::multiset<vostok::logging::node_base,boost::intrusive::member_hook<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,boost::intrusive::compare<vostok::logging::compare_nodes>,boost::intrusive::constant_time_size<0>,boost::intrusive::none> *p_m_children; // edi
  vostok::logging::node *v11; // esi
  vostok::logging::base_allocator *v12; // ebx
  int v13; // eax
  boost::intrusive::multiset_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0> > *v14; // ecx
  vostok::logging::node *v15; // eax
  bool v16; // zf
  char _Dst[32]; // [esp+8h] [ebp-24h] BYREF
  int v18; // [esp+28h] [ebp-4h]

  v6 = initiator_path;
  if ( initiator_path && *initiator_path )
  {
    strchr(initiator_path, 0x3Au);
    v18 = v8;
    if ( v8 )
      strncpy_s(_Dst, 0x20u, v6, v8 - (_DWORD)v6);
    else
      strcpy_s(_Dst, 0x20u, v6);
    p_m_children = &this->m_children;
    boost::intrusive::multiset_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>::find<char [32],vostok::logging::compare_nodes>(
      v9,
      &this->m_children.tree_.data_.node_plus_pred_.header_plus_size_.header_,
      (boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0> >,0> *)&initiator_path,
      (const char (*)[32])_Dst,
      (vostok::logging::compare_nodes)verbosity);
    v11 = (vostok::logging::node *)initiator_path;
    v12 = allocator;
    if ( initiator_path == (char *)p_m_children )
    {
      v13 = allocator->allocate(allocator, 72);
      v11 = 0;
      if ( v13 )
      {
        vostok::logging::node::node((vostok::logging::node *)_Dst, v13, _Dst, invalid);
        v11 = v15;
      }
      boost::intrusive::multiset_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>::insert(
        v14,
        &p_m_children->tree_.data_.node_plus_pred_.header_plus_size_.header_,
        (boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0> >,0> *)&initiator_path,
        v11);
    }
    vostok::logging::node::set(v11, v18 != 0 ? (char *)(v18 + 1) : 0, verbosity, thread_id, v12, allocator_to_clean);
  }
  else
  {
    v16 = (verbosity & 0x100) == 0;
    this->m_verbosity = verbosity & 0xFFFFFEFF;
    this->m_thread_id = thread_id;
    if ( v16 )
      vostok::logging::node::clean(this, allocator_to_clean);
  }
}
