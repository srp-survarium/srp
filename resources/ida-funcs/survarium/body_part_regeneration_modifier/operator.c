void __thiscall survarium::body_part_regeneration_modifier::operator()(
        survarium::body_part_regeneration_modifier *this,
        const char *bodypart,
        survarium::body_part_regeneration_info *regeneration_info)
{
  const std::exception *v4; // eax
  stlp_std::out_of_range v5; // [esp+8h] [ebp-110h] BYREF

  if ( !this->m_functor.vtable )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v5);
    boost::throw_exception(v4);
    stlp_std::__Named_exception::~__Named_exception(&v5);
  }
  (*(void (__cdecl **)(boost::detail::function::function_buffer *, const char *, survarium::body_part_regeneration_info *))(((int)this->m_functor.vtable & 0xFFFFFFFE) + 4))(
    &this->m_functor.functor,
    bodypart,
    regeneration_info);
}
