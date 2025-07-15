BOOL __thiscall vostok::ai::brain_unit::is_feeling_safe(vostok::ai::brain_unit *this)
{
  return !vostok::ai::working_memory::has_facts_about_danger(&this->m_working_memory);
}
