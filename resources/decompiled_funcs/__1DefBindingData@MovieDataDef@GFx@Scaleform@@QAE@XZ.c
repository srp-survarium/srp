void __thiscall Scaleform::GFx::MovieDataDef::DefBindingData::~DefBindingData(
        Scaleform::GFx::MovieDataDef::DefBindingData *this)
{
  Scaleform::GFx::FrameBindData *volatile Value; // edi
  Scaleform::GFx::ImportData *volatile v3; // ebx
  volatile LONG *v4; // edi
  Scaleform::GFx::ResourceDataNode *volatile v5; // eax
  Scaleform::GFx::FontDataUseNode *volatile v6; // eax
  Scaleform::RefCountVImpl *pObject; // ecx

  Value = this->pFrameData.Value;
  InterlockedExchange((volatile LONG *)this, 0);
  for ( ; Value; Value = Value->pNextFrame.Value )
    ;
  while ( this->pImports.Value )
  {
    v3 = this->pImports.Value;
    this->pImports.Value = v3->pNext.Value;
    v4 = (volatile LONG *)(v3->SourceUrl.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
    Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::FrameLabelInfo>::DestructArray(
      (Scaleform::GFx::MovieDataDef::FrameLabelInfo *)v3->Imports.Data.Data,
      v3->Imports.Data.Size);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3->Imports.Data.Data);
  }
  while ( this->pResourceNodes.Value )
  {
    v5 = this->pResourceNodes.Value;
    this->pResourceNodes.Value = v5->pNext.Value;
    if ( v5->Data.pInterface )
      v5->Data.pInterface->Release(v5->Data.pInterface, v5->Data.hData);
  }
  while ( this->pFonts.Value )
  {
    v6 = this->pFonts.Value;
    this->pFonts.Value = v6->pNext.Value;
    pObject = (Scaleform::RefCountVImpl *)v6->pFontData.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
  }
}
