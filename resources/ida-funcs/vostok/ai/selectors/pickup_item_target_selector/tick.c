void __thiscall vostok::ai::selectors::pickup_item_target_selector::tick(
        vostok::ai::selectors::pickup_item_target_selector *this)
{
  vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::selectors::find_highest_confidence_predicate> pred; // [esp+20h] [ebp-1Ch] BYREF
  vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v3; // [esp+24h] [ebp-18h]
  vostok::ai::ai_world *m_world; // [esp+28h] [ebp-14h]
  const vostok::ai::game_object *object; // [esp+2Ch] [ebp-10h]
  vostok::ai::percept_memory_object *memory_object; // [esp+30h] [ebp-Ch]
  vostok::ai::selectors::find_highest_confidence_predicate find_predicate; // [esp+34h] [ebp-8h] BYREF

  m_world = this->m_world;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&find_predicate);
  find_predicate.object_with_highest_confidence = 0;
  find_predicate.world = m_world;
  v3 = &this->m_working_memory->m_percept_objects.elems[5];
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.m_predicate_ref = &find_predicate;
  vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::selectors::find_highest_confidence_predicate>>(
    v3,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  memory_object = find_predicate.object_with_highest_confidence;
  if ( find_predicate.object_with_highest_confidence )
  {
    object = memory_object->object;
    this->m_blackboard->m_current_pickup_item = object;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&find_predicate);
}
