void __thiscall vostok::ai::ai_world::on_hit_event(
        vostok::ai::ai_world *this,
        vostok::ai::npc *npc,
        const vostok::ai::sensed_sound_object *perceived_hit)
{
  vostok::ai::npc_subscriptions_manager<vostok::ai::sensors::damage_subscriber,vostok::ai::sensed_hit_object>::on_event(
    (vostok::ai::npc_subscriptions_manager<vostok::ai::sensors::sound_subscriber,vostok::ai::sensed_sound_object> *)&this->m_damage_subscriptions_manager,
    npc,
    perceived_hit);
}
