void __userpurge vostok::resources::quality_increase_functionality::insert_to_increase_quality_tree(
        vostok::resources::resource_base *resource@<esi>,
        vostok::resources::quality_increase_functionality *this)
{
  vostok::threading::interlocked_or(&resource->m_flags.m_flags, 0x80u);
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0>>::insert_equal(
    &this->m_data->increase_quality_tree.tree_,
    resource,
    (boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none> **)&this);
}
