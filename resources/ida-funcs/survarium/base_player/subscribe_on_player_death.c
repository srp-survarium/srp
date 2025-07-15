void __thiscall survarium::base_player::subscribe_on_player_death(
        survarium::base_player *this,
        survarium::game_camera *subscriber)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::intrusive_list<survarium::player_death_subscriber,survarium::player_death_subscriber *,32,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::push_back(
    &this->m_player_death_subscribers,
    subscriber,
    0);
}
