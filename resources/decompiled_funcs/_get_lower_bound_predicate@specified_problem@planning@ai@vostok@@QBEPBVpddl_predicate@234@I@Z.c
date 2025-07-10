stlp_std::priv::_Rb_tree_node_base *__thiscall vostok::ai::planning::specified_problem::get_lower_bound_predicate(
        vostok::ai::planning::specified_problem *this,
        unsigned int offset)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx
  stlp_std::priv::_Rb_tree_node_base *M_left; // ecx
  vostok::buffer_vector<vostok::resources::request> *v4; // ecx
  vostok::buffer_vector<vostok::resources::request> *v6; // ecx
  vostok::buffer_vector<vostok::resources::request> *v7; // ecx
  boost::_bi::list1<vostok::network_core::packet_reader &> *__last; // [esp+Ch] [ebp-D0h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *__first; // [esp+10h] [ebp-CCh]
  _DWORD v11[7]; // [esp+2Ch] [ebp-B0h] BYREF
  stlp_std::priv::_Rb_tree_node_base *v12; // [esp+48h] [ebp-94h]
  int v13; // [esp+4Ch] [ebp-90h]
  stlp_std::priv::_Rb_tree_node_base *v14; // [esp+50h] [ebp-8Ch] BYREF
  stlp_std::priv::_Rb_tree_node_base *M_parent; // [esp+54h] [ebp-88h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v16; // [esp+58h] [ebp-84h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v17[2]; // [esp+5Ch] [ebp-80h] BYREF
  _DWORD v18[5]; // [esp+64h] [ebp-78h] BYREF
  stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > temp_value; // [esp+78h] [ebp-64h] BYREF
  stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> temp_pair; // [esp+84h] [ebp-58h]
  vostok::ai::planning::pddl_predicate temp_predicate; // [esp+8Ch] [ebp-50h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > iter; // [esp+D8h] [ebp-4h] BYREF

  temp_predicate.m_type = 0;
  vostok::fixed_vector<unsigned int,4>::fixed_vector<unsigned int,4>(&temp_predicate.m_parameters);
  temp_predicate.m_caption = (const char *)&buf;
  v11[6] = &temp_predicate.m_function_storage;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, &temp_predicate.m_function_storage.vtable);
  v11[4] = offset;
  v11[5] = &temp_predicate;
  v18[3] = &temp_predicate;
  v18[4] = offset;
  temp_pair.first = &temp_predicate;
  temp_pair.second = offset;
  v11[3] = v11;
  v11[0] = &temp_predicate;
  v11[1] = offset;
  v17[1] = 0;
  v11[2] = v18;
  v18[0] = &temp_predicate;
  v18[1] = offset;
  temp_value.first = 0;
  temp_value.second.first = &temp_predicate;
  temp_value.second.second = offset;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)this,
    v17);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)this->m_predicates._M_t._M_header._M_data._M_left,
    &v16);
  __last = v17[0];
  __first = v16;
  stlp_std::priv::__less2<unsigned int,vostok::ai::planning::operator_pair>();
  stlp_std::priv::__less2<unsigned int,vostok::ai::planning::operator_pair>();
  stlp_std::priv::__lower_bound<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>>,stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>,stlp_std::priv::__less_2<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>,stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,stlp_std::priv::__less_2<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>,stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,int>(
    &iter,
    (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > >)__first,
    (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > >)__last,
    &temp_value);
  M_left = iter._M_node[1]._M_left;
  if ( M_left == (stlp_std::priv::_Rb_tree_node_base *)offset )
  {
    M_parent = iter._M_node[1]._M_parent;
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)M_left,
      (int *)&temp_predicate.m_function_storage);
    vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v4, &temp_predicate.m_parameters.m_begin);
    return M_parent;
  }
  else
  {
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      (boost::_bi::list1<vostok::network_core::packet_reader &> *)this->m_predicates._M_t._M_header._M_data._M_left,
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v14);
    if ( iter._M_node == v14 )
    {
      v13 = 0;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(iter._M_node == v14),
        (int *)&temp_predicate.m_function_storage);
      vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v6, &temp_predicate.m_parameters.m_begin);
      return (stlp_std::priv::_Rb_tree_node_base *)v13;
    }
    else
    {
      iter._M_node = stlp_std::priv::_Rb_global<bool>::_M_decrement(iter._M_node);
      v12 = iter._M_node[1]._M_parent;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)iter._M_node,
        (int *)&temp_predicate.m_function_storage);
      vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v7, &temp_predicate.m_parameters.m_begin);
      return v12;
    }
  }
}
