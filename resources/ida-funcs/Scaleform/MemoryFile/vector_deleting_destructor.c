Scaleform::MemoryFile *__thiscall Scaleform::MemoryFile::`vector deleting destructor'(
        Scaleform::MemoryFile *this,
        char a2)
{
  Scaleform::MemoryFile::~MemoryFile(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
