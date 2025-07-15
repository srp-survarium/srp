int __usercall stlp_std::priv::__format_nan_or_inf_long_double_@<eax>(
        stlp_std::priv::__basic_iostring<char> *buf@<edi>,
        unsigned int flags@<eax>,
        long double x)
{
  int v4; // eax
  char *M_finish; // ebx
  char *M_data; // ebp
  const char *v7; // esi
  const char **inf_or_nan; // [esp+14h] [ebp-4h]

  v4 = _fpclass(x);
  if ( v4 == 4 || v4 == 512 )
  {
    inf_or_nan = inf_0;
    if ( _fpclass(x) == 4 )
    {
LABEL_4:
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::operator+=(
        buf,
        45);
      goto LABEL_8;
    }
  }
  else
  {
    inf_or_nan = nan_0;
    if ( stlp_std::priv::_Stl_is_neg_nan(x) )
      goto LABEL_4;
  }
  if ( (flags & 0x800) != 0 )
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::operator+=(
      buf,
      43);
LABEL_8:
  M_finish = buf->_M_finish;
  M_data = buf->_M_start_of_storage._M_data;
  v7 = inf_or_nan[(flags >> 14) & 1];
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_append(
    buf,
    v7,
    &v7[strlen(v7)]);
  return M_finish - M_data;
}
