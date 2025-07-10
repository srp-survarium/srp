void __thiscall Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(
        Scaleform::Render::ImageScanlineBufferImpl *this)
{
  if ( this->BuffersAllocated )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pReadScanline);
}
