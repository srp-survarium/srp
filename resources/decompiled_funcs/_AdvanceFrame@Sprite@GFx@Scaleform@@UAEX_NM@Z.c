void __thiscall Scaleform::GFx::Sprite::AdvanceFrame(Scaleform::GFx::Sprite *this, int nextFrame, float framePos)
{
  Scaleform::GFx::SoundStreamDef *v4; // eax
  unsigned __int8 AvmObjOffset; // al
  int v6; // eax

  if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x800) != 0
    && (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 0xC) == 0
    && (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x1000) == 0
    && this->Depth >= -1 )
  {
    ++this->RefCount;
    if ( (_BYTE)nextFrame )
    {
      Scaleform::GFx::Sprite::CheckActiveSounds(this);
      if ( this->PlayStatePriv != State_Stopped )
      {
        v4 = this->pDef.pObject->GetSoundStream(this->pDef.pObject);
        if ( v4 )
        {
          if ( !v4->ProcessSwfFrame(v4, this->pASRoot->pMovieImpl, this->CurrentFrame, this) )
            this->pDef.pObject->SetSoundStream(this->pDef.pObject, 0);
        }
      }
    }
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v6 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + AvmObjOffset)
                                         + 8))(
             (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
           + 4 * AvmObjOffset);
      (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v6 + 100))(v6, nextFrame, LODWORD(framePos));
    }
    Scaleform::RefCountNTSImpl::Release(this);
  }
}
