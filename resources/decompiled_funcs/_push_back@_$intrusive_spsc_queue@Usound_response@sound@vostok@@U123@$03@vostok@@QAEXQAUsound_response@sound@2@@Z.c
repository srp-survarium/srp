void __thiscall vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>::push_back(
        vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> *this,
        vostok::sound::sound_order *const value)
{
  value->m_next_for_orders = 0;
  _InterlockedExchange((volatile __int32 *)&this->m_head->m_next_for_orders, (__int32)value);
  this->m_head = value;
}
