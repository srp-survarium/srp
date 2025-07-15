void __thiscall Scaleform::Render::RawImage::~RawImage(Scaleform::Render::RawImage *this)
{
  unsigned __int8 Flags; // al
  Scaleform::Render::ImagePlane *pPlanes; // edx
  Scaleform::Render::Palette *pObject; // edi
  LONG v5; // eax
  Scaleform::RefCountVImpl *v6; // edi

  this->__vftable = (Scaleform::Render::RawImage_vtbl *)&Scaleform::Render::RawImage::`vftable';
  Scaleform::Render::RawImage::freeData(this);
  Flags = this->Data.Flags;
  if ( (Flags & 2) != 0 )
  {
    pPlanes = this->Data.pPlanes;
    this->Data.Flags = Flags & 0xFD;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pPlanes);
  }
  this->Data.pPlanes = &this->Data.Plane0;
  pObject = this->Data.pPalette.pObject;
  if ( pObject && InterlockedExchangeAdd(&pObject->RefCount.Value, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
  this->__vftable = (Scaleform::Render::RawImage_vtbl *)&Scaleform::Render::Image::`vftable';
  v5 = InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  v6 = (Scaleform::RefCountVImpl *)v5;
  if ( v5 )
  {
    (*(void (__thiscall **)(LONG))(*(_DWORD *)v5 + 32))(v5);
    Scaleform::RefCountImpl::Release(v6);
  }
  if ( this->pInverseMatrix )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pInverseMatrix);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
