double __thiscall survarium::hit_animations_selector::hit_body_part::hit_time_factor_calculator(
        survarium::hit_animations_selector::hit_body_part *this,
        const float __formal,
        const float a3,
        const unsigned int a4,
        const unsigned int a5,
        unsigned int target_time_in_ms,
        const float a7)
{
  return (double)survarium::hit_animations_selector::hit_body_part::get_current_hit_amount(this, target_time_in_ms)
       * 0.001;
}
