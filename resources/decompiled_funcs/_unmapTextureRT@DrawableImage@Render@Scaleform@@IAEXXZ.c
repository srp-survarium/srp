void __thiscall Scaleform::Render::DrawableImage::unmapTextureRT(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Lock *p_QueueLock; // edi

  p_QueueLock = &this->pQueue.pObject->QueueLock;
  EnterCriticalSection(&p_QueueLock->cs);
  if ( (this->DrawableImageState & 3) != 0 && this->pTexture.Value )
  {
    this->pTexture.Value->Unmap(this->pTexture.Value);
    this->DrawableImageState &= 0xFFFFFFFC;
  }
  LeaveCriticalSection(&p_QueueLock->cs);
}
