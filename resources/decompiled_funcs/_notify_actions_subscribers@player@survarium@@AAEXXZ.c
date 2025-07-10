void __usercall survarium::player::notify_actions_subscribers(survarium::player *this@<ecx>, float *a2@<esi>)
{
  float v2; // xmm2_4
  float v3; // xmm0_4
  float v4; // xmm1_4
  long double v5; // st7
  void (__stdcall ****v6)(int, int, float); // edi
  void (__stdcall ****v7)(int, int, float); // ebx
  void (__stdcall **v8)(int, int, float); // edx
  float _X; // [esp+0h] [ebp-14h]
  float movement; // [esp+Ch] [ebp-8h]

  v2 = a2[8682] - *(float *)((char *)&dword_10ECC + (_DWORD)a2);
  v3 = a2[8680] - *(float *)((char *)&dword_10EC4 + (_DWORD)a2);
  v4 = a2[8681] - *(float *)((char *)&dword_10EC8 + (_DWORD)a2);
  v5 = sqrtf((float)((float)(v2 * v2) + (float)(v3 * v3)) + (float)(v4 * v4));
  movement = v5;
  v6 = *(void (__stdcall *****)(int, int, float))((char *)&dword_10E10 + (_DWORD)a2);
  v7 = *(void (__stdcall *****)(int, int, float))((char *)&dword_10E14 + (_DWORD)a2);
  if ( v6 != v7 )
  {
    while ( 1 )
    {
      if ( COERCE_FLOAT(LODWORD(movement) & 0x7FFFFFFF) >= 0.001 )
      {
        v8 = **v6;
        _X = v5;
        if ( (*(int *)((_BYTE *)&dword_10EE0 + (_DWORD)a2) & 0x200) != 0 )
          (*v8)((int)(a2 + 14), 1, COERCE_FLOAT(LODWORD(_X)));
        else
          (*v8)((int)(a2 + 14), 0, COERCE_FLOAT(LODWORD(_X)));
      }
      if ( ++v6 == v7 )
        break;
      v5 = movement;
    }
  }
}
