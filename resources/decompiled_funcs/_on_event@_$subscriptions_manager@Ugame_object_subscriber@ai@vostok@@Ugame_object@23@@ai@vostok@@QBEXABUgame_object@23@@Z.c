void __thiscall vostok::ai::subscriptions_manager<vostok::ai::game_object_subscriber,vostok::ai::game_object>::on_event(
        vostok::ai::subscriptions_manager<vostok::ai::game_object_subscriber,vostok::ai::game_object> *this,
        const vostok::ai::game_object *parameter)
{
  vostok::intrusive_list<vostok::ai::game_object_subscriber,vostok::ai::game_object_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::subscribers_callback_predicate<vostok::ai::game_object_subscriber,vostok::ai::game_object> > pred; // [esp+18h] [ebp-8h] BYREF
  vostok::ai::subscribers_callback_predicate<vostok::ai::game_object_subscriber,vostok::ai::game_object> callback_predicate; // [esp+1Ch] [ebp-4h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&callback_predicate);
  callback_predicate.m_parameter = parameter;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.m_predicate_ref = &callback_predicate;
  vostok::intrusive_list<vostok::ai::game_object_subscriber,vostok::ai::game_object_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::ai::game_object_subscriber,vostok::ai::game_object_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::subscribers_callback_predicate<vostok::ai::game_object_subscriber,vostok::ai::game_object>>>(
    &this->m_subscribers,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&callback_predicate);
}
