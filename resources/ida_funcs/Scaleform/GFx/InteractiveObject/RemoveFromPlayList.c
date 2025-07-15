void __thiscall Scaleform::GFx::InteractiveObject::RemoveFromPlayList(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  Scaleform::GFx::InteractiveObject *v2; // ecx
  Scaleform::GFx::InteractiveObject *pPlayNext; // eax
  Scaleform::GFx::InteractiveObject *pPlayPrev; // eax

  pMovieImpl = this->pASRoot->pMovieImpl;
  Scaleform::GFx::InteractiveObject::RemoveFromOptimizedPlayList(this);
  pPlayNext = v2->pPlayNext;
  if ( pPlayNext )
    pPlayNext->pPlayPrev = v2->pPlayPrev;
  pPlayPrev = v2->pPlayPrev;
  if ( pPlayPrev )
  {
    pPlayPrev->pPlayNext = v2->pPlayNext;
    v2->pPlayPrev = 0;
    v2->pPlayNext = 0;
  }
  else
  {
    if ( pMovieImpl->pPlayListHead == v2 )
      pMovieImpl->pPlayListHead = v2->pPlayNext;
    v2->pPlayPrev = 0;
    v2->pPlayNext = 0;
  }
}
