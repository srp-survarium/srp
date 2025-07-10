void __thiscall survarium::booby_trap_set_core::remove(survarium::booby_trap_set_core *this)
{
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v1; // [esp+4h] [ebp-58h] BYREF
  vostok::resources::queries_result *a1; // [esp+14h] [ebp-48h]
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> > m_traps; // [esp+2Ch] [ebp-30h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+44h] [ebp-18h] BYREF
  void (__thiscall *f)(survarium::booby_trap_set_core *, vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *); // [esp+54h] [ebp-8h]
  int f_4; // [esp+58h] [ebp-4h]

  f = survarium::booby_trap_set_core::remove_trap_if_active;
  f_4 = 0;
  m_traps = this->m_traps;
  v1 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::booby_trap_set_core::remove_trap_if_active, (survarium::weapon_core_animation_end_aware_state *)this);
  for ( a1 = (vostok::resources::queries_result *)m_traps.m_begin;
        a1 != (vostok::resources::queries_result *)m_traps.m_end;
        a1 = (vostok::resources::queries_result *)((char *)a1 + 4) )
  {
    boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::sound::create_sound_propagator_params const &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::arg<1>>>::operator()<vostok::sound::create_sound_propagator_params>(
      &v1,
      a1);
  }
}
