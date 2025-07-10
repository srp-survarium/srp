bool __thiscall vostok::ai::working_memory::has_facts_about_danger(vostok::ai::working_memory *this)
{
  return this->m_percept_objects.elems[0].m_first && this->m_percept_objects.elems[1].m_first;
}
