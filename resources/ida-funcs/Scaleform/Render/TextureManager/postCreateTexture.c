Scaleform::RefCountVImpl *__thiscall Scaleform::Render::TextureManager::postCreateTexture(
        Scaleform::Render::TextureManager *this,
        Scaleform::RefCountVImpl *ptexture,
        __int16 use)
{
  Scaleform::Mutex *p_TextureMutex; // ebx
  volatile int RefCount; // ecx

  if ( !ptexture )
    return 0;
  if ( !((unsigned __int8 (__thiscall *)(Scaleform::RefCountVImpl *))ptexture->Release)(ptexture) )
  {
    Scaleform::RefCountImpl::Release(ptexture);
    return 0;
  }
  p_TextureMutex = &this->pLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(p_TextureMutex);
  if ( this->CanCreateTextureCurrentThread(this) )
  {
    this->processTextureKillList(this);
    this->processInitTextures(this);
    if ( ((unsigned __int8 (__thiscall *)(Scaleform::RefCountVImpl *))ptexture->AddRef)(ptexture) )
    {
      ptexture[1].__vftable = (Scaleform::RefCountVImpl_vtbl *)this->Textures.Root.pPrev;
      ptexture[1].RefCount = (volatile int)&this->TextureFormats.Data.Size;
      this->Textures.Root.pPrev->pNext = (Scaleform::Render::Texture *)ptexture;
      this->Textures.Root.pPrev = (Scaleform::Render::Texture *)ptexture;
    }
  }
  else
  {
    ptexture[1].__vftable = (Scaleform::RefCountVImpl_vtbl *)this->TextureInitQueue.Root.pPrev;
    ptexture[1].RefCount = (volatile int)&this->Textures;
    this->TextureInitQueue.Root.pPrev->pNext = (Scaleform::Render::Texture *)ptexture;
    this->TextureInitQueue.Root.pPrev = (Scaleform::Render::Texture *)ptexture;
    Scaleform::Mutex::Unlock(&this->pLocks.pObject->TextureMutex);
    this->pRTCommandQueue->PushThreadCommand(this->pRTCommandQueue, &this->ServiceCommandInstance);
    Scaleform::Mutex::DoLock(&this->pLocks.pObject->TextureMutex);
    while ( !ptexture[4].__vftable )
      Scaleform::WaitCondition::Wait(
        &this->pLocks.pObject->TextureInitWC,
        &this->pLocks.pObject->TextureMutex,
        0xFFFFFFFF);
  }
  if ( (use & 0x100) != 0 )
  {
    RefCount = ptexture[2].RefCount;
    if ( RefCount && (*(int (__thiscall **)(volatile int))(*(_DWORD *)RefCount + 12))(RefCount) == 2 )
      Scaleform::Render::RawImage::freeData((Scaleform::Render::RawImage *)ptexture[2].RefCount);
    ptexture[2].RefCount = 0;
  }
  if ( ptexture[4].__vftable == (Scaleform::RefCountVImpl_vtbl *)1 )
  {
    Scaleform::RefCountImpl::Release(ptexture);
    Scaleform::Mutex::Unlock(p_TextureMutex);
    return 0;
  }
  else
  {
    Scaleform::Mutex::Unlock(p_TextureMutex);
    return ptexture;
  }
}
