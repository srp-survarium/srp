BOOL __userpurge survarium::hit_animations_selector::selected_animations_::_2_::hit_body_part_greater::operator()@<eax>(
        survarium::hit_animations_selector::selected_animations::__l2::hit_body_part_greater *this@<ecx>,
        survarium::hit_animations_selector::hit_body_part_type left_id@<eax>,
        unsigned int right_id)
{
  const survarium::hit_animations_selector::hit_body_part *m_body_parts; // edi
  survarium::hit_animations_selector::hit_body_part *v5; // esi
  BOOL result; // eax
  survarium::hit_animations_selector::hit_body_part *v7; // [esp+Ch] [ebp-4h]
  unsigned int current_time_in_ms; // [esp+18h] [ebp+8h]

  m_body_parts = this->m_body_parts;
  current_time_in_ms = this->m_current_time_in_ms;
  v7 = (survarium::hit_animations_selector::hit_body_part *)&this->m_body_parts[left_id];
  result = 0;
  if ( survarium::hit_animations_selector::hit_body_part::has_hit(v7, current_time_in_ms) )
  {
    v5 = (survarium::hit_animations_selector::hit_body_part *)&m_body_parts[right_id];
    if ( !survarium::hit_animations_selector::hit_body_part::has_hit(v5, current_time_in_ms)
      || v7->target_hit_amount > v5->target_hit_amount )
    {
      return 1;
    }
  }
  return result;
}
