float __usercall BaryEval_float_@<xmm0>(
        const float *b@<ecx>,
        const btVector3 *coord@<eax>,
        const float *a,
        const float *c)
{
  return (float)((float)(coord->mVec128.m128_f32[1] * *b) + (float)(coord->mVec128.m128_f32[2] * *c))
       + (float)(*a * coord->mVec128.m128_f32[0]);
}
