void __thiscall survarium::chat_handler::~chat_handler(survarium::chat_handler *this)
{
  survarium::flash_movie_resource *m_object; // eax
  survarium::flash_external_handler_impl *impl; // ecx
  survarium::flash_function_handler_impl *v4; // ecx

  this->vostok::input::handler::__vftable = (survarium::chat_handler_vtbl *)&survarium::chat_handler::`vftable'{for `vostok::input::handler'};
  this->survarium::flash_function_handler::__vftable = (survarium::flash_function_handler_vtbl *)&survarium::chat_handler::`vftable'{for `survarium::flash_function_handler'};
  this->survarium::flash_external_handler::__vftable = (survarium::flash_external_handler_vtbl *)&survarium::chat_handler::`vftable'{for `survarium::flash_external_handler'};
  m_object = this->m_chat_ui.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_chat_ui.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_chat_ui.m_object);
  impl = this->survarium::flash_external_handler::impl;
  this->survarium::flash_external_handler::__vftable = (survarium::flash_external_handler_vtbl *)&survarium::flash_external_handler::`vftable';
  if ( impl )
    ((void (__thiscall *)(survarium::flash_external_handler_impl *, int))impl->~survarium::flash_external_handler_impl)(
      impl,
      1);
  v4 = this->survarium::flash_function_handler::impl;
  this->survarium::flash_function_handler::__vftable = (survarium::flash_function_handler_vtbl *)&survarium::flash_function_handler::`vftable';
  if ( v4 )
    ((void (__thiscall *)(survarium::flash_function_handler_impl *, int))v4->~survarium::flash_function_handler_impl)(
      v4,
      1);
}
