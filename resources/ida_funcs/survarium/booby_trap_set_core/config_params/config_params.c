void __thiscall survarium::booby_trap_set_core::config_params::config_params(
        survarium::booby_trap_set_core::config_params *this)
{
  this->max_slope_cos = *(float *)&FLOAT_0_0;
  this->max_distance = *(float *)&FLOAT_0_0;
  this->armed_life_time = 0;
  this->fired_life_time = 0;
  this->disarmed_life_time = 0;
  this->defuse_time = 0;
  this->defuse_by_hit = 0;
  this->material_can_place_test = 0;
  this->material_can_stick_test = 0;
}
