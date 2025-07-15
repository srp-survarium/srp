void __thiscall survarium::damage_model::unsubscribe_from_affect(
        survarium::damage_model *this,
        survarium::hit_affects_type_enum affect_type,
        vostok::ai::perceptors::sensors_subscriber *subscriber)
{
  vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *subscribers; // [esp+28h] [ebp-4h]

  subscribers = &this->m_affect_subscriptions.elems[affect_type];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
    (vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)subscribers,
    subscriber);
}
