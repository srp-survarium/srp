stlp_std::priv::_Rb_tree_node_base *__thiscall vostok::ai::planning::specified_problem::get_predicate_offset(
        vostok::ai::planning::specified_problem *this,
        unsigned int type)
{
  boost::_bi::list1<vostok::network_core::packet_reader &> *v5; // [esp+8h] [ebp-1Ch]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v6; // [esp+1Ch] [ebp-8h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > iter; // [esp+20h] [ebp-4h] BYREF

  v5 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>>::_M_find<unsigned int>(
                                                                     &this->m_predicates._M_t,
                                                                     &type);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v5,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&iter);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)this,
    &v6);
  if ( (boost::_bi::list1<vostok::network_core::packet_reader &> *)iter._M_node == v6 )
    return (stlp_std::priv::_Rb_tree_node_base *)-1;
  else
    return iter._M_node[1]._M_left;
}
