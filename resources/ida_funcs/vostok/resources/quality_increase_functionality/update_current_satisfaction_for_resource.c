void __userpurge vostok::resources::quality_increase_functionality::update_current_satisfaction_for_resource(
        boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0> > *resource@<esi>,
        double a2@<st0>,
        vostok::resources::quality_increase_functionality *this)
{
  vostok::resources::quality_increase_functionality *v3; // ebp
  char v4; // al
  bool v5; // bl
  unsigned int color; // ecx
  void *v7; // [esp+0h] [ebp-10h]

  v3 = this;
  v4 = (int)resource->data_.node_plus_pred_.header_plus_size_.header_.right_ & 0x80;
  v5 = v4 == (char)0x80;
  if ( resource[6].data_.node_plus_pred_.header_plus_size_.header_.color_ != black_t && v4 == (char)0x80 )
  {
    boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0>>::erase<vostok::resources::resource_base,vostok::resources::compare_by_target_satisfaction>(
      resource,
      &this->m_data->increase_quality_tree.tree_.data_.node_plus_pred_.header_plus_size_.header_,
      (vostok::resources::compare_by_target_satisfaction)this->m_data->increase_quality_tree.tree_.data_.node_plus_pred_.header_plus_size_.header_.parent_,
      v7);
    vostok::threading::interlocked_and(
      (volatile int *)&resource->data_.node_plus_pred_.header_plus_size_.header_.right_,
      0xFFFFFF7F);
  }
  vostok::resources::resource_quality::update_satisfaction(
    (vostok::resources::resource_quality *)resource,
    a2,
    v3->m_data->current_increase_quality_tick);
  if ( resource[6].data_.node_plus_pred_.header_plus_size_.header_.color_ != black_t )
  {
    color = resource[7].data_.node_plus_pred_.header_plus_size_.header_.color_;
    resource[7].data_.node_plus_pred_.header_plus_size_.header_.left_ = resource[7].data_.node_plus_pred_.header_plus_size_.header_.parent_;
    resource[8].data_.node_plus_pred_.header_plus_size_.header_.parent_ = (boost::intrusive::rbtree_node<void *> *)color;
    if ( v5 )
    {
      vostok::threading::interlocked_or(
        (volatile int *)&resource->data_.node_plus_pred_.header_plus_size_.header_.right_,
        0x80u);
      boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0>>::insert_equal(
        &v3->m_data->increase_quality_tree.tree_,
        (vostok::resources::resource_base *)resource,
        (boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none> **)&this);
    }
  }
}
