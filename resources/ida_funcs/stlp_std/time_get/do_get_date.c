stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__thiscall stlp_std::time_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::do_get_date(
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
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *M_buf; // edx
  int v11; // ecx
  int v12; // ecx

  M_finish = this->_M_timeinfo._M_date_format._M_finish;
  v8 = __err;
  if ( stlp_std::priv::__get_formatted_time<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,char,stlp_std::priv::_Time_Info>(
         __s,
         __end,
         this->_M_timeinfo._M_date_format._M_start_of_storage._M_data,
         M_finish,
         0,
         &this->_M_timeinfo,
         __str,
         __err,
         __t) == M_finish )
  {
    v9 = result;
    M_buf = __s._M_buf;
    v11 = *(_DWORD *)&__s._M_c;
    *v8 = 0;
    result->_M_buf = M_buf;
    *(_DWORD *)&result->_M_c = v11;
  }
  else
  {
    *v8 = 4;
    if ( stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(&__s, &__end) )
      *v8 |= 2u;
    v9 = result;
    v12 = *(_DWORD *)&__s._M_c;
    result->_M_buf = __s._M_buf;
    *(_DWORD *)&result->_M_c = v12;
  }
  return v9;
}
