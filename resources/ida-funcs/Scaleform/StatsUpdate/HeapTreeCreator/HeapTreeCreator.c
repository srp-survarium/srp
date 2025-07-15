void __thiscall Scaleform::StatsUpdate::HeapTreeCreator::HeapTreeCreator(
        Scaleform::StatsUpdate::HeapTreeCreator *this,
        Scaleform::MemoryHeap *debugHeap,
        Scaleform::StatsUpdate *memReporter,
        unsigned int *nextHandle)
{
  Scaleform::MemItem *v5; // edi
  unsigned int *v6; // eax
  unsigned int v7; // ebp
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::MemItem *v9; // edi
  unsigned int *v10; // eax
  unsigned int v11; // ebp
  Scaleform::RefCountVImpl *v12; // ecx
  Scaleform::MemItem *v13; // edi
  unsigned int *v14; // eax
  unsigned int v15; // ebp
  Scaleform::RefCountVImpl *v16; // ecx
  Scaleform::MemItem *v17; // edi
  unsigned int *v18; // eax
  unsigned int v19; // ebp
  Scaleform::RefCountVImpl *v20; // ecx
  Scaleform::MemItem *v21; // edi
  unsigned int *v22; // eax
  unsigned int v23; // ebp
  Scaleform::RefCountVImpl *v24; // ecx
  Scaleform::MemItem *v25; // edi
  unsigned int *v26; // eax
  unsigned int v27; // ebp
  Scaleform::RefCountVImpl *v28; // ecx
  Scaleform::MemItem *v29; // edi
  unsigned int *v30; // eax
  unsigned int v31; // ebp
  Scaleform::RefCountVImpl *v32; // ecx

  this->__vftable = (Scaleform::StatsUpdate::HeapTreeCreator_vtbl *)&Scaleform::StatsUpdate::HeapTreeCreator::`vftable';
  this->UsedSpaceRoot.pObject = 0;
  this->GlobalHeap.pObject = 0;
  this->MovieViewRoot.pObject = 0;
  this->MovieDataRoot.pObject = 0;
  this->VideoRoot.pObject = 0;
  this->OtherRoot.pObject = 0;
  this->UnusedSpaceRoot.pObject = 0;
  this->NextHandle = nextHandle;
  this->CurrentUsedSpaceParent = 0;
  this->CurrentUnusedSpaceParent = 0;
  this->DebugHeap = debugHeap;
  this->MemReporter = memReporter;
  v5 = (Scaleform::MemItem *)debugHeap->Alloc(debugHeap, 40, 0);
  if ( v5 )
  {
    v6 = this->NextHandle;
    v7 = (*v6)++;
    v5->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v5->RefCount = 1;
    v5->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::MemItem::`vftable';
    Scaleform::StringLH::StringLH(&v5->Name);
    v5->Value = 0;
    v5->HasValue = 0;
    v5->StartExpanded = 0;
    v5->ID = v7;
    v5->ImageExtraData.pObject = 0;
    v5->Children.Data.Data = 0;
    v5->Children.Data.Size = 0;
    v5->Children.Data.Policy.Capacity = 0;
  }
  else
  {
    v5 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->UsedSpaceRoot.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->UsedSpaceRoot.pObject = v5;
  v9 = (Scaleform::MemItem *)this->DebugHeap->Alloc(this->DebugHeap, 40, 0);
  if ( v9 )
  {
    v10 = this->NextHandle;
    v11 = (*v10)++;
    v9->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v9->RefCount = 1;
    v9->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::MemItem::`vftable';
    Scaleform::StringLH::StringLH(&v9->Name);
    v9->Value = 0;
    v9->HasValue = 0;
    v9->StartExpanded = 0;
    v9->ID = v11;
    v9->ImageExtraData.pObject = 0;
    v9->Children.Data.Data = 0;
    v9->Children.Data.Size = 0;
    v9->Children.Data.Policy.Capacity = 0;
  }
  else
  {
    v9 = 0;
  }
  v12 = (Scaleform::RefCountVImpl *)this->GlobalHeap.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  this->GlobalHeap.pObject = v9;
  Scaleform::String::operator=(&v9->Name, (const __m128i *)"Global Heap");
  v13 = (Scaleform::MemItem *)this->DebugHeap->Alloc(this->DebugHeap, 40, 0);
  if ( v13 )
  {
    v14 = this->NextHandle;
    v15 = (*v14)++;
    v13->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v13->RefCount = 1;
    v13->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::MemItem::`vftable';
    Scaleform::StringLH::StringLH(&v13->Name);
    v13->Value = 0;
    v13->HasValue = 0;
    v13->StartExpanded = 0;
    v13->ID = v15;
    v13->ImageExtraData.pObject = 0;
    v13->Children.Data.Data = 0;
    v13->Children.Data.Size = 0;
    v13->Children.Data.Policy.Capacity = 0;
  }
  else
  {
    v13 = 0;
  }
  v16 = (Scaleform::RefCountVImpl *)this->MovieViewRoot.pObject;
  if ( v16 )
    Scaleform::RefCountImpl::Release(v16);
  this->MovieViewRoot.pObject = v13;
  Scaleform::String::operator=(&v13->Name, (const __m128i *)"Movie View Heaps");
  v17 = (Scaleform::MemItem *)this->DebugHeap->Alloc(this->DebugHeap, 40, 0);
  if ( v17 )
  {
    v18 = this->NextHandle;
    v19 = (*v18)++;
    v17->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v17->RefCount = 1;
    v17->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::MemItem::`vftable';
    Scaleform::StringLH::StringLH(&v17->Name);
    v17->Value = 0;
    v17->HasValue = 0;
    v17->StartExpanded = 0;
    v17->ID = v19;
    v17->ImageExtraData.pObject = 0;
    v17->Children.Data.Data = 0;
    v17->Children.Data.Size = 0;
    v17->Children.Data.Policy.Capacity = 0;
  }
  else
  {
    v17 = 0;
  }
  v20 = (Scaleform::RefCountVImpl *)this->MovieDataRoot.pObject;
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  this->MovieDataRoot.pObject = v17;
  Scaleform::String::operator=(&v17->Name, (const __m128i *)"Movie Data Heaps");
  v21 = (Scaleform::MemItem *)this->DebugHeap->Alloc(this->DebugHeap, 40, 0);
  if ( v21 )
  {
    v22 = this->NextHandle;
    v23 = (*v22)++;
    v21->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v21->RefCount = 1;
    v21->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::MemItem::`vftable';
    Scaleform::StringLH::StringLH(&v21->Name);
    v21->Value = 0;
    v21->HasValue = 0;
    v21->StartExpanded = 0;
    v21->ID = v23;
    v21->ImageExtraData.pObject = 0;
    v21->Children.Data.Data = 0;
    v21->Children.Data.Size = 0;
    v21->Children.Data.Policy.Capacity = 0;
  }
  else
  {
    v21 = 0;
  }
  v24 = (Scaleform::RefCountVImpl *)this->VideoRoot.pObject;
  if ( v24 )
    Scaleform::RefCountImpl::Release(v24);
  this->VideoRoot.pObject = v21;
  Scaleform::String::operator=(&v21->Name, (const __m128i *)"Video Heaps");
  v25 = (Scaleform::MemItem *)this->DebugHeap->Alloc(this->DebugHeap, 40, 0);
  if ( v25 )
  {
    v26 = this->NextHandle;
    v27 = (*v26)++;
    v25->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v25->RefCount = 1;
    v25->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::MemItem::`vftable';
    Scaleform::StringLH::StringLH(&v25->Name);
    v25->Value = 0;
    v25->HasValue = 0;
    v25->StartExpanded = 0;
    v25->ID = v27;
    v25->ImageExtraData.pObject = 0;
    v25->Children.Data.Data = 0;
    v25->Children.Data.Size = 0;
    v25->Children.Data.Policy.Capacity = 0;
  }
  else
  {
    v25 = 0;
  }
  v28 = (Scaleform::RefCountVImpl *)this->OtherRoot.pObject;
  if ( v28 )
    Scaleform::RefCountImpl::Release(v28);
  this->OtherRoot.pObject = v25;
  Scaleform::String::operator=(&v25->Name, (const __m128i *)"Other Heaps");
  v29 = (Scaleform::MemItem *)this->DebugHeap->Alloc(this->DebugHeap, 40, 0);
  if ( v29 )
  {
    v30 = this->NextHandle;
    v31 = (*v30)++;
    v29->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v29->RefCount = 1;
    v29->__vftable = (Scaleform::MemItem_vtbl *)&Scaleform::MemItem::`vftable';
    Scaleform::StringLH::StringLH(&v29->Name);
    v29->Value = 0;
    v29->HasValue = 0;
    v29->StartExpanded = 0;
    v29->ID = v31;
    v29->ImageExtraData.pObject = 0;
    v29->Children.Data.Data = 0;
    v29->Children.Data.Size = 0;
    v29->Children.Data.Policy.Capacity = 0;
  }
  else
  {
    v29 = 0;
  }
  v32 = (Scaleform::RefCountVImpl *)this->UnusedSpaceRoot.pObject;
  if ( v32 )
    Scaleform::RefCountImpl::Release(v32);
  this->UnusedSpaceRoot.pObject = v29;
  Scaleform::String::operator=(&v29->Name, (const __m128i *)"Unused Space");
}
