void __userpurge survarium::flash_text::set_position(
        survarium::flash_text *this@<ecx>,
        _DWORD *a2@<esi>,
        float screen_position_x,
        float screen_position_y)
{
  float *v4; // eax
  int v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm1_4
  _DWORD v8[4]; // [esp+20h] [ebp-20h] BYREF
  _BYTE v9[16]; // [esp+30h] [ebp-10h] BYREF

  v4 = (float *)(*(int (__thiscall **)(_DWORD, _BYTE *))(*(_DWORD *)*a2 + 76))(*a2, v9);
  v5 = *a2;
  v6 = (float)(v4[2] - *v4) + screen_position_x;
  v7 = (float)(v4[3] - v4[1]) + screen_position_y;
  *(float *)v8 = screen_position_x;
  *(float *)&v8[1] = screen_position_y;
  *(float *)&v8[2] = v6;
  *(float *)&v8[3] = v7;
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v5 + 72))(v5, v8);
  *(_BYTE *)(a2[1] + 4) = 1;
}
