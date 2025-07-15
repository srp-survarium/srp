void __thiscall Scaleform::GFx::AS3::Abc::MetadataTable::~MetadataTable(Scaleform::GFx::AS3::Abc::MetadataTable *this)
{
  unsigned int i; // edi
  Scaleform::GFx::AS3::Abc::MetadataInfo *v3; // esi

  for ( i = 0; i < this->Info.Data.Size; ++i )
  {
    v3 = this->Info.Data.Data[i];
    if ( v3 )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3->Items.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
    }
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Info.Data.Data);
}
