Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *__thiscall Scaleform::GFx::XML::DOMStringManager::AllocTextBuffer(
        Scaleform::GFx::XML::DOMStringManager *this,
        const __m128i *pbuffer,
        unsigned int length)
{
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *pFreeTextBuffers; // eax
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v5; // esi

  if ( length >= 0xC )
  {
    v5 = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)this->pHeap->Alloc(this->pHeap, length + 1, 0);
  }
  else
  {
    if ( !this->pFreeTextBuffers )
      Scaleform::GFx::XML::DOMStringManager::AllocateTextBuffers(this);
    pFreeTextBuffers = this->pFreeTextBuffers;
    v5 = 0;
    if ( pFreeTextBuffers )
    {
      v5 = this->pFreeTextBuffers;
      this->pFreeTextBuffers = pFreeTextBuffers->pNextAlloc;
    }
  }
  if ( v5 )
  {
    memcpy((int)v5, pbuffer, length);
    v5->Buff[length] = 0;
  }
  return v5;
}
