void __cdecl vostok::ai::planning::finalize_binder<vostok::ai::brain_unit *,vostok::ai::sound_item const *,vostok::ai::brain_unit *,vostok::ai::sound_item const *>(
        const vostok::ai::planning::action_instance *action,
        const vostok::fixed_vector<void const *,4> *values)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // [esp+13Ch] [ebp-24h]
  const vostok::network_core::udp_match_packet *v5; // [esp+150h] [ebp-10h]

  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  v4 = (survarium::game_camera *)(values->m_begin + 1);
  v5 = (const vostok::network_core::udp_match_packet *)v4->__vftable;
  survarium::weapon_user_dead_state::finalize(v4);
  boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
    (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)&action->m_finalize_storage,
    *(const char **)values->m_begin,
    v5);
}
