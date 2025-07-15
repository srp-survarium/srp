int __cdecl ppmd_allocator::GetUsedMemory(ppmd_allocator *this)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // esi
  int result; // eax
  unsigned int i; // edx

  v2 = v1 + 1;
  result = v1[120] + v1[122] + v1[124] - v1[125] - v1[123];
  for ( i = 0; i < 0x26; ++i )
  {
    result += -12 * *v2 * *((unsigned __int8 *)v1 + i + 308);
    v2 += 2;
  }
  return result;
}
