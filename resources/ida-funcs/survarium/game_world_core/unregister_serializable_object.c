void __usercall survarium::game_world_core::unregister_serializable_object(
        survarium::game_world_core *this@<esi>,
        survarium::serializable_object *object@<eax>)
{
  survarium::serializable_object *prev; // edx
  survarium::serializable_object *next; // ecx

  if ( this->m_serializable_objects.m_first )
  {
    prev = object->prev;
    next = object->next;
    object->prev = 0;
    object->next = 0;
    if ( prev )
      prev->next = next;
    else
      this->m_serializable_objects.m_first = next;
    if ( next )
      next->prev = prev;
    else
      this->m_serializable_objects.m_last = prev;
    object->prev = 0;
    object->next = 0;
  }
}
