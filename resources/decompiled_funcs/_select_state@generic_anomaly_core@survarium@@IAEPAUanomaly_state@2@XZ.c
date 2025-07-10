survarium::anomaly_state *__thiscall survarium::generic_anomaly_core::select_state(
        survarium::generic_anomaly_core *this)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v1; // ecx
  survarium::game_camera *v2; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  boost::arg<1> *v4; // eax
  boost::arg<1> *v7; // [esp+Ch] [ebp-1Ch]
  boost::arg<1> *result; // [esp+14h] [ebp-14h]
  survarium::anomaly_state *s; // [esp+1Ch] [ebp-Ch]
  unsigned int i; // [esp+20h] [ebp-8h]
  survarium::anomaly_state *state; // [esp+24h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  result = (boost::arg<1> *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                              v1,
                              (int)&this->m_states);
  state = *(survarium::anomaly_state **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result);
  for ( i = 0;
        i < stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&this->m_states._M_impl);
        ++i )
  {
    survarium::weapon_user_dead_state::finalize(v2);
    v7 = (boost::arg<1> *)&stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                             v3,
                             (int)&this->m_states)[i];
    v4 = stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v7);
    s = *(survarium::anomaly_state **)v4;
    if ( **(_BYTE **)v4 )
    {
      if ( (double)s->energy_threshold > this->m_energy_current )
        return state;
      if ( (!s->zone_activity_trigger || this->m_was_zone_trigger_event)
        && (!s->shoot_trigger || this->m_was_shoot_trigger_event) )
      {
        state = *(survarium::anomaly_state **)v4;
      }
    }
  }
  return state;
}
