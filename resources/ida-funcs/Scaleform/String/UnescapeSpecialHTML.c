void __stdcall Scaleform::String::UnescapeSpecialHTML(
        char *psrc,
        unsigned int length,
        Scaleform::String *punescapedStr)
{
  char *v3; // ebx
  char *pData; // esi
  unsigned int v5; // ebp
  unsigned int v6; // edi
  unsigned int Char_Advance0; // eax
  const char *v8; // ecx
  unsigned int v9; // ebx
  int v10; // eax
  unsigned int v11; // ebx
  int v12; // eax
  unsigned int v13; // [esp-4h] [ebp-40h]
  char *v14; // [esp+10h] [ebp-2Ch]
  __m128i pbuffer; // [esp+14h] [ebp-28h] BYREF
  Scaleform::StringBuffer src; // [esp+24h] [ebp-18h] BYREF

  src.pHeap = Scaleform::Memory::pGlobalHeap;
  v3 = &psrc[length];
  pData = 0;
  v5 = 0;
  v6 = 0;
  memset(&src, 0, 12);
  src.GrowSize = 512;
  src.LengthIsSize = 0;
  v14 = &psrc[length];
  Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&psrc);
  v8 = psrc;
  if ( psrc >= v3 )
    goto LABEL_33;
  while ( 1 )
  {
    if ( Char_Advance0 != 38 )
    {
      v11 = v5;
      length = 0;
      Scaleform::UTF8Util::EncodeChar(&pbuffer.m128i_i8[8], (int *)&length, Char_Advance0);
      v5 += length;
      if ( v5 >= v6 )
      {
        v6 = (v5 + 512) & 0xFFFFFE00;
        if ( pData )
          v12 = ((int (__stdcall *)(char *, unsigned int))Scaleform::Memory::pGlobalHeap->Realloc)(
                  pData,
                  (v5 + 512) & 0xFFFFFE00);
        else
          v12 = ((int (__stdcall *)(unsigned int, _DWORD))src.pHeap->Alloc)((v5 + 512) & 0xFFFFFE00, 0);
        pData = (char *)v12;
      }
      src.LengthIsSize = 0;
      if ( pData )
        pData[v5] = 0;
      memcpy((int)&pData[v11], (const __m128i *)&pbuffer.m128i_u64[1], length);
      goto LABEL_24;
    }
    if ( !strncmp(v8, "quot;", 5u) )
    {
      src.Size = v5;
      src.pData = pData;
      src.BufferSize = v6;
      Scaleform::StringBuffer::AppendChar(&src, 0x22u);
      psrc += 5;
      goto LABEL_32;
    }
    if ( !strncmp(psrc, "apos;", 5u) )
    {
      src.Size = v5;
      src.pData = pData;
      src.BufferSize = v6;
      Scaleform::StringBuffer::AppendChar(&src, 0x27u);
      psrc += 5;
      goto LABEL_32;
    }
    if ( !strncmp(psrc, "amp;", 4u) )
    {
      src.Size = v5;
      src.pData = pData;
      src.BufferSize = v6;
      Scaleform::StringBuffer::AppendChar(&src, 0x26u);
      psrc += 4;
      goto LABEL_32;
    }
    if ( !strncmp(psrc, "lt;", 3u) )
    {
      v13 = 60;
      goto LABEL_31;
    }
    if ( !strncmp(psrc, "gt;", 3u) )
      break;
    v9 = v5;
    length = 0;
    Scaleform::UTF8Util::EncodeChar(pbuffer.m128i_i8, (int *)&length, 0x26u);
    v5 += length;
    if ( v5 >= v6 )
    {
      v6 = (v5 + 512) & 0xFFFFFE00;
      if ( pData )
        v10 = ((int (__stdcall *)(char *, unsigned int))Scaleform::Memory::pGlobalHeap->Realloc)(
                pData,
                (v5 + 512) & 0xFFFFFE00);
      else
        v10 = ((int (__stdcall *)(unsigned int, _DWORD))src.pHeap->Alloc)((v5 + 512) & 0xFFFFFE00, 0);
      pData = (char *)v10;
    }
    src.LengthIsSize = 0;
    if ( pData )
      pData[v5] = 0;
    memcpy((int)&pData[v9], &pbuffer, length);
LABEL_24:
    Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&psrc);
    v8 = psrc;
    if ( psrc >= v14 )
    {
      src.Size = v5;
      src.pData = pData;
      src.BufferSize = v6;
      goto LABEL_33;
    }
  }
  v13 = 62;
LABEL_31:
  src.Size = v5;
  src.pData = pData;
  src.BufferSize = v6;
  Scaleform::StringBuffer::AppendChar(&src, v13);
  psrc += 3;
LABEL_32:
  pData = src.pData;
LABEL_33:
  Scaleform::String::operator=(punescapedStr, &src);
  if ( pData )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pData);
}
