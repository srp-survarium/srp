Scaleform::GFx::ImageFileInfo *__thiscall Scaleform::GFx::ImageFileInfo::`scalar deleting destructor'(
        Scaleform::GFx::ImageFileInfo *this,
        char a2)
{
  Scaleform::GFx::ImageFileInfo::~ImageFileInfo(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
