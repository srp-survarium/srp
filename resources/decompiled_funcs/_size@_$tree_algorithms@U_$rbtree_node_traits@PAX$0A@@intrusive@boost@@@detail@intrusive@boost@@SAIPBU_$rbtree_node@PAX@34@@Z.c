unsigned int __cdecl boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::size(
        const boost::intrusive::rbtree_node<void *> *header)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v1; // ecx
  survarium::game_camera *v2; // ecx
  boost::intrusive::rbtree_node<void *> *v3; // eax
  boost::intrusive::rbtree_node<void *> *end; // [esp+Ch] [ebp-Ch]
  unsigned int i; // [esp+10h] [ebp-8h]
  boost::intrusive::rbtree_node<void *> *beg; // [esp+14h] [ebp-4h]

  beg = (boost::intrusive::rbtree_node<void *> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                                                   v1,
                                                   (int)header);
  survarium::weapon_user_dead_state::finalize(v2);
  end = v3;
  i = 0;
  while ( beg != end )
  {
    ++i;
    beg = boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::next_node(beg);
  }
  return i;
}
