void __thiscall Scaleform::GFx::Sprite::Restart(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::DisplayList *p_mDisplayList; // edi
  unsigned __int8 AvmObjOffset; // al
  int v4; // eax

  p_mDisplayList = &this->mDisplayList;
  Scaleform::GFx::DisplayList::MarkAllEntriesForRemoval(&this->mDisplayList, this, 0);
  this->Flags = this->Flags & 0xFC | 1;
  AvmObjOffset = this->AvmObjOffset;
  this->CurrentFrame = 0;
  this->RollOverCnt = 0;
  this->PlayStatePriv = State_Playing;
  if ( AvmObjOffset )
  {
    v4 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + AvmObjOffset)
                                       + 8))(
           (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * AvmObjOffset);
    (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 112))(v4, this->CurrentFrame);
  }
  Scaleform::GFx::Sprite::ExecuteFrameTags(this, this->CurrentFrame);
  Scaleform::GFx::DisplayList::UnloadMarkedObjects(p_mDisplayList, this);
}
