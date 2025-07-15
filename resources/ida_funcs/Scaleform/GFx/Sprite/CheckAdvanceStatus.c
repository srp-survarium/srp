int __thiscall Scaleform::GFx::Sprite::CheckAdvanceStatus(Scaleform::GFx::Sprite *this, bool playingNow)
{
  char v3; // bl
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax
  int result; // eax
  unsigned __int8 AvmObjOffset; // al
  int v7; // eax
  unsigned __int8 v8; // al
  int v9; // eax
  bool v10; // zf

  if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 0xC) != 0
    || (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x40) != 0 )
  {
    v3 = 1;
  }
  else
  {
    v3 = 0;
    if ( this->GetPlayState(this) == State_Playing )
      return !playingNow;
    if ( Scaleform::GFx::MovieImpl::IsDraggingCharacter(this->pASRoot->pMovieImpl, this, 0) )
      return !playingNow;
    pActiveSounds = this->pActiveSounds;
    if ( pActiveSounds )
    {
      if ( pActiveSounds->Sounds.Data.Size )
        return !playingNow;
    }
  }
  if ( playingNow )
  {
    if ( v3 )
      return -1;
    AvmObjOffset = this->AvmObjOffset;
    if ( !AvmObjOffset )
      return -1;
    v7 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + AvmObjOffset)
                                       + 8))(
           (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * AvmObjOffset);
    if ( !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v7 + 128))(v7) )
      return -1;
    return 0;
  }
  if ( v3 )
    return 0;
  v8 = this->AvmObjOffset;
  if ( !v8 )
    return 0;
  v9 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                       + v8)
                                     + 8))(
         (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + 4 * v8);
  v10 = (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v9 + 128))(v9) == 0;
  result = 1;
  if ( v10 )
    return 0;
  return result;
}
