void __usercall survarium::game_world_core::register_serializable_object(
        survarium::game_world_core *this@<ecx>,
        survarium::serializable_object *object@<eax>)
{
  survarium::serializable_object *m_last; // edx

  m_last = this->m_serializable_objects.m_last;
  object->next = 0;
  object->prev = m_last;
  if ( this->m_serializable_objects.m_first )
    this->m_serializable_objects.m_last->next = object;
  else
    this->m_serializable_objects.m_first = object;
  this->m_serializable_objects.m_last = object;
}
