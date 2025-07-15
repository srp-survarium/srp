char __thiscall Scaleform::GFx::MovieImpl::ReleaseLevelMovie(Scaleform::GFx::MovieImpl *this, int level)
{
  Scaleform::GFx::MovieImpl *v3; // ecx
  Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::LevelInfo,327,Scaleform::ArrayDefaultPolicy> *v4; // esi
  Scaleform::GFx::InteractiveObject *v5; // ebp
  unsigned int v6; // ebp
  Scaleform::RefCountNTSImpl *v7; // ecx
  int v9; // ebx
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // ecx
  Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::LevelInfo,327,Scaleform::ArrayDefaultPolicy> *p_MovieLevels; // ebp
  Scaleform::GFx::MovieImpl::LevelInfo *i; // eax
  Scaleform::GFx::InteractiveObject *pObject; // eax
  Scaleform::RefCountNTSImpl *v14; // esi
  Scaleform::RefCountNTSImpl *v15; // ecx

  if ( level )
  {
    v9 = 0;
    if ( this->MovieLevels.Data.Size )
    {
      Data = this->MovieLevels.Data.Data;
      p_MovieLevels = &this->MovieLevels;
      for ( i = this->MovieLevels.Data.Data; i->Level != level; ++i )
      {
        if ( ++v9 >= this->MovieLevels.Data.Size )
          return 0;
      }
      pObject = Data[v9].pSprite.pObject;
      if ( pObject )
        ++pObject->RefCount;
      v14 = Data[v9].pSprite.pObject;
      v14->__vftable[73].~Scaleform::RefCountNTSImpl(v14);
      this->pASMovieRoot.pObject->DoActions(this->pASMovieRoot.pObject);
      v14->__vftable[58].~Scaleform::RefCountNTSImpl(v14);
      if ( this->MovieLevels.Data.Size == 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &this->MovieLevels.Data,
          &this->MovieLevels,
          0);
      }
      else
      {
        v15 = p_MovieLevels->Data.Data[v9].pSprite.pObject;
        if ( v15 )
          Scaleform::RefCountNTSImpl::Release(v15);
        memmove(
          (unsigned __int8 *)&p_MovieLevels->Data.Data[v9],
          (unsigned __int8 *)&p_MovieLevels->Data.Data[v9 + 1],
          8 * (this->MovieLevels.Data.Size - v9) - 8);
        --this->MovieLevels.Data.Size;
      }
      this->Flags |= 0x100u;
      Scaleform::RefCountNTSImpl::Release(v14);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    Scaleform::GFx::MovieImpl::StopAllDrags(this);
    Scaleform::GFx::MovieImpl::ShutdownTimers(v3);
    if ( this->MovieLevels.Data.Size )
    {
      v4 = &this->MovieLevels;
      do
      {
        v5 = v4->Data.Data[this->MovieLevels.Data.Size - 1].pSprite.pObject;
        v5->OnEventUnload(v5);
        this->pASMovieRoot.pObject->DoActions(this->pASMovieRoot.pObject);
        v5->ForceShutdown(v5);
        v6 = this->MovieLevels.Data.Size - 1;
        if ( this->MovieLevels.Data.Size == 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &this->MovieLevels.Data,
            &this->MovieLevels,
            0);
        }
        else
        {
          v7 = v4->Data.Data[v6].pSprite.pObject;
          if ( v7 )
            Scaleform::RefCountNTSImpl::Release(v7);
          memmove(
            (unsigned __int8 *)&v4->Data.Data[v6],
            (unsigned __int8 *)&v4->Data.Data[v6 + 1],
            8 * (this->MovieLevels.Data.Size - v6) - 8);
          --this->MovieLevels.Data.Size;
        }
      }
      while ( this->MovieLevels.Data.Size );
    }
    this->pMainMovie = 0;
    this->FrameTime = 0.083333336;
    this->Flags |= 0x100u;
    return 1;
  }
}
