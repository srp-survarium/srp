void __thiscall vostok::ai::ai_world::on_sound_event(
        vostok::ai::ai_world *this,
        vostok::ai::npc *npc,
        const vostok::ai::sensed_sound_object *perceived_sound)
{
  vostok::ai::npc_subscriptions_manager<vostok::ai::sensors::damage_subscriber,vostok::ai::sensed_hit_object>::on_event(
    &this->m_sounds_subscriptions_manager,
    npc,
    perceived_sound);
}
