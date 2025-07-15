char __cdecl Scaleform::GFx::XML::CheckWhiteSpaceNode(Scaleform::GFx::XML::TextNode *textNode)
{
  unsigned int Char_Advance0; // eax
  int v2; // ecx
  int v3; // edx

  textNode = (Scaleform::GFx::XML::TextNode *)textNode->Value.pNode->pData;
  while ( 1 )
  {
    Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&textNode);
    if ( !Char_Advance0 )
      break;
    v2 = BYTE1(Char_Advance0);
    v3 = Scaleform::UnicodeSpaceBits[v2];
    if ( !Scaleform::UnicodeSpaceBits[v2]
      || v3 != 1
      && (Scaleform::UnicodeSpaceBits[v3 + ((unsigned __int8)Char_Advance0 >> 4)] & (1 << (Char_Advance0 & 0xF))) == 0 )
    {
      return 0;
    }
  }
  return 1;
}
