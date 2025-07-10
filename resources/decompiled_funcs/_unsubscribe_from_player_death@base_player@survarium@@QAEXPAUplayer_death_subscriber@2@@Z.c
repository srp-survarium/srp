void __thiscall survarium::base_player::unsubscribe_from_player_death(
        survarium::base_player *this,
        survarium::player_death_subscriber *subscriber)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::intrusive_list<survarium::player_death_subscriber,survarium::player_death_subscriber *,32,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::erase(
    &this->m_player_death_subscribers,
    subscriber);
}
