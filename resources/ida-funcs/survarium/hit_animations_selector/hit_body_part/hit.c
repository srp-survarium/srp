void __userpurge survarium::hit_animations_selector::hit_body_part::hit(
        survarium::hit_animations_selector::hit_body_part *this@<ecx>,
        survarium::hit_animations_selector::hit_body_part *a2@<eax>,
        unsigned int current_time_in_ms,
        const float amount)
{
  unsigned int current_hit_amount; // ebx
  unsigned int max_hit_amount; // eax
  unsigned int *p_max_hit_amount; // edi

  current_hit_amount = survarium::hit_animations_selector::hit_body_part::get_current_hit_amount(a2, current_time_in_ms);
  a2->current_hit_amount = current_hit_amount;
  if ( s_hit_animations_always_max )
  {
    max_hit_amount = a2->max_hit_amount;
  }
  else
  {
    p_max_hit_amount = &a2->max_hit_amount;
    LODWORD(amount) = current_hit_amount + (unsigned __int64)((double)a2->max_hit_amount * amount);
    if ( a2->max_hit_amount >= LODWORD(amount) )
      p_max_hit_amount = (unsigned int *)&amount;
    max_hit_amount = *p_max_hit_amount;
  }
  a2->target_hit_amount = max_hit_amount;
  a2->last_hit_time = current_time_in_ms;
}
