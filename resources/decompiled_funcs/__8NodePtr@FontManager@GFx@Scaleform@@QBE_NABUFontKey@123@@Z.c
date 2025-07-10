BOOL __thiscall Scaleform::GFx::FontManager::NodePtr::operator==(
        Scaleform::GFx::FontManager::NodePtr *this,
        const Scaleform::GFx::FontManager::FontKey *key)
{
  Scaleform::GFx::FontHandle *pNode; // ecx
  _DWORD *v3; // eax
  const char *v4; // eax
  BOOL result; // eax

  pNode = this->pNode;
  result = 0;
  if ( ((pNode->OverridenFontFlags | pNode->pFont.pObject->Flags)
      & (key->FontStyle & 0x10 | ((key->FontStyle & 0x300) != 0 ? 0x300 : 0) | 3)) == (key->FontStyle & 0x313) )
  {
    v3 = (_DWORD *)(pNode->FontName.HeapTypeBits & 0xFFFFFFFC);
    v4 = (*v3 & 0x7FFFFFFF) != 0 ? (const char *)(v3 + 2) : pNode->pFont.pObject->GetName(pNode->pFont.pObject);
    if ( !Scaleform::String::CompareNoCase(v4, key->pFontName) )
      return 1;
  }
  return result;
}
