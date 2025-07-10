void __thiscall Scaleform::Render::MeshKeyManager::DestroyAllKeys(Scaleform::Render::MeshKeyManager *this)
{
  Scaleform::Lock *p_KeySetLock; // edi

  p_KeySetLock = &this->KeySetLock;
  EnterCriticalSection(&this->KeySetLock.cs);
  Scaleform::Render::MeshKeyManager::destroyKeySetList_NTS(this, KeySet_KillList);
  Scaleform::Render::MeshKeyManager::destroyKeySetList_NTS(this, KeySet_LiveList);
  LeaveCriticalSection(&p_KeySetLock->cs);
}
