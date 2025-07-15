void __thiscall survarium::hit_animations_selector::hit_body_part::hit_body_part(
        survarium::hit_animations_selector::hit_body_part *this)
{
  this->growth_speed = s_hit_animations_growth_speed;
  this->fall_speed = s_hit_animations_fall_speed;
  this->last_hit_time = 0;
  this->current_hit_amount = 0;
  this->target_hit_amount = 0;
  this->max_hit_amount = 0;
}
