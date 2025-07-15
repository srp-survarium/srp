btSoftBodyWorldInfo *__usercall btSoftBodyWorldInfo::btSoftBodyWorldInfo@<eax>(
        btSoftBodyWorldInfo *this@<ecx>,
        btSoftBodyWorldInfo *result@<eax>)
{
  result->air_density = FLOAT_1_2;
  result->water_density = 0.0;
  result->water_offset = 0.0;
  result->water_normal.mVec128.m128_i32[0] = 0;
  result->water_normal.mVec128.m128_i32[1] = 0;
  result->water_normal.mVec128.m128_i32[2] = 0;
  result->water_normal.mVec128.m128_i32[3] = 0;
  result->m_broadphase = 0;
  result->m_dispatcher = 0;
  result->m_gravity.mVec128.m128_i32[0] = 0;
  result->m_gravity.mVec128.m128_f32[1] = FLOAT_N10_0;
  result->m_gravity.mVec128.m128_i32[2] = 0;
  result->m_gravity.mVec128.m128_i32[3] = 0;
  result->m_sparsesdf.cells.m_ownsMemory = 1;
  result->m_sparsesdf.cells.m_data = 0;
  result->m_sparsesdf.cells.m_size = 0;
  result->m_sparsesdf.cells.m_capacity = 0;
  return result;
}
