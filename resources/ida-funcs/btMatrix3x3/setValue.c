void __userpurge btMatrix3x3::setValue(
        btMatrix3x3 *this@<ecx>,
        int a2@<eax>,
        float *xx,
        float *xy,
        float *xz,
        float *yx,
        float *yy,
        float *yz,
        float *zx,
        const float *zy,
        const float *zz)
{
  double v11; // st7

  *(float *)a2 = this->m_el[0].mVec128.m128_f32[0];
  *(float *)(a2 + 4) = *xx;
  *(float *)(a2 + 8) = *xy;
  *(_DWORD *)(a2 + 12) = 0;
  *(float *)(a2 + 16) = *xz;
  *(float *)(a2 + 20) = *yx;
  *(float *)(a2 + 24) = *yy;
  *(_DWORD *)(a2 + 28) = 0;
  *(float *)(a2 + 32) = *yz;
  *(float *)(a2 + 36) = *zx;
  v11 = *zy;
  *(_DWORD *)(a2 + 44) = 0;
  *(float *)(a2 + 40) = v11;
}
