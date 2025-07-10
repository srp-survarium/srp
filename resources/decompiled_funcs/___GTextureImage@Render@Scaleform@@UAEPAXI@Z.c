Scaleform::Render::TextureImage *__thiscall Scaleform::Render::TextureImage::`scalar deleting destructor'(
        Scaleform::Render::TextureImage *this,
        char a2)
{
  LONG v3; // eax
  Scaleform::RefCountVImpl *v4; // edi

  this->__vftable = (Scaleform::Render::TextureImage_vtbl *)&Scaleform::Render::Image::`vftable';
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
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
