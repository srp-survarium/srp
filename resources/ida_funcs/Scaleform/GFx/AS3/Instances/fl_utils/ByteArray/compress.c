void __userpurge Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::compress(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this@<ecx>,
        int a2@<edi>,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int Length; // eax
  unsigned __int8 *v7; // edi
  unsigned int Position; // ecx
  char *v9; // eax
  unsigned int retaddr; // [esp+10h] [ebp+0h] BYREF

  Length = this->Length;
  if ( Length )
  {
    v7 = (unsigned __int8 *)((int (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *, unsigned int, _DWORD, int))Scaleform::Memory::pGlobalHeap->AllocAutoHeap)(
                              Scaleform::Memory::pGlobalHeap,
                              this,
                              ((3 * Length) >> 1) + 32,
                              0,
                              a2);
    compress2(v7, &retaddr, this->Data.Data.Data, this->Length, 9);
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, 0);
    Position = this->Position;
    v9 = (char *)(Position + retaddr);
    if ( Position + retaddr < this->Data.Data.Size )
    {
      if ( (unsigned int)v9 >= this->Length )
        this->Length = (unsigned int)v9;
    }
    else
    {
      Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, Position + retaddr);
    }
    memcpy(&this->Data.Data.Data[this->Position], v7, retaddr);
    this->Position += retaddr;
    ((void (__thiscall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->Free)(Scaleform::Memory::pGlobalHeap);
  }
}
