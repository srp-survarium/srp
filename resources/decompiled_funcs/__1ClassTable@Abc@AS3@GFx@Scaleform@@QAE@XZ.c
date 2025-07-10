void __thiscall Scaleform::GFx::AS3::Abc::ClassTable::~ClassTable(Scaleform::GFx::AS3::Abc::ClassTable *this)
{
  unsigned int i; // edi
  Scaleform::GFx::AS3::Abc::ClassInfo *v3; // esi

  for ( i = 0; i < this->Info.Data.Size; ++i )
  {
    v3 = this->Info.Data.Data[i];
    if ( v3 )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3->stat_info.obj_traits.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(
        Scaleform::Memory::pGlobalHeap,
        v3->inst_info.implemented_interfaces.info.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3->inst_info.obj_traits.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
    }
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Info.Data.Data);
}
