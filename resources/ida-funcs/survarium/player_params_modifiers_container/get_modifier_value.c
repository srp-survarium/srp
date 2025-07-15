__m128 __usercall survarium::player_params_modifiers_container::get_modifier_value@<xmm0>(
        survarium::player_params_modifiers_container *this@<ecx>,
        const survarium::player_params_modifiers_enum modifier_id@<eax>)
{
  __m128 result; // xmm0
  survarium::player_params_modifier *m_first; // eax
  __m128 value_low; // xmm1

  result = (__m128)LODWORD(this->m_static_modifiers[modifier_id]);
  m_first = this->m_modifiers.elems[modifier_id].m_first;
  while ( m_first )
  {
    value_low = (__m128)LODWORD(m_first->value);
    m_first = m_first->next;
    value_low.m128_f32[0] = value_low.m128_f32[0] + result.m128_f32[0];
    result = value_low;
  }
  return result;
}
