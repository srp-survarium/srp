void __thiscall Scaleform::GFx::AS2::MovieRoot::NotifyOnResize(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  int v4; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // esi
  Scaleform::GFx::Sprite *LevelMovie; // eax
  Scaleform::GFx::Sprite *v9; // edi
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::RefCountNTSImpl *v11; // ecx

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v4 = 0;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    for ( i = Data; i->Level; ++i )
    {
      if ( ++v4 >= Size )
        return;
    }
    if ( Data[v4].pSprite.pObject )
    {
      inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(&this->ActionQueue, AP_Frame);
      if ( inserted )
      {
        LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(this, 0);
        v9 = LevelMovie;
        inserted->Type = Entry_CFunction;
        if ( LevelMovie )
          ++LevelMovie->RefCount;
        pObject = inserted->pCharacter.pObject;
        if ( pObject )
          Scaleform::RefCountNTSImpl::Release(pObject);
        inserted->pCharacter.pObject = v9;
        v11 = inserted->pActionBuffer.pObject;
        if ( v11 )
          Scaleform::RefCountNTSImpl::Release(v11);
        inserted->pActionBuffer.pObject = 0;
        inserted->CFunction = Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize;
      }
    }
  }
}
