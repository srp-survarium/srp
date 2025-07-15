void __userpurge survarium::anomaly_damage_protector::reduce_damage(
        survarium::anomaly_damage_protector *this@<ecx>,
        float a2@<xmm0>,
        const char *const body_part_name,
        const survarium::hit_type_enum damage_type,
        float *amount,
        float *armor_piercing)
{
  int v6; // eax

  v6 = 0;
  while ( anomaly_damage_types_18[v6] != damage_type )
  {
    if ( (unsigned int)++v6 >= 4 )
      return;
  }
  *amount = survarium::player_params_modifiers_container::apply_modifier(
              &this->m_model->m_owner->m_profile->modifiers,
              anomaly_damage_modifier,
              a2,
              *amount,
              1.0);
}
