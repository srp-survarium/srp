void __thiscall vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>::push_null_node(
        vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> *this,
        vostok::network::response *const null_node)
{
  survarium::game_camera *v2; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  null_node->next_for_responses = 0;
  this->m_tail = null_node;
  this->m_head = null_node;
}
