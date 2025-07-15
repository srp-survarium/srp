char __thiscall vostok::render::render_model::get_locator(
        vostok::render::render_model *this,
        const char *locator_name,
        vostok::render::model_locator_item *result)
{
  unsigned __int16 v3; // di
  vostok::render::model_locator_item *m_locators; // ebp
  unsigned __int16 m_locators_count; // [esp+10h] [ebp-4h]

  v3 = 0;
  m_locators_count = this->m_locators_count;
  if ( !m_locators_count )
    return 0;
  m_locators = this->m_locators;
  while ( strcmp(m_locators[v3].m_name, locator_name) )
  {
    if ( ++v3 >= m_locators_count )
      return 0;
  }
  qmemcpy(result, &m_locators[v3], sizeof(vostok::render::model_locator_item));
  return 1;
}
