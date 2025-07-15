void __thiscall survarium::base_player::insert(survarium::base_player *this, const bool real_insert)
{
  survarium::hit_affects_type_enum v3; // ebx
  survarium::affect_subscriber *v4; // edi

  v3 = affects_type_death;
  this->m_has_been_inserted = 1;
  if ( this->m_is_alive )
  {
    survarium::base_player::activate_physics(this, (int)this);
    v4 = (survarium::affect_subscriber *)&byte_10EB8[(_DWORD)this];
    do
      survarium::damage_model::subscribe_on_affect(this->m_damage_model.m_object, v3++, v4++);
    while ( (unsigned int)v3 < affect_types_count );
  }
}
