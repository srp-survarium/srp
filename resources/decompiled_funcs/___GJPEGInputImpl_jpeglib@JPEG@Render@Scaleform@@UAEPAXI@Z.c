Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *__thiscall Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::`scalar deleting destructor'(
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *this,
        char a2)
{
  Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::~JPEGInputImpl_jpeglib(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
