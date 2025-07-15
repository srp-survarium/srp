void __thiscall Scaleform::GFx::TextFieldDef::~TextFieldDef(Scaleform::GFx::TextFieldDef *this)
{
  volatile LONG *v2; // edi
  volatile LONG *v3; // edi
  volatile LONG *v4; // edi
  Scaleform::GFx::Resource *pResource; // ecx

  v2 = (volatile LONG *)(this->VariableName.HeapTypeBits & 0xFFFFFFFC);
  this->__vftable = (Scaleform::GFx::TextFieldDef_vtbl *)&Scaleform::GFx::TextFieldDef::`vftable';
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  v3 = (volatile LONG *)(this->DefaultText.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  v4 = (volatile LONG *)(this->FontClass.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  if ( this->pFont.HType == RH_Pointer )
  {
    pResource = this->pFont.pResource;
    if ( pResource )
      Scaleform::GFx::Resource::Release(pResource);
  }
  this->__vftable = (Scaleform::GFx::TextFieldDef_vtbl *)&Scaleform::GFx::Resource::`vftable';
}
