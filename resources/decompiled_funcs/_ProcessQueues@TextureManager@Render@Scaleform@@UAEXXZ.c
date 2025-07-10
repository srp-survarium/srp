void __thiscall Scaleform::Render::TextureManager::ProcessQueues(Scaleform::Render::TextureManager *this)
{
  Scaleform::Mutex *p_TextureMutex; // edi

  p_TextureMutex = &this->pLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(p_TextureMutex);
  this->processTextureKillList(this);
  this->processInitTextures(this);
  Scaleform::Render::ImageUpdateQueue::ProcessUpdates(&this->ImageUpdates, (int)this);
  Scaleform::Mutex::Unlock(p_TextureMutex);
}
