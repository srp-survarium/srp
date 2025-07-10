bool __thiscall Scaleform::GFx::FontManager::NodePtr::operator==(
        Scaleform::GFx::FontManager::NodePtr *this,
        const Scaleform::GFx::FontManager::NodePtr *other)
{
  Scaleform::GFx::FontHandle *pNode; // eax
  Scaleform::GFx::FontHandle *v4; // ecx
  _DWORD *v6; // ecx
  const char *v7; // edi
  _DWORD *v8; // eax
  const char *v9; // eax

  pNode = other->pNode;
  v4 = this->pNode;
  if ( v4 == other->pNode )
    return 1;
  if ( (((v4->OverridenFontFlags | v4->pFont.pObject->Flags)
       ^ (pNode->OverridenFontFlags | pNode->pFont.pObject->Flags))
      & 0x313) != 0 )
    return 0;
  v6 = (_DWORD *)(pNode->FontName.HeapTypeBits & 0xFFFFFFFC);
  v7 = (*v6 & 0x7FFFFFFF) != 0 ? (const char *)(v6 + 2) : pNode->pFont.pObject->GetName(pNode->pFont.pObject);
  v8 = (_DWORD *)(this->pNode->FontName.HeapTypeBits & 0xFFFFFFFC);
  v9 = (*v8 & 0x7FFFFFFF) != 0
     ? (const char *)(v8 + 2)
     : this->pNode->pFont.pObject->GetName(this->pNode->pFont.pObject);
  return !Scaleform::String::CompareNoCase(v9, v7);
}
