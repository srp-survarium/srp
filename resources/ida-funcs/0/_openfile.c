_iobuf *__usercall _openfile@<eax>(int a1@<edi>, char *filename, char *mode, int shflag, _iobuf *str)
{
  char v6; // al
  _iobuf *result; // eax
  int v8; // ecx
  char *v9; // esi
  char v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int pfh; // [esp+8h] [ebp-10h] BYREF
  int v22; // [esp+Ch] [ebp-Ch]
  int v23; // [esp+10h] [ebp-8h]
  unsigned int v24; // [esp+14h] [ebp-4h]
  unsigned int oflag; // [esp+24h] [ebp+Ch]

  v24 = _commode;
  v22 = 0;
  v23 = 0;
  pfh = 0;
  while ( *mode == 32 )
    ++mode;
  v6 = *mode;
  if ( *mode == 97 )
  {
    oflag = 265;
LABEL_11:
    v24 |= 2u;
    goto LABEL_12;
  }
  if ( v6 != 114 )
  {
    if ( v6 != 119 )
    {
      *_errno() = 22;
      _invalid_parameter(0, a1, (int)mode);
      return 0;
    }
    oflag = 769;
    goto LABEL_11;
  }
  v24 |= 1u;
  oflag = 0;
LABEL_12:
  v8 = 1;
  v9 = mode + 1;
  v10 = *v9;
  if ( !*v9 )
    goto LABEL_67;
  a1 = 0x4000;
  while ( v8 )
  {
    if ( v10 > 83 )
    {
      v16 = v10 - 84;
      if ( !v16 )
      {
        if ( (oflag & 0x1000) == 0 )
        {
          oflag |= 0x1000u;
          goto LABEL_49;
        }
        goto LABEL_47;
      }
      v17 = v16 - 14;
      if ( v17 )
      {
        v18 = v17 - 1;
        if ( v18 )
        {
          v19 = v18 - 11;
          if ( v19 )
          {
            if ( v19 != 6 )
              goto LABEL_69;
            if ( (oflag & 0xC000) != 0 )
              goto LABEL_47;
            oflag |= 0x4000u;
          }
          else
          {
            if ( v22 )
              goto LABEL_47;
            v24 &= ~0x4000u;
            v22 = 1;
          }
        }
        else
        {
          if ( v22 )
            goto LABEL_47;
          v24 |= 0x4000u;
          v22 = 1;
        }
      }
      else
      {
        if ( (oflag & 0xC000) != 0 )
          goto LABEL_47;
        oflag |= 0x8000u;
      }
    }
    else if ( v10 == 83 )
    {
      if ( v23 )
        goto LABEL_47;
      oflag |= 0x20u;
      v23 = 1;
    }
    else
    {
      v11 = v10 - 32;
      if ( v11 )
      {
        v12 = v11 - 11;
        if ( v12 )
        {
          v13 = v12 - 1;
          if ( !v13 )
          {
            pfh = 1;
LABEL_47:
            v8 = 0;
            goto LABEL_49;
          }
          v14 = v13 - 24;
          if ( v14 )
          {
            v15 = v14 - 10;
            if ( v15 )
            {
              if ( v15 != 4 )
                goto LABEL_69;
              if ( v23 )
                goto LABEL_47;
              oflag |= 0x10u;
              v23 = 1;
            }
            else
            {
              oflag |= 0x80u;
            }
          }
          else
          {
            if ( (oflag & 0x40) != 0 )
              goto LABEL_47;
            oflag |= 0x40u;
          }
        }
        else
        {
          if ( (oflag & 2) != 0 )
            goto LABEL_47;
          oflag = oflag & 0xFFFFFFFC | 2;
          v24 = v24 & 0xFFFFFF7C | 0x80;
        }
      }
    }
LABEL_49:
    v10 = *++v9;
    if ( !*v9 )
      break;
  }
  if ( !pfh )
    goto LABEL_67;
  while ( *v9 == 32 )
    ++v9;
  if ( _mbsnbcmp((int)v9, (char *)ccsField, v9, 3u) )
    goto LABEL_69;
  for ( v9 += 3; *v9 == 32; ++v9 )
    ;
  if ( *v9 != 61 )
    goto LABEL_69;
  do
    ++v9;
  while ( *v9 == 32 );
  if ( !_mbsnbicmp(0x4000, (int)v9, v9, "UTF-8", 5u) )
  {
    v9 += 5;
    oflag |= 0x40000u;
    goto LABEL_67;
  }
  if ( !_mbsnbicmp(0x4000, (int)v9, v9, "UTF-16LE", 8u) )
  {
    v9 += 8;
    oflag |= (unsigned int)&loc_20000;
    goto LABEL_67;
  }
  if ( _mbsnbicmp(0x4000, (int)v9, v9, "UNICODE", 7u) )
    goto LABEL_69;
  v9 += 7;
  oflag |= (unsigned int)&_sbh_sizeHeaderList;
LABEL_67:
  while ( *v9 == 32 )
    ++v9;
  if ( *v9 )
  {
LABEL_69:
    *_errno() = 22;
    _invalid_parameter(0, a1, (int)v9);
    return 0;
  }
  if ( _sopen_s(&pfh, filename, oflag, shflag, 384) )
    return 0;
  result = str;
  ++_cflush;
  str->_flag = v24;
  v20 = pfh;
  str->_cnt = 0;
  str->_ptr = 0;
  str->_base = 0;
  str->_tmpfname = 0;
  str->_file = v20;
  return result;
}
