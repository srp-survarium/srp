void __cdecl stlp_std::priv::__write_formatted_timeT<wchar_t,stlp_std::priv::_WTime_Info>(
        stlp_std::priv::__basic_iostring<wchar_t> *buf,
        stlp_std::ctype<wchar_t> *ct,
        char format,
        char modifier,
        const stlp_std::priv::_WTime_Info *table,
        const tm *t)
{
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *p_M_date_time_format; // eax
  char v7; // bl
  const char *v8; // eax
  bool v9; // cc
  char *v10; // edx
  const char *v11; // eax
  int v12; // edx
  const char *v13; // eax
  int v14; // edx
  char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  int v19; // eax
  int tm_wday; // eax
  int tm_yday; // esi
  int v22; // esi
  wchar_t v23; // ax
  char _buf[64]; // [esp+Ch] [ebp-44h] BYREF

  switch ( format )
  {
    case '%':
      v23 = ct->do_widen(ct, 37);
      stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::append(
        buf,
        1u,
        v23);
      return;
    case 'A':
    case 'B':
    case 'a':
    case 'b':
    case 'p':
      stlp_std::priv::__append_0(buf);
      return;
    case 'H':
      v7 = modifier;
      v11 = Format;
      if ( modifier == 35 )
        v11 = "%ld";
      sprintf_s<64>((char (*)[64])_buf, v11, t->tm_hour);
      v9 = t->tm_hour < 10;
      goto LABEL_9;
    case 'I':
      v12 = t->tm_hour % 12;
      if ( !v12 )
        v12 = 12;
      v7 = modifier;
      v13 = Format;
      if ( modifier == 35 )
        v13 = "%ld";
      sprintf_s<64>((char (*)[64])_buf, v13, v12);
      v14 = t->tm_hour % 12;
      if ( !v14 )
        goto LABEL_11;
      v9 = v14 < 10;
      goto LABEL_9;
    case 'M':
      v7 = modifier;
      v17 = Format;
      if ( modifier == 35 )
        v17 = "%ld";
      sprintf_s<64>((char (*)[64])_buf, v17, t->tm_min);
      v9 = t->tm_min < 10;
      goto LABEL_9;
    case 'S':
      v7 = modifier;
      v18 = Format;
      if ( modifier == 35 )
        v18 = "%ld";
      sprintf_s<64>((char (*)[64])_buf, v18, t->tm_sec);
      v9 = t->tm_sec < 10;
      goto LABEL_9;
    case 'U':
      v19 = (t->tm_yday - t->tm_wday + 7) / 7;
      goto LABEL_44;
    case 'W':
      tm_wday = t->tm_wday;
      tm_yday = t->tm_yday;
      if ( tm_wday )
        v22 = tm_yday - tm_wday + 8;
      else
        v22 = tm_yday + 1;
      v19 = v22 / 7;
      goto LABEL_44;
    case 'X':
      stlp_std::priv::__subformat<wchar_t,stlp_std::priv::_WTime_Info>(buf, ct, &table->_M_time_format, table, t);
      return;
    case 'Y':
      v19 = t->tm_year + 1900;
LABEL_44:
      v15 = stlp_std::priv::__write_integer(_buf, 0, v19);
      goto LABEL_45;
    case 'c':
      p_M_date_time_format = &table->_M_date_time_format;
      if ( modifier == 35 )
        p_M_date_time_format = &table->_M_long_date_time_format;
      goto LABEL_5;
    case 'd':
      v7 = modifier;
      v8 = Format;
      if ( modifier == 35 )
        v8 = "%ld";
      sprintf_s<64>((char (*)[64])_buf, v8, t->tm_mday);
      v9 = t->tm_mday < 10;
      goto LABEL_9;
    case 'e':
      sprintf_s<64>((char (*)[64])_buf, "%2ld", t->tm_mday);
      stlp_std::priv::__append_1(buf, _buf, &_buf[2], ct);
      return;
    case 'j':
      v15 = stlp_std::priv::__write_integer(_buf, 0, t->tm_yday + 1);
      goto LABEL_45;
    case 'm':
      v7 = modifier;
      v16 = Format;
      if ( modifier == 35 )
        v16 = "%ld";
      sprintf_s<64>((char (*)[64])_buf, v16, t->tm_mon + 1);
      v9 = t->tm_mon + 1 < 10;
LABEL_9:
      if ( v9 )
      {
        v10 = &_buf[1];
        if ( v7 == 35 )
          goto LABEL_46;
      }
LABEL_11:
      stlp_std::priv::__append_1(buf, _buf, &_buf[2], ct);
      break;
    case 'w':
      v15 = stlp_std::priv::__write_integer(_buf, 0, t->tm_wday);
      goto LABEL_45;
    case 'x':
      p_M_date_time_format = &table->_M_date_format;
      if ( modifier == 35 )
        p_M_date_time_format = &table->_M_long_date_format;
LABEL_5:
      stlp_std::priv::__subformat<wchar_t,stlp_std::priv::_WTime_Info>(buf, ct, p_M_date_time_format, table, t);
      return;
    case 'y':
      v15 = stlp_std::priv::__write_integer(_buf, 0, (t->tm_year + 1900) % 100);
LABEL_45:
      v10 = v15;
LABEL_46:
      stlp_std::priv::__append_1(buf, _buf, v10, ct);
      break;
    default:
      return;
  }
}
