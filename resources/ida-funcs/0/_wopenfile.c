_iobuf *__usercall _wopenfile@<eax>(
        unsigned int a1@<ebx>,
        const wchar_t *filename,
        const wchar_t *mode,
        int shflag,
        _iobuf *str)
{
  const wchar_t *v5; // esi
  int v6; // eax
  _iobuf *result; // eax
  int v8; // ecx
  unsigned __int16 v9; // ax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  const wchar_t *v19; // ecx
  int encodingFlag; // [esp+Ch] [ebp-10h]
  int commodeset; // [esp+10h] [ebp-Ch]
  int scanset; // [esp+14h] [ebp-8h]
  unsigned int streamflag; // [esp+18h] [ebp-4h]

  v5 = mode;
  commodeset = 0;
  scanset = 0;
  encodingFlag = 0;
  while ( *v5 == 32 )
    ++v5;
  v6 = *v5;
  switch ( v6 )
  {
    case 'a':
      a1 = 265;
      break;
    case 'r':
      a1 = 0;
      streamflag = _commode | 1;
      goto LABEL_13;
    case 'w':
      a1 = 769;
      break;
    default:
LABEL_7:
      *_errno() = 22;
      _invalid_parameter(a1, 0, (int)v5);
      return 0;
  }
  streamflag = _commode | 2;
LABEL_13:
  v8 = 1;
  v9 = *++v5;
  if ( !*v5 )
    goto LABEL_67;
  while ( v8 )
  {
    if ( v9 > 0x53u )
    {
      v15 = v9 - 84;
      if ( !v15 )
      {
        if ( (a1 & 0x1000) == 0 )
        {
          a1 |= 0x1000u;
          goto LABEL_49;
        }
        goto LABEL_47;
      }
      v16 = v15 - 14;
      if ( v16 )
      {
        v17 = v16 - 1;
        if ( v17 )
        {
          v18 = v17 - 11;
          if ( v18 )
          {
            if ( v18 != 6 )
              goto LABEL_7;
            if ( (a1 & 0xC000) != 0 )
              goto LABEL_47;
            a1 |= 0x4000u;
          }
          else
          {
            if ( commodeset )
              goto LABEL_47;
            streamflag &= ~0x4000u;
            commodeset = 1;
          }
        }
        else
        {
          if ( commodeset )
            goto LABEL_47;
          streamflag |= 0x4000u;
          commodeset = 1;
        }
      }
      else
      {
        if ( (a1 & 0xC000) != 0 )
          goto LABEL_47;
        a1 |= 0x8000u;
      }
    }
    else if ( v9 == 83 )
    {
      if ( scanset )
        goto LABEL_47;
      scanset = 1;
      a1 |= 0x20u;
    }
    else
    {
      v10 = v9 - 32;
      if ( v10 )
      {
        v11 = v10 - 11;
        if ( v11 )
        {
          v12 = v11 - 1;
          if ( !v12 )
          {
            encodingFlag = 1;
LABEL_47:
            v8 = 0;
            goto LABEL_49;
          }
          v13 = v12 - 24;
          if ( v13 )
          {
            v14 = v13 - 10;
            if ( v14 )
            {
              if ( v14 != 4 )
                goto LABEL_7;
              if ( scanset )
                goto LABEL_47;
              scanset = 1;
              a1 |= 0x10u;
            }
            else
            {
              a1 |= 0x80u;
            }
          }
          else
          {
            if ( (a1 & 0x40) != 0 )
              goto LABEL_47;
            a1 |= 0x40u;
          }
        }
        else
        {
          if ( (a1 & 2) != 0 )
            goto LABEL_47;
          a1 = a1 & 0xFFFFFFFC | 2;
          streamflag = streamflag & 0xFFFFFF7C | 0x80;
        }
      }
    }
LABEL_49:
    v9 = *++v5;
    if ( !*v5 )
      break;
  }
  if ( !encodingFlag )
    goto LABEL_67;
  while ( *v5 == 32 )
    ++v5;
  if ( wcsncmp(L"ccs", v5, 3u) )
    goto LABEL_7;
  for ( v5 += 3; *v5 == 32; ++v5 )
    ;
  if ( *v5 != 61 )
    goto LABEL_7;
  do
    ++v5;
  while ( *v5 == 32 );
  if ( !_wcsnicmp(v5, L"UTF-8", 5u) )
  {
    v5 += 5;
    a1 |= 0x40000u;
    goto LABEL_67;
  }
  if ( !_wcsnicmp(v5, L"UTF-16LE", 8u) )
  {
    v5 += 8;
    a1 |= (unsigned int)&loc_20000;
    goto LABEL_67;
  }
  if ( _wcsnicmp(v5, L"UNICODE", 7u) )
    goto LABEL_7;
  v5 += 7;
  a1 |= (unsigned int)&_sbh_sizeHeaderList;
LABEL_67:
  while ( *v5 == 32 )
    ++v5;
  if ( *v5 )
    goto LABEL_7;
  if ( _wsopen_s((int *)&mode, filename, a1, shflag, 384) )
    return 0;
  result = str;
  ++_cflush;
  str->_flag = streamflag;
  v19 = mode;
  result->_cnt = 0;
  result->_ptr = 0;
  result->_base = 0;
  result->_tmpfname = 0;
  result->_file = (int)v19;
  return result;
}
