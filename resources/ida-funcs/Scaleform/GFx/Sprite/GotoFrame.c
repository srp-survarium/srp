void __thiscall Scaleform::GFx::Sprite::GotoFrame(Scaleform::GFx::Sprite *this, signed int targetFrameNumber)
{
  signed int v3; // eax
  unsigned int v4; // edi
  unsigned int CurrentFrame; // eax
  unsigned int v6; // eax
  Scaleform::MemoryHeap *v7; // eax
  unsigned __int8 v8; // al
  int v9; // eax
  unsigned int i; // ebx
  int v11; // eax
  unsigned __int8 AvmObjOffset; // al
  int v13; // eax
  Scaleform::GFx::TimelineSnapshot v14; // [esp+4h] [ebp-34h] BYREF

  if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x800) != 0
    && (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x1000) == 0
    && this->Depth >= -1 )
  {
    v3 = this->GetLoadingFrame(this) - 1;
    if ( targetFrameNumber < v3 )
      v3 = targetFrameNumber;
    v4 = v3 < 0 ? 0 : v3;
    Scaleform::GFx::Sprite::SetStreamingSound(this, 0);
    CurrentFrame = this->CurrentFrame;
    if ( v4 >= CurrentFrame )
    {
      if ( v4 > CurrentFrame )
      {
        if ( v4 <= 1 || v4 <= CurrentFrame + 1 )
        {
          this->CurrentFrame = v4;
        }
        else
        {
          Scaleform::GFx::TimelineSnapshot::TimelineSnapshot(
            &v14,
            Direction_Forward,
            this->pASRoot->pMovieImpl->pHeap,
            this);
          Scaleform::GFx::TimelineSnapshot::MakeSnapshot(&v14, this->pDef.pObject, this->CurrentFrame + 1, v4 - 1);
          if ( this->AvmObjOffset )
          {
            for ( i = this->CurrentFrame + 1; i < v4; ++i )
            {
              v11 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                    + this->AvmObjOffset)
                                                  + 8))(
                      (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                    + 4 * this->AvmObjOffset);
              (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v11 + 112))(v11, i);
            }
          }
          this->CurrentFrame = v4;
          Scaleform::GFx::TimelineSnapshot::ExecuteSnapshot(&v14, this);
          Scaleform::GFx::TimelineSnapshot::~TimelineSnapshot(&v14);
        }
        AvmObjOffset = this->AvmObjOffset;
        if ( AvmObjOffset )
        {
          v13 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                + AvmObjOffset)
                                              + 8))(
                  (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                + 4 * AvmObjOffset);
          (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v13 + 112))(v13, v4);
        }
        Scaleform::GFx::Sprite::ExecuteFrameTags(this, v4);
      }
      this->PlayStatePriv = State_Stopped;
    }
    else
    {
      if ( v4 )
        v6 = v4 - 1;
      else
        v6 = 0;
      Scaleform::GFx::DisplayList::MarkAllEntriesForRemoval(&this->mDisplayList, this, v6);
      if ( v4 )
      {
        v7 = this->pASRoot->pMovieImpl->GetHeap(this->pASRoot->pMovieImpl);
        Scaleform::GFx::TimelineSnapshot::TimelineSnapshot(&v14, Direction_Backward, v7, this);
        Scaleform::GFx::TimelineSnapshot::MakeSnapshot(&v14, this->pDef.pObject, 0, v4 - 1);
        this->CurrentFrame = v4;
        Scaleform::GFx::TimelineSnapshot::ExecuteSnapshot(&v14, this);
        Scaleform::GFx::TimelineSnapshot::~TimelineSnapshot(&v14);
      }
      else
      {
        this->CurrentFrame = 0;
      }
      v8 = this->AvmObjOffset;
      if ( v8 )
      {
        v9 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                             + v8)
                                           + 8))(
               (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
             + 4 * v8);
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v9 + 112))(v9, v4);
      }
      Scaleform::GFx::Sprite::ExecuteFrameTags(this, v4);
      Scaleform::GFx::DisplayList::UnloadMarkedObjects(&this->mDisplayList, this);
      this->PlayStatePriv = State_Stopped;
    }
  }
}
