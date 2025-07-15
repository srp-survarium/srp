void __thiscall survarium::damage_model::notify_on_affect_event(
        survarium::damage_model *this,
        const char *body_part_name,
        survarium::hit_affects_type_enum affect_type,
        survarium::affect_event_type_enum event_type)
{
  survarium::affect_event_predicate pred; // [esp+124h] [ebp-10h] BYREF
  vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *subscribers; // [esp+130h] [ebp-4h]

  subscribers = &this->m_affect_subscriptions.elems[affect_type];
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.body_part_name = body_part_name;
  pred.affect_type = affect_type;
  pred.event_type = event_type;
  vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<survarium::affect_event_predicate>(
    subscribers,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
}
