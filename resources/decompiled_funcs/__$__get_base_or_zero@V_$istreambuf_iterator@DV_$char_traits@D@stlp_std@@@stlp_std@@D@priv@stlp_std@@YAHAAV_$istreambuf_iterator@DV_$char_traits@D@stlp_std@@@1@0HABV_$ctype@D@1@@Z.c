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
