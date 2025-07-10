Scaleform::Render::Text::FontHandle *__thiscall Scaleform::Render::Text::FontHandle::`vector deleting destructor'(
        Scaleform::Render::Text::FontHandle *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  volatile LONG *v4; // edi

  this->__vftable = (Scaleform::Render::Text::FontHandle_vtbl *)&Scaleform::Render::Text::FontHandle::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = (volatile LONG *)(this->FontName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
