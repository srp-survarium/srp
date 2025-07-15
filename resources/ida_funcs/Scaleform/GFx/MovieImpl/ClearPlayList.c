void __thiscall Scaleform::GFx::MovieImpl::ClearPlayList(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *pPlayListHead; // eax
  Scaleform::GFx::InteractiveObject *pPlayNext; // edx

  pPlayListHead = this->pPlayListHead;
  if ( pPlayListHead )
  {
    do
    {
      pPlayNext = pPlayListHead->pPlayNext;
      pPlayListHead->pPlayPrevOpt = 0;
      pPlayListHead->pPlayNextOpt = 0;
      pPlayListHead->pPlayPrev = 0;
      pPlayListHead->pPlayNext = 0;
      pPlayListHead = pPlayNext;
    }
    while ( pPlayNext );
  }
  this->pPlayListHead = 0;
  this->pPlayListOptHead = 0;
}
