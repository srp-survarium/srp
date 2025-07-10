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
