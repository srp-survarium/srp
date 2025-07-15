void __thiscall btBoxShape::getPlaneEquation(btBoxShape *this, btVector4 *plane, int i)
{
  int v3; // xmm1_4
  btVector4 *v4; // eax
  int v5; // xmm0_4
  btVector3 v6; // [esp+10h] [ebp-10h]

  v6.mVec128 = (__m128)this->m_implicitShapeDimensions;
  switch ( i )
  {
    case 0:
      plane->mVec128.m128_u64[0] = (unsigned int)clear_value;
      plane->mVec128.m128_i32[2] = 0;
      plane->mVec128.m128_f32[3] = -v6.mVec128.m128_f32[0];
      return;
    case 1:
      plane->mVec128.m128_u64[0] = 3212836864LL;
      plane->mVec128.m128_i32[2] = 0;
      plane->mVec128.m128_f32[3] = -v6.mVec128.m128_f32[0];
      return;
    case 2:
      v3 = (int)clear_value;
      goto LABEL_5;
    case 3:
      v3 = -1082130432;
LABEL_5:
      plane->mVec128.m128_i32[0] = 0;
      *(unsigned __int64 *)((char *)plane->mVec128.m128_u64 + 4) = (unsigned int)v3;
      plane->mVec128.m128_f32[3] = -v6.mVec128.m128_f32[1];
      return;
    case 4:
      v4 = plane;
      plane->mVec128.m128_u64[0] = 0;
      v5 = (int)clear_value;
      goto LABEL_9;
    case 5:
      v4 = plane;
      plane->mVec128.m128_u64[0] = 0;
      v5 = -1082130432;
LABEL_9:
      v4->mVec128.m128_i32[2] = v5;
      v4->mVec128.m128_f32[3] = -v6.mVec128.m128_f32[2];
      break;
    default:
      return;
  }
}
