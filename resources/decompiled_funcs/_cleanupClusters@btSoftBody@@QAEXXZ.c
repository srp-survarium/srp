void __usercall btSoftBody::cleanupClusters(btSoftBody *this@<ecx>, int a2@<esi>)
{
  int i; // ebx
  btAlignedObjectArray<btSoftBody *> *v3; // ecx
  _BYTE *v4; // eax

  for ( i = 0; i < *(_DWORD *)(a2 + 860); ++i )
  {
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(4 * i + *(_DWORD *)(a2 + 868)) + 12))(*(float *)(a2 + 460));
    v3 = *(btAlignedObjectArray<btSoftBody *> **)(a2 + 868);
    v4 = (_BYTE *)*((_DWORD *)&v3->m_allocator + i);
    if ( v4[176] )
    {
      if ( v4 )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(v4);
      }
      btAlignedObjectArray<btSoftBody::Joint *>::remove(
        v3,
        a2 + 856,
        (btSoftBody *const *)(4 * i-- + *(_DWORD *)(a2 + 868)));
    }
  }
}
