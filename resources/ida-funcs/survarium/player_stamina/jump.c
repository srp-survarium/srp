void __usercall survarium::player_stamina::jump(
        survarium::player_stamina *this@<ecx>,
        survarium::player_stamina *a2@<esi>,
        float a3@<xmm0>)
{
  float v4; // xmm0_4

  v4 = survarium::player_params_modifiers_container::apply_modifier(
         a2->m_modifiers,
         stamina_spending_speed_modifier,
         a3,
         a2->m_params.amount_to_jump,
         1.0);
  survarium::player_stamina::spend(a2, v4);
}
