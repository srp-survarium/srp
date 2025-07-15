int __cdecl jpeg_CreateDecompress(int a1, int a2, int a3)
{
  int v3; // ebx
  int v4; // ebp
  int result; // eax

  *(_DWORD *)(a1 + 4) = 0;
  if ( a2 != 80 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 13;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = 80;
    *(_DWORD *)(*(_DWORD *)a1 + 28) = a2;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  if ( a3 != 448 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 22;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = 448;
    *(_DWORD *)(*(_DWORD *)a1 + 28) = a3;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v3 = *(_DWORD *)a1;
  v4 = *(_DWORD *)(a1 + 12);
  memset(a1, 0, 448);
  *(_DWORD *)a1 = v3;
  *(_DWORD *)(a1 + 12) = v4;
  *(_BYTE *)(a1 + 16) = 1;
  jinit_memory_mgr(a1);
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 144) = 0;
  *(_DWORD *)(a1 + 148) = 0;
  *(_DWORD *)(a1 + 152) = 0;
  *(_DWORD *)(a1 + 156) = 0;
  *(_DWORD *)(a1 + 160) = 0;
  *(_DWORD *)(a1 + 176) = 0;
  *(_DWORD *)(a1 + 164) = 0;
  *(_DWORD *)(a1 + 180) = 0;
  *(_DWORD *)(a1 + 168) = 0;
  *(_DWORD *)(a1 + 184) = 0;
  *(_DWORD *)(a1 + 172) = 0;
  *(_DWORD *)(a1 + 188) = 0;
  *(_DWORD *)(a1 + 268) = 0;
  jinit_marker_reader(a1);
  result = jinit_input_controller(a1);
  *(_DWORD *)(a1 + 20) = 200;
  return result;
}
