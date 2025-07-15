void __thiscall Scaleform::Render::MeshKeyManager::ProcessKillList(Scaleform::Render::MeshKeyManager *this)
{
  Scaleform::Lock *p_KeySetLock; // edi

  p_KeySetLock = &this->KeySetLock;
  EnterCriticalSection(&this->KeySetLock.cs);
  Scaleform::Render::MeshKeyManager::destroyKeySetList_NTS(this, KeySet_KillList);
  LeaveCriticalSection(&p_KeySetLock->cs);
}
