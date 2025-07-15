void __thiscall Scaleform::GFx::AS3::VM::UnregisterAllAbcFiles(Scaleform::GFx::AS3::VM *this)
{
  unsigned int Size; // ebp
  bool InDestructor; // bl
  unsigned int v4; // edi
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS3::VMAbcFile *,329,Scaleform::ArrayDefaultPolicy> *p_VMAbcFilesWeak; // edi

  Size = this->VMAbcFilesWeak.Data.Size;
  InDestructor = this->InDestructor;
  v4 = 0;
  for ( this->InDestructor = 1; v4 < Size; ++v4 )
    Scaleform::GFx::AS3::VMAbcFile::UnRegister(this->VMAbcFilesWeak.Data.Data[v4]);
  p_VMAbcFilesWeak = &this->VMAbcFilesWeak;
  if ( this->VMAbcFilesWeak.Data.Size )
  {
    if ( (this->VMAbcFilesWeak.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_VMAbcFilesWeak->Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_VMAbcFilesWeak->Data.Data);
        p_VMAbcFilesWeak->Data.Data = 0;
      }
      this->VMAbcFilesWeak.Data.Policy.Capacity = 0;
    }
    goto LABEL_8;
  }
  if ( this->VMAbcFilesWeak.Data.Policy.Capacity )
  {
LABEL_8:
    this->VMAbcFilesWeak.Data.Size = 0;
    this->InDestructor = InDestructor;
    return;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::VMAbcFile *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::VMAbcFile *,329>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->VMAbcFilesWeak.Data,
    &this->VMAbcFilesWeak,
    0);
  this->VMAbcFilesWeak.Data.Size = 0;
  this->InDestructor = InDestructor;
}
