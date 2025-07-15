void __cdecl stlp_std::priv::__write_formatted_timeT<char,stlp_std::priv::_Time_Info>(
        stlp_std::priv::__basic_iostring<char> *buf,
        const stlp_std::ctype<char> *ct,
        char format,
        char modifier,
        const stlp_std::priv::_Time_Info *table,
        const tm *t)
{
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *p_M_date_time_format; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  int v10; // edx
  char *v11; // eax
  int v12; // edx
  char v13; // bl
  char *v14; // eax
  bool v15; // cc
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  int tm_wday; // eax
  int tm_yday; // esi
  int v21; // esi
  char v22; // al
  int v23; // [esp-8h] [ebp-5Ch]
  stlp_std::forward_iterator_tag v24; // [esp+Fh] [ebp-45h] BYREF
  char v25[64]; // [esp+10h] [ebp-44h] BYREF

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
      v9 = a2l;
      if ( modifier == 35 )
        v9 = "%ld";
      sprintf_s<64>((char (*)[64])v25, v9, t->tm_hour);
      if ( t->tm_hour >= 10 || (v8 = &v25[1], modifier != 35) )
        v8 = &v25[2];
      goto LABEL_58;
    case 'I':
      v10 = t->tm_hour % 12;
      if ( !v10 )
        v10 = 12;
      v11 = a2l;
      if ( modifier == 35 )
        v11 = "%ld";
      sprintf_s<64>((char (*)[64])v25, v11, v10);
      v12 = t->tm_hour % 12;
      if ( !v12 || v12 >= 10 || (v8 = &v25[1], modifier != 35) )
        v8 = &v25[2];
      goto LABEL_58;
    case 'M':
      v13 = modifier;
      v16 = a2l;
      if ( modifier == 35 )
        v16 = "%ld";
      sprintf_s<64>((char (*)[64])v25, v16, t->tm_min);
      v15 = t->tm_min < 10;
      goto LABEL_41;
    case 'S':
      v13 = modifier;
      v17 = a2l;
      if ( modifier == 35 )
        v17 = "%ld";
      sprintf_s<64>((char (*)[64])v25, v17, t->tm_sec);
      v15 = t->tm_sec < 10;
      goto LABEL_41;
    case 'U':
      v18 = stlp_std::priv::__write_integer(v25, 0, (t->tm_yday - t->tm_wday + 7) / 7);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_appendT<char const *>(
        buf,
        v25,
        v18,
        &v24);
      return;
    case 'W':
      tm_wday = t->tm_wday;
      tm_yday = t->tm_yday;
      if ( tm_wday )
        v21 = tm_yday - tm_wday + 8;
      else
        v21 = tm_yday + 1;
      v8 = stlp_std::priv::__write_integer(v25, 0, v21 / 7);
      goto LABEL_58;
    case 'X':
      stlp_std::priv::__subformat<char,stlp_std::priv::_Time_Info>(buf, ct, &table->_M_time_format, table, t);
      return;
    case 'Y':
      v8 = stlp_std::priv::__write_integer(v25, 0, t->tm_year + 1900);
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
      v7 = a2l;
      if ( modifier == 35 )
        v7 = "%ld";
      sprintf_s<64>((char (*)[64])v25, v7, t->tm_mday);
      if ( t->tm_mday >= 10 || (v8 = &v25[1], modifier != 35) )
        v8 = &v25[2];
      goto LABEL_58;
    case 'e':
      sprintf_s<64>((char (*)[64])v25, "%2ld", t->tm_mday);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_appendT<char const *>(
        buf,
        v25,
        &v25[2],
        &v24);
      return;
    case 'j':
      v23 = t->tm_yday + 1;
      goto LABEL_55;
    case 'm':
      v13 = modifier;
      v14 = a2l;
      if ( modifier == 35 )
        v14 = "%ld";
      sprintf_s<64>((char (*)[64])v25, v14, t->tm_mon + 1);
      v15 = t->tm_mon + 1 < 10;
LABEL_41:
      if ( !v15 || (v8 = &v25[1], v13 != 35) )
        v8 = &v25[2];
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
      v8 = stlp_std::priv::__write_integer(v25, 0, v23);
LABEL_58:
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_appendT<char const *>(
        buf,
        v25,
        v8,
        &v24);
      break;
    default:
      return;
  }
}


