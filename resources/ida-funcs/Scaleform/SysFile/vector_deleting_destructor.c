Scaleform::Render::UnmapTextureThreadCommand *__thiscall Scaleform::SysFile::`vector deleting destructor'(
        Scaleform::Render::UnmapTextureThreadCommand *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pTexture.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
