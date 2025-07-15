void __thiscall survarium::weapon::tick(survarium::weapon *this, unsigned int current_time_in_ms)
{
  survarium::player *v3; // ecx
  int v4; // edx
  survarium::rifle_scope *m_object; // ecx
  bool *p_m_is_scope_aimed; // eax

  survarium::weapon_core::tick(this, current_time_in_ms);
  if ( survarium::player::is_current(v3, (int)this->m_user) )
  {
    m_object = this->m_rifle_scope.m_object;
    if ( m_object )
    {
      p_m_is_scope_aimed = &this->m_is_scope_aimed;
      if ( this->m_aimed )
      {
        if ( !*p_m_is_scope_aimed && this->m_aim_progress.m_current_value >= m_object->m_change_scope_factor )
          *p_m_is_scope_aimed = 1;
      }
      else if ( *p_m_is_scope_aimed
             && (m_object->m_change_scope_factor > this->m_aim_progress.m_current_value || !*(_BYTE *)(v4 + 764)) )
      {
        *p_m_is_scope_aimed = 0;
      }
    }
  }
}
