Scaleform::Render::ContextImpl::Entry *__thiscall Scaleform::Render::ContextImpl::Context::createEntryHelper(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::EntryData *pdata)
{
  Scaleform::Render::ContextImpl::Entry *v4; // eax
  Scaleform::Render::ContextImpl::Entry *v5; // esi
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // eax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // ecx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // edx

  if ( !pdata )
    return 0;
  v4 = Scaleform::Render::ContextImpl::EntryTable::AllocEntry(&this->Table, pdata);
  v5 = v4;
  if ( v4 )
  {
    v4->pPrev = (Scaleform::Render::ContextImpl::Entry *)Scaleform::Render::ContextImpl::Snapshot::AddChangeItem(
                                                           this->pSnapshots[0],
                                                           v4,
                                                           0x80000000);
    p_PNode = &v5->PNode;
    v5->RefCount = 1;
    v5->pNative = pdata;
    v5->pRenderer = 0;
    v5->pParent = 0;
    v5->PNode.pNext = 0;
    v5->PNode.pPrev = 0;
    if ( !v5->PNode.pPrev )
    {
      v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned int)v5 & 0xFFFFF000) + 0xC);
      pPrev = v7[4].pPrev;
      v7 += 4;
      p_PNode->pPrev = pPrev;
      v5->PNode.pNext = v7;
      v7->pPrev->pNext = p_PNode;
      v7->pPrev = p_PNode;
    }
    return v5;
  }
  else
  {
    pdata->Destroy(pdata);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pdata);
    return 0;
  }
}
