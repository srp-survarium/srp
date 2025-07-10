void __thiscall vostok::ai::brain_unit::unsubscribe_from_sensors_events(
        vostok::ai::brain_unit *this,
        vostok::ai::perceptors::sensors_subscriber *subscriber)
{
  vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
    &this->m_perceptors_subscriptions_manager.m_subscribers,
    subscriber);
}
