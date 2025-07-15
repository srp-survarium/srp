void __thiscall Scaleform::StatsUpdate::HeapTreeCreator::Visit(
        Scaleform::StatsUpdate::HeapTreeCreator *this,
        Scaleform::MemItem *parent,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v3; // edi
  Scaleform::MemItem *pObject; // ecx
  unsigned int *NextHandle; // eax
  unsigned int v7; // ebx
  const __m128i *pName; // ebp
  unsigned int v9; // eax
  Scaleform::GFx::Resource *v10; // ebx
  unsigned int *v11; // eax
  unsigned int v12; // ebp
  Scaleform::MemoryHeap_vtbl *v13; // eax
  int v14; // eax
  Scaleform::MemItem *v15; // ecx
  Scaleform::MemItem *v16; // ebp
  int v17; // eax
  Scaleform::MemItem *v18; // eax
  Scaleform::MemItem *CurrentUsedSpaceParent; // ebp

  v3 = heap;
  if ( (heap->Info.Desc.Flags & 0x1000) == 0 )
  {
    if ( !parent )
    {
      pObject = this->UnusedSpaceRoot.pObject;
      this->CurrentUsedSpaceParent = this->UsedSpaceRoot.pObject;
      this->CurrentUnusedSpaceParent = pObject;
      v3->GetRootStats(v3, &this->RootHeapStats);
    }
    NextHandle = this->NextHandle;
    v7 = (*NextHandle)++;
    pName = (const __m128i *)v3->Info.pName;
    v9 = v3->GetUsedSpace(v3);
    v10 = (Scaleform::GFx::Resource *)Scaleform::MemItem::AddChild(this->CurrentUsedSpaceParent, v7, pName, v9);
    v11 = this->NextHandle;
    v12 = (*v11)++;
    v13 = v3->__vftable;
    heap = (Scaleform::MemoryHeap *)v3->Info.pName;
    v14 = v13->GetFootprint(v3);
    heap = (Scaleform::MemoryHeap *)Scaleform::MemItem::AddChild(
                                      this->CurrentUnusedSpaceParent,
                                      v12,
                                      (const __m128i *)heap,
                                      v14 - (unsigned int)v10[1].__vftable);
    switch ( v3->Info.Desc.HeapId )
    {
      case 1u:
        v16 = this->GlobalHeap.pObject;
        v17 = v3->GetUsedSpace(v3);
        Scaleform::MemItem::SetValue(v16, v16->Value + v17);
        goto LABEL_13;
      case 3u:
        Scaleform::RefCountImpl::AddRef(v10);
        v15 = this->MovieViewRoot.pObject;
        goto LABEL_12;
      case 4u:
        Scaleform::RefCountImpl::AddRef(v10);
        v15 = this->MovieDataRoot.pObject;
        goto LABEL_12;
      case 8u:
        Scaleform::RefCountImpl::AddRef(v10);
        v15 = this->VideoRoot.pObject;
        goto LABEL_12;
      default:
        if ( !parent || parent[1].Value != 1 )
          goto LABEL_13;
        Scaleform::RefCountImpl::AddRef(v10);
        v15 = this->OtherRoot.pObject;
LABEL_12:
        parent = (Scaleform::MemItem *)v10;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,2>,Scaleform::ArrayDefaultPolicy> > *)&v15->Children,
          (const Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem> *)&parent);
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
LABEL_13:
        v18 = (Scaleform::MemItem *)heap;
        CurrentUsedSpaceParent = this->CurrentUsedSpaceParent;
        parent = this->CurrentUnusedSpaceParent;
        this->CurrentUsedSpaceParent = (Scaleform::MemItem *)v10;
        this->CurrentUnusedSpaceParent = v18;
        Scaleform::MemoryHeap::VisitChildHeaps(v3, this);
        this->CurrentUnusedSpaceParent = parent;
        this->CurrentUsedSpaceParent = CurrentUsedSpaceParent;
        Scaleform::MemItem::SetValue(
          CurrentUsedSpaceParent,
          (unsigned int)v10[1].__vftable + CurrentUsedSpaceParent->Value);
        Scaleform::MemItem::SetValue(
          this->CurrentUnusedSpaceParent,
          heap->SelfSize + this->CurrentUnusedSpaceParent->Value);
        break;
    }
  }
}
