BOOL __usercall survarium::hit_animations_selector::hit_body_part::has_hit@<eax>(
        survarium::hit_animations_selector::hit_body_part *this@<esi>,
        const unsigned int current_time_in_ms@<eax>)
{
  return current_time_in_ms - this->last_hit_time < (unsigned int)(unsigned __int64)((double)this->target_hit_amount
                                                                                   / this->fall_speed)
                                                  + (unsigned int)(unsigned __int64)((double)(this->target_hit_amount
                                                                                            - this->current_hit_amount)
                                                                                   / this->growth_speed);
}
