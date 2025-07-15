unsigned int __thiscall Scaleform::AllocAddr::Alloc(Scaleform::AllocAddr *this, unsigned int size)
{
  Scaleform::AllocAddrNode *v3; // eax
  unsigned int Addr; // esi

  v3 = Scaleform::AllocAddr::pullBest(this, size);
  if ( !v3 )
    return -1;
  Addr = v3->Addr;
  Scaleform::AllocAddr::splitNode(this, v3, Addr, size);
  return Addr;
}
