char __thiscall vostok::engine::engine_world::is_application_active(vostok::engine::engine_world *this)
{
  char result; // al

  result = 1;
  if ( !BYTE2(this->m_resources_cooker_destruction_started) )
    return BYTE1(this->m_resources_cooker_destruction_started);
  return result;
}
