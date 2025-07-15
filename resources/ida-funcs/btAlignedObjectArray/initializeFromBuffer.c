void __userpurge btAlignedObjectArray<btOptimizedBvhNode>::initializeFromBuffer(
        btAlignedObjectArray<btOptimizedBvhNode> *this@<ecx>,
        int a2@<esi>,
        void *buffer,
        int size,
        int capacity)
{
  if ( *(_DWORD *)(a2 + 12) )
  {
    if ( *(_BYTE *)(a2 + 16) )
      btAlignedFreeInternal(*(void **)(a2 + 12));
    *(_DWORD *)(a2 + 12) = 0;
  }
  *(_DWORD *)(a2 + 12) = buffer;
  *(_DWORD *)(a2 + 4) = size;
  *(_BYTE *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 8) = capacity;
}
