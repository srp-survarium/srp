_iobuf *__usercall _fdopen@<eax>(int a1@<ebx>, int a2@<esi>, int filedes, const char *mode)
{
  const char *v4; // ecx
  char v6; // al
  int v7; // ebx
  int v8; // edx
  _iobuf *v9; // eax
  _iobuf *v10; // esi
  int _Expr_val; // [esp+34h] [ebp+Ch]

  v4 = mode;
  if ( !mode )
    goto LABEL_2;
  if ( filedes == -2 )
  {
    *_errno() = 9;
    return 0;
  }
  if ( filedes < 0
    || filedes >= _nhandle
    || (a2 = 1, (*(&__pioinfo[filedes >> 5]->osfile + 64 * (filedes & 0x1F)) & 1) == 0) )
  {
    *_errno() = 9;
    goto LABEL_3;
  }
  while ( *v4 == 32 )
    ++v4;
  v6 = *v4;
  if ( *v4 != 97 )
  {
    if ( v6 == 114 )
    {
      v7 = 1;
      goto LABEL_18;
    }
    if ( v6 != 119 )
    {
LABEL_2:
      *_errno() = 22;
LABEL_3:
      _invalid_parameter(a1, 0, a2);
      return 0;
    }
  }
  v7 = 2;
LABEL_18:
  v8 = 0;
  _Expr_val = 0;
  a1 = _commode | v7;
  while ( *++v4 && a2 )
  {
    if ( *v4 != 32 )
    {
      switch ( *v4 )
      {
        case '+':
          if ( (a1 & 0x80u) == 0 )
            a1 = a1 & 0xFFFFFF7C | 0x80;
          else
LABEL_34:
            a2 = 0;
          break;
        case 'b':
          goto LABEL_27;
        case 'c':
          if ( v8 )
            goto LABEL_34;
          v8 = 1;
          a1 |= 0x4000u;
          break;
        case 'n':
          if ( v8 )
            goto LABEL_34;
          v8 = 1;
          a1 &= ~0x4000u;
          break;
        case 't':
LABEL_27:
          if ( _Expr_val )
            goto LABEL_34;
          _Expr_val = 1;
          break;
        default:
          goto LABEL_2;
      }
    }
  }
  while ( *v4 == 32 )
    ++v4;
  if ( *v4 )
    goto LABEL_2;
  v9 = _getstream();
  v10 = v9;
  if ( v9 )
  {
    ++_cflush;
    v9->_flag = a1;
    v9->_file = filedes;
    _unlock_file(v9);
    return v10;
  }
  else
  {
    *_errno() = 24;
    return 0;
  }
}
