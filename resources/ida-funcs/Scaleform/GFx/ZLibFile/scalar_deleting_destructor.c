Scaleform::GFx::ZLibFile *__thiscall Scaleform::GFx::ZLibFile::`scalar deleting destructor'(
        Scaleform::GFx::ZLibFile *this,
        char a2)
{
  Scaleform::GFx::ZLibFile::~ZLibFile(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
