void __cdecl Scaleform::calcTreeSize(const Scaleform::AllocAddrNode *node, unsigned int *size)
{
  const Scaleform::AllocAddrNode *i; // esi

  for ( i = node; i; i = i->AddrChild[1] )
  {
    *size += i->Size;
    Scaleform::calcTreeSize(i->AddrChild[0], size);
  }
}
