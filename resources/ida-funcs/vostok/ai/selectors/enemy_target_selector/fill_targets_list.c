void __thiscall vostok::ai::selectors::enemy_target_selector::fill_targets_list(
        vostok::ai::selectors::enemy_target_selector *this)
{
  vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::selectors::fill_list_with_the_best_enemies_predicate> pred; // [esp+20h] [ebp-14h] BYREF
  vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v3; // [esp+24h] [ebp-10h]
  vostok::ai::ai_world *m_world; // [esp+28h] [ebp-Ch]
  vostok::ai::selectors::fill_list_with_the_best_enemies_predicate get_best_enemies_predicate; // [esp+2Ch] [ebp-8h] BYREF

  this->clear_targets(this);
  m_world = this->m_world;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&get_best_enemies_predicate);
  get_best_enemies_predicate.enemies_list = &this->m_selected_enemies;
  get_best_enemies_predicate.world = m_world;
  v3 = &this->m_working_memory->m_percept_objects.elems[1];
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.m_predicate_ref = &get_best_enemies_predicate;
  vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::selectors::fill_list_with_the_best_enemies_predicate>>(
    v3,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  stlp_std::sort<stlp_std::pair<vostok::ai::npc const *,float> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
    this->m_selected_enemies.m_begin,
    this->m_selected_enemies.m_end,
    vostok::ai::selectors::sort_by_confidence);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&get_best_enemies_predicate);
}
