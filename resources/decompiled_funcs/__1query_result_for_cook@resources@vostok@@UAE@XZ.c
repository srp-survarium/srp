void __thiscall vostok::resources::query_result_for_cook::~query_result_for_cook(
        vostok::resources::query_result_for_cook *this)
{
  vostok::variant<32> *m_user_data; // edi
  vostok::detail::abstract_type_helper *m_helper; // ecx
  boost::detail::function::vtable_base *vtable; // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  m_user_data = this->m_user_data;
  this->__vftable = (vostok::resources::query_result_for_cook_vtbl *)&vostok::resources::query_result_for_cook::`vftable';
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
  vtable = this->m_tasks_finished_callback.vtable;
  if ( vtable )
  {
    if ( ((unsigned __int8)vtable & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
      if ( v5 )
        v5(&this->m_tasks_finished_callback.functor, &this->m_tasks_finished_callback.functor, 2);
    }
    this->m_tasks_finished_callback.vtable = 0;
  }
  vostok::resources::query_result_for_user::~query_result_for_user(this);
}
