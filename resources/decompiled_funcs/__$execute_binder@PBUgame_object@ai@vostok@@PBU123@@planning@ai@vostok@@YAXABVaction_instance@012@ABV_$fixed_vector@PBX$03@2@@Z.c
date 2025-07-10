void __cdecl vostok::ai::planning::execute_binder<vostok::ai::game_object const *,vostok::ai::game_object const *>(
        const vostok::ai::planning::action_instance *action,
        const vostok::fixed_vector<void const *,4> *values)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx

  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
    (boost::function1<void,vostok::ai::sensors::sensed_object const &> *)&action->m_execute_storage,
    *(const vostok::ai::sensors::sensed_object **)values->m_begin);
}
