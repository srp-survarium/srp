vostok::ai::selectors::target_selector_base *__thiscall vostok::ai::brain_unit::get_selector_by_name(
        vostok::ai::brain_unit *this,
        const char *selector_name)
{
  vostok::intrusive_list<vostok::ai::selectors::target_selector_base,vostok::ai::selectors::target_selector_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::ai::find_selector_by_name_predicate> pred; // [esp+24h] [ebp-10h] BYREF
  vostok::ai::selectors::target_selector_base *selector_by_name; // [esp+28h] [ebp-Ch]
  vostok::ai::selectors::target_selector_base *v6; // [esp+2Ch] [ebp-8h]
  vostok::ai::find_selector_by_name_predicate find_selector_predicate; // [esp+30h] [ebp-4h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&find_selector_predicate);
  find_selector_predicate.selector_name = selector_name;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.m_predicate_ref = &find_selector_predicate;
  selector_by_name = vostok::intrusive_list<vostok::ai::selectors::target_selector_base,vostok::ai::selectors::target_selector_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::find_if<vostok::intrusive_list<vostok::ai::selectors::target_selector_base,vostok::ai::selectors::target_selector_base *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::ai::find_selector_by_name_predicate>>(
                       &this->m_target_selectors,
                       &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  v6 = selector_by_name;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&find_selector_predicate);
  return v6;
}
