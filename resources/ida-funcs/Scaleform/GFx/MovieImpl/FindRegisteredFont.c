Scaleform::GFx::FontResource *__thiscall Scaleform::GFx::MovieImpl::FindRegisteredFont(
        Scaleform::GFx::MovieImpl *this,
        char *pfontName,
        __int16 matchFontFlags,
        Scaleform::GFx::MovieDef **ppsrcMovieDef)
{
  unsigned int Size; // edx
  int v6; // edi
  Scaleform::Render::Font *pObject; // ecx
  char *v8; // eax
  unsigned int v10; // [esp+10h] [ebp-4h]

  Size = this->RegisteredFonts.Data.Size;
  v6 = 0;
  v10 = Size;
  if ( !Size )
    return 0;
  while ( 1 )
  {
    pObject = this->RegisteredFonts.Data.Data[v6].pFont.pObject->pFont.pObject;
    if ( ((matchFontFlags & 0x10 | ((matchFontFlags & 0x300) != 0 ? 0x300 : 0) | 3) & pObject->Flags) == (matchFontFlags & 0x313) )
      break;
LABEL_5:
    if ( ++v6 >= Size )
      return 0;
  }
  v8 = (char *)pObject->GetName(pObject);
  if ( Scaleform::String::CompareNoCase(v8, pfontName) )
  {
    Size = v10;
    goto LABEL_5;
  }
  *ppsrcMovieDef = this->RegisteredFonts.Data.Data[v6].pMovieDef.pObject;
  return this->RegisteredFonts.Data.Data[v6].pFont.pObject;
}
