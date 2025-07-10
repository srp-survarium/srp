void __thiscall survarium::anomaly_state::execute(
        survarium::anomaly_state *this,
        unsigned int time_delta_ms,
        unsigned int current_time_ms)
{
  survarium::game_camera *v3; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  survarium::zone_group **v5; // eax
  float energy_on_exit; // [esp+Ch] [ebp-18h]
  boost::arg<1> *result; // [esp+18h] [ebp-Ch]
  unsigned int g; // [esp+20h] [ebp-4h]

  for ( g = 0; g < stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&this->groups._M_impl); ++g )
  {
    survarium::weapon_user_dead_state::finalize(v3);
    result = (boost::arg<1> *)&stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                 v4,
                                 (int)&this->groups)[g];
    v5 = (survarium::zone_group **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result);
    survarium::zone_group::execute(*v5, time_delta_ms, current_time_ms);
  }
  if ( this->m_finish_time_ms )
  {
    if ( current_time_ms > this->m_finish_time_ms )
    {
      energy_on_exit = (float)this->energy_on_exit;
      this->owner->m_energy_current = energy_on_exit;
    }
  }
}
