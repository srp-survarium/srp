void __thiscall survarium::character_dispersion_params::character_dispersion_params(
        survarium::character_dispersion_params *this)
{
  LODWORD(this->idle_multiplier) = clear_value;
  LODWORD(this->idle_aim_multiplier) = clear_value;
  LODWORD(this->walk_multiplier) = clear_value;
  LODWORD(this->walk_aim_multiplier) = clear_value;
  LODWORD(this->run_multiplier) = clear_value;
  LODWORD(this->jump_multiplier) = clear_value;
  LODWORD(this->crouch_multiplier) = clear_value;
  LODWORD(this->crouch_aim_multiplier) = clear_value;
  LODWORD(this->crouch_walk_multiplier) = clear_value;
  LODWORD(this->crouch_walk_aim_multiplier) = clear_value;
  LODWORD(this->prone_multiplier) = clear_value;
  LODWORD(this->prone_aim_multiplier) = clear_value;
  LODWORD(this->injury_penalty_for_double_handed) = clear_value;
  LODWORD(this->injury_penalty_for_one_handed) = clear_value;
}
