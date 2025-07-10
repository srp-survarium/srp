unsigned int __thiscall Scaleform::GFx::FontManager::NodePtrHashOp::operator()(
        Scaleform::GFx::FontManager::NodePtrHashOp *this,
        const Scaleform::GFx::FontHandle *pnode)
{
  _DWORD *v2; // eax
  char *v3; // eax
  unsigned int Flags; // edi
  unsigned __int8 v5; // si

  v2 = (_DWORD *)(pnode->FontName.HeapTypeBits & 0xFFFFFFFC);
  if ( (*v2 & 0x7FFFFFFF) != 0 )
    v3 = (char *)(v2 + 2);
  else
    v3 = (char *)pnode->pFont.pObject->GetName(pnode->pFont.pObject);
  Flags = pnode->pFont.pObject->Flags;
  v5 = (Flags | pnode->OverridenFontFlags) & 3;
  return ((unsigned __int8)Flags | v5) & 3 ^ Scaleform::String::BernsteinHashFunctionCIS(v3, strlen(v3), 0x1505u);
}
