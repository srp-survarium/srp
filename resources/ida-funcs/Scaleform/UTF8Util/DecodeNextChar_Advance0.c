unsigned int __stdcall Scaleform::UTF8Util::DecodeNextChar_Advance0(const char **putf8Buffer)
{
  unsigned int result; // eax
  const char *v2; // edx
  char v3; // si
  char v4; // al
  int v5; // esi
  unsigned int v6; // esi
  char v7; // si
  char v8; // al
  int v9; // esi
  const char *v10; // edx
  int v11; // esi
  char v12; // al
  unsigned int v13; // esi
  char v14; // si
  char v15; // al
  int v16; // esi
  const char *v17; // edx
  char v18; // bl
  int v19; // esi
  const char *v20; // eax
  int v21; // esi
  char v22; // dl
  unsigned int v23; // esi
  char v24; // si
  char v25; // al
  int v26; // esi
  const char *v27; // edx
  char v28; // bl
  int v29; // esi
  _BYTE *v30; // eax
  int v31; // esi
  char v32; // dl
  const char *v33; // eax
  int v34; // esi
  char v35; // dl
  unsigned int v36; // esi
  char v37; // si
  char v38; // al
  int v39; // esi
  const char *v40; // edx
  char v41; // bl
  int v42; // esi
  _BYTE *v43; // eax
  int v44; // esi
  char v45; // dl
  const char *v46; // eax
  int v47; // esi
  char v48; // dl
  const char *v49; // eax
  int v50; // esi
  char v51; // dl

  LOBYTE(result) = **putf8Buffer;
  v2 = *putf8Buffer + 1;
  *putf8Buffer = v2;
  if ( !(_BYTE)result )
    return 0;
  if ( (result & 0x80u) == 0 )
    return (char)result;
  if ( (result & 0xE0) == 0xC0 )
  {
    v3 = result;
    v4 = *v2;
    v5 = (v3 & 0x1F) << 6;
    if ( *v2 )
    {
      if ( (v4 & 0xC0) == 0x80 )
      {
        v6 = v4 & 0x3F | v5;
        *putf8Buffer = v2 + 1;
        if ( v6 >= 0x80 )
          return v6;
      }
      return 65533;
    }
    return 0;
  }
  if ( (result & 0xF0) == 0xE0 )
  {
    v7 = result;
    v8 = *v2;
    v9 = (v7 & 0xF) << 12;
    if ( !*v2 )
      return 0;
    if ( (v8 & 0xC0) == 0x80 )
    {
      v10 = v2 + 1;
      v11 = ((v8 & 0x3F) << 6) | v9;
      *putf8Buffer = v10;
      v12 = *v10;
      if ( *v10 )
      {
        if ( (v12 & 0xC0) == 0x80 )
        {
          *putf8Buffer = v10 + 1;
          v13 = v12 & 0x3F | v11;
          if ( v13 >= 0x800 )
            return v13;
        }
        return 65533;
      }
      return 0;
    }
    return 65533;
  }
  if ( (result & 0xF8) == 0xF0 )
  {
    v14 = result;
    v15 = *v2;
    v16 = (v14 & 7) << 18;
    if ( !*v2 )
      return 0;
    if ( (v15 & 0xC0) == 0x80 )
    {
      v17 = v2 + 1;
      *putf8Buffer = v17;
      v18 = *v17;
      v19 = ((v15 & 0x3F) << 12) | v16;
      if ( !*v17 )
        return 0;
      if ( (v18 & 0xC0) == 0x80 )
      {
        v20 = v17 + 1;
        v21 = ((v18 & 0x3F) << 6) | v19;
        *putf8Buffer = v17 + 1;
        v22 = *v20;
        if ( *v20 )
        {
          if ( (v22 & 0xC0) == 0x80 )
          {
            *putf8Buffer = v20 + 1;
            v23 = v22 & 0x3F | v21;
            if ( v23 >= (unsigned int)&_sbh_sizeHeaderList )
              return v23;
          }
          return 65533;
        }
        return 0;
      }
    }
    return 65533;
  }
  if ( (result & 0xFC) == 0xF8 )
  {
    v24 = result;
    v25 = *v2;
    v26 = (v24 & 3) << 24;
    if ( !*v2 )
      return 0;
    if ( (v25 & 0xC0) == 0x80 )
    {
      v27 = v2 + 1;
      *putf8Buffer = v27;
      v28 = *v27;
      v29 = ((v25 & 0x3F) << 18) | v26;
      if ( !*v27 )
        return 0;
      if ( (v28 & 0xC0) == 0x80 )
      {
        v30 = v27 + 1;
        v31 = ((v28 & 0x3F) << 12) | v29;
        *putf8Buffer = v27 + 1;
        v32 = *v30;
        if ( !*v30 )
          return 0;
        if ( (v32 & 0xC0) == 0x80 )
        {
          v33 = v30 + 1;
          v34 = ((v32 & 0x3F) << 6) | v31;
          *putf8Buffer = v33;
          v35 = *v33;
          if ( *v33 )
          {
            if ( (v35 & 0xC0) == 0x80 )
            {
              *putf8Buffer = v33 + 1;
              v36 = v35 & 0x3F | v34;
              if ( v36 >= (unsigned int)&loc_200000 )
                return v36;
            }
            return 65533;
          }
          return 0;
        }
      }
    }
    return 65533;
  }
  if ( (result & 0xFE) != 0xFC )
    return 65533;
  v37 = result;
  v38 = *v2;
  v39 = (v37 & 1) << 30;
  if ( !*v2 )
    return 0;
  if ( (v38 & 0xC0) != 0x80 )
    return 65533;
  v40 = v2 + 1;
  *putf8Buffer = v40;
  v41 = *v40;
  v42 = ((v38 & 0x3F) << 24) | v39;
  if ( !*v40 )
    return 0;
  if ( (v41 & 0xC0) != 0x80 )
    return 65533;
  v43 = v40 + 1;
  v44 = ((v41 & 0x3F) << 18) | v42;
  *putf8Buffer = v40 + 1;
  v45 = *v43;
  if ( !*v43 )
    return 0;
  if ( (v45 & 0xC0) != 0x80 )
    return 65533;
  v46 = v43 + 1;
  v47 = ((v45 & 0x3F) << 12) | v44;
  *putf8Buffer = v46;
  v48 = *v46;
  if ( !*v46 )
    return 0;
  if ( (v48 & 0xC0) != 0x80 )
    return 65533;
  v49 = v46 + 1;
  v50 = ((v48 & 0x3F) << 6) | v47;
  *putf8Buffer = v49;
  v51 = *v49;
  if ( !*v49 )
    return 0;
  if ( (v51 & 0xC0) != 0x80 )
    return 65533;
  *putf8Buffer = v49 + 1;
  result = v51 & 0x3F | v50;
  if ( result < 0x4000000 )
    return 65533;
  return result;
}
