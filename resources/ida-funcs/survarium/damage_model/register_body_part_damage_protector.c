void __userpurge survarium::damage_model::register_body_part_damage_protector(
        survarium::damage_model *this@<eax>,
        survarium::damage_protector *protector@<esi>,
        survarium::damage_model *a3@<ecx>,
        char *part_name)
{
  survarium::body_part_parameters *body_part; // eax
  vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,104,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *p_m_damage_protectors; // eax

  body_part = survarium::damage_model::get_body_part(a3, (int)this, part_name);
  protector->next = 0;
  p_m_damage_protectors = &body_part->m_damage_protectors;
  ++p_m_damage_protectors->m_size;
  if ( p_m_damage_protectors->m_first )
    p_m_damage_protectors->m_last->next = protector;
  else
    p_m_damage_protectors->m_first = protector;
  p_m_damage_protectors->m_last = protector;
}
