void __userpurge btCompoundShape::removeChildShapeByIndex(
        btCompoundShape *this@<ecx>,
        int a2@<esi>,
        int childShapeIndex)
{
  int v3; // edi
  btDbvtNode *v4; // ebp
  void *v5; // eax

  ++*(_DWORD *)(a2 + 68);
  v3 = *(_DWORD *)(a2 + 64);
  if ( v3 )
  {
    v4 = *(btDbvtNode **)(80 * childShapeIndex + *(_DWORD *)(a2 + 24) + 76);
    removeleaf(v4, *(btDbvt **)(a2 + 64));
    v5 = *(void **)(v3 + 4);
    if ( v5 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v5);
    }
    --*(_DWORD *)(v3 + 12);
    *(_DWORD *)(v3 + 4) = v4;
  }
  btAlignedObjectArray<btCompoundShapeChild>::swap(
    childShapeIndex,
    *(_DWORD *)(a2 + 16) - 1,
    (btAlignedObjectArray<btCompoundShapeChild> *)(a2 + 12));
  if ( *(_DWORD *)(a2 + 64) )
    *(_DWORD *)(*(_DWORD *)(80 * childShapeIndex + *(_DWORD *)(a2 + 24) + 76) + 36) = childShapeIndex;
  --*(_DWORD *)(a2 + 16);
}
