void __cdecl stlp_std::_Destroy_Range<vostok::variant<32> *>(vostok::variant<32> *__first, vostok::variant<32> *__last)
{
  while ( __first != __last )
    vostok::variant<32>::`scalar deleting destructor'(0, __first++, 0);
}


void __cdecl stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>()
{
  ;
}


void __cdecl stlp_std::_Destroy_Range<stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *>>(
        stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *> __first,
        stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *> __last)
{
  survarium::base_project::resolve_link_object *v2; // ecx
  survarium::base_project::resolve_link_object *v3; // ecx
  stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *> v4; // [esp-Ch] [ebp-20h] BYREF
  stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *> v5; // [esp-8h] [ebp-1Ch] BYREF
  survarium::base_project::resolve_link_object *v6; // [esp-4h] [ebp-18h]

  v6 = 0;
  v5.current = v2;
  boost::_bi::value<survarium::weapon_state_creation_params const *>::value<survarium::weapon_state_creation_params const *>(
    (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)&__last,
    &v5);
  v4.current = v3;
  boost::_bi::value<survarium::weapon_state_creation_params const *>::value<survarium::weapon_state_creation_params const *>(
    (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)&__first,
    &v4);
  stlp_std::__destroy_range<stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *>,survarium::base_project::resolve_link_object>(
    v4,
    v5,
    v6);
}


void __cdecl stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::ai::planning::specified_action *>>(
        stlp_std::reverse_iterator<vostok::ai::planning::specified_action *> __first,
        stlp_std::reverse_iterator<vostok::ai::planning::specified_action *> __last)
{
  int v2; // [esp-Ch] [ebp-D8h] BYREF
  _DWORD v3[53]; // [esp-8h] [ebp-D4h] BYREF

  v3[50] = v3;
  v3[49] = &v2;
  stlp_std::__destroy_range<stlp_std::reverse_iterator<vostok::ai::planning::specified_action *>,vostok::ai::planning::specified_action>(
    __first,
    __last,
    0);
}


void __cdecl stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *>>(
        stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *> __first,
        stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *> __last)
{
  int v2; // [esp-Ch] [ebp-40h] BYREF
  _DWORD v3[15]; // [esp-8h] [ebp-3Ch] BYREF

  v3[12] = v3;
  v3[11] = &v2;
  stlp_std::__destroy_mv_srcs<stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *>,vostok::fixed_vector<unsigned int,32>>(
    __first,
    __last,
    0);
}


void __cdecl stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::variant<32> *>>(
        stlp_std::reverse_iterator<vostok::variant<32> *> __first,
        stlp_std::reverse_iterator<vostok::variant<32> *> __last)
{
  int v2; // [esp-Ch] [ebp-44h] BYREF
  _DWORD v3[16]; // [esp-8h] [ebp-40h] BYREF

  v3[13] = v3;
  v3[12] = &v2;
  stlp_std::__destroy_range<stlp_std::reverse_iterator<vostok::variant<32> *>,vostok::variant<32>>(__first, __last, 0);
}
