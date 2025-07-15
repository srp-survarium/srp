void __thiscall Scaleform::Render::JPEG::JpegErrorHandler::JpegErrorHandler(
        Scaleform::Render::JPEG::JpegErrorHandler *this)
{
  this->psetjmp_buffer = (int (*)[16])Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 64, 32, 0);
}
