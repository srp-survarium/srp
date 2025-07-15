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


vostok::network::response *__thiscall vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>::pop_front(
        vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> *this,
        vostok::network::response **item_to_delete)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  vostok::network::response *node; // [esp+8h] [ebp-8h]
  vostok::network::response *value; // [esp+Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  node = this->m_tail;
  value = node->next_for_responses;
  if ( !value )
    return 0;
  *item_to_delete = node;
  this->m_tail = value;
  return value;
}
