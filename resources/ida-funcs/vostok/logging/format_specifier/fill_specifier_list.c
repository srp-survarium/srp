void __thiscall vostok::logging::format_specifier::fill_specifier_list(
        vostok::logging::format_specifier *this,
        vostok::fixed_vector<enum vostok::logging::format_specifier_enum,8> *list,
        char (*out_format_string)[512])
{
  vostok::logging::format_specifier *m_left; // ecx
  char out_format_stringa[512]; // [esp+8h] [ebp-400h] BYREF
  char _Src[512]; // [esp+208h] [ebp-200h] BYREF

  m_left = (vostok::logging::format_specifier *)this->m_left;
  if ( m_left )
  {
    vostok::logging::format_specifier::fill_specifier_list(m_left, list, (char (*)[512])out_format_stringa);
    vostok::logging::format_specifier::fill_specifier_list(
      (vostok::logging::format_specifier *)this->m_right,
      list,
      (char (*)[512])_Src);
    vostok::strings::copy<512>(out_format_string, out_format_stringa);
    strcat_s((char *)out_format_string, 0x200u, _Src);
  }
  else if ( this->m_specifier == format_specifier_separator )
  {
    vostok::strings::copy<512>(out_format_string, (char *)&this[1]);
  }
  else
  {
    vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(0, (int)list, &this->m_specifier);
    vostok::strings::copy<512>(out_format_string, (char *)&stru_7F9BE8.allocator);
  }
}
