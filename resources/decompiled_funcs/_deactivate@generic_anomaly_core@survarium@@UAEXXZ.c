void __thiscall survarium::generic_anomaly_core::deactivate(survarium::generic_anomaly_core *this)
{
  survarium::game_camera *v1; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  boost::arg<1> *v4; // [esp+8h] [ebp-40h]
  boost::arg<1> *result; // [esp+Ch] [ebp-3Ch]
  unsigned int a; // [esp+44h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::scheduler::unregister(this->m_scheduler, &this->m_scheduler_identifier);
  if ( this->m_current_state )
  {
    survarium::anomaly_state::finalize(this->m_current_state);
    this->m_current_state = 0;
  }
  for ( a = 0;
        a < stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&this->m_artefact_containers._M_impl);
        ++a )
  {
    survarium::weapon_user_dead_state::finalize(v1);
    result = (boost::arg<1> *)&stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                 v2,
                                 (int)&this->m_artefact_containers)[a];
    v4 = stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result);
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)v4 + 36))(*(_DWORD *)v4, *(_DWORD *)v4);
  }
  this->m_scheduler = 0;
}
