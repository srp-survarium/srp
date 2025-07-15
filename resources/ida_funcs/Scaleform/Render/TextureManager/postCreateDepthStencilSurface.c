Scaleform::Render::DepthStencilSurface *__thiscall Scaleform::Render::TextureManager::postCreateDepthStencilSurface(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::DepthStencilSurface *pdss)
{
  Scaleform::Mutex *p_TextureMutex; // ebx

  if ( !pdss )
    return 0;
  p_TextureMutex = &this->pLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(p_TextureMutex);
  if ( this->CanCreateTextureCurrentThread(this) )
  {
    this->processTextureKillList(this);
    this->processInitTextures(this);
    pdss->Initialize(pdss);
    Scaleform::Mutex::Unlock(p_TextureMutex);
    return pdss;
  }
  else
  {
    pdss->pPrev = this->DepthStencilInitQueue.Root.pPrev;
    pdss->pNext = (Scaleform::Render::DepthStencilSurface *)&this->TextureInitQueue;
    this->DepthStencilInitQueue.Root.pPrev->pNext = pdss;
    this->DepthStencilInitQueue.Root.pPrev = pdss;
    if ( this->pRTCommandQueue )
    {
      Scaleform::Mutex::Unlock(&this->pLocks.pObject->TextureMutex);
      this->pRTCommandQueue->PushThreadCommand(this->pRTCommandQueue, &this->ServiceCommandInstance);
      Scaleform::Mutex::DoLock(&this->pLocks.pObject->TextureMutex);
    }
    while ( pdss->State == State_PreCapture )
      Scaleform::WaitCondition::Wait(
        &this->pLocks.pObject->TextureInitWC,
        &this->pLocks.pObject->TextureMutex,
        0xFFFFFFFF);
    Scaleform::Mutex::Unlock(p_TextureMutex);
    return pdss;
  }
}
