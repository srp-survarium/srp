unsigned __int8 *__thiscall Scaleform::HeapPT::AllocLite::Alloc(
        Scaleform::HeapPT::AllocLite *this,
        unsigned int size,
        unsigned int alignSize,
        Scaleform::HeapPT::TreeSeg **allocSeg)
{
  unsigned int v4; // edx
  unsigned int MinSize; // ecx
  unsigned int v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // ebx
  Scaleform::HeapPT::DualTNode *v10; // eax
  unsigned __int8 *v11; // edi
  unsigned int v12; // edx

  v4 = size;
  MinSize = this->MinSize;
  if ( size < MinSize )
    v4 = MinSize;
  v7 = alignSize;
  if ( alignSize < MinSize )
    v7 = MinSize;
  v8 = v7 - 1;
  v9 = ~(v7 - 1) & (v4 + v7 - 1);
  v10 = Scaleform::HeapPT::AllocLite::pullBest(this, v9 >> this->MinShift, v7 - 1);
  if ( !v10 )
    return 0;
  v11 = (unsigned __int8 *)(~v8 & ((unsigned int)v10 + v8));
  v12 = v11 - (unsigned __int8 *)v10;
  if ( v11 != (unsigned __int8 *)v10 )
  {
    do
    {
      if ( v12 >= 0x40 )
        break;
      v11 += v8 + 1;
      v12 += v8 + 1;
    }
    while ( v12 );
  }
  *allocSeg = v10->ParentSeg;
  Scaleform::HeapPT::AllocLite::splitNode(this, v10, v11, v9);
  return v11;
}
