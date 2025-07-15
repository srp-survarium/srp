int __usercall Scaleform::GFx::AS3::SF_ECMA_dtostr@<eax>(
        char *a1@<edi>,
        char *buffer,
        unsigned int bufflen,
        long double val)
{
  int result; // eax
  long double v5; // st6
  int v6; // eax
  int v7; // ecx
  int v8; // ecx
  char v9; // dl
  int v10; // edx
  int i; // eax
  char v12; // cl
  char *v13; // ebp
  char v14; // bl
  int v15; // edx
  char *v16; // esi
  char *v17; // eax
  char v18; // cl
  char *v19; // eax
  char v20; // cl
  char j; // cl
  int v22; // edi
  char *v23; // edi
  char v24; // bl
  _BYTE *v25; // esi
  int v26; // ebp
  long double intVal; // [esp+Ch] [ebp-30h] BYREF
  char temp[40]; // [esp+14h] [ebp-28h] BYREF

  LODWORD(intVal) = (int)val;
  if ( (double)(int)val == val )
  {
    _itoa_s(a1, (int)val, buffer, bufflen, 0xAu);
    return strlen(buffer);
  }
  intVal = val;
  if ( (HIDWORD(intVal) & 0x7FF00000) == 0x7FF00000 && HIDWORD(intVal) & 0xFFFFF | LODWORD(intVal) )
  {
    *(_DWORD *)buffer = 5136718;
    return 3;
  }
  if ( val == INFINITY )
  {
    strcpy(buffer, "Infinity");
    return 8;
  }
  intVal = val;
  if ( val == -INFINITY )
  {
    strcpy(buffer, "-Infinity");
    return 9;
  }
  memset(temp, 0, sizeof(temp));
  v5 = fabs(val);
  strcpy((char *)&intVal, "%.16g");
  if ( v5 >= 1.0e16 && v5 < 1.0e21 )
  {
    BYTE3(intVal) = 55;
    if ( v5 >= 1.0e17 )
    {
      BYTE3(intVal) = 56;
      if ( v5 >= 1.0e18 )
      {
        BYTE3(intVal) = 57;
        if ( v5 >= 1.0e19 )
        {
          WORD1(intVal) = 12338;
          if ( v5 >= 1.0e20 )
            WORD1(intVal) = 12594;
        }
      }
    }
  }
  v6 = Scaleform::SFsprintf(temp, 0x28u, (char *)&intVal, val);
  v7 = 0;
  if ( v6 <= 0 )
  {
LABEL_20:
    v8 = 0;
    if ( temp[0] )
    {
      while ( 1 )
      {
        v9 = temp[v8];
        if ( v9 == 46 || v9 == 44 )
          break;
        if ( !temp[++v8] )
          goto LABEL_32;
      }
      if ( temp[v6 - 1] != 48 )
      {
        v10 = v6 - 2;
        for ( i = v6 - 2; i > v8; --i )
        {
          if ( temp[i] != 48 )
            break;
        }
        if ( i < v10 && i != v8 )
          temp[i + 1] = 0;
      }
    }
  }
  else
  {
    while ( temp[v7] != 101 )
    {
      if ( ++v7 >= v6 )
        goto LABEL_20;
    }
  }
LABEL_32:
  v12 = temp[0];
  v13 = buffer;
  v14 = 0;
  v15 = 0;
  v16 = buffer;
  v17 = temp;
  if ( !temp[0] )
    goto LABEL_62;
  while ( v12 == 44 )
  {
    *v16 = 46;
LABEL_37:
    v12 = *++v17;
    ++v16;
    if ( !v12 )
    {
      result = v16 - buffer;
      *v16 = 0;
      return result;
    }
  }
  if ( v12 != 101 )
  {
    *v16 = v12;
    goto LABEL_37;
  }
  v18 = *v17;
  v19 = v17 + 1;
  *v16 = v18;
  v20 = *v19;
  ++v16;
  if ( *v19 == 45 )
  {
    v14 = 1;
    goto LABEL_43;
  }
  if ( v20 == 43 )
  {
LABEL_43:
    *v16++ = v20;
    ++v19;
  }
  for ( ; *v19 == 48; ++v19 )
    ;
  for ( j = *v19; *v19 >= 48; v15 = v22 + 10 * v15 - 48 )
  {
    if ( j > 57 )
      break;
    ++v19;
    v22 = j;
    *v16 = j;
    j = *v19;
    ++v16;
  }
  if ( v14 && (unsigned int)(v15 - 1) <= 5 )
  {
    v23 = temp;
    v16 = buffer;
    if ( temp[0] == 45 )
    {
      v23 = &temp[1];
      v16 = buffer + 1;
    }
    v24 = *v23;
    if ( *v23 >= 49 && v24 <= 57 && v16[1] == 46 )
    {
      *v16 = 48;
      v25 = v16 + 1;
      *v25 = 46;
      v16 = v25 + 1;
      if ( v15 > 1 )
      {
        v26 = v15 - 1;
        memset((int)v16, 48, v15 - 1);
        v16 += v26;
        v13 = buffer;
      }
      do
      {
        if ( v24 >= 48 && v24 <= 57 )
          *v16++ = v24;
        v24 = *++v23;
      }
      while ( v24 != 101 );
    }
  }
LABEL_62:
  result = v16 - v13;
  *v16 = 0;
  return result;
}
