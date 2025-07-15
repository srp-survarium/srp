void __thiscall vostok::ai::planning::operator_holder::remove_impl(
        vostok::ai::planning::operator_holder *this,
        unsigned int *operator_id,
        bool notify_holder)
{
  survarium::game_camera *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // eax
  stlp_std::__false_type __formal; // [esp+23h] [ebp-2Dh] BYREF
  vostok::memory::doug_lea_allocator *allocator; // [esp+24h] [ebp-2Ch]
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+33h] [ebp-1Dh]
  vostok::ai::planning::operator_impl *m_operator; // [esp+34h] [ebp-1Ch]
  char v10; // [esp+3Ah] [ebp-16h]
  char v11; // [esp+3Bh] [ebp-15h]
  vostok::ai::planning::operator_pair *__first; // [esp+3Ch] [ebp-14h]
  vostok::ai::planning::operator_pair *__last; // [esp+40h] [ebp-10h]
  char v14; // [esp+47h] [ebp-9h]
  vostok::ai::planning::operator_impl *operator_ptr; // [esp+48h] [ebp-8h] BYREF
  vostok::ai::planning::operator_pair *iter; // [esp+4Ch] [ebp-4h]

  __last = this->m_objects._M_impl._M_finish;
  __first = this->m_objects._M_impl._M_start;
  v11 = stlp_std::priv::__less2<unsigned int,vostok::ai::planning::operator_pair>();
  v10 = stlp_std::priv::__less2<unsigned int,vostok::ai::planning::operator_pair>();
  iter = stlp_std::priv::__lower_bound<vostok::ai::planning::operator_pair *,unsigned int,stlp_std::priv::__less_2<vostok::ai::planning::operator_pair,unsigned int>,stlp_std::priv::__less_2<unsigned int,vostok::ai::planning::operator_pair>,int>(
           __first,
           __last,
           operator_id);
  v14 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  m_operator = iter->m_operator;
  operator_ptr = m_operator;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)iter);
  allocator = v4;
  call_destructor_predicate = 0;
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::inventory,vostok::memory::detail::call_destructor_predicate>(
    v4,
    (vostok::sound::sound_scene **)&operator_ptr);
  __formal = 0;
  stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::_M_erase(
    &this->m_objects._M_impl,
    iter,
    &__formal);
  if ( notify_holder )
    this->m_planner->m_actual = 0;
}
