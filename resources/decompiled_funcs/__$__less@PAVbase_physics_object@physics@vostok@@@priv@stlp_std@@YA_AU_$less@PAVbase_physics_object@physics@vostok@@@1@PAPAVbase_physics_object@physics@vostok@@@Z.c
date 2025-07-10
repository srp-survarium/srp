survarium::game_camera *__cdecl stlp_std::priv::__less<vostok::physics::base_physics_object *>(
        survarium::game_camera *result)
{
  char v2; // [esp+3h] [ebp-1h]

  LOBYTE(result->__vftable) = v2;
  survarium::weapon_user_dead_state::finalize(result);
  return result;
}
