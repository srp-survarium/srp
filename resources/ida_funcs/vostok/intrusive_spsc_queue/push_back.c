void __thiscall vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>::push_back(
        vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> *this,
        vostok::sound::sound_order *const value)
{
  value->m_next_for_orders = 0;
  _InterlockedExchange((volatile __int32 *)&this->m_head->m_next_for_orders, (__int32)value);
  this->m_head = value;
}


void __thiscall vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>::push_back(
        vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> *this,
        vostok::network::response *const value)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
  value->next_for_responses = 0;
  vostok::threading::interlocked_exchange_pointer((volatile int *)&this->m_head->next_for_responses, (int)value);
  this->m_head = value;
}
