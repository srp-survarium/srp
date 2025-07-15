char __thiscall vostok::engine::engine_world::is_application_active(vostok::engine::engine_world *this)
{
  char result; // al

  result = 1;
  if ( !BYTE2(this->m_render_has_been_created) )
    return BYTE1(this->m_render_has_been_created);
  return result;
}
