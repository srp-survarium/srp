void __thiscall vostok::logging::node::~node(vostok::logging::node *this)
{
  boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none> *v1; // ecx

  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>::clear(&this->m_children.tree_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_children);
  boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>::~set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>(
    v1,
    &this->tree_hook.boost::intrusive::rbtree_node<void *>);
}
