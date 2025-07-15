_iobuf *__cdecl _fdopen(int filedes, const char *mode)
{
  const char *v2; // ecx
  int v4; // esi
  char v5; // al
  int v6; // ebx
  int v7; // edx
  unsigned int v8; // ebx
  _iobuf *v9; // eax
  _iobuf *v10; // esi
  int _Expr_val; // [esp+34h] [ebp+Ch]

  v2 = mode;
  if ( !mode )
    goto LABEL_2;
  if ( filedes == -2 )
  {
    *_errno() = 9;
    return 0;
  }
  if ( filedes < 0
    || filedes >= _nhandle
    || (v4 = 1, (*(&__pioinfo[filedes >> 5]->osfile + 64 * (filedes & 0x1F)) & 1) == 0) )
  {
    *_errno() = 9;
    goto LABEL_3;
  }
  while ( *v2 == 32 )
    ++v2;
  v5 = *v2;
  if ( *v2 != 97 )
  {
    if ( v5 == 114 )
    {
      v6 = 1;
      goto LABEL_18;
    }
    if ( v5 != 119 )
    {
LABEL_2:
      *_errno() = 22;
LABEL_3:
      _invalid_parameter(0, 0, 0, 0, 0);
      return 0;
    }
  }
  v6 = 2;
LABEL_18:
  v7 = 0;
  _Expr_val = 0;
  v8 = _commode | v6;
  while ( *++v2 && v4 )
  {
    if ( *v2 != 32 )
    {
      switch ( *v2 )
      {
        case '+':
          if ( (v8 & 0x80u) == 0 )
            v8 = v8 & 0xFFFFFF7C | 0x80;
          else
LABEL_34:
            v4 = 0;
          break;
        case 'b':
          goto LABEL_27;
        case 'c':
          if ( v7 )
            goto LABEL_34;
          v7 = 1;
          v8 |= 0x4000u;
          break;
        case 'n':
          if ( v7 )
            goto LABEL_34;
          v7 = 1;
          v8 &= ~0x4000u;
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
  while ( *v2 == 32 )
    ++v2;
  if ( *v2 )
    goto LABEL_2;
  v9 = _getstream();
  v10 = v9;
  if ( v9 )
  {
    ++_cflush;
    v9->_flag = v8;
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
