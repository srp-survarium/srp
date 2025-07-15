void __thiscall vostok::resources::cook_base::satisfaction_with(
        vostok::resources::cook_base *this,
        unsigned int quality_level,
        survarium::game_camera *user_matrix,
        unsigned int users_count)
{
  survarium::weapon_user_dead_state::finalize(user_matrix);
  JUMPOUT(0x226F7);
}
