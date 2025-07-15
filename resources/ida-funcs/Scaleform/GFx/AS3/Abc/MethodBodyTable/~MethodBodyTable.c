void __thiscall Scaleform::GFx::AS3::Abc::MethodBodyTable::~MethodBodyTable(
        Scaleform::GFx::AS3::Abc::MethodBodyTable *this)
{
  unsigned int Size; // ebp
  unsigned int i; // edi
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v4; // esi
  int *Data; // edx

  Size = this->Info.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    v4 = this->Info.Data.Data[i];
    if ( v4 )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4->exception.info.Data.Data);
      Data = v4->obj_traits.Data.Data;
      v4->code.__vftable = (Scaleform::GFx::AS3::Abc::Code_vtbl *)&Scaleform::GFx::AS3::Abc::Code::`vftable';
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Info.Data.Data);
}
