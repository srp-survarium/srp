void __thiscall Scaleform::Render::Texture::LoseManager(Scaleform::Render::Texture *this)
{
  Scaleform::Lock *p_ImageLock; // edi
  void (__thiscall *ReleaseHWTextures)(Scaleform::Render::Texture *, bool); // eax
  Scaleform::Render::ImageBase *pImage; // ecx

  p_ImageLock = &this->pManagerLocks.pObject->ImageLock;
  EnterCriticalSection(&p_ImageLock->cs);
  this->pPrev->pNext = this->pNext;
  this->pNext->pPrev = this->pPrev;
  ReleaseHWTextures = this->ReleaseHWTextures;
  this->pPrev = 0;
  this->pNext = 0;
  ReleaseHWTextures(this, 1);
  pImage = this->pImage;
  this->State = 4;
  this->pFormat = 0;
  if ( pImage )
  {
    this->pImage = 0;
    ((void (__thiscall *)(Scaleform::Render::ImageBase *, _DWORD))pImage->__vftable[2].Release)(pImage, 0);
  }
  LeaveCriticalSection(&p_ImageLock->cs);
}
