btVector3 *__usercall btBoxShape::getHalfExtentsWithMargin@<eax>(
        btCylinderShape *this@<ecx>,
        _QWORD *a2@<edi>,
        btVector3 *a3@<esi>)
{
  double (__thiscall *v3)(_QWORD *); // edx
  double v4; // st7
  btVector3 *v5; // eax
  float v6; // [esp+8h] [ebp-8h]
  float v7; // [esp+Ch] [ebp-4h]

  v3 = *(double (__thiscall **)(_QWORD *))(*(_DWORD *)a2 + 40);
  a3->mVec128.m128_u64[0] = a2[4];
  a3->mVec128.m128_u64[1] = a2[5];
  v7 = v3(a2);
  v6 = ((double (__thiscall *)(_QWORD *))*(_DWORD *)(*(_DWORD *)a2 + 40))(a2);
  v4 = ((double (__thiscall *)(_QWORD *))*(_DWORD *)(*(_DWORD *)a2 + 40))(a2);
  v5 = a3;
  a3->mVec128.m128_f32[0] = v4 + a3->mVec128.m128_f32[0];
  a3->mVec128.m128_f32[1] = a3->mVec128.m128_f32[1] + v6;
  a3->mVec128.m128_f32[2] = a3->mVec128.m128_f32[2] + v7;
  return v5;
}
