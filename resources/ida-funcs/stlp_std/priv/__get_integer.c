BOOL __cdecl stlp_std::priv::__get_integer<char *,long double,char>(
        char **__first,
        char **__last,
        int __base,
        long double *__val,
        int __got,
        bool __is_negative,
        char __separator,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__grouping)
{
  double v8; // st7
  const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v9; // edx
  double v10; // st6
  char v11; // bl
  char *v12; // edi
  char v13; // al
  int v14; // eax
  double v15; // st5
  bool v16; // c0
  bool v17; // c3
  char v19; // [esp+6h] [ebp-6Eh]
  bool v20; // [esp+7h] [ebp-6Dh]
  double v21; // [esp+14h] [ebp-60h]
  double v22; // [esp+1Ch] [ebp-58h]
  double i; // [esp+24h] [ebp-50h]
  char first1[68]; // [esp+2Ch] [ebp-48h] BYREF

  v8 = 0.0;
  v9 = __grouping;
  v21 = 0.0;
  v10 = (double)__base;
  v22 = v10;
  v20 = __grouping->_M_start_of_storage._M_data != __grouping->_M_finish;
  v11 = 0;
  v19 = 0;
  v12 = first1;
  for ( i = 1.797693134862316e308 / v10; *__first != *__last; ++*__first )
  {
    v13 = **__first;
    if ( v20 && v13 == __separator )
    {
      *v12++ = v11;
      v11 = 0;
    }
    else
    {
      if ( (unsigned int)v13 <= 0x7F )
      {
        LOBYTE(v14) = stlp_std::priv::__digit_val_table(v13);
        v9 = __grouping;
        v14 = (unsigned __int8)v14;
        v10 = v22;
        v8 = v21;
      }
      else
      {
        v14 = 255;
      }
      if ( v14 >= __base )
        break;
      ++__got;
      ++v11;
      if ( i >= v8 )
      {
        v15 = v10 * v8 + (double)v14;
        if ( 0.0 == v8 )
        {
          v8 = v15;
          goto LABEL_18;
        }
        if ( v19 )
        {
          v8 = v15;
        }
        else
        {
          v16 = v15 < v8;
          v17 = v15 == v8;
          v8 = v15;
          if ( !v16 && !v17 )
          {
            v19 = 0;
LABEL_18:
            v21 = v8;
            continue;
          }
        }
        v19 = 1;
        goto LABEL_18;
      }
      v19 = 1;
    }
  }
  if ( v20 && v12 != first1 )
    *v12++ = v11;
  if ( __got <= 0 )
    return 0;
  if ( v19 )
  {
    v8 = 1.797693134862316e308;
  }
  else if ( __is_negative )
  {
    v8 = -v8;
  }
  *__val = v8;
  return !v19 && (!v20 || stlp_std::priv::__valid_grouping(first1, v12, v9->_M_start_of_storage._M_data, v9->_M_finish));
}


BOOL __cdecl stlp_std::priv::__get_integer<wchar_t *,long double,wchar_t>(
        wchar_t **__first,
        wchar_t **__last,
        int __base,
        long double *__val,
        int __got,
        bool __is_negative,
        wchar_t __separator,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__grouping)
{
  double v8; // st7
  const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v9; // edx
  double v10; // st6
  char v11; // bl
  char *v12; // edi
  unsigned __int16 v13; // ax
  int v14; // eax
  double v15; // st5
  bool v16; // c0
  bool v17; // c3
  char v19; // [esp+6h] [ebp-6Eh]
  bool v20; // [esp+7h] [ebp-6Dh]
  double v21; // [esp+14h] [ebp-60h]
  double v22; // [esp+1Ch] [ebp-58h]
  double i; // [esp+24h] [ebp-50h]
  char first1[68]; // [esp+2Ch] [ebp-48h] BYREF

  v8 = 0.0;
  v9 = __grouping;
  v21 = 0.0;
  v10 = (double)__base;
  v22 = v10;
  v20 = __grouping->_M_start_of_storage._M_data != __grouping->_M_finish;
  v11 = 0;
  v19 = 0;
  v12 = first1;
  for ( i = 1.797693134862316e308 / v10; *__first != *__last; ++*__first )
  {
    v13 = **__first;
    if ( v20 && v13 == __separator )
    {
      *v12++ = v11;
      v11 = 0;
    }
    else
    {
      if ( v13 <= 0x7Fu )
      {
        LOBYTE(v14) = stlp_std::priv::__digit_val_table(v13);
        v9 = __grouping;
        v14 = (unsigned __int8)v14;
        v10 = v22;
        v8 = v21;
      }
      else
      {
        v14 = 255;
      }
      if ( v14 >= __base )
        break;
      ++__got;
      ++v11;
      if ( i >= v8 )
      {
        v15 = v10 * v8 + (double)v14;
        if ( 0.0 == v8 )
        {
          v8 = v15;
          goto LABEL_18;
        }
        if ( v19 )
        {
          v8 = v15;
        }
        else
        {
          v16 = v15 < v8;
          v17 = v15 == v8;
          v8 = v15;
          if ( !v16 && !v17 )
          {
            v19 = 0;
LABEL_18:
            v21 = v8;
            continue;
          }
        }
        v19 = 1;
        goto LABEL_18;
      }
      v19 = 1;
    }
  }
  if ( v20 && v12 != first1 )
    *v12++ = v11;
  if ( __got <= 0 )
    return 0;
  if ( v19 )
  {
    v8 = 1.797693134862316e308;
  }
  else if ( __is_negative )
  {
    v8 = -v8;
  }
  *__val = v8;
  return !v19 && (!v20 || stlp_std::priv::__valid_grouping(first1, v12, v9->_M_start_of_storage._M_data, v9->_M_finish));
}
