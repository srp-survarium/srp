int __cdecl sub_4810F0(int a1)
{
  int result; // eax

  sub_480EB0((_DWORD *)a1);
  sub_481050(a1);
  (**(void (__cdecl ***)(int))(a1 + 424))(a1);
  (**(void (__cdecl ***)(int))(a1 + 408))(a1);
  result = *(_DWORD *)(*(_DWORD *)(a1 + 408) + 4);
  **(_DWORD **)(a1 + 416) = result;
  return result;
}
