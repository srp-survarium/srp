void __thiscall btBoxShape::getPreferredPenetrationDirection(btBoxShape *this, int index, btVector3 *penetrationVector)
{
  const vostok::math::float4x4 *v3; // xmm1_4
  int v4; // xmm1_4

  switch ( index )
  {
    case 0:
      penetrationVector->mVec128.m128_i32[0] = (int)clear_value;
      *(unsigned __int64 *)((char *)penetrationVector->mVec128.m128_u64 + 4) = 0;
      penetrationVector->mVec128.m128_i32[3] = 0;
      break;
    case 1:
      penetrationVector->mVec128.m128_i32[0] = -1082130432;
      *(unsigned __int64 *)((char *)penetrationVector->mVec128.m128_u64 + 4) = 0;
      penetrationVector->mVec128.m128_i32[3] = 0;
      break;
    case 2:
      v3 = clear_value;
      penetrationVector->mVec128.m128_i32[0] = 0;
      *(unsigned __int64 *)((char *)penetrationVector->mVec128.m128_u64 + 4) = (unsigned int)v3;
      penetrationVector->mVec128.m128_i32[3] = 0;
      break;
    case 3:
      penetrationVector->mVec128.m128_i32[0] = 0;
      *(unsigned __int64 *)((char *)penetrationVector->mVec128.m128_u64 + 4) = 3212836864LL;
      penetrationVector->mVec128.m128_i32[3] = 0;
      break;
    case 4:
      v4 = (int)clear_value;
      goto LABEL_8;
    case 5:
      v4 = -1082130432;
LABEL_8:
      penetrationVector->mVec128.m128_i32[2] = v4;
      penetrationVector->mVec128.m128_u64[0] = 0;
      penetrationVector->mVec128.m128_i32[3] = 0;
      break;
    default:
      return;
  }
}
