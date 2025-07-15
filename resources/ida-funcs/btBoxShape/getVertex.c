void __thiscall btBoxShape::getVertex(btBoxShape *this, int i, btVector3 *vtx)
{
  btVector3 v3; // [esp+10h] [ebp-20h] BYREF
  btVector3 v4; // [esp+20h] [ebp-10h]

  btBoxShape::getHalfExtentsWithMargin(this, (btVector3 *)this, &v3);
  v4.mVec128.m128_f32[0] = (float)((float)(1 - (i & 1)) * v3.mVec128.m128_f32[0])
                         - (float)((float)(i & 1) * v3.mVec128.m128_f32[0]);
  v4.mVec128.m128_f32[1] = (float)((float)(1 - ((i >> 1) & 1)) * v3.mVec128.m128_f32[1])
                         - (float)((float)((i >> 1) & 1) * v3.mVec128.m128_f32[1]);
  v4.mVec128.m128_f32[2] = (float)((float)(1 - ((i >> 2) & 1)) * v3.mVec128.m128_f32[2])
                         - (float)((float)((i >> 2) & 1) * v3.mVec128.m128_f32[2]);
  v4.mVec128.m128_i32[3] = 0;
  *vtx = (btVector3)v4.mVec128;
}
