int __thiscall vostok::ai::ai_world::get_current_time_in_ms(vostok::ai::ai_world *this)
{
  return ((int (__thiscall *)(vostok::ai::engine *, vostok::ai::ai_world *))this->m_engine->get_current_time_in_ms)(
           this->m_engine,
           this);
}
