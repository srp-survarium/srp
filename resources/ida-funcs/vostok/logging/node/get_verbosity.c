vostok::logging::verbosity __userpurge vostok::logging::node::get_verbosity@<eax>(
        vostok::logging::node *this@<eax>,
        vostok::logging::path_parts *path@<esi>,
        vostok::logging::verbosity inherited_verbosity)
{
  char *m_current_element; // ebx
  boost::intrusive::multiset<vostok::logging::node_base,boost::intrusive::member_hook<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,boost::intrusive::compare<vostok::logging::compare_nodes>,boost::intrusive::constant_time_size<0>,boost::intrusive::none> *p_m_children; // edi
  const char *v7; // eax
  const char *v8; // eax
  char *key; // [esp+8h] [ebp-8h] BYREF
  vostok::logging::compare_nodes comp[4]; // [esp+Ch] [ebp-4h] BYREF
  vostok::logging::verbosity m_verbosity; // [esp+18h] [ebp+8h]

  while ( 1 )
  {
    if ( this->m_thread_id == -1 || this->m_thread_id == GetCurrentThreadId() )
    {
      m_verbosity = this->m_verbosity;
      if ( m_verbosity == invalid )
        m_verbosity = inherited_verbosity;
    }
    else
    {
      m_verbosity = silent;
    }
    m_current_element = (char *)path->m_current_element;
    key = m_current_element;
    if ( !m_current_element )
      break;
    if ( !*m_current_element )
      break;
    p_m_children = &this->m_children;
    boost::intrusive::multiset_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>::find<char const *,vostok::logging::compare_nodes>(
      p_m_children,
      &key,
      (boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0> >,1> *)comp,
      m_verbosity);
    if ( *(boost::intrusive::multiset<vostok::logging::node_base,boost::intrusive::member_hook<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,boost::intrusive::compare<vostok::logging::compare_nodes>,boost::intrusive::constant_time_size<0>,boost::intrusive::none> **)comp == p_m_children )
      break;
    strchr(m_current_element, 0x3Au);
    path->m_current_element = v7;
    if ( !v7 || (v8 = v7 + 1, !*v8) )
      v8 = path->m_parts.m_begin[++path->m_index];
    inherited_verbosity = m_verbosity;
    this = *(vostok::logging::node **)comp;
    path->m_current_element = v8;
  }
  return m_verbosity;
}
