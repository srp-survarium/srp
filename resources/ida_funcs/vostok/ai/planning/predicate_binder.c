unsigned int __cdecl vostok::ai::planning::predicate_binder<vostok::ai::weapon const *,vostok::ai::weapon const *>(
        const vostok::ai::planning::pddl_predicate *predicate,
        const vostok::fixed_vector<void const *,4> *values)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx

  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  return boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
           (boost::function1<unsigned int,char const *> *)&predicate->m_function_storage,
           *(const char **)values->m_begin);
}


bool __cdecl vostok::ai::planning::predicate_binder<vostok::ai::brain_unit const *,vostok::ai::animation_item const *,vostok::ai::sound_item const *,vostok::ai::brain_unit const *,vostok::ai::animation_item const *,vostok::ai::sound_item const *>(
        const vostok::ai::planning::pddl_predicate *predicate,
        const vostok::fixed_vector<void const *,4> *values)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v5; // [esp+144h] [ebp-34h]
  survarium::game_camera *v6; // [esp+14Ch] [ebp-2Ch]
  const vostok::ai::animation_item *v7; // [esp+160h] [ebp-18h]
  const vostok::ai::sound_item *v8; // [esp+168h] [ebp-10h]

  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  v6 = (survarium::game_camera *)(values->m_begin + 2);
  v8 = (const vostok::ai::sound_item *)v6->__vftable;
  survarium::weapon_user_dead_state::finalize(v6);
  v5 = (survarium::game_camera *)(values->m_begin + 1);
  v7 = (const vostok::ai::animation_item *)v5->__vftable;
  survarium::weapon_user_dead_state::finalize(v5);
  return boost::function3<bool,vostok::ai::brain_unit const *,vostok::ai::animation_item const *,vostok::ai::sound_item const *>::operator()(
           (boost::function3<bool,vostok::ai::brain_unit const *,vostok::ai::animation_item const *,vostok::ai::sound_item const *> *)&predicate->m_function_storage,
           *(const vostok::ai::brain_unit **)values->m_begin,
           v7,
           v8);
}


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
