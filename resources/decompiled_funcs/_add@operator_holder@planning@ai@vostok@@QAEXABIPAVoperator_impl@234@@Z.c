void __thiscall vostok::ai::planning::operator_holder::add(
        vostok::ai::planning::operator_holder *this,
        unsigned int *operator_id,
        vostok::ai::planning::operator_impl *operator_impl)
{
  survarium::game_camera *v3; // ecx
  vostok::ai::planning::operator_pair *__first; // [esp+10h] [ebp-18h]
  vostok::ai::planning::operator_pair *__last; // [esp+14h] [ebp-14h]
  vostok::ai::planning::operator_pair __x; // [esp+18h] [ebp-10h] BYREF
  char v8; // [esp+23h] [ebp-5h]
  vostok::ai::planning::operator_pair *iter; // [esp+24h] [ebp-4h]

  __last = this->m_objects._M_impl._M_finish;
  __first = this->m_objects._M_impl._M_start;
  stlp_std::priv::__less2<unsigned int,vostok::ai::planning::operator_pair>();
  stlp_std::priv::__less2<unsigned int,vostok::ai::planning::operator_pair>();
  iter = stlp_std::priv::__lower_bound<vostok::ai::planning::operator_pair *,unsigned int,stlp_std::priv::__less_2<vostok::ai::planning::operator_pair,unsigned int>,stlp_std::priv::__less_2<unsigned int,vostok::ai::planning::operator_pair>,int>(
           __first,
           __last,
           operator_id);
  v8 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  this->m_planner->m_actual = 0;
  __x.m_id = *operator_id;
  __x.m_operator = operator_impl;
  stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::insert(
    &this->m_objects._M_impl,
    iter,
    &__x);
  vostok::ai::planning::operator_impl::on_after_addition(operator_impl, this->m_planner);
}
