void __thiscall btBoxShape::getPlaneEquation(btBoxShape *this, btVector4 *plane, int i)
{
  btVector4 *v3; // eax
  float v4; // xmm0_4
  int v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  unsigned __int64 v8; // [esp+10h] [ebp-10h]
  int v9; // [esp+18h] [ebp-8h]

  v8 = this->m_implicitShapeDimensions.mVec128.m128_u64[0];
  v9 = this->m_implicitShapeDimensions.mVec128.m128_i32[2];
  switch ( i )
  {
    case 0:
      v7 = s_bm_current_air_resistance;
      goto LABEL_15;
    case 1:
      v7 = FLOAT_N1_0;
LABEL_15:
      v3 = plane;
      plane->mVec128.m128_u64[0] = LODWORD(v7);
      plane->mVec128.m128_i32[2] = 0;
      v5 = v8;
      goto LABEL_16;
    case 2:
      v6 = s_bm_current_air_resistance;
      goto LABEL_11;
    case 3:
      v6 = FLOAT_N1_0;
LABEL_11:
      v3 = plane;
      plane->mVec128.m128_i32[0] = 0;
      plane->mVec128.m128_i32[2] = 0;
      v5 = HIDWORD(v8);
      plane->mVec128.m128_f32[1] = v6;
      goto LABEL_16;
    case 4:
      v3 = plane;
      plane->mVec128.m128_u64[0] = 0;
      v4 = s_bm_current_air_resistance;
      break;
    case 5:
      v3 = plane;
      plane->mVec128.m128_u64[0] = 0;
      v4 = FLOAT_N1_0;
      break;
    default:
      return;
  }
  v3->mVec128.m128_f32[2] = v4;
  v5 = v9;
LABEL_16:
  v3->mVec128.m128_i32[3] = v5 ^ _mask__NegFloat_;
}
