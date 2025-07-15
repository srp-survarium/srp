stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *> *vostok::math::_dynamic_initializer_for__SNaN___7()
{
  stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *> *result; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > v1; // [esp+0h] [ebp-14h] BYREF

  v1._M_start = (survarium::base_project::resolve_link_object *)2139095041;
  result = boost::_bi::value<survarium::weapon_state_creation_params const *>::value<survarium::weapon_state_creation_params const *>(
             &v1,
             (stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *> *)&v1._M_finish);
  SNaN_83 = *(const float *)&result->current;
  return result;
}
