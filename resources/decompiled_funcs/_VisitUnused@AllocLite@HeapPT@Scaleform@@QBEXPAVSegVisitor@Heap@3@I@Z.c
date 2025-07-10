void __thiscall Scaleform::HeapPT::AllocLite::VisitUnused(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::Heap::SegVisitor *visitor,
        unsigned int cat)
{
  Scaleform::HeapPT::AllocLite::visitUnusedInTree(this, this->SizeTree.Tree.Root, visitor, cat);
}
