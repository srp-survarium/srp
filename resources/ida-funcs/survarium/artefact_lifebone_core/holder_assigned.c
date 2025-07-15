void __thiscall survarium::artefact_lifebone_core::holder_assigned(survarium::artefact_lifebone_core *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::artefact_lifebone_core::switch_passive_mode_impl(this, 1);
}
