void __thiscall Scaleform::Render::Texture::ImageLost(Scaleform::Render::Texture *this)
{
  Scaleform::Lock *p_ImageLock; // esi

  p_ImageLock = &this->pManagerLocks.pObject->ImageLock;
  EnterCriticalSection(&p_ImageLock->cs);
  this->pImage = 0;
  LeaveCriticalSection(&p_ImageLock->cs);
}
