void __thiscall survarium::teammate_cure_event_manager::on_cured_event(
        survarium::teammate_cure_event_manager *this,
        const survarium::curing_event_status *curing_event_status)
{
  int v3; // ebx
  const std::exception *v4; // eax
  stlp_std::out_of_range v5; // [esp+10h] [ebp-110h] BYREF

  v3 = ((char *)curing_event_status - (char *)this - 32) / 40;
  if ( !this->m_event_callback.vtable )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)0x28, (stlp_std::runtime_error *)&v5);
    boost::throw_exception(v4);
    stlp_std::__Named_exception::~__Named_exception(&v5);
  }
  (*(void (__cdecl **)(boost::detail::function::function_buffer *, int))(((int)this->m_event_callback.vtable & 0xFFFFFFFE)
                                                                       + 4))(
    &this->m_event_callback.functor,
    v3);
}
