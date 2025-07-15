void __thiscall Scaleform::GFx::AS3::Classes::fl_system::IME::conversionModeSet(
        Scaleform::GFx::AS3::Classes::fl_system::IME *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  void (__thiscall *v3)(Scaleform::GFx::AS3::VM *); // ecx
  Scaleform::RefCountVImpl *v4; // ebx
  int v5; // edi

  v3 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  v4 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*((_DWORD *)v3 + 2) + 12))((int)v3 + 8, 24);
  v5 = 0;
  if ( v4 )
  {
    if ( !strcmp(value->pNode->pData, "ALPHANUMERIC_FULL") )
      v5 = 0;
    if ( !strcmp(value->pNode->pData, "ALPHANUMERIC_HALF") )
      v5 = 1;
    if ( !strcmp(value->pNode->pData, "JAPANESE_HIRAGANA") )
      v5 = 4;
    if ( !strcmp(value->pNode->pData, "JAPANESE_KATAKANA_FULL") )
      v5 = 8;
    if ( !strcmp(value->pNode->pData, "JAPANESE_KATAKANA_HALF") )
      v5 = 22;
    ((void (__thiscall *)(Scaleform::RefCountVImpl *, int))v4->__vftable[2].~Scaleform::RefCountVImpl)(v4, v5);
    Scaleform::RefCountImpl::Release(v4);
  }
}
