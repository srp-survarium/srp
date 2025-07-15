void __stdcall Scaleform::String::EscapeSpecialHTML(char *psrc, unsigned int length, Scaleform::String *pescapedStr)
{
  char *pData; // esi
  unsigned int Size; // edi
  char *v5; // ebp
  unsigned int Char_Advance0; // eax
  Scaleform::StringBuffer src; // [esp+Ch] [ebp-18h] BYREF

  src.pHeap = Scaleform::Memory::pGlobalHeap;
  pData = 0;
  Size = 0;
  memset(&src, 0, 12);
  src.GrowSize = 512;
  src.LengthIsSize = 0;
  v5 = &psrc[length];
  Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&psrc);
  if ( psrc < v5 )
  {
    while ( 1 )
    {
      switch ( Char_Advance0 )
      {
        case '<':
          Scaleform::StringBuffer::Resize(&src, Size + 4);
          pData = src.pData;
          *(_DWORD *)&src.pData[Size] = *(_DWORD *)"&lt;";
          break;
        case '>':
          Scaleform::StringBuffer::Resize(&src, Size + 4);
          pData = src.pData;
          *(_DWORD *)&src.pData[Size] = *(_DWORD *)"&gt;";
          break;
        case '"':
          Scaleform::StringBuffer::Resize(&src, Size + 6);
          pData = src.pData;
          *(_DWORD *)&src.pData[Size] = *(_DWORD *)aQuo;
          *(_WORD *)&pData[Size + 4] = 15220;
          break;
        case '\'':
          Scaleform::StringBuffer::Resize(&src, Size + 6);
          pData = src.pData;
          *(_DWORD *)&src.pData[Size] = *(_DWORD *)aApo;
          *(_WORD *)&pData[Size + 4] = 15219;
          break;
        case '&':
          Scaleform::StringBuffer::Resize(&src, Size + 5);
          pData = src.pData;
          *(_DWORD *)&src.pData[Size] = *(_DWORD *)aAmp_3;
          pData[Size + 4] = 59;
          break;
        default:
          Scaleform::StringBuffer::AppendChar(&src, Char_Advance0);
          pData = src.pData;
          break;
      }
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&psrc);
      if ( psrc >= v5 )
        break;
      Size = src.Size;
    }
  }
  Scaleform::String::operator=(pescapedStr, &src);
  if ( pData )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pData);
}
