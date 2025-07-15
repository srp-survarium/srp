void __thiscall vostok::ai::working_memory::dump_state(
        vostok::ai::working_memory *this,
        vostok::ai::npc_statistics *stats)
{
  vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::dump_memory_facts_predicate> pred; // [esp+40h] [ebp-48h] BYREF
  const char *second; // [esp+44h] [ebp-44h]
  vostok::ai::dump_memory_facts_predicate state_dumper_predicate; // [esp+78h] [ebp-10h] BYREF
  const vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *facts; // [esp+80h] [ebp-8h]
  unsigned int i; // [esp+84h] [ebp-4h]

  vostok::fixed_string<16>::operator=(&stru_97F6C0, &stats->working_memory_state.caption);
  for ( i = 0; i < 6; ++i )
  {
    facts = &this->m_percept_objects.elems[i];
    if ( facts->m_first )
    {
      second = memory_object_types_captions_5[i].second;
      survarium::weapon_core::cast_weapon_core((survarium::game_options *)&state_dumper_predicate);
      state_dumper_predicate.npc_stats = stats;
      state_dumper_predicate.caption = second;
      survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
      pred.m_predicate_ref = &state_dumper_predicate;
      vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::dump_memory_facts_predicate>>(
        (vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)facts,
        &pred);
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&state_dumper_predicate);
    }
  }
}
