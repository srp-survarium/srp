void __usercall btSoftBody::solveClusters(btSoftBody *this@<ecx>, int a2@<edi>)
{
  int v2; // ebx
  int i; // esi
  int v4; // ecx

  v2 = *(_DWORD *)(a2 + 860);
  for ( i = 0; i < v2; ++i )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(a2 + 868) + 4 * i);
    (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v4 + 8))(v4, *(float *)(a2 + 460), 1.0);
  }
}
