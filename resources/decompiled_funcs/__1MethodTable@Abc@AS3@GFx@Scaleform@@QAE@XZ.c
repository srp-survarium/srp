void __thiscall Scaleform::GFx::AS3::Abc::MethodTable::~MethodTable(Scaleform::GFx::AS3::Abc::MethodTable *this)
{
  unsigned int i; // edi
  Scaleform::GFx::AS3::Abc::MethodInfo *v3; // esi

  for ( i = 0; i < this->Info.Data.Size; ++i )
  {
    v3 = this->Info.Data.Data[i];
    if ( v3 )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3->ParamNames.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3->OptionalParams.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3->ParamTypes.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
    }
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Info.Data.Data);
}
