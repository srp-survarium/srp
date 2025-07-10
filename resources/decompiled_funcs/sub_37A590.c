int __usercall sub_37A590@<eax>(int a1@<eax>)
{
  _DWORD *v2; // esi
  int result; // eax
  int v4; // edi
  int v5; // edx
  int v6; // ecx
  char *v7; // [esp+10h] [ebp-4h]

  v2 = *(_DWORD **)(a1 + 436);
  v2[2] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  v2[3] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  v2[4] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  v2[5] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  result = 0;
  v7 = (char *)&loc_5B6900;
  v4 = -14831872;
  v5 = -11728000;
  v6 = 2919680;
  do
  {
    *(_DWORD *)(result + v2[2]) = v5 >> 16;
    *(_DWORD *)(result + v2[3]) = v4 >> 16;
    *(_DWORD *)(result + v2[4]) = v7;
    *(_DWORD *)(result + v2[5]) = v6;
    v6 -= 22554;
    v5 += (int)&loc_166E9;
    v4 += (int)&loc_1C5A2;
    result += 4;
    v7 -= 46802;
  }
  while ( v6 >= -2831590 );
  return result;
}
