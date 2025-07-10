void __thiscall Scaleform::GFx::InteractiveObject::RemoveFromOptimizedPlayList(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  Scaleform::GFx::InteractiveObject *pPlayPrevOpt; // eax
  Scaleform::GFx::InteractiveObject *pPlayNextOpt; // eax

  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( (this->Flags & 0x200000) != 0 )
  {
    if ( (pMovieImpl->Flags & 0x80000) == 0 )
    {
      pPlayPrevOpt = this->pPlayPrevOpt;
      if ( pPlayPrevOpt )
        pPlayPrevOpt->pPlayNextOpt = this->pPlayNextOpt;
      else
        pMovieImpl->pPlayListOptHead = this->pPlayNextOpt;
      pPlayNextOpt = this->pPlayNextOpt;
      if ( pPlayNextOpt )
        pPlayNextOpt->pPlayPrevOpt = this->pPlayPrevOpt;
    }
    this->Flags &= 0xFF9FFFFF;
    this->pPlayPrevOpt = 0;
    this->pPlayNextOpt = 0;
  }
}
