void __cdecl stlp_std::priv::__write_formatted_timeT<char,stlp_std::priv::_Time_Info>(
        stlp_std::priv::__basic_iostring<char> *buf,
        const stlp_std::ctype<char> *ct,
        char format,
        char modifier,
        const stlp_std::priv::_Time_Info *table,
        const tm *t)
{
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *p_M_date_time_format; // eax
  const char *v7; // eax
  char *v8; // eax
  const char *v9; // eax
  int v10; // edx
  const char *v11; // eax
  int v12; // edx
  char v13; // bl
  const char *v14; // eax
  bool v15; // cc
  const char *v16; // eax
  const char *v17; // eax
  char *v18; // eax
  int tm_wday; // eax
  int tm_yday; // esi
  int v21; // esi
  char v22; // al
  int v23; // [esp-8h] [ebp-5Ch]
  stlp_std::forward_iterator_tag __formal; // [esp+Fh] [ebp-45h] BYREF
  char _buf[64]; // [esp+10h] [ebp-44h] BYREF

  switch ( format )
  {
    case '%':
      v22 = ((int (__stdcall *)(int))ct->do_widen)(37);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::append(
        buf,
        1u,
        v22);
      return;
    case 'A':
      stlp_std::priv::__append(&table->_M_dayname[t->tm_wday + 7], buf);
      return;
    case 'B':
      stlp_std::priv::__append(&table->_M_monthname[t->tm_mon + 12], buf);
      return;
    case 'H':
      v9 = Format;
      if ( modifier == 35 )
        v9 = "%ld";
      sprintf_s<64>((char (*)[64])_buf, v9, t->tm_hour);
      if ( t->tm_hour >= 10 || (v8 = &_buf[1], modifier != 35) )
        v8 = &_buf[2];
      goto LABEL_58;
    case 'I':
      v10 = t->tm_hour % 12;
      if ( !v10 )
        v10 = 12;
      v11 = Format;
      if ( modifier == 35 )
        v11 = "%ld";
      sprintf_s<64>((char (*)[64])_buf, v11, v10);
      v12 = t->tm_hour % 12;
      if ( !v12 || v12 >= 10 || (v8 = &_buf[1], modifier != 35) )
        v8 = &_buf[2];
      goto LABEL_58;
    case 'M':
      v13 = modifier;
      v16 = Format;
      if ( modifier == 35 )
        v16 = "%ld";
      sprintf_s<64>((char (*)[64])_buf, v16, t->tm_min);
      v15 = t->tm_min < 10;
      goto LABEL_41;
    case 'S':
      v13 = modifier;
      v17 = Format;
      if ( modifier == 35 )
        v17 = "%ld";
      sprintf_s<64>((char (*)[64])_buf, v17, t->tm_sec);
      v15 = t->tm_sec < 10;
      goto LABEL_41;
    case 'U':
      v18 = stlp_std::priv::__write_integer(_buf, 0, (t->tm_yday - t->tm_wday + 7) / 7);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_appendT<char const *>(
        buf,
        _buf,
        v18,
        &__formal);
      return;
    case 'W':
      tm_wday = t->tm_wday;
      tm_yday = t->tm_yday;
      if ( tm_wday )
        v21 = tm_yday - tm_wday + 8;
      else
        v21 = tm_yday + 1;
      v8 = stlp_std::priv::__write_integer(_buf, 0, v21 / 7);
      goto LABEL_58;
    case 'X':
      stlp_std::priv::__subformat<char,stlp_std::priv::_Time_Info>(buf, ct, &table->_M_time_format, table, t);
      return;
    case 'Y':
      v8 = stlp_std::priv::__write_integer(_buf, 0, t->tm_year + 1900);
      goto LABEL_58;
    case 'a':
      stlp_std::priv::__append(&table->_M_dayname[t->tm_wday], buf);
      return;
    case 'b':
      stlp_std::priv::__append(&table->_M_monthname[t->tm_mon], buf);
      return;
    case 'c':
      p_M_date_time_format = &table->_M_date_time_format;
      if ( modifier == 35 )
        p_M_date_time_format = &table->_M_long_date_time_format;
      goto LABEL_8;
    case 'd':
      v7 = Format;
      if ( modifier == 35 )
        v7 = "%ld";
      sprintf_s<64>((char (*)[64])_buf, v7, t->tm_mday);
      if ( t->tm_mday >= 10 || (v8 = &_buf[1], modifier != 35) )
        v8 = &_buf[2];
      goto LABEL_58;
    case 'e':
      sprintf_s<64>((char (*)[64])_buf, "%2ld", t->tm_mday);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_appendT<char const *>(
        buf,
        _buf,
        &_buf[2],
        &__formal);
      return;
    case 'j':
      v23 = t->tm_yday + 1;
      goto LABEL_55;
    case 'm':
      v13 = modifier;
      v14 = Format;
      if ( modifier == 35 )
        v14 = "%ld";
      sprintf_s<64>((char (*)[64])_buf, v14, t->tm_mon + 1);
      v15 = t->tm_mon + 1 < 10;
LABEL_41:
      if ( !v15 || (v8 = &_buf[1], v13 != 35) )
        v8 = &_buf[2];
      goto LABEL_58;
    case 'p':
      stlp_std::priv::__append(&table->_M_am_pm[t->tm_hour / 12], buf);
      return;
    case 'w':
      v23 = t->tm_wday;
      goto LABEL_55;
    case 'x':
      p_M_date_time_format = &table->_M_date_format;
      if ( modifier == 35 )
        p_M_date_time_format = &table->_M_long_date_format;
LABEL_8:
      stlp_std::priv::__subformat<char,stlp_std::priv::_Time_Info>(buf, ct, p_M_date_time_format, table, t);
      return;
    case 'y':
      v23 = (t->tm_year + 1900) % 100;
LABEL_55:
      v8 = stlp_std::priv::__write_integer(_buf, 0, v23);
LABEL_58:
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_appendT<char const *>(
        buf,
        _buf,
        v8,
        &__formal);
      break;
    default:
      return;
  }
}
