unsigned int __usercall survarium::hit_animations_selector::hit_body_part::get_current_hit_amount@<eax>(
        survarium::hit_animations_selector::hit_body_part *this@<esi>,
        const unsigned int current_time_in_ms@<eax>)
{
  double growth_speed; // st7
  unsigned int *p_target_hit_amount; // ebx
  unsigned int v4; // edi
  __int64 v6; // rax
  double fall_speed; // st7
  unsigned int v9; // [esp+Ch] [ebp-4h]

  growth_speed = this->growth_speed;
  p_target_hit_amount = &this->target_hit_amount;
  v4 = current_time_in_ms - this->last_hit_time;
  v9 = (unsigned __int64)((double)(this->target_hit_amount - this->current_hit_amount) / growth_speed);
  if ( v4 > v9 )
  {
    fall_speed = this->fall_speed;
    if ( v4 > v9 + (unsigned int)(unsigned __int64)((double)*p_target_hit_amount / fall_speed) )
    {
      LODWORD(v6) = 0;
      return v6;
    }
    return (unsigned __int64)((double)*p_target_hit_amount - fall_speed * (double)(v4 - v9));
  }
  else
  {
    return (unsigned __int64)(growth_speed * (double)v4 + (double)this->current_hit_amount);
  }
}
