void __stdcall Scaleform::String::EscapeSpecialHTML(
        const char *psrc,
        unsigned int length,
        Scaleform::String *pescapedStr)
{
  char *pData; // esi
  unsigned int Size; // edi
  const char *v5; // ebp
  unsigned int v6; // eax
  Scaleform::StringBuffer buf; // [esp+Ch] [ebp-18h] BYREF

  buf.pHeap = Scaleform::Memory::pGlobalHeap;
  pData = 0;
  Size = 0;
  memset(&buf, 0, 12);
  buf.GrowSize = 512;
  buf.LengthIsSize = 0;
  v5 = &psrc[length];
  v6 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&psrc);
  if ( psrc < v5 )
  {
    while ( 1 )
    {
      switch ( v6 )
      {
        case '<':
          Scaleform::StringBuffer::Resize(&buf, Size + 4);
          pData = buf.pData;
          *(_DWORD *)&buf.pData[Size] = *(_DWORD *)"&lt;";
          break;
        case '>':
          Scaleform::StringBuffer::Resize(&buf, Size + 4);
          pData = buf.pData;
          *(_DWORD *)&buf.pData[Size] = *(_DWORD *)"&gt;";
          break;
        case '"':
          Scaleform::StringBuffer::Resize(&buf, Size + 6);
          pData = buf.pData;
          *(_DWORD *)&buf.pData[Size] = *(_DWORD *)aQuo;
          *(_WORD *)&pData[Size + 4] = 15220;
          break;
        case '\'':
          Scaleform::StringBuffer::Resize(&buf, Size + 6);
          pData = buf.pData;
          *(_DWORD *)&buf.pData[Size] = *(_DWORD *)aApo;
          *(_WORD *)&pData[Size + 4] = 15219;
          break;
        case '&':
          Scaleform::StringBuffer::Resize(&buf, Size + 5);
          pData = buf.pData;
          *(_DWORD *)&buf.pData[Size] = *(_DWORD *)aAmp_0;
          pData[Size + 4] = 59;
          break;
        default:
          Scaleform::StringBuffer::AppendChar(&buf, v6);
          pData = buf.pData;
          break;
      }
      v6 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&psrc);
      if ( psrc >= v5 )
        break;
      Size = buf.Size;
    }
  }
  Scaleform::String::operator=(pescapedStr, &buf);
  if ( pData )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pData);
}
