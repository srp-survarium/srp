void __thiscall Scaleform::GFx::InteractiveObject::AddToPlayList(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::GFx::InteractiveObject *pPlayListHead; // edx

  if ( (this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0
    && (this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x1000) == 0
    && this->Depth >= -1 )
  {
    pMovieImpl = this->pASRoot->pMovieImpl;
    pPlayListHead = pMovieImpl->pPlayListHead;
    if ( pPlayListHead )
    {
      pPlayListHead->pPlayPrev = this;
      this->pPlayNext = pMovieImpl->pPlayListHead;
    }
    pMovieImpl->pPlayListHead = this;
  }
}
