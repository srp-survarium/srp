void __thiscall btBoxShape::getPreferredPenetrationDirection(btBoxShape *this, int index, btVector3 *penetrationVector)
{
  float v3; // xmm1_4
  btVector3 *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm0_4

  if ( !index )
  {
    v6 = s_bm_current_air_resistance;
    goto LABEL_15;
  }
  if ( index == 1 )
  {
    v6 = FLOAT_N1_0;
LABEL_15:
    v4 = penetrationVector;
    penetrationVector->mVec128.m128_f32[0] = v6;
    penetrationVector->mVec128.m128_i32[2] = 0;
LABEL_16:
    v4->mVec128.m128_i32[1] = 0;
    goto LABEL_17;
  }
  if ( index == 2 )
  {
    v5 = s_bm_current_air_resistance;
  }
  else
  {
    if ( index != 3 )
    {
      if ( index == 4 )
      {
        v3 = s_bm_current_air_resistance;
      }
      else
      {
        if ( index != 5 )
          return;
        v3 = FLOAT_N1_0;
      }
      v4 = penetrationVector;
      penetrationVector->mVec128.m128_i32[0] = 0;
      penetrationVector->mVec128.m128_f32[2] = v3;
      goto LABEL_16;
    }
    v5 = FLOAT_N1_0;
  }
  v4 = penetrationVector;
  penetrationVector->mVec128.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)penetrationVector->mVec128.m128_u64 + 4) = LODWORD(v5);
LABEL_17:
  v4->mVec128.m128_i32[3] = 0;
}
