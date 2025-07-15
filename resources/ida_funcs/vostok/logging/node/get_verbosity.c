vostok::logging::verbosity __thiscall vostok::logging::node::get_verbosity(
        vostok::logging::node *this,
        vostok::logging::path_parts *path,
        vostok::logging::verbosity inherited_verbosity)
{
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  vostok::logging::verbosity m_verbosity; // [esp+0h] [ebp-68h]
  vostok::logging::verbosity v7; // [esp+4h] [ebp-64h]
  const vostok::variant<32> **v9; // [esp+24h] [ebp-44h]
  boost::intrusive::multiset<vostok::logging::node_base,boost::intrusive::member_hook<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,boost::intrusive::compare<vostok::logging::compare_nodes>,boost::intrusive::constant_time_size<0>,boost::intrusive::none> *v10; // [esp+28h] [ebp-40h] BYREF
  char v11; // [esp+2Fh] [ebp-39h]
  boost::intrusive::rbtree_node<void *> *header; // [esp+30h] [ebp-38h]
  boost::intrusive::rbtree_node<void *> *v13; // [esp+34h] [ebp-34h]
  boost::intrusive::detail::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0> > > comp; // [esp+38h] [ebp-30h]
  char v15; // [esp+47h] [ebp-21h]
  boost::intrusive::multiset<vostok::logging::node_base,boost::intrusive::member_hook<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,boost::intrusive::compare<vostok::logging::compare_nodes>,boost::intrusive::constant_time_size<0>,boost::intrusive::none> *p_m_children; // [esp+48h] [ebp-20h]
  const char *m_current_element; // [esp+4Ch] [ebp-1Ch]
  const vostok::variant<32> **v18; // [esp+50h] [ebp-18h]
  char v19; // [esp+57h] [ebp-11h]
  const vostok::logging::node *child; // [esp+58h] [ebp-10h]
  vostok::logging::verbosity verbosity; // [esp+5Ch] [ebp-Ch]
  const char *cur_part; // [esp+60h] [ebp-8h] BYREF
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0> >,1> it; // [esp+64h] [ebp-4h] BYREF

  if ( this->m_thread_id == -1 || this->m_thread_id == vostok::threading::current_thread_id() )
  {
    if ( this->m_verbosity )
      m_verbosity = this->m_verbosity;
    else
      m_verbosity = inherited_verbosity;
    v7 = m_verbosity;
  }
  else
  {
    v7 = silent;
  }
  verbosity = v7;
  m_current_element = path->m_current_element;
  cur_part = m_current_element;
  if ( !m_current_element || !*cur_part )
    return verbosity;
  v11 = v19;
  header = &this->m_children.tree_.data_.node_plus_pred_.header_plus_size_.header_;
  v15 = v19;
  p_m_children = &this->m_children;
  comp.cont_ = &this->m_children.tree_;
  v13 = boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::find<char const *,boost::intrusive::detail::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>>>(
          &this->m_children.tree_.data_.node_plus_pred_.header_plus_size_.header_,
          (char *const *)&cur_part,
          (boost::intrusive::detail::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0> > >)&this->m_children);
  survarium::weapon_user_dead_state::finalize(v4);
  it.members_.nodeptr_ = v13;
  v10 = &this->m_children;
  v9 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)&this->m_children,
         (int)&v10);
  survarium::weapon_user_dead_state::finalize(v5);
  v18 = v9;
  if ( (const vostok::variant<32> **)it.members_.nodeptr_ == v9 )
    return verbosity;
  child = (const vostok::logging::node *)boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>,0>::operator->((boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0> >,0> *)&it);
  vostok::logging::path_parts::to_next_element(path);
  return vostok::logging::node::get_verbosity((vostok::logging::node *)child, path, verbosity);
}
