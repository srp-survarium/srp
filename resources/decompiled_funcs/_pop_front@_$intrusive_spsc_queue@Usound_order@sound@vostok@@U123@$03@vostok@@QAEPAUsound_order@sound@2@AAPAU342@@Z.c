vostok::sound::sound_order *__thiscall vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>::pop_front(
        vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> *this,
        vostok::sound::sound_order **item_to_delete)
{
  vostok::sound::sound_order *node; // [esp+8h] [ebp-8h]
  vostok::sound::sound_order *value; // [esp+Ch] [ebp-4h]

  node = this->m_tail;
  value = node->m_next_for_orders;
  if ( !value )
    return 0;
  *item_to_delete = node;
  this->m_tail = value;
  return value;
}
