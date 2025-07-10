void __thiscall Scaleform::Render::Image::~Image(Scaleform::Render::Image *this)
{
  LONG v2; // eax
  Scaleform::RefCountVImpl *v3; // edi

  this->__vftable = (Scaleform::Render::Image_vtbl *)&Scaleform::Render::Image::`vftable';
  v2 = InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  v3 = (Scaleform::RefCountVImpl *)v2;
  if ( v2 )
  {
    (*(void (__thiscall **)(LONG))(*(_DWORD *)v2 + 32))(v2);
    Scaleform::RefCountImpl::Release(v3);
  }
  if ( this->pInverseMatrix )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pInverseMatrix);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
