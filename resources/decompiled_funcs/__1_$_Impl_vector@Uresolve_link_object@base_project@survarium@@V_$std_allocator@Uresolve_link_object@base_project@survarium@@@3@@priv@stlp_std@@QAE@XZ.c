void __thiscall stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::~_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>(
        stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *this)
{
  survarium::base_project::resolve_link_object *v1; // ecx
  stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *> v2; // [esp-8h] [ebp-28h] BYREF
  stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *> v3; // [esp-4h] [ebp-24h] BYREF
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *thisa; // [esp+0h] [ebp-20h]

  thisa = this;
  v3.current = (survarium::base_project::resolve_link_object *)this;
  boost::_bi::value<survarium::weapon_state_creation_params const *>::value<survarium::weapon_state_creation_params const *>(
    this,
    &v3);
  v2.current = v1;
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::rbegin(
    thisa,
    &v2);
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *>>(v2, v3);
  if ( thisa->_M_start )
    survarium::std_allocator<survarium::base_project::resolve_link_object>::deallocate(
      thisa->_M_start,
      (survarium::std_allocator<survarium::base_project::resolve_link_object> *)thisa);
}
