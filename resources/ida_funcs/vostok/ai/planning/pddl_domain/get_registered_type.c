stlp_std::priv::_Rb_tree_node_base *__thiscall vostok::ai::planning::pddl_domain::get_registered_type(
        vostok::ai::planning::pddl_domain *this,
        const char *registered_typename)
{
  boost::_bi::list1<vostok::network_core::packet_reader &> *v5; // [esp+8h] [ebp-20h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v6; // [esp+20h] [ebp-8h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<char const * const,unsigned int> > > iter; // [esp+24h] [ebp-4h] BYREF

  v5 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<char const *,stlp_std::less<char const *>,stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_Select1st<stlp_std::pair<char const * const,unsigned int>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<char const * const,unsigned int>>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::_M_find<char const *>(
                                                                     &this->m_registered_types._M_t,
                                                                     &registered_typename);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v5,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&iter);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)this,
    &v6);
  if ( (boost::_bi::list1<vostok::network_core::packet_reader &> *)iter._M_node == v6 )
    return (stlp_std::priv::_Rb_tree_node_base *)-1;
  else
    return iter._M_node[1]._M_parent;
}
