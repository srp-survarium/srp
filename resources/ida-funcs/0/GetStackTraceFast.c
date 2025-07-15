void __cdecl GetStackTraceFast(char *ranOffsets)
{
  unsigned int v1; // esi
  unsigned __int16 v2; // ax
  signed int v3; // edi
  char *v4; // ecx
  __int64 v5; // rax
  char *v6; // eax
  void *v7[513]; // [esp+Ch] [ebp-804h] BYREF

  v1 = 0;
  v2 = s_pfnCaptureStackBackTrace(3u, 0x200u, v7, 0);
  v3 = v2;
  if ( !v2 )
    goto LABEL_5;
  v4 = ranOffsets;
  do
  {
    v5 = (int)v7[v1];
    *(_QWORD *)v4 = v5;
    *((_QWORD *)v4 + 1) = v5;
    ++v1;
    v4 += 16;
  }
  while ( (int)v1 < v3 );
  if ( v1 <= 0x200 )
  {
LABEL_5:
    v6 = &ranOffsets[16 * v1];
    *(_DWORD *)v6 = 0;
    *((_DWORD *)v6 + 1) = 0;
    *((_DWORD *)v6 + 2) = 0;
    *((_DWORD *)v6 + 3) = 0;
  }
}
