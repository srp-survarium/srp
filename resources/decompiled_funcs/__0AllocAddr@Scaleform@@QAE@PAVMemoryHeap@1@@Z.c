void __thiscall Scaleform::AllocAddr::AllocAddr(Scaleform::AllocAddr *this, Scaleform::MemoryHeap *nodeHeap)
{
  this->pNodeHeap = nodeHeap;
  this->SizeTree.Tree.Root = 0;
  this->AddrTree.Root = 0;
}
