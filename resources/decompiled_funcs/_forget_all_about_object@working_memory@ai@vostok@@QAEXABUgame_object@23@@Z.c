void __thiscall vostok::ai::working_memory::forget_all_about_object(
        vostok::ai::working_memory *this,
        const vostok::ai::game_object *object)
{
  vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::find_percept_object_by_game_object> pred; // [esp+14h] [ebp-14h] BYREF
  vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *knowledge_by_type; // [esp+18h] [ebp-10h]
  vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *iter; // [esp+1Ch] [ebp-Ch]
  vostok::ai::find_percept_object_by_game_object find_all_facts_predicate; // [esp+20h] [ebp-8h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&find_all_facts_predicate);
  find_all_facts_predicate.object_to_be_forgotten = object;
  find_all_facts_predicate.memory_to_be_cleaned = this;
  for ( iter = (vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this;
        iter != (vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_subscription;
        ++iter )
  {
    knowledge_by_type = iter;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
    pred.m_predicate_ref = &find_all_facts_predicate;
    vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::find_percept_object_by_game_object>>(
      knowledge_by_type,
      &pred);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&find_all_facts_predicate);
}
