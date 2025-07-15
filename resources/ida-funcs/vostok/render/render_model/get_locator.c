char __thiscall vostok::render::render_model::get_locator(
        vostok::render::render_model *this,
        unsigned int idx,
        vostok::render::model_locator_item *result)
{
  qmemcpy(result, &this->m_locators[idx], sizeof(vostok::render::model_locator_item));
  return 1;
}


char __thiscall vostok::render::render_model::get_locator(
        vostok::render::render_model *this,
        char *locator_name,
        vostok::render::model_locator_item *result)
{
  unsigned __int16 v3; // di
  vostok::render::model_locator_item *m_locators; // ebx
  unsigned __int16 m_locators_count; // [esp+Ch] [ebp-4h]

  v3 = 0;
  m_locators_count = this->m_locators_count;
  if ( !m_locators_count )
    return 0;
  m_locators = this->m_locators;
  while ( vostok::strings::compare(m_locators[v3].m_name, locator_name) )
  {
    if ( ++v3 >= m_locators_count )
      return 0;
  }
  qmemcpy(result, &m_locators[v3], sizeof(vostok::render::model_locator_item));
  return 1;
}
