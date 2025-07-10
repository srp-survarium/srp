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
