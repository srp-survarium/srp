void __thiscall Scaleform::GFx::AS2::AvmSprite::InitObjectMembers_::_4_::InitVisitor::Visit(
        Scaleform::GFx::AS2::AvmSprite::InitObjectMembers::__l4::InitVisitor *this,
        const Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  Scaleform::GFx::InteractiveObject *pCharacter; // eax
  int *p_RefCount; // ecx
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  char v8; // [esp+7h] [ebp-1h] BYREF

  pCharacter = this->pCharacter;
  if ( pCharacter )
    pCharacter = (Scaleform::GFx::InteractiveObject *)(*(int (__thiscall **)(int))(*((_DWORD *)&pCharacter->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                   + pCharacter->AvmObjOffset)
                                                                                 + 4))((int)pCharacter + 4 * pCharacter->AvmObjOffset);
  p_RefCount = &pCharacter->RefCount;
  pEnv = this->pEnv;
  v8 = 0;
  (*(void (__thiscall **)(int *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, char *))(*p_RefCount + 12))(
    p_RefCount,
    pEnv,
    name,
    val,
    &v8);
}
