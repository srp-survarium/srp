void __thiscall survarium::flash_movie::HandleMouseMove(
        survarium::flash_movie *this,
        const float x,
        const float y,
        const float scroll_delta,
        int a5)
{
  int v5; // ecx
  _DWORD v6[7]; // [esp+0h] [ebp-38h] BYREF
  _DWORD v7[7]; // [esp+1Ch] [ebp-1Ch] BYREF

  v5 = *(_DWORD *)(LODWORD(x) + 4);
  *(float *)&v7[2] = y;
  *(float *)&v7[3] = scroll_delta;
  LOBYTE(v7[1]) = 0;
  v7[0] = 1;
  memset(&v7[4], 0, 12);
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v5 + 136))(v5, v7);
  *(float *)&v6[2] = y;
  *(float *)&v6[3] = scroll_delta;
  v6[5] = 0;
  v6[6] = 0;
  v6[4] = a5;
  LOBYTE(v6[1]) = 0;
  v6[0] = 4;
  qmemcpy(v7, v6, sizeof(v7));
  (*(void (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)(LODWORD(x) + 4) + 136))(*(_DWORD *)(LODWORD(x) + 4), v7);
}
