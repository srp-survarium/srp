btVector3 *__thiscall btBoxShape::getHalfExtentsWithMargin(btBoxShape *this, btVector3 *result, btVector3 *a3)
{
  int v3; // eax
  btVector3 *v4; // eax
  float v5; // [esp+18h] [ebp-8h]
  float v6; // [esp+1Ch] [ebp-4h]

  v3 = result->mVec128.m128_i32[0];
  *a3 = (btVector3)result[2].mVec128;
  v6 = ((double (*)(void))*(_DWORD *)(v3 + 40))();
  v5 = ((double (__thiscall *)(btVector3 *))*(_DWORD *)(result->mVec128.m128_i32[0] + 40))(result);
  a3->mVec128.m128_f32[0] = ((double (__thiscall *)(btVector3 *))*(_DWORD *)(result->mVec128.m128_i32[0] + 40))(result)
                          + a3->mVec128.m128_f32[0];
  v4 = a3;
  a3->mVec128.m128_f32[1] = a3->mVec128.m128_f32[1] + v5;
  a3->mVec128.m128_f32[2] = a3->mVec128.m128_f32[2] + v6;
  return v4;
}
