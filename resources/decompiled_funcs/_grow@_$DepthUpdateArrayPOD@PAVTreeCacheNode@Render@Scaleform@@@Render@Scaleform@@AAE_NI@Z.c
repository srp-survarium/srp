char __thiscall Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(
        Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *this,
        unsigned int depth)
{
  unsigned int v3; // edi
  unsigned __int8 *v4; // eax
  Scaleform::Render::TreeCacheNode **v5; // ebx
  unsigned int v6; // edi
  unsigned int i; // eax
  int v8; // ecx

  v3 = (depth + 31) & 0xFFFFFFE0;
  v4 = (unsigned __int8 *)this->pHeap->Alloc(this->pHeap, 4 * v3, 0);
  v5 = (Scaleform::Render::TreeCacheNode **)v4;
  if ( !v4 )
    return 0;
  memcpy(v4, (unsigned __int8 *)this->pDepth, 4 * this->DepthUsed);
  v6 = v3 - this->DepthUsed;
  for ( i = 0; i < v6; v5[v8] = this->NullValue )
  {
    v8 = i + this->DepthUsed;
    ++i;
  }
  if ( this->pDepth != this->ArrayReserve )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pDepth);
  this->pDepth = v5;
  this->DepthAvailable = depth;
  return 1;
}
