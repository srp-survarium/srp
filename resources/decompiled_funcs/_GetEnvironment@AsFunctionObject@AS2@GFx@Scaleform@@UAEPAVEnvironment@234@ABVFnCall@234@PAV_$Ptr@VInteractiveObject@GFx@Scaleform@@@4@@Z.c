Scaleform::GFx::AS2::Environment *__thiscall Scaleform::GFx::AS2::AsFunctionObject::GetEnvironment(
        Scaleform::GFx::AS2::AsFunctionObject *this,
        const Scaleform::GFx::AS2::FnCall *fn,
        Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *ptargetCh)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // eax
  Scaleform::GFx::InteractiveObject *v4; // esi
  Scaleform::GFx::InteractiveObject *v5; // eax
  Scaleform::GFx::AS2::Environment *Env; // edi
  int v7; // eax

  pMovieRoot = this->pMovieRoot;
  if ( pMovieRoot
    && (v5 = Scaleform::GFx::CharacterHandle::ResolveCharacter(this->TargetHandle.pObject, pMovieRoot)) != 0 )
  {
    v4 = LOBYTE(v5->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0 ? v5 : 0;
    if ( v4 )
      ++v4->RefCount;
  }
  else
  {
    v4 = 0;
  }
  Env = 0;
  if ( v4 )
  {
    v7 = (*(int (__thiscall **)(int))(*((_DWORD *)&v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                      + v4->AvmObjOffset)
                                    + 4))((int)v4 + 4 * v4->AvmObjOffset);
    Env = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 124))(v7);
  }
  if ( ptargetCh )
  {
    if ( v4 )
      ++v4->RefCount;
    if ( ptargetCh->pObject )
      Scaleform::RefCountNTSImpl::Release(ptargetCh->pObject);
    ptargetCh->pObject = v4;
  }
  if ( !Env )
    Env = fn->Env;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
  return Env;
}
