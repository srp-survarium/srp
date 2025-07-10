bool __cdecl vostok::ai::planning::predicate_binder<vostok::ai::brain_unit const *,vostok::ai::animation_item const *,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>(
        const vostok::ai::planning::pddl_predicate *predicate,
        const vostok::fixed_vector<void const *,4> *values)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v5; // [esp+140h] [ebp-24h]
  survarium::hit_affects_type_enum v6; // [esp+154h] [ebp-10h]

  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  v5 = (survarium::game_camera *)(values->m_begin + 1);
  v6 = (survarium::hit_affects_type_enum)v5->__vftable;
  survarium::weapon_user_dead_state::finalize(v5);
  return boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
           (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&predicate->m_function_storage,
           *(const char **)values->m_begin,
           v6);
}
