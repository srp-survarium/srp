btMatrix3x3 *__usercall Add@<eax>(const btMatrix3x3 *a@<ecx>, const btMatrix3x3 *b@<eax>, int a3)
{
  int v3; // edx
  float *v4; // eax
  int v5; // ebx
  float v6; // xmm0_4
  _DWORD *v7; // edi
  bool v8; // zf
  int v10; // [esp+0h] [ebp-14h]
  float v11; // [esp+8h] [ebp-Ch]

  v3 = (char *)a - (char *)b;
  v4 = &b->m_el[0].mVec128.m128_f32[1];
  v5 = a3 - (_DWORD)a;
  v10 = 3;
  do
  {
    v11 = *(float *)((char *)v4 + v3) + *v4;
    v6 = v4[1] + a->m_el[0].mVec128.m128_f32[2];
    *(float *)((char *)a->m_el[0].mVec128.m128_f32 + v5) = *(v4 - 1) + a->m_el[0].mVec128.m128_f32[0];
    *(float *)((char *)&a->m_el[0].mVec128.m128_f32[1] + v5) = v11;
    *(float *)((char *)&a->m_el[0].mVec128.m128_f32[2] + v5) = v6;
    v7 = (int *)((char *)&a->m_el[0].mVec128.m128_i32[3] + v5);
    v4 += 4;
    a = (const btMatrix3x3 *)((char *)a + 16);
    v8 = v10-- == 1;
    *v7 = 0;
  }
  while ( !v8 );
  return (btMatrix3x3 *)a3;
}
