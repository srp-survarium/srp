void __thiscall vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
        vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this)
{
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    this);
  vostok::threading::mutex::mutex(&this->vostok::threading::mutex);
  this->m_first = 0;
  this->m_last = 0;
}


void __thiscall vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
        vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        const vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *other)
{
  _BYTE *v2; // eax

  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    this);
  vostok::threading::mutex::mutex(&this->vostok::threading::mutex);
  this->m_first = 0;
  this->m_last = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v2 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(other->m_first == 0));
}


void __usercall vostok::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>(
        vostok::intrusive_list<vostok::ai::fsm_state,vostok::ai::fsm_state *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  *a2 = 0;
  a2[2] = 0;
  a2[3] = 0;
}


void __thiscall vostok::intrusive_list<vostok::sound::voice_bridge,vostok::sound::voice_bridge *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::sound::voice_bridge,vostok::sound::voice_bridge *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>(
        vostok::intrusive_list<vostok::sound::voice_bridge,vostok::sound::voice_bridge *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this)
{
  this->m_size = 0;
  this->m_first = 0;
  this->m_last = 0;
}
