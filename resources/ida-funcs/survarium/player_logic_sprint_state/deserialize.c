void __thiscall survarium::player_logic_sprint_state::deserialize(
        survarium::player_logic_sprint_state *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  survarium::player_stamina::subscribe_on_depletion(
    &this->m_user->m_stamina,
    &this->m_stamina_subscriber,
    (vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this);
}
