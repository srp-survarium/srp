Scaleform::GFx::GFxMovieDataDefFileKeyData *__thiscall Scaleform::GFx::GFxMovieDataDefFileKeyData::`vector deleting destructor'(
        Scaleform::GFx::GFxMovieDataDefFileKeyData *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::FileOpener *v4; // ecx
  volatile LONG *v5; // edi

  pObject = (Scaleform::RefCountVImpl *)this->pImageCreator.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = this->pFileOpener.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
  v5 = (volatile LONG *)(this->FileName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v5 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v5);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
