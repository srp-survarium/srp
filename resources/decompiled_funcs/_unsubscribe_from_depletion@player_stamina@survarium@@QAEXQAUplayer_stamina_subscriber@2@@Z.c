void __thiscall survarium::player_stamina::unsubscribe_from_depletion(
        survarium::player_stamina *this,
        vostok::ai::perceptors::sensors_subscriber *subscriber)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
    (vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
    subscriber);
}
