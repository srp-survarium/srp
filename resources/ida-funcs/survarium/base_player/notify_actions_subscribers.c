void __userpurge survarium::base_player::notify_actions_subscribers(
        survarium::base_player *this@<ecx>,
        int a2@<eax>,
        unsigned int time_delta_in_ms)
{
  char v4; // bl
  void (__stdcall ****v5)(_DWORD, BOOL, float); // edi
  void (__stdcall ****v6)(_DWORD, BOOL, float); // ebx
  int v7; // esi
  BOOL v8; // [esp+10h] [ebp-4h] BYREF
  float v9; // [esp+1Ch] [ebp+8h]

  v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 320) + 68))(*(_DWORD *)(a2 + 320));
  if ( v4 || (v8 = 0, !vostok::math::is_similar<float>((const float *)(a2 + 756), (const float *)&v8, 0.001)) )
  {
    v8 = v4 != 0;
    v5 = *(void (__stdcall *****)(_DWORD, BOOL, float))((char *)&dword_10EA8 + a2);
    v6 = *(void (__stdcall *****)(_DWORD, BOOL, float))((char *)&dword_10EAC + a2);
    v9 = (double)time_delta_in_ms * 0.001;
    if ( v5 != v6 )
    {
      v7 = a2 + 308;
      do
        (***v5++)(v7, v8, COERCE_FLOAT(LODWORD(v9)));
      while ( v5 != v6 );
    }
  }
}
