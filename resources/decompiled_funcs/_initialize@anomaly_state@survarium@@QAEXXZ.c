void __thiscall survarium::anomaly_state::initialize(survarium::anomaly_state *this)
{
  survarium::game_camera *v1; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  survarium::zone_group **v4; // [esp+8h] [ebp-10h]
  boost::arg<1> *result; // [esp+Ch] [ebp-Ch]
  unsigned int g; // [esp+14h] [ebp-4h]

  for ( g = 0; g < stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&this->groups._M_impl); ++g )
  {
    survarium::weapon_user_dead_state::finalize(v1);
    result = (boost::arg<1> *)&stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                 v2,
                                 (int)&this->groups)[g];
    v4 = (survarium::zone_group **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result);
    survarium::zone_group::initialize(*v4);
  }
  if ( this->active_time_sec )
    this->m_finish_time_ms = this->owner->m_current_time + 1000 * this->active_time_sec;
  else
    this->m_finish_time_ms = 0;
}
