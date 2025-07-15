unsigned int __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::GetInitActionListSize(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  Scaleform::Lock *p_PlaylistLock; // edi
  unsigned int Size; // esi

  p_PlaylistLock = &this->PlaylistLock;
  EnterCriticalSection(&this->PlaylistLock.cs);
  Size = this->InitActionList.Data.Size;
  LeaveCriticalSection(&p_PlaylistLock->cs);
  return Size;
}
