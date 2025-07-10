void __thiscall survarium::artefact_lifebone_core::activate(
        survarium::weapon_ammunition *this,
        survarium::base_player *user,
        survarium::engine *engine)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)engine);
}
