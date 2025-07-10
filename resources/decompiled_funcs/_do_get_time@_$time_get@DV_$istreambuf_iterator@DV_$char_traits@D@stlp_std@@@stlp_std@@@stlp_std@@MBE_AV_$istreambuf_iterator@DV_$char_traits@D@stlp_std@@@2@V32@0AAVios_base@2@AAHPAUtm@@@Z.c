stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::time_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::do_get_time(
        stlp_std::time_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > > *this,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > __end,
        stlp_std::ios_base *__str,
        int *__err,
        tm *__t)
{
  char *M_finish; // esi
  int *v8; // edi
  stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *v9; // eax
  int v10; // ecx

  M_finish = this->_M_timeinfo._M_time_format._M_finish;
  v8 = __err;
  *v8 = M_finish != stlp_std::priv::__get_formatted_time<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,char,stlp_std::priv::_Time_Info>(
                      __s,
                      __end,
                      this->_M_timeinfo._M_time_format._M_start_of_storage._M_data,
                      M_finish,
                      0,
                      &this->_M_timeinfo,
                      __str,
                      __err,
                      __t)
      ? 4
      : 0;
  if ( stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(&__s, &__end) )
    *v8 |= 2u;
  v9 = result;
  v10 = *(_DWORD *)&__s._M_c;
  result->_M_buf = __s._M_buf;
  *(_DWORD *)&result->_M_c = v10;
  return v9;
}
