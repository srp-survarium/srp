void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::AddFrameName(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        const Scaleform::String *name,
        Scaleform::GFx::LogState *plog)
{
  Scaleform::Lock *p_PlaylistLock; // edi

  p_PlaylistLock = &this->PlaylistLock;
  EnterCriticalSection(&this->PlaylistLock.cs);
  Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::SetCaseInsensitive(
    &this->NamedFrames,
    name,
    &this->LoadingFrame);
  LeaveCriticalSection(&p_PlaylistLock->cs);
}
