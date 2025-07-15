bool __thiscall Scaleform::GFx::FontManager::NodePtr::operator==(
        Scaleform::GFx::FontManager::NodePtr *this,
        const Scaleform::GFx::FontManager::NodePtr *other)
{
  Scaleform::GFx::FontHandle *pNode; // eax
  Scaleform::GFx::FontHandle *v4; // ecx
  _DWORD *v6; // ecx
  char *v7; // edi
  _DWORD *v8; // eax
  char *v9; // eax

  pNode = other->pNode;
  v4 = this->pNode;
  if ( v4 == other->pNode )
    return 1;
  if ( (((v4->OverridenFontFlags | v4->pFont.pObject->Flags)
       ^ (pNode->OverridenFontFlags | pNode->pFont.pObject->Flags))
      & 0x313) != 0 )
    return 0;
  v6 = (_DWORD *)(pNode->FontName.HeapTypeBits & 0xFFFFFFFC);
  v7 = (char *)((*v6 & 0x7FFFFFFF) != 0 ? v6 + 2 : pNode->pFont.pObject->GetName(pNode->pFont.pObject));
  v8 = (_DWORD *)(this->pNode->FontName.HeapTypeBits & 0xFFFFFFFC);
  v9 = (char *)((*v8 & 0x7FFFFFFF) != 0 ? v8 + 2 : this->pNode->pFont.pObject->GetName(this->pNode->pFont.pObject));
  return !Scaleform::String::CompareNoCase(v9, v7);
}


BOOL __thiscall Scaleform::GFx::FontManager::NodePtr::operator==(
        Scaleform::GFx::FontManager::NodePtr *this,
        const Scaleform::GFx::FontManager::FontKey *key)
{
  Scaleform::GFx::FontHandle *pNode; // ecx
  _DWORD *v3; // eax
  char *v4; // eax
  BOOL result; // eax

  pNode = this->pNode;
  result = 0;
  if ( ((pNode->OverridenFontFlags | pNode->pFont.pObject->Flags)
      & (key->FontStyle & 0x10 | ((key->FontStyle & 0x300) != 0 ? 0x300 : 0) | 3)) == (key->FontStyle & 0x313) )
  {
    v3 = (_DWORD *)(pNode->FontName.HeapTypeBits & 0xFFFFFFFC);
    v4 = (char *)((*v3 & 0x7FFFFFFF) != 0 ? v3 + 2 : pNode->pFont.pObject->GetName(pNode->pFont.pObject));
    if ( !Scaleform::String::CompareNoCase(v4, (char *)key->pFontName) )
      return 1;
  }
  return result;
}
