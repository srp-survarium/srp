BOOL __userpurge survarium::player_stamina::is_overburdened@<eax>(
        survarium::player_stamina *this@<ecx>,
        int a2@<eax>,
        float a3@<xmm0>,
        float current_weight)
{
  return current_weight >= survarium::player_params_modifiers_container::apply_modifier(
                             *(survarium::player_params_modifiers_container **)(a2 + 120),
                             max_carried_weight_modifier,
                             a3,
                             *(float *)(a2 + 76),
                             1.0);
}
