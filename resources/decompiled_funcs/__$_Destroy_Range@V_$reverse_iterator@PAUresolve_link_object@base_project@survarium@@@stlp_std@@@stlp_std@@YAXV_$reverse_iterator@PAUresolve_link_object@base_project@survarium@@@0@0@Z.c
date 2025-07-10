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
