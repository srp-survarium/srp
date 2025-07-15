void __userpurge btSoftBody::prepareClusters(btSoftBody *this@<ecx>, int a2@<edi>, int iterations)
{
  int i; // esi

  for ( i = 0; i < *(_DWORD *)(a2 + 860); ++i )
    (*(void (__stdcall **)(_DWORD, int))(**(_DWORD **)(*(_DWORD *)(a2 + 868) + 4 * i) + 4))(
      *(float *)(a2 + 460),
      iterations);
}
