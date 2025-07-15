int __cdecl sub_4890A0(int a1)
{
  int v1; // esi
  int result; // eax

  v1 = *(_DWORD *)(a1 + 440);
  *(_DWORD *)(a1 + 116) = *(_DWORD *)(v1 + 16);
  result = sub_488760(a1, *(_DWORD *)(v1 + 20));
  *(_BYTE *)(v1 + 28) = 1;
  return result;
}
