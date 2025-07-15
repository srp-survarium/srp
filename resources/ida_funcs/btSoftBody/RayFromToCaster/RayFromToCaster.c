void __fastcall btSoftBody::RayFromToCaster::RayFromToCaster(
        const btVector3 *rayTo,
        const btVector3 *rayFrom,
        btSoftBody::RayFromToCaster *this,
        float mxt)
{
  unsigned __int64 v4; // [esp+0h] [ebp-10h]
  unsigned int v5; // [esp+8h] [ebp-8h]

  this->m_rayFrom = (btVector3)rayFrom->mVec128;
  *(float *)&v4 = rayTo->mVec128.m128_f32[0] - rayFrom->mVec128.m128_f32[0];
  *((float *)&v4 + 1) = rayTo->mVec128.m128_f32[1] - rayFrom->mVec128.m128_f32[1];
  *(float *)&v5 = rayTo->mVec128.m128_f32[2] - rayFrom->mVec128.m128_f32[2];
  this->m_rayNormalizedDirection.mVec128.m128_u64[0] = v4;
  this->m_rayNormalizedDirection.mVec128.m128_u64[1] = v5;
  this->m_rayTo = (btVector3)rayTo->mVec128;
  this->m_mint = mxt;
  this->m_face = 0;
  this->m_tests = 0;
}
