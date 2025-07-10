void __thiscall Scaleform::HeapPT::AllocLite::InitSegment(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::TreeSeg *seg)
{
  Scaleform::HeapPT::DualTNode *Buffer; // esi
  unsigned int v4; // ebx
  Scaleform::HeapPT::DualTNode *v5; // eax

  Buffer = (Scaleform::HeapPT::DualTNode *)seg->Buffer;
  v4 = seg->Size >> this->MinShift;
  Buffer->ParentSeg = seg;
  Buffer->Size = v4;
  Buffer->pPrev = Buffer;
  Buffer->pNext = Buffer;
  v5 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Insert(
         &this->SizeTree.Tree,
         Buffer);
  if ( v5 )
  {
    Buffer->pNext = v5->pNext;
    Buffer->pPrev = v5;
    v5->pNext = Buffer;
    Buffer->pNext->Scaleform::ListNode<Scaleform::HeapPT::DualTNode>::$FA7D61F44F114A80126F7766EA9000B1::pPrev = Buffer;
  }
  Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Insert(
    &this->AddrTree,
    Buffer);
  this->FreeBlocks += v4;
}
