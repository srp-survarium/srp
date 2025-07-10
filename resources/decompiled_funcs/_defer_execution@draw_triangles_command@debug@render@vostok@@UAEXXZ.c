void __thiscall vostok::render::debug::draw_triangles_command::defer_execution(
        vostok::render::debug::draw_triangles_command *this)
{
  vostok::render::base_scene *m_object; // eax
  vostok::render::base_command *last_command; // edx

  this->deferred_next = 0;
  m_object = this->m_scene.m_object;
  last_command = m_object->last_command;
  if ( last_command )
    last_command->deferred_next = this;
  else
    m_object->first_command = this;
  this->m_scene.m_object->last_command = this;
}
