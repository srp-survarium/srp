void __thiscall Scaleform::Render::SubImage::~SubImage(Scaleform::Render::SubImage *this)
{
  Scaleform::Render::Image *pObject; // ecx
  LONG v3; // eax
  Scaleform::RefCountVImpl *v4; // edi

  pObject = this->pImage.pObject;
  if ( pObject )
    pObject->Release(pObject);
  this->__vftable = (Scaleform::Render::SubImage_vtbl *)&Scaleform::Render::Image::`vftable';
  v3 = InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  v4 = (Scaleform::RefCountVImpl *)v3;
  if ( v3 )
  {
    (*(void (__thiscall **)(LONG))(*(_DWORD *)v3 + 32))(v3);
    Scaleform::RefCountImpl::Release(v4);
  }
  if ( this->pInverseMatrix )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pInverseMatrix);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
