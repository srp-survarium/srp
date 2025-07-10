unsigned int __cdecl ppmd_allocator::GetUsedMemory(ppmd_allocator *this)
{
  _DWORD *v1; // ecx
  int v2; // eax
  int v3; // edi
  unsigned __int8 *v4; // edx
  _DWORD *v5; // esi
  int v6; // ebx
  int v7; // ecx

  v2 = v1[120] + v1[122] + v1[124] - v1[125] - v1[123];
  v3 = 0;
  v4 = (unsigned __int8 *)v1 + 309;
  v5 = v1 + 3;
  v6 = 19;
  do
  {
    v7 = *v5 * *v4;
    v2 -= 12 * *(v5 - 2) * *(v4 - 1);
    v4 += 2;
    v5 += 4;
    --v6;
    v3 -= 12 * v7;
  }
  while ( v6 );
  return v3 + v2;
}
