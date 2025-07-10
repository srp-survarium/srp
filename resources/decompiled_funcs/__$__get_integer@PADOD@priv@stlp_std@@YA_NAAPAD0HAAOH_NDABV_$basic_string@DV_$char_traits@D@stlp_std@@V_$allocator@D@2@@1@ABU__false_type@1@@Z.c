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
  bool __ovflow; // [esp+6h] [ebp-6Eh]
  bool __is_group; // [esp+7h] [ebp-6Dh]
  double __result; // [esp+14h] [ebp-60h]
  double v22; // [esp+1Ch] [ebp-58h]
  double __over_base; // [esp+24h] [ebp-50h]
  char __group_sizes[68]; // [esp+2Ch] [ebp-48h] BYREF

  v8 = 0.0;
  v9 = __grouping;
  __result = 0.0;
  v10 = (double)__base;
  v22 = v10;
  __is_group = __grouping->_M_start_of_storage._M_data != __grouping->_M_finish;
  v11 = 0;
  __ovflow = 0;
  v12 = __group_sizes;
  for ( __over_base = 1.797693134862316e308 / v10; *__first != *__last; ++*__first )
  {
    v13 = **__first;
    if ( __is_group && v13 == __separator )
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
        v8 = __result;
      }
      else
      {
        v14 = 255;
      }
      if ( v14 >= __base )
        break;
      ++__got;
      ++v11;
      if ( __over_base >= v8 )
      {
        v15 = v10 * v8 + (double)v14;
        if ( 0.0 == v8 )
        {
          v8 = v15;
          goto LABEL_18;
        }
        if ( __ovflow )
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
            __ovflow = 0;
LABEL_18:
            __result = v8;
            continue;
          }
        }
        __ovflow = 1;
        goto LABEL_18;
      }
      __ovflow = 1;
    }
  }
  if ( __is_group && v12 != __group_sizes )
    *v12++ = v11;
  if ( __got <= 0 )
    return 0;
  if ( __ovflow )
  {
    v8 = 1.797693134862316e308;
  }
  else if ( __is_negative )
  {
    v8 = -v8;
  }
  *__val = v8;
  return !__ovflow
      && (!__is_group
       || stlp_std::priv::__valid_grouping(__group_sizes, v12, v9->_M_start_of_storage._M_data, v9->_M_finish));
}
