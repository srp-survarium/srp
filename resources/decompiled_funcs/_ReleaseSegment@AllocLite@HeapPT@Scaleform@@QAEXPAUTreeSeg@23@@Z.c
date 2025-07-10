void __thiscall Scaleform::HeapPT::AllocLite::ReleaseSegment(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::TreeSeg *seg)
{
  Scaleform::HeapPT::DualTNode *Buffer; // esi
  Scaleform::HeapPT::DualTNode *pPrev; // eax
  Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *p_SizeTree; // ecx
  Scaleform::HeapPT::DualTNode *pNext; // edx
  Scaleform::HeapPT::DualTNode *v7; // [esp-4h] [ebp-Ch]

  Buffer = (Scaleform::HeapPT::DualTNode *)seg->Buffer;
  this->FreeBlocks -= Buffer->Size;
  pPrev = Buffer->pPrev;
  p_SizeTree = &this->SizeTree;
  if ( Buffer->pPrev == Buffer )
  {
    Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(&p_SizeTree->Tree, Buffer);
  }
  else
  {
    pNext = Buffer->pNext;
    v7 = Buffer->pPrev;
    pNext->pPrev = pPrev;
    pPrev->pNext = pNext;
    Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
      &p_SizeTree->Tree,
      Buffer,
      v7);
  }
  Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(&this->AddrTree, Buffer);
}
