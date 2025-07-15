void __thiscall vostok::ai::ai_world::on_destruction_event(
        vostok::ai::ai_world *this,
        const vostok::ai::game_object *object_to_be_destroyed)
{
  vostok::ai::subscriptions_manager<vostok::ai::game_object_subscriber,vostok::ai::game_object>::on_event(
    &this->m_destruction_subscriptions_manager,
    object_to_be_destroyed);
}
