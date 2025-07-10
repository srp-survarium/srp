void __thiscall vostok::logging::node::clean(vostok::logging::node *this, vostok::memory::base_allocator *allocator)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  vostok::memory::base_allocator *v4; // eax
  vostok::logging::node *dying; // [esp+3Ch] [ebp-4h] BYREF

  while ( 1 )
  {
    dying = (vostok::logging::node *)boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>::unlink_leftmost_without_rebalance(&this->m_children.tree_);
    if ( !dying )
      break;
    survarium::weapon_user_dead_state::finalize(v2);
    vostok::logging::node::clean(dying, allocator);
    survarium::weapon_user_dead_state::finalize(v3);
    vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,vostok::logging::node,vostok::memory::detail::call_destructor_predicate>(
      v4,
      &dying);
  }
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>::clear(&this->m_children.tree_);
}
