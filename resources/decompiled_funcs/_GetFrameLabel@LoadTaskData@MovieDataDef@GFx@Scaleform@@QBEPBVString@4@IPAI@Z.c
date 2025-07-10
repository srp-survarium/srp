Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *__thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::GetFrameLabel(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        unsigned int frameNumber,
        unsigned int *exactFrameNumberForLabel)
{
  Scaleform::Lock *p_PlaylistLock; // esi
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v6; // edi

  if ( this->LoadState >= LS_LoadFinished )
    return Scaleform::GFx::MovieDataDef::TranslateNumberToFrameString(
             &this->NamedFrames,
             frameNumber,
             exactFrameNumberForLabel);
  p_PlaylistLock = &this->PlaylistLock;
  EnterCriticalSection(&this->PlaylistLock.cs);
  v6 = Scaleform::GFx::MovieDataDef::TranslateNumberToFrameString(
         &this->NamedFrames,
         frameNumber,
         exactFrameNumberForLabel);
  LeaveCriticalSection(&p_PlaylistLock->cs);
  return v6;
}
