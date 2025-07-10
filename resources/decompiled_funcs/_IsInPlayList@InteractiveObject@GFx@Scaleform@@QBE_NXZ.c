BOOL __thiscall Scaleform::GFx::InteractiveObject::IsInPlayList(Scaleform::GFx::InteractiveObject *this)
{
  return this->pPlayNext || this->pPlayPrev || this->pASRoot->pMovieImpl->pPlayListHead == this;
}
