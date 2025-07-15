void __userpurge vostok::resources::quality_increase_functionality::erase_from_increase_quality_tree(
        vostok::resources::quality_increase_functionality *this@<ecx>,
        vostok::resources::resource_base_vtbl **a2@<eax>,
        vostok::resources::compare_by_target_satisfaction *a3@<ebx>,
        vostok::resources::resource_base *resource)
{
  vostok::resources::resource_base_vtbl *v4; // edi
  boost::intrusive::rbtree_node<void *> *first; // ebx
  boost::intrusive::rbtree_node<void *> *v6; // esi
  stlp_std::pair<boost::intrusive::rbtree_node<void *> *,boost::intrusive::rbtree_node<void *> *> z; // [esp+Ch] [ebp-8h] BYREF

  v4 = *a2 + 2;
  boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::equal_range<vostok::resources::resource_base,boost::intrusive::detail::key_nodeptr_comp<vostok::resources::compare_by_target_satisfaction,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0>>>>(
    v4,
    a3,
    &z,
    resource);
  first = z.first;
  while ( first != z.second )
  {
    v6 = first;
    first = boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::next_node(first);
    boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::erase(
      v6,
      (boost::intrusive::rbtree_node<void *> *)v4);
    v6->parent_ = 0;
    v6->left_ = 0;
    v6->right_ = 0;
  }
  _InterlockedAnd(&resource->m_flags.m_flags, 0xFFFFFF7F);
}
