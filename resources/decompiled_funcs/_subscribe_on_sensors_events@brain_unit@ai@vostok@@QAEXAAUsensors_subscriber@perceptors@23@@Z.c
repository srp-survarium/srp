void __thiscall vostok::ai::brain_unit::subscribe_on_sensors_events(
        vostok::ai::brain_unit *this,
        vostok::ai::perceptors::sensors_subscriber *subscriber)
{
  vostok::intrusive_list<vostok::ai::game_object_subscriber,vostok::ai::game_object_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back_unique(
    &this->m_perceptors_subscriptions_manager.m_subscribers,
    subscriber,
    0);
}
