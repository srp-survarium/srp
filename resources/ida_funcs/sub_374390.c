void __usercall sub_374390(int a1@<ebx>)
{
  int v1; // ebp
  unsigned int v2; // esi
  void *v3; // eax
  int *v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  v5 = 0;
  if ( *(int *)(a1 + 296) > 0 )
  {
    v4 = (int *)(a1 + 300);
    do
    {
      v1 = *v4;
      if ( !*(_DWORD *)(*v4 + 80) )
      {
        v2 = *(_DWORD *)(v1 + 16);
        if ( v2 > 3 || !*(_DWORD *)(a1 + 4 * v2 + 144) )
        {
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 54;
          *(_DWORD *)(*(_DWORD *)a1 + 24) = v2;
          (**(void (__cdecl ***)(int))a1)(a1);
        }
        v3 = (void *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 130);
        qmemcpy(v3, *(const void **)(a1 + 4 * v2 + 144), 0x82u);
        *(_DWORD *)(v1 + 80) = v3;
      }
      ++v4;
      ++v5;
    }
    while ( v5 < *(_DWORD *)(a1 + 296) );
  }
}
