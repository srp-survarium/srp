int __cdecl jpeg_CreateDecompress(unsigned __int8 *dst, int a2, int a3)
{
  int v3; // ebx
  int v4; // ebp
  int result; // eax

  *((_DWORD *)dst + 1) = 0;
  if ( a2 != 80 )
  {
    *(_DWORD *)(*(_DWORD *)dst + 20) = 13;
    *(_DWORD *)(*(_DWORD *)dst + 24) = 80;
    *(_DWORD *)(*(_DWORD *)dst + 28) = a2;
    (**(void (__cdecl ***)(unsigned __int8 *))dst)(dst);
  }
  if ( a3 != 448 )
  {
    *(_DWORD *)(*(_DWORD *)dst + 20) = 22;
    *(_DWORD *)(*(_DWORD *)dst + 24) = 448;
    *(_DWORD *)(*(_DWORD *)dst + 28) = a3;
    (**(void (__cdecl ***)(unsigned __int8 *))dst)(dst);
  }
  v3 = *(_DWORD *)dst;
  v4 = *((_DWORD *)dst + 3);
  memset((int)dst, 0, 0x1C0u);
  *(_DWORD *)dst = v3;
  *((_DWORD *)dst + 3) = v4;
  dst[16] = 1;
  jinit_memory_mgr(dst);
  *((_DWORD *)dst + 2) = 0;
  *((_DWORD *)dst + 6) = 0;
  *((_DWORD *)dst + 36) = 0;
  *((_DWORD *)dst + 37) = 0;
  *((_DWORD *)dst + 38) = 0;
  *((_DWORD *)dst + 39) = 0;
  *((_DWORD *)dst + 40) = 0;
  *((_DWORD *)dst + 44) = 0;
  *((_DWORD *)dst + 41) = 0;
  *((_DWORD *)dst + 45) = 0;
  *((_DWORD *)dst + 42) = 0;
  *((_DWORD *)dst + 46) = 0;
  *((_DWORD *)dst + 43) = 0;
  *((_DWORD *)dst + 47) = 0;
  *((_DWORD *)dst + 67) = 0;
  jinit_marker_reader(dst);
  result = jinit_input_controller(dst);
  *((_DWORD *)dst + 5) = 200;
  return result;
}
