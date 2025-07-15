void __userpurge survarium::damage_model::unregister_body_part_damage_protector(
        survarium::damage_model *this@<ecx>,
        int a2@<eax>,
        char *part_name,
        survarium::damage_protector *protector)
{
  survarium::body_part_parameters *body_part; // eax
  survarium::damage_protector *m_first; // ecx
  vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,104,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *p_m_damage_protectors; // eax
  survarium::damage_protector *v7; // edx
  survarium::damage_protector *next; // esi
  survarium::damage_protector *v9; // ecx

  body_part = survarium::damage_model::get_body_part(this, a2, part_name);
  m_first = body_part->m_damage_protectors.m_first;
  p_m_damage_protectors = &body_part->m_damage_protectors;
  if ( m_first )
  {
    v7 = 0;
    while ( m_first != protector )
    {
      v7 = m_first;
      m_first = m_first->next;
      if ( !m_first )
      {
        if ( protector )
          return;
        break;
      }
    }
    --p_m_damage_protectors->m_size;
    next = m_first->next;
    if ( v7 )
      v7->next = next;
    else
      p_m_damage_protectors->m_first = next;
    if ( !m_first->next )
    {
      v9 = v7;
      if ( !v7 )
        v9 = p_m_damage_protectors->m_first;
      p_m_damage_protectors->m_last = v9;
    }
  }
}
