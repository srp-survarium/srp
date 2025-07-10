void __thiscall vostok::resources::query_result_for_cook::clear_user_data(
        vostok::resources::query_result_for_cook *this)
{
  vostok::variant<32> *m_user_data; // esi
  vostok::detail::abstract_type_helper *m_helper; // ecx

  m_user_data = this->m_user_data;
  if ( m_user_data )
  {
    m_helper = m_user_data->m_helper;
    if ( m_helper )
    {
      m_helper->destroy(m_helper, m_user_data->m_storage);
      m_user_data->m_helper = 0;
    }
  }
  this->m_user_data = 0;
}
