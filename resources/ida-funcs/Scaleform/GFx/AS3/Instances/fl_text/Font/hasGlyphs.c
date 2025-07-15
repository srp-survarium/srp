void __thiscall Scaleform::GFx::AS3::Instances::fl_text::Font::hasGlyphs(
        Scaleform::GFx::AS3::Instances::fl_text::Font *this,
        bool *result,
        const Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  const char *pData; // ecx
  unsigned int v6; // esi
  unsigned int Char_Advance0; // eax

  if ( this->pFont.pObject )
  {
    pNode = str->pNode;
    pData = str->pNode->pData;
    str = (const Scaleform::GFx::ASString *)pData;
    v6 = (unsigned int)&pData[pNode->Size];
    *result = 1;
    if ( (unsigned int)pData < v6 )
    {
      while ( 1 )
      {
        Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&str);
        if ( !Char_Advance0 )
          str = (const Scaleform::GFx::ASString *)((char *)str - 1);
        if ( this->pFont.pObject->GetGlyphIndex(this->pFont.pObject, Char_Advance0) < 0 )
          break;
        if ( (unsigned int)str >= v6 )
          return;
      }
      *result = 0;
    }
  }
  else
  {
    *result = 0;
  }
}
