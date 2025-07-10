void __thiscall survarium::player_logic_sprint_state::player_logic_sprint_state(
        survarium::player_logic_sprint_state *this,
        survarium::weapon_user_animations_selector *owner)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::player_logic_sprint_state>,boost::_bi::list1<boost::_bi::value<survarium::player_logic_sprint_state *> > > f; // [esp+4h] [ebp-60h]
  boost::function0<void> v5; // [esp+38h] [ebp-2Ch] BYREF
  boost::function<void __cdecl(void)> *p_subscription_callback; // [esp+58h] [ebp-Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+5Ch] [ebp-8h] BYREF

  survarium::player_logic_base_state::player_logic_base_state(this, owner, type_sprint);
  this->__vftable = (survarium::player_logic_sprint_state_vtbl *)&survarium::player_logic_sprint_state::`vftable';
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    &this->m_initialize_callback.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, &this->m_finalize_callback.vtable);
  p_subscription_callback = &this->m_stamina_subscriber.subscription_callback;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    &this->m_stamina_subscriber.subscription_callback,
    0);
  this->m_stamina_subscriber.next = 0;
  f = (boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::player_logic_sprint_state>,boost::_bi::list1<boost::_bi::value<survarium::player_logic_sprint_state *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))survarium::player_logic_sprint_state::on_stamina_depleted, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
    &v5);
  boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::player_logic_sprint_state>,boost::_bi::list1<boost::_bi::value<survarium::player_logic_sprint_state *>>>>(
    &v5,
    f);
  boost::function0<void>::swap(&v5, &this->m_stamina_subscriber.subscription_callback);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v5);
}
