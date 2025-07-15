int __cdecl stlp_std::priv::__get_base_or_zero<stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>,char>(
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__in_ite,
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char> > *__end,
        char __flags,
        stlp_std::ctype<char> *__c_type)
{
  const char *v4; // edi
  const char *v5; // eax
  int v6; // ebx
  char *M_gnext; // eax
  int v8; // eax
  char M_c; // al
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *M_buf; // ecx
  char *v11; // eax
  int v12; // eax
  char v13; // al
  char v14; // al
  char v15; // al
  int v16; // edi
  char v17; // al
  char v18; // al
  char v19; // al
  bool __negative; // [esp+13h] [ebp-Dh]
  char __atoms[8]; // [esp+14h] [ebp-Ch] BYREF

  v4 = stlp_std::priv::__narrow_atoms() + 5;
  v5 = stlp_std::priv::__narrow_atoms();
  __c_type->do_widen(__c_type, v5, v4, __atoms);
  v6 = 0;
  __negative = 0;
  if ( !__in_ite->_M_have_c )
  {
    M_gnext = __in_ite->_M_buf->_M_gnext;
    if ( M_gnext >= __in_ite->_M_buf->_M_gend )
      v8 = __in_ite->_M_buf->underflow(__in_ite->_M_buf);
    else
      v8 = (unsigned __int8)*M_gnext;
    __in_ite->_M_c = v8;
    __in_ite->_M_eof = v8 == -1;
    __in_ite->_M_have_c = 1;
  }
  M_c = __in_ite->_M_c;
  if ( M_c == __atoms[1] )
  {
    __negative = 1;
  }
  else if ( M_c != __atoms[0] )
  {
    goto LABEL_13;
  }
  M_buf = __in_ite->_M_buf;
  v11 = __in_ite->_M_buf->_M_gnext;
  if ( v11 >= __in_ite->_M_buf->_M_gend )
    M_buf->uflow(M_buf);
  else
    M_buf->_M_gnext = v11 + 1;
  __in_ite->_M_have_c = 0;
LABEL_13:
  v12 = __flags & 0x38;
  if ( v12 == 8 )
    goto LABEL_31;
  if ( v12 != 16 )
  {
    if ( v12 == 32 )
    {
      v16 = 8;
      return v6 | (2 * (__negative | (2 * v16)));
    }
    if ( !stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(__in_ite, __end) )
    {
      v13 = stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::operator*(__in_ite);
      if ( v13 == __atoms[2] )
      {
        stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::operator++(__in_ite);
        if ( stlp_std::operator!=<char,stlp_std::char_traits<char>>(__in_ite, __end) )
        {
          v14 = stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::operator*(__in_ite);
          if ( v14 == __atoms[3]
            || (v15 = stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::operator*(__in_ite),
                v15 == __atoms[4]) )
          {
            stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::operator++(__in_ite);
            v16 = 16;
            return v6 | (2 * (__negative | (2 * v16)));
          }
        }
        v16 = 8;
LABEL_23:
        v6 = 1;
        return v6 | (2 * (__negative | (2 * v16)));
      }
    }
LABEL_31:
    v16 = 10;
    return v6 | (2 * (__negative | (2 * v16)));
  }
  v16 = 16;
  if ( !stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(__in_ite, __end) )
  {
    v17 = stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::operator*(__in_ite);
    if ( v17 == __atoms[2] )
    {
      stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::operator++(__in_ite);
      if ( !stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::equal(__in_ite, __end) )
      {
        v18 = stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::operator*(__in_ite);
        if ( v18 == __atoms[3]
          || (v19 = stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::operator*(__in_ite),
              v19 == __atoms[4]) )
        {
          stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>::operator++(__in_ite);
          return v6 | (2 * (__negative | (2 * v16)));
        }
      }
      goto LABEL_23;
    }
  }
  return v6 | (2 * (__negative | (2 * v16)));
}


