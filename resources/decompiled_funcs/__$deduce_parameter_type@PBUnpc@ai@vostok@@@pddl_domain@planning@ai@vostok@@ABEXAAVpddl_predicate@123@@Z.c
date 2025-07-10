void __thiscall vostok::ai::planning::pddl_domain::deduce_parameter_type<vostok::ai::npc const *>(
        vostok::ai::planning::pddl_domain *this,
        vostok::ai::planning::pddl_predicate *predicate)
{
  survarium::game_camera *v2; // ecx
  vostok::variant<32> *value; // [esp+4h] [ebp-30h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v5; // [esp+10h] [ebp-24h]
  char v6; // [esp+2Bh] [ebp-9h]
  char *__k; // [esp+2Ch] [ebp-8h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<char const * const,unsigned int> > > iter; // [esp+30h] [ebp-4h] BYREF

  __k = (char *)type_info::name(&vostok::ai::npc const * `RTTI Type Descriptor', &__type_info_root_node);
  v5 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<char const *,stlp_std::less<char const *>,stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_Select1st<stlp_std::pair<char const * const,unsigned int>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<char const * const,unsigned int>>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::_M_find<char const *>(
                                                                     &this->m_registered_types._M_t,
                                                                     (const char *const *)&__k);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v5,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&iter);
  v6 = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  value = (vostok::variant<32> *)iter._M_node[1]._M_parent;
  vostok::buffer_vector<unsigned int>::push_back(
    (vostok::buffer_vector<vostok::variant<32> const *> *)&predicate->m_parameters,
    (const vostok::variant<32> **)&value);
}
