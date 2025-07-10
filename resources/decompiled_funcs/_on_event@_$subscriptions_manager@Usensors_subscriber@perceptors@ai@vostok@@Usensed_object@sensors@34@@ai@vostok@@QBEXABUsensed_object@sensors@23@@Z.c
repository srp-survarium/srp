void __thiscall vostok::ai::subscriptions_manager<vostok::ai::perceptors::sensors_subscriber,vostok::ai::sensors::sensed_object>::on_event(
        vostok::ai::subscriptions_manager<vostok::ai::perceptors::sensors_subscriber,vostok::ai::sensors::sensed_object> *this,
        const vostok::ai::sensors::sensed_object *parameter)
{
  vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::subscribers_callback_predicate<vostok::ai::perceptors::sensors_subscriber,vostok::ai::sensors::sensed_object> > pred; // [esp+18h] [ebp-8h] BYREF
  vostok::ai::subscribers_callback_predicate<vostok::ai::perceptors::sensors_subscriber,vostok::ai::sensors::sensed_object> callback_predicate; // [esp+1Ch] [ebp-4h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&callback_predicate);
  callback_predicate.m_parameter = parameter;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.m_predicate_ref = &callback_predicate;
  vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::npc_subscribers_callback_predicate<vostok::ai::sensors::damage_subscriber,vostok::ai::sensed_hit_object>>>(
    &this->m_subscribers,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&callback_predicate);
}
