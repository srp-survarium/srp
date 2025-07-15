float __userpurge survarium::player_params_modifiers_container::apply_modifier@<xmm0>(
        survarium::player_params_modifiers_container *this@<ecx>,
        survarium::player_params_modifiers_enum modifier_id@<edx>,
        float a3@<xmm0>,
        const float value,
        const float factor)
{
  int v5; // edx
  int v6; // eax

  survarium::player_params_modifiers_container::get_modifier_value(this, modifier_id);
  v6 = 0;
  while ( v5 != additive_modifiers_118[v6] )
  {
    if ( (unsigned int)++v6 >= 6 )
      return (float)((float)(a3 * factor) + s_bm_current_air_resistance) * value;
  }
  return (float)(a3 * factor) + value;
}
