void __stdcall Scaleform::String::UnescapeSpecialHTML(
        const char *psrc,
        unsigned int length,
        Scaleform::String *punescapedStr)
{
  const char *v3; // ebx
  char *pData; // esi
  unsigned int v5; // ebp
  unsigned int v6; // edi
  unsigned int v7; // eax
  const char *v8; // ecx
  unsigned int v9; // ebx
  int v10; // eax
  unsigned int v11; // ebx
  int v12; // eax
  unsigned int v13; // [esp-4h] [ebp-40h]
  const char *end; // [esp+10h] [ebp-2Ch]
  char pbuffer[8]; // [esp+14h] [ebp-28h] BYREF
  char v16[8]; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::StringBuffer buf; // [esp+24h] [ebp-18h] BYREF

  buf.pHeap = Scaleform::Memory::pGlobalHeap;
  v3 = &psrc[length];
  pData = 0;
  v5 = 0;
  v6 = 0;
  memset(&buf, 0, 12);
  buf.GrowSize = 512;
  buf.LengthIsSize = 0;
  end = &psrc[length];
  v7 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&psrc);
  v8 = psrc;
  if ( psrc >= v3 )
    goto LABEL_33;
  while ( 1 )
  {
    if ( v7 != 38 )
    {
      v11 = v5;
      length = 0;
      Scaleform::UTF8Util::EncodeChar(v16, (int *)&length, v7);
      v5 += length;
      if ( v5 >= v6 )
      {
        v6 = (v5 + 512) & 0xFFFFFE00;
        if ( pData )
          v12 = ((int (__stdcall *)(char *, unsigned int))Scaleform::Memory::pGlobalHeap->Realloc)(
                  pData,
                  (v5 + 512) & 0xFFFFFE00);
        else
          v12 = ((int (__stdcall *)(unsigned int, _DWORD))buf.pHeap->Alloc)((v5 + 512) & 0xFFFFFE00, 0);
        pData = (char *)v12;
      }
      buf.LengthIsSize = 0;
      if ( pData )
        pData[v5] = 0;
      memcpy((unsigned __int8 *)&pData[v11], (unsigned __int8 *)v16, length);
      goto LABEL_24;
    }
    if ( !strncmp(v8, "quot;", 5u) )
    {
      buf.Size = v5;
      buf.pData = pData;
      buf.BufferSize = v6;
      Scaleform::StringBuffer::AppendChar(&buf, 0x22u);
      psrc += 5;
      goto LABEL_32;
    }
    if ( !strncmp(psrc, "apos;", 5u) )
    {
      buf.Size = v5;
      buf.pData = pData;
      buf.BufferSize = v6;
      Scaleform::StringBuffer::AppendChar(&buf, 0x27u);
      psrc += 5;
      goto LABEL_32;
    }
    if ( !strncmp(psrc, "amp;", 4u) )
    {
      buf.Size = v5;
      buf.pData = pData;
      buf.BufferSize = v6;
      Scaleform::StringBuffer::AppendChar(&buf, 0x26u);
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
    Scaleform::UTF8Util::EncodeChar(pbuffer, (int *)&length, 0x26u);
    v5 += length;
    if ( v5 >= v6 )
    {
      v6 = (v5 + 512) & 0xFFFFFE00;
      if ( pData )
        v10 = ((int (__stdcall *)(char *, unsigned int))Scaleform::Memory::pGlobalHeap->Realloc)(
                pData,
                (v5 + 512) & 0xFFFFFE00);
      else
        v10 = ((int (__stdcall *)(unsigned int, _DWORD))buf.pHeap->Alloc)((v5 + 512) & 0xFFFFFE00, 0);
      pData = (char *)v10;
    }
    buf.LengthIsSize = 0;
    if ( pData )
      pData[v5] = 0;
    memcpy((unsigned __int8 *)&pData[v9], (unsigned __int8 *)pbuffer, length);
LABEL_24:
    v7 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&psrc);
    v8 = psrc;
    if ( psrc >= end )
    {
      buf.Size = v5;
      buf.pData = pData;
      buf.BufferSize = v6;
      goto LABEL_33;
    }
  }
  v13 = 62;
LABEL_31:
  buf.Size = v5;
  buf.pData = pData;
  buf.BufferSize = v6;
  Scaleform::StringBuffer::AppendChar(&buf, v13);
  psrc += 3;
LABEL_32:
  pData = buf.pData;
LABEL_33:
  Scaleform::String::operator=(punescapedStr, &buf);
  if ( pData )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pData);
}
