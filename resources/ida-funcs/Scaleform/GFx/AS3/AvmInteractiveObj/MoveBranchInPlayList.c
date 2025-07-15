void __thiscall Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(
        Scaleform::GFx::AS3::AvmInteractiveObj *this)
{
  Scaleform::GFx::DisplayObject *pDispObj; // esi
  Scaleform::GFx::InteractiveObject *RefCount; // ecx
  Scaleform::GFx::DisplayObject_vtbl *v4; // edx
  Scaleform::GFx::DisplayObject *pParent; // eax
  Scaleform::GFx::InteractiveObject *pPlayNext; // edi
  Scaleform::GFx::InteractiveObject *v7; // eax
  Scaleform::GFx::InteractiveObject_vtbl **v8; // ecx
  int v9; // eax
  int v10; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  int v12; // eax
  Scaleform::GFx::DisplayObject_vtbl *v13; // ecx
  Scaleform::GFx::InteractiveObject *pPlayListHead; // eax
  unsigned int *p_Flags; // eax
  Scaleform::GFx::InteractiveObject *pafter; // [esp+Ch] [ebp-4h]

  pDispObj = this->pDispObj;
  RefCount = (Scaleform::GFx::InteractiveObject *)pDispObj[1].RefCount;
  v4 = pDispObj[1].Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
  for ( pafter = 0; RefCount; RefCount = RefCount->pPlayPrev )
  {
    pParent = RefCount;
    while ( pParent != pDispObj )
    {
      pParent = pParent->pParent;
      if ( !pParent )
      {
        pafter = RefCount;
        pPlayNext = RefCount->pPlayNext;
        RefCount->pPlayNext = (Scaleform::GFx::InteractiveObject *)v4;
        goto LABEL_6;
      }
    }
  }
  if ( v4 )
  {
    pMovieImpl = pDispObj->pASRoot->pMovieImpl;
    pPlayNext = pMovieImpl->pPlayListHead;
    pMovieImpl->pPlayListHead = (Scaleform::GFx::InteractiveObject *)v4;
LABEL_6:
    if ( v4 )
      v4->GetY = (long double (__thiscall *)(Scaleform::GFx::DisplayObjectBase *))pafter;
  }
  else
  {
    pPlayNext = (Scaleform::GFx::InteractiveObject *)pDispObj;
  }
  pDispObj[1].Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = 0;
  pPlayNext->pPlayPrev = 0;
  v7 = this->pDispObj->pParent;
  if ( v7
    && ((v8 = &v7->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
            + v7->AvmObjOffset,
         (v9 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject_vtbl **))(*v8)->CreateRenderNode)(v8)) == 0)
      ? (v10 = 0)
      : (v10 = v9 - 28),
        (v12 = (*(int (__thiscall **)(int, Scaleform::GFx::DisplayObject *))(*(_DWORD *)v10 + 100))(v10, pDispObj)) != 0) )
  {
    v13 = *(Scaleform::GFx::DisplayObject_vtbl **)(v12 + 84);
    pDispObj[1].Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = v13;
    if ( v13 )
      v13->GetY = (long double (__thiscall *)(Scaleform::GFx::DisplayObjectBase *))pDispObj;
    *(_DWORD *)(v12 + 84) = pPlayNext;
    pPlayNext->pPlayPrev = (Scaleform::GFx::InteractiveObject *)v12;
  }
  else
  {
    pPlayListHead = this->pDispObj->pASRoot->pMovieImpl->pPlayListHead;
    if ( pPlayListHead )
    {
      pDispObj[1].Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::DisplayObject_vtbl *)pPlayListHead;
      pPlayListHead->pPlayPrev = (Scaleform::GFx::InteractiveObject *)pDispObj;
    }
    this->pDispObj->pASRoot->pMovieImpl->pPlayListHead = pPlayNext;
  }
  p_Flags = &this->pDispObj->pASRoot->pMovieImpl->Flags;
  *p_Flags |= 0x80000u;
}
