void __cdecl stlp_std::priv::__get_floor_digits(stlp_std::priv::__basic_iostring<char> *out, long double __x)
{
  int v2; // eax
  unsigned int size; // eax
  stlp_std::forward_iterator_tag __formal; // [esp+1Bh] [ebp-145h] BYREF
  int sign; // [esp+1Ch] [ebp-144h] BYREF
  int decpt; // [esp+20h] [ebp-140h] BYREF
  char cvtbuf[312]; // [esp+24h] [ebp-13Ch] BYREF

  _fcvt_s(cvtbuf, 0x135u, __x, 0, &decpt, &sign);
  if ( sign )
  {
    if ( (stlp_std::priv::__basic_iostring<char> *)out->_M_start_of_storage._M_data == out )
      v2 = (char *)out - out->_M_finish + 16;
    else
      v2 = out->_M_buffers._M_end_of_storage - out->_M_finish;
    if ( v2 == 1 )
    {
      size = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
               out,
               1u);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_reserve(
        out,
        size);
    }
    out->_M_finish[1] = 0;
    *out->_M_finish++ = 45;
  }
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_appendT<char const *>(
    out,
    cvtbuf,
    &cvtbuf[decpt],
    &__formal);
}
