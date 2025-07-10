unsigned int __thiscall Scaleform::GFx::FontManager::NodePtrHashOp::operator()(
        Scaleform::GFx::FontManager::NodePtrHashOp *this,
        const Scaleform::GFx::FontManager::NodePtr *other)
{
  Scaleform::GFx::FontHandle *pNode; // esi
  _DWORD *v3; // eax
  char *v4; // eax
  unsigned int Flags; // edi
  unsigned __int8 v6; // si

  pNode = other->pNode;
  v3 = (_DWORD *)(other->pNode->FontName.HeapTypeBits & 0xFFFFFFFC);
  if ( (*v3 & 0x7FFFFFFF) != 0 )
    v4 = (char *)(v3 + 2);
  else
    v4 = (char *)pNode->pFont.pObject->GetName(pNode->pFont.pObject);
  Flags = pNode->pFont.pObject->Flags;
  v6 = (Flags | pNode->OverridenFontFlags) & 3;
  return ((unsigned __int8)Flags | v6) & 3 ^ Scaleform::String::BernsteinHashFunctionCIS(v4, strlen(v4), 0x1505u);
}
