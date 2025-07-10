void __thiscall vostok::logging::format_specifier::fill_specifier_list(
        vostok::logging::format_specifier *this,
        vostok::fixed_vector<enum vostok::logging::format_specifier_enum,8> *list,
        char (*out_format_string)[512])
{
  const vostok::variant<32> **v3; // eax
  char right_string[512]; // [esp+34h] [ebp-400h] BYREF
  char left_string[512]; // [esp+234h] [ebp-200h] BYREF

  if ( this->m_left )
  {
    vostok::logging::format_specifier::fill_specifier_list(
      (vostok::logging::format_specifier *)this->m_left,
      list,
      (char (*)[512])left_string);
    vostok::logging::format_specifier::fill_specifier_list(
      (vostok::logging::format_specifier *)this->m_right,
      list,
      (char (*)[512])right_string);
    vostok::strings::copy<512>(out_format_string, left_string);
    vostok::strings::append<512>(out_format_string, right_string);
  }
  else if ( this->m_specifier == format_specifier_separator )
  {
    v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
           (int)&this[1]);
    vostok::strings::copy<512>(out_format_string, (const char *)v3);
  }
  else
  {
    vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
      (vostok::buffer_vector<void const *> *)list,
      (const void **)&this->m_specifier);
    vostok::strings::copy<512>(out_format_string, "%s");
  }
}
