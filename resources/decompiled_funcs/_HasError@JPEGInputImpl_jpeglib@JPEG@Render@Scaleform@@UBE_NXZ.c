bool __thiscall Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::HasError(
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *this)
{
  return (*((_BYTE *)this + 792) & 2) != 0;
}