int __cdecl stlp_std::priv::__get_base_or_zero<stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,wchar_t>(
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__in_ite,
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__end,
        char __flags,
        stlp_std::ctype<wchar_t> *__c_type)
{
  const char *v4; // edi
  const char *v5; // eax
  int v6; // ebx
  wchar_t *M_gnext; // eax
  unsigned __int16 v8; // ax
  wchar_t M_c; // ax
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t> > *M_buf; // ecx
  wchar_t *v11; // eax
  wchar_t *v12; // eax
  int v13; // eax
  wchar_t v14; // ax
  wchar_t v15; // ax
  wchar_t v16; // ax
  int v17; // edi
  wchar_t v18; // ax
  wchar_t v19; // ax
  wchar_t v20; // ax
  bool __negative; // [esp+13h] [ebp-11h]
  wchar_t __atoms[6]; // [esp+14h] [ebp-10h] BYREF

  v4 = stlp_std::priv::__narrow_atoms() + 5;
  v5 = stlp_std::priv::__narrow_atoms();
  __c_type->do_widen(__c_type, v5, v4, __atoms);
  v6 = 0;
  __negative = 0;
  if ( !__in_ite->_M_have_c )
  {
    M_gnext = __in_ite->_M_buf->_M_gnext;
    if ( M_gnext >= __in_ite->_M_buf->_M_gend )
      v8 = __in_ite->_M_buf->underflow(__in_ite->_M_buf);
    else
      v8 = *M_gnext;
    __in_ite->_M_c = v8;
    __in_ite->_M_eof = v8 == 0xFFFF;
    __in_ite->_M_have_c = 1;
  }
  M_c = __in_ite->_M_c;
  if ( M_c != __atoms[1] )
  {
    if ( M_c != __atoms[0] )
      goto LABEL_14;
    M_buf = __in_ite->_M_buf;
    v12 = __in_ite->_M_buf->_M_gnext;
    if ( v12 < __in_ite->_M_buf->_M_gend )
    {
      M_buf->_M_gnext = v12 + 1;
      goto LABEL_13;
    }
LABEL_12:
    M_buf->uflow(M_buf);
    goto LABEL_13;
  }
  M_buf = __in_ite->_M_buf;
  v11 = __in_ite->_M_buf->_M_gnext;
  __negative = 1;
  if ( v11 >= __in_ite->_M_buf->_M_gend )
    goto LABEL_12;
  M_buf->_M_gnext = v11 + 1;
LABEL_13:
  __in_ite->_M_have_c = 0;
LABEL_14:
  v13 = __flags & 0x38;
  if ( v13 == 8 )
    goto LABEL_32;
  if ( v13 != 16 )
  {
    if ( v13 == 32 )
    {
      v17 = 8;
      return v6 | (2 * (__negative | (2 * v17)));
    }
    if ( !stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::equal(__in_ite, __end) )
    {
      v14 = stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator*(__in_ite);
      if ( v14 == __atoms[2] )
      {
        stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator++(__in_ite);
        if ( stlp_std::operator!=<wchar_t,stlp_std::char_traits<wchar_t>>(__in_ite, __end) )
        {
          v15 = stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator*(__in_ite);
          if ( v15 == __atoms[3]
            || (v16 = stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator*(__in_ite),
                v16 == __atoms[4]) )
          {
            stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator++(__in_ite);
            v17 = 16;
            return v6 | (2 * (__negative | (2 * v17)));
          }
        }
        v17 = 8;
LABEL_24:
        v6 = 1;
        return v6 | (2 * (__negative | (2 * v17)));
      }
    }
LABEL_32:
    v17 = 10;
    return v6 | (2 * (__negative | (2 * v17)));
  }
  v17 = 16;
  if ( !stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::equal(__in_ite, __end) )
  {
    v18 = stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator*(__in_ite);
    if ( v18 == __atoms[2] )
    {
      stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator++(__in_ite);
      if ( !stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::equal(__in_ite, __end) )
      {
        v19 = stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator*(__in_ite);
        if ( v19 == __atoms[3]
          || (v20 = stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator*(__in_ite),
              v20 == __atoms[4]) )
        {
          stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator++(__in_ite);
          return v6 | (2 * (__negative | (2 * v17)));
        }
      }
      goto LABEL_24;
    }
  }
  return v6 | (2 * (__negative | (2 * v17)));
}
