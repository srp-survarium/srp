void __thiscall Scaleform::GFx::AS3::Abc::TraitTable::~TraitTable(Scaleform::GFx::AS3::Abc::TraitTable *this)
{
  unsigned int i; // edi
  Scaleform::GFx::AS3::Abc::TraitInfo *v3; // esi

  for ( i = 0; i < this->TraitInfos.Data.Size; ++i )
  {
    v3 = this->TraitInfos.Data.Data[i];
    if ( v3 )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3->meta_info.info.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
    }
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->TraitInfos.Data.Data);
}
