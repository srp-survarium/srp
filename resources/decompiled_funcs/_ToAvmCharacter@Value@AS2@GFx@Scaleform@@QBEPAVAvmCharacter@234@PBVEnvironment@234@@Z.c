Scaleform::GFx::AS2::AvmCharacter *__thiscall Scaleform::GFx::AS2::Value::ToAvmCharacter(
        Scaleform::GFx::AS2::Value *this,
        const Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  Scaleform::GFx::InteractiveObject *v3; // eax
  Scaleform::GFx::InteractiveObject *v4; // ecx
  int v6; // edx

  if ( this->T.Type != 7 )
    return 0;
  if ( !penv )
    return 0;
  pStringNode = this->V.pStringNode;
  if ( !pStringNode )
    return 0;
  v3 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
         (Scaleform::GFx::CharacterHandle *)pStringNode,
         penv->Target->pASRoot->pMovieImpl);
  if ( !v3
    || (LOBYTE(v3->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
      ? (unsigned int)v3
      : 0) == 0 )
  {
    return 0;
  }
  v6 = *(LOBYTE(v3->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
       ? &v3->AvmObjOffset
       : (unsigned __int8 *)65);
  v4 = LOBYTE(v3->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0 ? v3 : 0;
  return (Scaleform::GFx::AS2::AvmCharacter *)(*(int (__thiscall **)(int))(*((_DWORD *)&v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                           + v6)
                                                                         + 4))((int)v4 + 4 * v6);
}
