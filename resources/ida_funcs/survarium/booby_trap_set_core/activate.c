void __thiscall survarium::booby_trap_set_core::activate(
        survarium::network_client *this,
        survarium::game_camera *map_name,
        const survarium::camera_director *director)
{
  survarium::weapon_user_dead_state::finalize(map_name);
  JUMPOUT(0xAEA12);
}
