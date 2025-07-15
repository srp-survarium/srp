void __cdecl vostok::ai::planning::finalize_binder<vostok::ai::brain_unit *,vostok::ai::animation_item const *,vostok::ai::sound_item const *,vostok::ai::brain_unit *,vostok::ai::animation_item const *,vostok::ai::sound_item const *>(
        const vostok::ai::planning::action_instance *action,
        const vostok::fixed_vector<void const *,4> *values)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // [esp+140h] [ebp-34h]
  survarium::game_camera *v5; // [esp+148h] [ebp-2Ch]
  const vostok::ai::npc *v6; // [esp+15Ch] [ebp-18h]
  const vostok::ai::weapon *v7; // [esp+164h] [ebp-10h]

  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  v5 = (survarium::game_camera *)(values->m_begin + 2);
  v7 = (const vostok::ai::weapon *)v5->__vftable;
  survarium::weapon_user_dead_state::finalize(v5);
  v4 = (survarium::game_camera *)(values->m_begin + 1);
  v6 = (const vostok::ai::npc *)v4->__vftable;
  survarium::weapon_user_dead_state::finalize(v4);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::operator()(
    (boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *> *)&action->m_finalize_storage,
    *(const vostok::ai::brain_unit **)values->m_begin,
    v6,
    v7);
}


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


void __cdecl vostok::ai::planning::finalize_binder<vostok::ai::game_object const *,vostok::ai::game_object const *>(
        const vostok::ai::planning::action_instance *action,
        const vostok::fixed_vector<void const *,4> *values)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx

  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
    (boost::function1<void,vostok::ai::sensors::sensed_object const &> *)&action->m_finalize_storage,
    *(const vostok::ai::sensors::sensed_object **)values->m_begin);
}
