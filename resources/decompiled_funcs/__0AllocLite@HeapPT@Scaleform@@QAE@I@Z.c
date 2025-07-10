void __thiscall Scaleform::HeapPT::AllocLite::AllocLite(Scaleform::HeapPT::AllocLite *this, unsigned int minSize)
{
  unsigned __int8 v3; // al
  unsigned int v4; // ecx
  unsigned int v5; // eax

  v3 = Scaleform::Alg::UpperBit(minSize);
  v4 = v3;
  v5 = 1 << v3;
  this->MinShift = v4;
  this->MinSize = v5;
  this->MinMask = v5 - 1;
  this->SizeTree.Tree.Root = 0;
  this->AddrTree.Root = 0;
  this->FreeBlocks = 0;
}
