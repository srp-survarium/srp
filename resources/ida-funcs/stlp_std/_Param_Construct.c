void __cdecl stlp_std::_Param_Construct<char,char>(char *__p, const char *__val)
{
  survarium::generate_shaders_world::is_loading();
  survarium::generate_shaders_world::is_loading();
  *__p = *__val;
}


void __cdecl stlp_std::_Param_Construct<vostok::logging::initiator_filter,vostok::logging::initiator_filter>(
        vostok::logging::initiator_filter *__p,
        const vostok::logging::initiator_filter *__val)
{
  vostok::logging::initiator_filter *v2; // [esp+1Ch] [ebp-8h]

  v2 = (vostok::logging::initiator_filter *)operator new(0x3Cu, __p);
  if ( v2 )
    vostok::logging::initiator_filter::initiator_filter(v2, __val);
}


void __cdecl stlp_std::_Param_Construct<stlp_std::pair<vostok::collision::bone_collision_data *,float>,stlp_std::pair<vostok::collision::bone_collision_data *,float>>(
        stlp_std::pair<vostok::collision::bone_collision_data *,float> *__p,
        const stlp_std::pair<vostok::collision::bone_collision_data *,float> *__val)
{
  stlp_std::pair<vostok::collision::bone_collision_data *,float> *v2; // [esp+4h] [ebp-8h]

  v2 = (stlp_std::pair<vostok::collision::bone_collision_data *,float> *)operator new(8u, __p);
  if ( v2 )
    *v2 = *__val;
}


void __cdecl stlp_std::_Param_Construct<vostok::ai::planning::operator_pair,vostok::ai::planning::operator_pair>(
        vostok::ai::planning::operator_pair *__p,
        const vostok::ai::planning::operator_pair *__val)
{
  vostok::ai::planning::operator_impl *m_operator; // ecx
  unsigned int *v3; // [esp+4h] [ebp-8h]

  v3 = (unsigned int *)operator new(8u, __p);
  if ( v3 )
  {
    m_operator = __val->m_operator;
    *v3 = __val->m_id;
    v3[1] = (unsigned int)m_operator;
  }
}


void __cdecl stlp_std::_Param_Construct<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::planning::pddl_world_state_property_impl>(
        vostok::ai::planning::pddl_world_state_property_impl *__p,
        const vostok::ai::planning::pddl_world_state_property_impl *__val)
{
  vostok::ai::planning::pddl_world_state_property_impl *v2; // [esp+20h] [ebp-8h]

  v2 = (vostok::ai::planning::pddl_world_state_property_impl *)operator new(0x20u, __p);
  if ( v2 )
    vostok::ai::planning::pddl_world_state_property_impl::pddl_world_state_property_impl(v2, __val);
}


void __cdecl stlp_std::_Param_Construct<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>(
        boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> *__p,
        const boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> *__val)
{
  stlp_std::__false_type __formal; // [esp+3Eh] [ebp-2h] BYREF
  char v3; // [esp+3Fh] [ebp-1h]

  v3 = 0;
  __formal = 0;
  stlp_std::_Param_Construct_aux<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>>(
    __p,
    __val,
    &__formal);
}


void __cdecl stlp_std::_Param_Construct<vostok::fixed_string<16>,vostok::fixed_string<16>>(
        vostok::fixed_string<16> *__p,
        const vostok::fixed_string<16> *__val)
{
  vostok::fixed_string<16> *v2; // [esp+20h] [ebp-8h]

  v2 = (vostok::fixed_string<16> *)operator new(0x1Cu, (void *)__p);
  if ( v2 )
    vostok::fixed_string<16>::fixed_string<16>(v2, __val);
}


void __cdecl stlp_std::_Param_Construct<vostok::fixed_vector<unsigned int,32>,vostok::fixed_vector<unsigned int,32>>(
        vostok::fixed_vector<unsigned int,32> *__p,
        const vostok::fixed_vector<unsigned int,32> *__val)
{
  stlp_std::__false_type __formal; // [esp+26h] [ebp-2h] BYREF
  char v3; // [esp+27h] [ebp-1h]

  v3 = 0;
  __formal = 0;
  stlp_std::_Param_Construct_aux<vostok::fixed_vector<unsigned int,32>,vostok::fixed_vector<unsigned int,32>>(
    __p,
    __val,
    &__formal);
}


void __cdecl stlp_std::_Param_Construct<boost::shared_ptr<boost::asio::detail::win_mutex>,boost::shared_ptr<boost::asio::detail::win_mutex>>(
        boost::shared_ptr<boost::asio::detail::win_mutex> *__p,
        const boost::shared_ptr<boost::asio::detail::win_mutex> *__val)
{
  stlp_std::__false_type __formal; // [esp+Eh] [ebp-2h] BYREF
  char v3; // [esp+Fh] [ebp-1h]

  v3 = 0;
  __formal = 0;
  stlp_std::_Copy_Construct_aux<boost::shared_ptr<boost::asio::detail::win_mutex>>(__p, __val, &__formal);
}
