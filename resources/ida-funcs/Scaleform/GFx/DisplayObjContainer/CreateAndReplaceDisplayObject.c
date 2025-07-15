void __thiscall Scaleform::GFx::DisplayObjContainer::CreateAndReplaceDisplayObject(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::DisplayObjectBase *pos,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::DisplayObjectBase **newChar)
{
  Scaleform::GFx::InteractiveObject *v5; // edi
  _DWORD v6[3]; // [esp+Ch] [ebp-Ch] BYREF

  Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
    this->pDefImpl.pObject,
    (Scaleform::GFx::ResourceBinding *)v6,
    (Scaleform::GFx::ResourceId)pos[1].pWeakProxy);
  if ( v6[0] )
  {
    v5 = (Scaleform::GFx::InteractiveObject *)((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, _DWORD *, Scaleform::GFx::DisplayObjContainer *, Scaleform::WeakPtrProxy *, _DWORD))this->pASRoot->pASSupport.pObject->CreateCharacterInstance)(
                                                this->pASRoot->pASSupport.pObject,
                                                this->pASRoot->pMovieImpl,
                                                v6,
                                                this,
                                                pos[1].pWeakProxy,
                                                0);
    Scaleform::GFx::DisplayObjContainer::ReplaceDisplayObject(this, pos, v5, name);
    if ( newChar )
      *newChar = v5->RefCount <= 1 ? 0 : v5;
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release(v5);
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogError(
      &this->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "DisplayObjContainer::ReplaceDisplayObject() - unknown cid = %d",
      LOWORD(pos[1].pWeakProxy));
  }
}
