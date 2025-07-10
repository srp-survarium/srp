void __thiscall Scaleform::GFx::InteractiveObject::OnEventUnload(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  Scaleform::GFx::InteractiveObject *pPlayNext; // eax
  Scaleform::GFx::InteractiveObject *pPlayPrev; // eax

  pASRoot = this->pASRoot;
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x1000u;
  pMovieImpl = pASRoot->pMovieImpl;
  Scaleform::GFx::InteractiveObject::RemoveFromOptimizedPlayList(this);
  pPlayNext = this->pPlayNext;
  if ( pPlayNext )
    pPlayNext->pPlayPrev = this->pPlayPrev;
  pPlayPrev = this->pPlayPrev;
  if ( pPlayPrev )
  {
    pPlayPrev->pPlayNext = this->pPlayNext;
  }
  else if ( pMovieImpl->pPlayListHead == this )
  {
    pMovieImpl->pPlayListHead = this->pPlayNext;
  }
  this->pPlayPrev = 0;
  this->pPlayNext = 0;
  Scaleform::GFx::MovieImpl::StopDragCharacter(pMovieImpl, this);
  if ( pMovieImpl )
    Scaleform::GFx::MovieImpl::ResetFocusForChar(pMovieImpl, this);
  Scaleform::GFx::DisplayObject::OnEventUnload(this);
}
