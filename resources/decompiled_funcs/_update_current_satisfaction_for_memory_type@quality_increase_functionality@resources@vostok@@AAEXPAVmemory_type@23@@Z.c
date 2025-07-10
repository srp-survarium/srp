void __usercall vostok::resources::quality_increase_functionality::update_current_satisfaction_for_memory_type(
        vostok::resources::quality_increase_functionality *this@<edi>,
        vostok::resources::memory_type *memory_type_resources@<eax>,
        double a3@<st0>)
{
  vostok::resources::resource_base *i; // esi

  for ( i = memory_type_resources->resources.m_first; i; i = i->m_next_in_memory_type )
  {
    if ( i->m_quality_levels_count == 1 || i->m_target_quality_level == i->m_current_quality_level )
    {
      vostok::resources::quality_increase_functionality::update_current_satisfaction_for_resource(
        (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0> > *)i,
        a3,
        this);
    }
    else if ( !i->is_increasing_quality(i) )
    {
      vostok::resources::quality_increase_functionality::update_current_satisfaction_for_resource(
        (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0> > *)i,
        a3,
        this);
      i->m_last_fail_of_increasing_quality = vostok::resources::quality_increase_functionality::s_elapsed_sec_from_start;
    }
  }
}
