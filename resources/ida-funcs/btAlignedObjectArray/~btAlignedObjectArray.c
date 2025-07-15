void __usercall btAlignedObjectArray<btFace>::~btAlignedObjectArray<btFace>(
        btAlignedObjectArray<btFace> *this@<ecx>,
        int a2@<edi>)
{
  int v2; // ebp
  int v3; // ebx

  if ( *(int *)(a2 + 4) > 0 )
  {
    v2 = 0;
    v3 = *(_DWORD *)(a2 + 4);
    do
    {
      btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
        (btAlignedObjectArray<GrahamVector2> *)this,
        v2 + *(_DWORD *)(a2 + 12));
      v2 += 36;
      --v3;
    }
    while ( v3 );
  }
  if ( *(_DWORD *)(a2 + 12) )
  {
    if ( *(_BYTE *)(a2 + 16) )
      btAlignedFreeInternal(*(void **)(a2 + 12));
    *(_DWORD *)(a2 + 12) = 0;
  }
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 16) = 1;
}


void __usercall btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
        btAlignedObjectArray<GrahamVector2> *this@<ecx>,
        int a2@<esi>)
{
  if ( *(_DWORD *)(a2 + 12) )
  {
    if ( *(_BYTE *)(a2 + 16) )
      btAlignedFreeInternal(*(void **)(a2 + 12));
    *(_DWORD *)(a2 + 12) = 0;
  }
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 16) = 1;
}
