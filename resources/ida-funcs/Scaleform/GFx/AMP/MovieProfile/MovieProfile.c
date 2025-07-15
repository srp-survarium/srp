void __thiscall Scaleform::GFx::AMP::MovieProfile::MovieProfile(Scaleform::GFx::AMP::MovieProfile *this)
{
  Scaleform::GFx::AMP::MovieInstructionStats *v2; // eax
  Scaleform::GFx::AMP::MovieInstructionStats *v3; // ebx
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::AMP::MovieFunctionStats *v5; // eax
  Scaleform::GFx::AMP::MovieFunctionStats *v6; // ebx
  Scaleform::RefCountVImpl *v7; // ecx
  Scaleform::GFx::AMP::MovieSourceLineStats *v8; // eax
  Scaleform::GFx::AMP::MovieSourceLineStats *v9; // ebx
  Scaleform::RefCountVImpl *v10; // ecx
  Scaleform::StringLH *v11; // eax
  Scaleform::GFx::AMP::MovieFunctionTreeStats *v12; // ebx
  Scaleform::RefCountVImpl *v13; // ecx
  int v14; // [esp+18h] [ebp-10h] BYREF
  int v15; // [esp+1Ch] [ebp-Ch] BYREF
  int v16; // [esp+20h] [ebp-8h] BYREF
  int v17; // [esp+24h] [ebp-4h] BYREF

  this->__vftable = (Scaleform::GFx::AMP::MovieProfile_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::MovieProfile_vtbl *)&Scaleform::GFx::AMP::MovieProfile::`vftable';
  this->ViewHandle = 0;
  this->MinFrame = 0;
  this->MaxFrame = 0;
  Scaleform::StringLH::StringLH(&this->ViewName);
  this->Markers.Data.Data = 0;
  this->Markers.Data.Size = 0;
  this->Markers.Data.Policy.Capacity = 0;
  this->InstructionStats.pObject = 0;
  this->FunctionStats.pObject = 0;
  this->SourceLineStats.pObject = 0;
  this->FunctionTreeStats.pObject = 0;
  v14 = 578;
  v2 = (Scaleform::GFx::AMP::MovieInstructionStats *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       this,
                                                       20,
                                                       &v14);
  if ( v2 )
  {
    v2->__vftable = (Scaleform::GFx::AMP::MovieInstructionStats_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v2->RefCount = 1;
    v2->__vftable = (Scaleform::GFx::AMP::MovieInstructionStats_vtbl *)&Scaleform::GFx::AMP::MovieInstructionStats::`vftable';
    v2->BufferStatsArray.Data.Data = 0;
    v2->BufferStatsArray.Data.Size = 0;
    v2->BufferStatsArray.Data.Policy.Capacity = 0;
    v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->InstructionStats.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->InstructionStats.pObject = v3;
  v15 = 578;
  v5 = (Scaleform::GFx::AMP::MovieFunctionStats *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    24,
                                                    &v15);
  if ( v5 )
  {
    v5->__vftable = (Scaleform::GFx::AMP::MovieFunctionStats_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v5->RefCount = 1;
    v5->__vftable = (Scaleform::GFx::AMP::MovieFunctionStats_vtbl *)&Scaleform::GFx::AMP::MovieFunctionStats::`vftable';
    v5->FunctionTimings.Data.Data = 0;
    v5->FunctionTimings.Data.Size = 0;
    v5->FunctionTimings.Data.Policy.Capacity = 0;
    v5->FunctionInfo.mHash.pTable = 0;
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = (Scaleform::RefCountVImpl *)this->FunctionStats.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  this->FunctionStats.pObject = v6;
  v16 = 578;
  v8 = (Scaleform::GFx::AMP::MovieSourceLineStats *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      this,
                                                      24,
                                                      &v16);
  if ( v8 )
  {
    v8->__vftable = (Scaleform::GFx::AMP::MovieSourceLineStats_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v8->RefCount = 1;
    v8->__vftable = (Scaleform::GFx::AMP::MovieSourceLineStats_vtbl *)&Scaleform::GFx::AMP::MovieSourceLineStats::`vftable';
    v8->SourceLineTimings.Data.Data = 0;
    v8->SourceLineTimings.Data.Size = 0;
    v8->SourceLineTimings.Data.Policy.Capacity = 0;
    v8->SourceFileInfo.mHash.pTable = 0;
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  v10 = (Scaleform::RefCountVImpl *)this->SourceLineStats.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  this->SourceLineStats.pObject = v9;
  v17 = 2;
  v11 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                 Scaleform::Memory::pGlobalHeap,
                                 this,
                                 28,
                                 &v17);
  v12 = (Scaleform::GFx::AMP::MovieFunctionTreeStats *)v11;
  if ( v11 )
  {
    v11->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
    v11[1].HeapTypeBits = 1;
    v11->HeapTypeBits = (unsigned int)&Scaleform::GFx::AMP::MovieFunctionTreeStats::`vftable';
    Scaleform::StringLH::StringLH(v11 + 2);
    v12->FunctionRoots.Data.Data = 0;
    v12->FunctionRoots.Data.Size = 0;
    v12->FunctionRoots.Data.Policy.Capacity = 0;
    v12->FunctionInfo.mHash.pTable = 0;
  }
  else
  {
    v12 = 0;
  }
  v13 = (Scaleform::RefCountVImpl *)this->FunctionTreeStats.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  this->FunctionTreeStats.pObject = v12;
}
