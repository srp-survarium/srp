double __stdcall Scaleform::GFx::NumberUtil::StringToInt(
        __m128i *str,
        unsigned int strLen,
        int radix,
        unsigned int *endIndex)
{
  unsigned int *v4; // esi
  bool v5; // bl
  int v6; // eax
  char *ByteIndex; // eax
  unsigned int v8; // edi
  volatile LONG *v9; // edi
  unsigned int v10; // eax
  char v12; // cl
  unsigned int v13; // eax
  char v14; // cl
  unsigned int v15; // eax
  unsigned int v16; // edi
  int v17; // edx
  double v18; // st6
  unsigned int v19; // ecx
  char v20; // al
  unsigned int v21; // ecx
  int v22; // ebp
  int v23; // ecx
  unsigned int v24; // esi
  char v25; // al
  char v26; // bl
  char v27; // cl
  char v28; // al
  int v29; // eax
  char v30; // al
  int v31; // eax
  char v32; // al
  unsigned int i; // edi
  char v34; // al
  int v35; // eax
  double v36; // st7
  double v37; // st6
  double v38; // rt0
  char v39; // [esp+Bh] [ebp-5h]
  int v40; // [esp+Ch] [ebp-4h]

  v4 = endIndex;
  v40 = 1;
  *endIndex = 0;
  v5 = 1;
  if ( radix )
  {
    if ( (unsigned int)(radix - 2) > 0x22 )
      return NAN;
    v5 = radix == 16;
  }
  else
  {
    radix = 10;
  }
  Scaleform::String::String((Scaleform::String *)&endIndex, str);
  v6 = Scaleform::GFx::ASUtils::SkipWhiteSpace((Scaleform::String *)&endIndex);
  ByteIndex = Scaleform::UTF8Util::GetByteIndex(v6, str->m128i_i8, strLen);
  v8 = (unsigned int)endIndex;
  *v4 = (unsigned int)ByteIndex;
  v9 = (volatile LONG *)(v8 & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v9 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v9);
  v10 = *v4;
  if ( *v4 == strLen )
    return 0.0;
  v12 = str->m128i_i8[v10];
  if ( v12 == 45 )
  {
    v40 = -1;
LABEL_12:
    *v4 = v10 + 1;
    goto LABEL_13;
  }
  if ( v12 == 43 )
    goto LABEL_12;
LABEL_13:
  if ( v5 )
  {
    v13 = *v4;
    if ( strLen - *v4 > 1 && str->m128i_i8[v13] == 48 )
    {
      v14 = str->m128i_i8[v13 + 1];
      if ( v14 == 120 || v14 == 88 )
      {
        v15 = v13 + 2;
        radix = 16;
        *v4 = v15;
        if ( strLen == v15 )
          return NAN;
      }
    }
  }
  v16 = *v4;
  LOBYTE(v17) = 0;
  v18 = 0.0;
  if ( *v4 < strLen )
  {
    do
    {
      v19 = *v4;
      v20 = str->m128i_i8[*v4];
      if ( (unsigned __int8)(v20 - 48) > 9u )
      {
        if ( (unsigned __int8)(v20 - 97) > 0x19u )
        {
          if ( (unsigned __int8)(v20 - 65) > 0x19u )
            v17 = -1;
          else
            v17 = v20 - 55;
        }
        else
        {
          v17 = v20 - 87;
        }
      }
      else
      {
        v17 = v20 - 48;
      }
      endIndex = (unsigned int *)v17;
      if ( v17 >= radix )
        break;
      if ( v17 < 0 )
        break;
      v21 = v19 + 1;
      *v4 = v21;
      v18 = v18 * (double)radix + (double)(int)endIndex;
    }
    while ( v21 < strLen );
  }
  if ( *v4 == v16 )
    return NAN;
  if ( v18 < 9.007199254740992e15 || radix != 2 && radix != 8 && radix != 16 )
    return v18 * (double)v40;
  v22 = 1;
  if ( radix == 8 )
  {
    v22 = 3;
  }
  else if ( radix == 16 )
  {
    v22 = 4;
  }
  for ( ; v16 < strLen; ++v16 )
  {
    if ( str->m128i_i8[v16] != 48 )
      break;
  }
  v23 = 0;
  v18 = 0.0;
  if ( v16 < strLen )
  {
    v24 = 0;
    while ( v24 <= 0x34 )
    {
      v25 = str->m128i_i8[v16];
      if ( (unsigned __int8)(v25 - 48) > 9u )
      {
        if ( (unsigned __int8)(v25 - 97) > 0x19u )
        {
          if ( (unsigned __int8)(v25 - 65) > 0x19u )
            v17 = -1;
          else
            v17 = v25 - 55;
        }
        else
        {
          v17 = v25 - 87;
        }
      }
      else
      {
        v17 = v25 - 48;
      }
      ++v16;
      endIndex = (unsigned int *)v17;
      if ( v17 >= radix || v17 < 0 )
      {
        LOBYTE(v17) = 0;
        break;
      }
      ++v23;
      v24 += v22;
      v18 = v18 * (double)radix + (double)(int)endIndex;
      if ( v16 >= strLen )
        break;
    }
  }
  if ( (unsigned int)(v22 * v23) <= 0x34 )
    return v18 * (double)v40;
  v26 = 0;
  v27 = 0;
  v39 = 0;
  LOBYTE(endIndex) = 0;
  if ( radix == 2 )
  {
    LOBYTE(endIndex) = v17 & 1;
    if ( v16 < strLen )
    {
      v32 = str->m128i_i8[v16];
      if ( (unsigned __int8)(v32 - 48) <= 9u )
      {
        v31 = v32 - 48;
LABEL_90:
        if ( v31 != -1 && v31 < 2 )
          goto LABEL_93;
        goto LABEL_92;
      }
      if ( (unsigned __int8)(v32 - 97) <= 0x19u )
      {
        v31 = v32 - 87;
        goto LABEL_90;
      }
      if ( (unsigned __int8)(v32 - 65) <= 0x19u )
      {
        v31 = v32 - 55;
        goto LABEL_90;
      }
    }
LABEL_92:
    LOBYTE(v31) = 0;
    goto LABEL_93;
  }
  if ( radix == 8 )
  {
    if ( v16 < strLen )
    {
      v30 = str->m128i_i8[v16];
      if ( (unsigned __int8)(v30 - 48) <= 9u )
      {
        v31 = v30 - 48;
LABEL_79:
        if ( v31 != -1 && v31 < 8 )
          goto LABEL_82;
        goto LABEL_81;
      }
      if ( (unsigned __int8)(v30 - 97) <= 0x19u )
      {
        v31 = v30 - 87;
        goto LABEL_79;
      }
      if ( (unsigned __int8)(v30 - 65) <= 0x19u )
      {
        v31 = v30 - 55;
        goto LABEL_79;
      }
    }
LABEL_81:
    LOBYTE(v31) = 0;
LABEL_82:
    LOBYTE(endIndex) = (v31 & 2) != 0;
LABEL_93:
    v26 = v31 & 1;
    goto LABEL_94;
  }
  LOBYTE(endIndex) = v17 & 1;
  if ( v16 < strLen )
  {
    v28 = str->m128i_i8[v16];
    if ( (unsigned __int8)(v28 - 48) > 9u )
    {
      if ( (unsigned __int8)(v28 - 97) > 0x19u )
      {
        if ( (unsigned __int8)(v28 - 65) > 0x19u )
          goto LABEL_71;
        v29 = v28 - 55;
      }
      else
      {
        v29 = v28 - 87;
      }
    }
    else
    {
      v29 = v28 - 48;
    }
    if ( v29 != -1 && v29 < 16 )
    {
      v26 = (v29 & 8) != 0;
      v39 = (v29 & 3) != 0;
LABEL_94:
      v27 = v22;
      goto LABEL_95;
    }
  }
LABEL_71:
  v39 = (_BYTE)endIndex != 0;
LABEL_95:
  for ( i = v16 + 1; i < strLen; v27 += v22 )
  {
    v34 = str->m128i_i8[i];
    if ( (unsigned __int8)(v34 - 48) > 9u )
    {
      if ( (unsigned __int8)(v34 - 97) > 0x19u )
      {
        if ( (unsigned __int8)(v34 - 65) > 0x19u )
          break;
        v35 = v34 - 55;
      }
      else
      {
        v35 = v34 - 87;
      }
    }
    else
    {
      v35 = v34 - 48;
    }
    if ( v35 == -1 )
      break;
    if ( v35 >= radix )
      break;
    v39 |= v35 != 0;
    ++i;
  }
  if ( v26 && ((_BYTE)endIndex || v39) )
  {
    v36 = v18;
    v37 = 1.0;
  }
  else
  {
    v38 = v18;
    v37 = 0.0;
    v36 = v38;
  }
  return (v36 + v37) * (double)(1 << v27) * (double)v40;
}
