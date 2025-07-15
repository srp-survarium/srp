int __cdecl jinit_input_controller(int a1)
{
  int result; // eax

  result = (**(int (__cdecl ***)(int, _DWORD, int))(a1 + 4))(a1, 0, 24);
  *(_DWORD *)(a1 + 416) = result;
  *(_DWORD *)result = sub_481130;
  *(_DWORD *)(result + 4) = sub_481220;
  *(_DWORD *)(result + 8) = sub_4810F0;
  *(_DWORD *)(result + 12) = sub_481270;
  *(_BYTE *)(result + 16) = 0;
  *(_BYTE *)(result + 17) = 0;
  *(_DWORD *)(result + 20) = 1;
  return result;
}
