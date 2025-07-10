void __cdecl jinit_d_coef_controller(int a1, char a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ebp
  _DWORD *v5; // edi
  int v6; // ecx
  int v7; // ebx
  int v8; // eax
  bool v9; // cc
  int v10; // eax
  int v11; // [esp-Ch] [ebp-18h]
  int v12; // [esp-8h] [ebp-14h]
  _DWORD *v13; // [esp+10h] [ebp+4h]
  int v14; // [esp+14h] [ebp+8h]

  v3 = (_DWORD *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 116);
  v4 = v3;
  *(_DWORD *)(a1 + 408) = v3;
  *v3 = sub_375340;
  v3[2] = sub_3760B0;
  v3[28] = 0;
  if ( a2 )
  {
    v14 = 0;
    if ( *(int *)(a1 + 36) > 0 )
    {
      v5 = (_DWORD *)(*(_DWORD *)(a1 + 196) + 12);
      v13 = v3 + 18;
      do
      {
        v6 = *v5;
        if ( *(_BYTE *)(a1 + 201) )
          v6 *= 3;
        v7 = *(_DWORD *)(a1 + 4);
        v12 = v6;
        v11 = jround_up(v5[5], *v5);
        v8 = jround_up(v5[4], *(v5 - 1));
        *v13 = (*(int (__cdecl **)(int, int, int, int, int, int))(v7 + 20))(a1, 1, 1, v8, v11, v12);
        v5 += 22;
        v9 = ++v14 < *(_DWORD *)(a1 + 36);
        ++v13;
      }
      while ( v9 );
    }
    v4[1] = sub_3755B0;
    v4[3] = sub_375790;
    v4[4] = v4 + 18;
  }
  else
  {
    v10 = (*(int (__cdecl **)(int, int, int))(*(_DWORD *)(a1 + 4) + 4))(a1, 1, 1280);
    v4[9] = v10 + 128;
    v4[10] = v10 + 256;
    v4[11] = v10 + 384;
    v4[12] = v10 + 512;
    v4[13] = v10 + 640;
    v4[14] = v10 + 768;
    v4[15] = v10 + 896;
    v4[8] = v10;
    v4[16] = v10 + 1024;
    v4[17] = v10 + 1152;
    if ( !*(_DWORD *)(a1 + 392) )
      memset(v10, 0, 0x500u);
    v4[4] = 0;
    v4[1] = Scaleform::GFx::ConstShapeNoStyles::GetStrokeStyleCount;
    v4[3] = sub_375360;
  }
}
