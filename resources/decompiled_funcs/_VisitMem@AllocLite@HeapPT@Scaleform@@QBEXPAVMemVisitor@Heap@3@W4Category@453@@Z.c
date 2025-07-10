void __thiscall Scaleform::HeapPT::AllocLite::VisitMem(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::Heap::MemVisitor *visitor,
        Scaleform::Heap::MemVisitor::Category cat)
{
  Scaleform::Heap::HeapSegment seg; // [esp+0h] [ebp-20h] BYREF

  seg.SegType = 16;
  seg.SelfSize = 0;
  memset(&seg.Alignment, 0, 18);
  Scaleform::HeapPT::AllocLite::visitTree(this, this->SizeTree.Tree.Root, &seg, visitor, cat);
}
