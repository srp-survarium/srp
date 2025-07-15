void __thiscall Scaleform::Render::JPEG::JpegErrorHandler::~JpegErrorHandler(
        Scaleform::Render::JPEG::JpegErrorHandler *this)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->psetjmp_buffer);
}
