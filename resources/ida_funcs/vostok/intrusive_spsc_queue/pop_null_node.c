vostok::sound::sound_order *__thiscall vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>::pop_null_node(
        vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> *this)
{
  vostok::sound::sound_order *result; // [esp+8h] [ebp-4h]

  result = this->m_head;
  this->m_tail = 0;
  this->m_head = 0;
  return result;
}
