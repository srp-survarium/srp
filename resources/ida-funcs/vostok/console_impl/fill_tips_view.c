// bad sp value at call has been detected, the output may be wrong!
void __usercall vostok::console_impl::fill_tips_view(
        vostok::console_impl *this@<ecx>,
        int a2@<eax>,
        int a3@<ebx>,
        int a4@<edi>,
        int a5@<esi>)
{
  int *v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // esi
  int v10; // esi
  int v11; // ebx
  int v12; // esi
  float v13; // xmm0_4
  int v14; // eax
  void (__thiscall ***v15)(_DWORD, float *); // eax
  int v16; // eax
  _DWORD *v17; // eax
  int v18; // ebx
  int v19; // eax
  int v20; // eax
  int v21; // eax
  char v23[8]; // [esp+4h] [ebp-28h] BYREF
  float v24; // [esp+Ch] [ebp-20h] BYREF
  float v25; // [esp+10h] [ebp-1Ch]
  float v26; // [esp+14h] [ebp-18h] BYREF
  float v27; // [esp+18h] [ebp-14h]
  _DWORD *v28; // [esp+1Ch] [ebp-10h]
  unsigned int v29; // [esp+20h] [ebp-Ch]
  float v30; // [esp+24h] [ebp-8h]
  unsigned int v31; // [esp+28h] [ebp-4h]

  v6 = *(int **)(a2 + 56);
  v26 = s_spot_max_distance;
  v27 = FLOAT_20_0;
  v7 = *v6;
  v30 = 0.0;
  v8 = (*(int (__thiscall **)(int *, int, int, int))(v7 + 8))(v6, a4, a5, a3);
  (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 72))(v8);
  v9 = *(_DWORD *)(a2 + 596) - *(_DWORD *)(a2 + 592);
  v31 = 0;
  v10 = v9 >> 2;
  v29 = v10;
  if ( v10 )
  {
    do
    {
      v11 = *(_DWORD *)(*(_DWORD *)(a2 + 592) + 4 * v31);
      v12 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 32) + 16))(*(_DWORD *)(a2 + 32));
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v12 + 8))(v12, v11);
      (**(void (__thiscall ***)(int, _DWORD))v12)(v12, 0);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v12 + 20))(v12, 0);
      v13 = *(float *)(*(int (__thiscall **)(int, char *))(*(_DWORD *)v12 + 24))(v12, v23);
      if ( v26 <= v13 )
        v26 = v13;
      v14 = (*(int (__thiscall **)(int))(*(_DWORD *)v12 + 28))(v12);
      (*(void (__thiscall **)(int, float *))(*(_DWORD *)v14 + 8))(v14, &v26);
      v15 = (void (__thiscall ***)(_DWORD, float *))(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 28))(v12);
      v24 = 0.0;
      v25 = v30;
      (**v15)(v15, &v24);
      v16 = (*(int (__thiscall **)(int))(*(_DWORD *)v12 + 28))(v12);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v16 + 16))(v16, 1);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v12 + 4))(v12, -16711936);
      v17 = (_DWORD *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 56) + 8))(*(_DWORD *)(a2 + 56));
      v18 = *v17;
      v28 = v17;
      v19 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v12 + 28))(v12, 1);
      (*(void (__thiscall **)(_DWORD *, int))(v18 + 64))(v28, v19);
      ++v31;
      v30 = v27 + v30;
    }
    while ( v31 < v29 );
    v10 = v29;
  }
  v20 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 56) + 8))(*(_DWORD *)(a2 + 56));
  v24 = v26;
  v25 = v30;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v20 + 8))(v20, &v24);
  v21 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 56) + 8))(*(_DWORD *)(a2 + 56));
  (*(void (__thiscall **)(int, bool))(*(_DWORD *)v21 + 16))(v21, v10 != 0);
}
