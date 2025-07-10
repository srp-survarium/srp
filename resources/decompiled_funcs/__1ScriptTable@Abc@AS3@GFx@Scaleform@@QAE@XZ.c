void __thiscall Scaleform::GFx::AS3::Abc::ScriptTable::~ScriptTable(Scaleform::GFx::AS3::Abc::ScriptTable *this)
{
  unsigned int i; // edi
  Scaleform::GFx::AS3::Abc::ScriptInfo *v3; // esi

  for ( i = 0; i < this->Info.Data.Size; ++i )
  {
    v3 = this->Info.Data.Data[i];
    if ( v3 )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3->obj_traits.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
    }
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Info.Data.Data);
}
