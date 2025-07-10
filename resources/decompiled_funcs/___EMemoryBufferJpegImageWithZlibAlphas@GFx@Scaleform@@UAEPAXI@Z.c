Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas *__thiscall Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas::`vector deleting destructor'(
        Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::Image *v4; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->ZLib.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = this->pImage.pObject;
  if ( v4 )
    v4->Release(v4);
  Scaleform::Render::Image::~Image(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
