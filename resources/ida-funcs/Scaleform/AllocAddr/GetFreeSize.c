unsigned int __thiscall Scaleform::AllocAddr::GetFreeSize(Scaleform::AllocAddr *this)
{
  Scaleform::AllocAddrNode *Root; // edx
  unsigned int result; // eax
  int v3; // edx
  unsigned int size; // [esp+0h] [ebp-4h] BYREF

  size = (unsigned int)this;
  Root = this->AddrTree.Root;
  result = 0;
  size = 0;
  if ( Root )
  {
    size = Root->Size;
    Scaleform::calcTreeSize(Root->AddrChild[0], &size);
    Scaleform::calcTreeSize(*(const Scaleform::AllocAddrNode **)(v3 + 16), &size);
    return size;
  }
  return result;
}
