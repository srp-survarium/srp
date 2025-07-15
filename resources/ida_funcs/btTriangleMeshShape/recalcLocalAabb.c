void __usercall btTriangleMeshShape::recalcLocalAabb(btTriangleMeshShape *this@<ecx>, float *a2@<esi>)
{
  float *v2; // ebx
  int i; // edi
  void (__thiscall *v4)(float *, _QWORD *, _QWORD *); // eax
  int (__thiscall *v5)(float *, _BYTE *, _QWORD *); // edx
  _QWORD *v6; // eax
  _QWORD v7[2]; // [esp+60h] [ebp-30h] BYREF
  _QWORD v8[2]; // [esp+70h] [ebp-20h] BYREF
  _BYTE v9[16]; // [esp+80h] [ebp-10h] BYREF

  v2 = a2 + 4;
  for ( i = 0; i < 12; i += 4 )
  {
    v4 = *(void (__thiscall **)(float *, _QWORD *, _QWORD *))(*(_DWORD *)a2 + 60);
    memset(v7, 0, sizeof(v7));
    *(_DWORD *)((char *)v7 + i) = clear_value;
    v4(a2, v8, v7);
    v2[4] = a2[3] + *(float *)((char *)v8 + i);
    v5 = *(int (__thiscall **)(float *, _BYTE *, _QWORD *))(*(_DWORD *)a2 + 60);
    *(_DWORD *)((char *)v7 + i) = -1082130432;
    v6 = (_QWORD *)v5(a2, v9, v7);
    v8[0] = *v6;
    v8[1] = v6[1];
    *v2++ = *(float *)((char *)v8 + i) - a2[3];
  }
}
