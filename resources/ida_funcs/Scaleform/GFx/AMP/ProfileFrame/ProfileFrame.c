void __thiscall Scaleform::GFx::AMP::ProfileFrame::ProfileFrame(Scaleform::GFx::AMP::ProfileFrame *this)
{
  Scaleform::StringLH *v2; // eax
  Scaleform::MemItem *v3; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::StringLH *v5; // eax
  Scaleform::MemItem *v6; // edi
  Scaleform::RefCountVImpl *v7; // ecx
  Scaleform::StringLH *v8; // eax
  Scaleform::MemItem *v9; // edi
  Scaleform::RefCountVImpl *v10; // ecx
  Scaleform::GFx::AMP::MovieFunctionStats *v11; // eax
  Scaleform::GFx::AMP::MovieFunctionStats *v12; // edi
  Scaleform::RefCountVImpl *v13; // ecx
  Scaleform::StringLH *v14; // eax
  Scaleform::GFx::AMP::MovieFunctionTreeStats *v15; // edi
  Scaleform::RefCountVImpl *v16; // ecx
  int v17; // [esp+20h] [ebp-14h] BYREF
  int v18; // [esp+24h] [ebp-10h] BYREF
  int v19; // [esp+28h] [ebp-Ch] BYREF
  int v20; // [esp+2Ch] [ebp-8h] BYREF
  int v21; // [esp+30h] [ebp-4h] BYREF

  this->__vftable = (Scaleform::GFx::AMP::ProfileFrame_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->__vftable = (Scaleform::GFx::AMP::ProfileFrame_vtbl *)&Scaleform::GFx::AMP::ProfileFrame::`vftable';
  this->TimeStamp = 0;
  this->FramesPerSecond = 0;
  this->ProfilingLevel = 0;
  this->DetailedMemReport = 0;
  this->AdvanceTime = 0;
  this->ActionTime = 0;
  this->TimelineTime = 0;
  this->InputTime = 0;
  this->MouseTime = 0;
  this->GcCollectTime = 0;
  this->GcMarkInCycleTime = 0;
  this->GcScanInUseTime = 0;
  this->GcFreeGarbageTime = 0;
  this->GcFinalizeTime = 0;
  this->GcDelayedCleanupTime = 0;
  this->GetVariableTime = 0;
  this->SetVariableTime = 0;
  this->InvokeTime = 0;
  this->DisplayTime = 0;
  this->PresentTime = 0;
  this->TesselationTime = 0;
  this->GradientGenTime = 0;
  this->UserTime = 0;
  this->LineCount = 0;
  this->MaskCount = 0;
  this->FilterCount = 0;
  this->MeshCount = 0;
  this->TriangleCount = 0;
  this->DrawPrimitiveCount = 0;
  this->StrokeCount = 0;
  this->GradientFillCount = 0;
  this->MeshThrashing = 0;
  this->RasterizedGlyphCount = 0;
  this->FontTextureCount = 0;
  this->NumFontCacheTextureUpdates = 0;
  this->FontThrashing = 0;
  this->FontFill = 0;
  this->FontFail = 0;
  this->FontMisses = 0;
  this->FontTotalArea = 0;
  this->FontUsedArea = 0;
  this->TotalMemory = 0;
  this->ImageMemory = 0;
  this->ImageGraphicsMemory = 0;
  this->MovieDataMemory = 0;
  this->MovieViewMemory = 0;
  this->MeshCacheMemory = 0;
  this->MeshCacheGraphicsMemory = 0;
  this->MeshCacheUnusedMemory = 0;
  this->MeshCacheGraphicsUnusedMemory = 0;
  this->FontCacheMemory = 0;
  this->VideoMemory = 0;
  this->SoundMemory = 0;
  this->OtherMemory = 0;
  this->GcRootsNumber = 0;
  this->GcFreedRootsNumber = 0;
  this->RefCount = 1;
  this->MovieStats.Data.Data = 0;
  this->MovieStats.Data.Size = 0;
  this->MovieStats.Data.Policy.Capacity = 0;
  this->DisplayStats.pObject = 0;
  this->DisplayFunctionStats.pObject = 0;
  this->SwdHandles.Data.Data = 0;
  this->SwdHandles.Data.Size = 0;
  this->SwdHandles.Data.Policy.Capacity = 0;
  this->FileHandles.Data.Data = 0;
  this->FileHandles.Data.Size = 0;
  this->FileHandles.Data.Policy.Capacity = 0;
  this->MemoryByStatId.pObject = 0;
  this->Images.pObject = 0;
  this->Fonts.pObject = 0;
  this->ImageList.Data.Data = 0;
  this->ImageList.Data.Size = 0;
  this->ImageList.Data.Policy.Capacity = 0;
  v17 = 2;
  v2 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                Scaleform::Memory::pGlobalHeap,
                                this,
                                40,
                                &v17);
  v3 = (Scaleform::MemItem *)v2;
  if ( v2 )
  {
    v2->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
    v2[1].HeapTypeBits = 1;
    v2->HeapTypeBits = (unsigned int)&Scaleform::MemItem::`vftable';
    Scaleform::StringLH::StringLH(v2 + 2);
    v3->Value = 0;
    v3->HasValue = 0;
    v3->StartExpanded = 0;
    v3->ID = 0;
    v3->ImageExtraData.pObject = 0;
    v3->Children.Data.Data = 0;
    v3->Children.Data.Size = 0;
    v3->Children.Data.Policy.Capacity = 0;
  }
  else
  {
    v3 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->MemoryByStatId.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->MemoryByStatId.pObject = v3;
  v18 = 2;
  v5 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                Scaleform::Memory::pGlobalHeap,
                                this,
                                40,
                                &v18);
  v6 = (Scaleform::MemItem *)v5;
  if ( v5 )
  {
    v5->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
    v5[1].HeapTypeBits = 1;
    v5->HeapTypeBits = (unsigned int)&Scaleform::MemItem::`vftable';
    Scaleform::StringLH::StringLH(v5 + 2);
    v6->Value = 0;
    v6->HasValue = 0;
    v6->StartExpanded = 0;
    v6->ID = 0;
    v6->ImageExtraData.pObject = 0;
    v6->Children.Data.Data = 0;
    v6->Children.Data.Size = 0;
    v6->Children.Data.Policy.Capacity = 0;
  }
  else
  {
    v6 = 0;
  }
  v7 = (Scaleform::RefCountVImpl *)this->Images.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  this->Images.pObject = v6;
  v19 = 2;
  v8 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                Scaleform::Memory::pGlobalHeap,
                                this,
                                40,
                                &v19);
  v9 = (Scaleform::MemItem *)v8;
  if ( v8 )
  {
    v8->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
    v8[1].HeapTypeBits = 1;
    v8->HeapTypeBits = (unsigned int)&Scaleform::MemItem::`vftable';
    Scaleform::StringLH::StringLH(v8 + 2);
    v9->Value = 0;
    v9->HasValue = 0;
    v9->StartExpanded = 0;
    v9->ID = 0;
    v9->ImageExtraData.pObject = 0;
    v9->Children.Data.Data = 0;
    v9->Children.Data.Size = 0;
    v9->Children.Data.Policy.Capacity = 0;
  }
  else
  {
    v9 = 0;
  }
  v10 = (Scaleform::RefCountVImpl *)this->Fonts.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  this->Fonts.pObject = v9;
  v20 = 578;
  v11 = (Scaleform::GFx::AMP::MovieFunctionStats *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this,
                                                     24,
                                                     &v20);
  if ( v11 )
  {
    v11->__vftable = (Scaleform::GFx::AMP::MovieFunctionStats_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v11->RefCount = 1;
    v11->__vftable = (Scaleform::GFx::AMP::MovieFunctionStats_vtbl *)&Scaleform::GFx::AMP::MovieFunctionStats::`vftable';
    v11->FunctionTimings.Data.Data = 0;
    v11->FunctionTimings.Data.Size = 0;
    v11->FunctionTimings.Data.Policy.Capacity = 0;
    v11->FunctionInfo.mHash.pTable = 0;
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  v13 = (Scaleform::RefCountVImpl *)this->DisplayStats.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  this->DisplayStats.pObject = v12;
  v21 = 2;
  v14 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                 Scaleform::Memory::pGlobalHeap,
                                 this,
                                 28,
                                 &v21);
  v15 = (Scaleform::GFx::AMP::MovieFunctionTreeStats *)v14;
  if ( v14 )
  {
    v14->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
    v14[1].HeapTypeBits = 1;
    v14->HeapTypeBits = (unsigned int)&Scaleform::GFx::AMP::MovieFunctionTreeStats::`vftable';
    Scaleform::StringLH::StringLH(v14 + 2);
    v15->FunctionRoots.Data.Data = 0;
    v15->FunctionRoots.Data.Size = 0;
    v15->FunctionRoots.Data.Policy.Capacity = 0;
    v15->FunctionInfo.mHash.pTable = 0;
  }
  else
  {
    v15 = 0;
  }
  v16 = (Scaleform::RefCountVImpl *)this->DisplayFunctionStats.pObject;
  if ( v16 )
    Scaleform::RefCountImpl::Release(v16);
  this->DisplayFunctionStats.pObject = v15;
}
