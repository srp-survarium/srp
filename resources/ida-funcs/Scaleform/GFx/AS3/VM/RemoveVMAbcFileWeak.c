char __thiscall Scaleform::GFx::AS3::VM::RemoveVMAbcFileWeak(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMAbcFile *f)
{
  unsigned int Size; // edx
  int v4; // eax
  Scaleform::GFx::AS3::VMAbcFile **i; // ecx

  if ( this->InDestructor )
    return 0;
  Size = this->VMAbcFilesWeak.Data.Size;
  v4 = 0;
  if ( !Size )
    return 0;
  for ( i = this->VMAbcFilesWeak.Data.Data; *i != f; ++i )
  {
    if ( ++v4 >= Size )
      return 0;
  }
  if ( Size == 1 )
  {
    if ( (this->VMAbcFilesWeak.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( this->VMAbcFilesWeak.Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->VMAbcFilesWeak.Data.Data);
        this->VMAbcFilesWeak.Data.Data = 0;
      }
      this->VMAbcFilesWeak.Data.Policy.Capacity = 0;
    }
    this->VMAbcFilesWeak.Data.Size = 0;
    return 1;
  }
  else
  {
    memmove(
      (int)&this->VMAbcFilesWeak.Data.Data[v4],
      (const __m128i *)&this->VMAbcFilesWeak.Data.Data[v4 + 1],
      4 * (this->VMAbcFilesWeak.Data.Size - v4) - 4);
    --this->VMAbcFilesWeak.Data.Size;
    return 1;
  }
}