void __cdecl stlp_std::priv::__write_formatted_timeT<wchar_t,stlp_std::priv::_WTime_Info>(
        stlp_std::priv::__basic_iostring<wchar_t> *buf,
        const stlp_std::ctype<wchar_t> *ct,
        char format,
        char modifier,
        const stlp_std::priv::_WTime_Info *table,
        const tm *t)
{
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *p_M_date_time_format; // eax
  char v7; // bl
  char *v8; // eax
  bool v9; // cc
  char *v10; // edx
  char *v11; // eax
  int v12; // edx
  char *v13; // eax
  int v14; // edx
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  int v19; // eax
  int tm_wday; // eax
  int tm_yday; // esi
  int v22; // esi
  wchar_t v23; // ax
  char v24[64]; // [esp+Ch] [ebp-44h] BYREF

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
      v11 = a2l;
      if ( modifier == 35 )
        v11 = "%ld";
      sprintf_s<64>((char (*)[64])v24, v11, t->tm_hour);
      v9 = t->tm_hour < 10;
      goto LABEL_9;
    case 'I':
      v12 = t->tm_hour % 12;
      if ( !v12 )
        v12 = 12;
      v7 = modifier;
      v13 = a2l;
      if ( modifier == 35 )
        v13 = "%ld";
      sprintf_s<64>((char (*)[64])v24, v13, v12);
      v14 = t->tm_hour % 12;
      if ( !v14 )
        goto LABEL_11;
      v9 = v14 < 10;
      goto LABEL_9;
    case 'M':
      v7 = modifier;
      v17 = a2l;
      if ( modifier == 35 )
        v17 = "%ld";
      sprintf_s<64>((char (*)[64])v24, v17, t->tm_min);
      v9 = t->tm_min < 10;
      goto LABEL_9;
    case 'S':
      v7 = modifier;
      v18 = a2l;
      if ( modifier == 35 )
        v18 = "%ld";
      sprintf_s<64>((char (*)[64])v24, v18, t->tm_sec);
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
      v15 = stlp_std::priv::__write_integer(v24, 0, v19);
      goto LABEL_45;
    case 'c':
      p_M_date_time_format = &table->_M_date_time_format;
      if ( modifier == 35 )
        p_M_date_time_format = &table->_M_long_date_time_format;
      goto LABEL_5;
    case 'd':
      v7 = modifier;
      v8 = a2l;
      if ( modifier == 35 )
        v8 = "%ld";
      sprintf_s<64>((char (*)[64])v24, v8, t->tm_mday);
      v9 = t->tm_mday < 10;
      goto LABEL_9;
    case 'e':
      sprintf_s<64>((char (*)[64])v24, "%2ld", t->tm_mday);
      stlp_std::priv::__append_1(buf, v24, &v24[2], ct);
      return;
    case 'j':
      v15 = stlp_std::priv::__write_integer(v24, 0, t->tm_yday + 1);
      goto LABEL_45;
    case 'm':
      v7 = modifier;
      v16 = a2l;
      if ( modifier == 35 )
        v16 = "%ld";
      sprintf_s<64>((char (*)[64])v24, v16, t->tm_mon + 1);
      v9 = t->tm_mon + 1 < 10;
LABEL_9:
      if ( v9 )
      {
        v10 = &v24[1];
        if ( v7 == 35 )
          goto LABEL_46;
      }
LABEL_11:
      stlp_std::priv::__append_1(buf, v24, &v24[2], ct);
      break;
    case 'w':
      v15 = stlp_std::priv::__write_integer(v24, 0, t->tm_wday);
      goto LABEL_45;
    case 'x':
      p_M_date_time_format = &table->_M_date_format;
      if ( modifier == 35 )
        p_M_date_time_format = &table->_M_long_date_format;
LABEL_5:
      stlp_std::priv::__subformat<wchar_t,stlp_std::priv::_WTime_Info>(buf, ct, p_M_date_time_format, table, t);
      return;
    case 'y':
      v15 = stlp_std::priv::__write_integer(v24, 0, (t->tm_year + 1900) % 100);
LABEL_45:
      v10 = v15;
LABEL_46:
      stlp_std::priv::__append_1(buf, v24, v10, ct);
      break;
    default:
      return;
  }
}
