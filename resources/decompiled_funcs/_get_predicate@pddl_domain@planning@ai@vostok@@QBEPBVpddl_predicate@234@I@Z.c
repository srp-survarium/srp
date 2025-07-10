stlp_std::priv::_Rb_tree_node_base *__thiscall vostok::ai::planning::pddl_domain::get_predicate(
        vostok::ai::planning::pddl_domain *this,
        unsigned int index)
{
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,vostok::ai::planning::pddl_predicate *>,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned int const ,vostok::ai::planning::pddl_predicate *> > > result; // [esp+14h] [ebp-4h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)this->m_predicates._M_t._M_header._M_data._M_left,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&result);
  stlp_std::advance<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const,vostok::ai::planning::pddl_predicate *>,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned int const,vostok::ai::planning::pddl_predicate *>>>,unsigned int>(
    &result,
    index);
  return result._M_node[1]._M_parent;
}
