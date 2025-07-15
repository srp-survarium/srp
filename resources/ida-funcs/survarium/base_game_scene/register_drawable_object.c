void __usercall survarium::base_game_scene::register_drawable_object(
        survarium::base_game_scene *this@<ecx>,
        survarium::drawable_object *object@<eax>)
{
  survarium::drawable_object *m_last; // edx

  m_last = this->m_drawable_objects.m_last;
  object->next = 0;
  object->prev = m_last;
  if ( this->m_drawable_objects.m_first )
    this->m_drawable_objects.m_last->next = object;
  else
    this->m_drawable_objects.m_first = object;
  this->m_drawable_objects.m_last = object;
}
