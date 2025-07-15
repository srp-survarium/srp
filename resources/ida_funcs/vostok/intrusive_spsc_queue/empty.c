bool __thiscall vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>::empty(
        vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> *this)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v1);
  return this->m_tail->next_for_responses == 0;
}
