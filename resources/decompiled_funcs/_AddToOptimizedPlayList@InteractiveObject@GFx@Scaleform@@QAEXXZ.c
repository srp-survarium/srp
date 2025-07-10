void __thiscall Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  Scaleform::GFx::InteractiveObject *pPlayPrev; // edi
  Scaleform::GFx::InteractiveObject *pPlayListOptHead; // eax
  unsigned int Flags; // eax
  unsigned int v6; // eax
  Scaleform::GFx::InteractiveObject *pPlayNextOpt; // edx

  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( (this->Flags & 0x200000) != 0 || (pMovieImpl->Flags & 0x80000) != 0 )
  {
    this->Flags &= ~0x400000u;
  }
  else if ( (this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0
         && (this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x1000) == 0
         && this->Depth >= -1
         && Scaleform::GFx::InteractiveObject::IsInPlayList(this) )
  {
    pPlayPrev = this->pPlayPrev;
    if ( pPlayPrev )
    {
      while ( !Scaleform::GFx::InteractiveObject::IsValidOptAdvListMember(pPlayPrev, pMovieImpl) )
      {
        pPlayPrev = pPlayPrev->pPlayPrev;
        if ( !pPlayPrev )
          goto LABEL_10;
      }
      pPlayNextOpt = pPlayPrev->pPlayNextOpt;
      this->pPlayNextOpt = pPlayNextOpt;
      this->pPlayPrevOpt = pPlayPrev;
      if ( pPlayNextOpt )
        pPlayNextOpt->pPlayPrevOpt = this;
      pPlayPrev->pPlayNextOpt = this;
    }
    else
    {
LABEL_10:
      pPlayListOptHead = pMovieImpl->pPlayListOptHead;
      this->pPlayNextOpt = pPlayListOptHead;
      this->pPlayPrevOpt = 0;
      if ( pPlayListOptHead )
        pPlayListOptHead->pPlayPrevOpt = this;
      pMovieImpl->pPlayListOptHead = this;
    }
    this->Flags |= 0x200000u;
    Flags = this->Flags;
    if ( (pMovieImpl->Flags2 & 8) != 0 )
      v6 = (unsigned int)&unk_800000 | Flags;
    else
      v6 = Flags & 0xFF7FFFFF;
    this->Flags = v6;
    this->Flags &= ~0x400000u;
  }
}
