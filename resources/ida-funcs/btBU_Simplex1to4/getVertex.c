void __thiscall btBU_Simplex1to4::getVertex(btBU_Simplex1to4 *this, int i, btVector3 *vtx)
{
  btVector3 *v3; // esi

  v3 = &this->m_vertices[i];
  vtx->mVec128.m128_i32[0] = v3->mVec128.m128_i32[0];
  v3 = (btVector3 *)((char *)v3 + 4);
  vtx->mVec128.m128_i32[1] = v3->mVec128.m128_i32[0];
  vtx->mVec128.m128_u64[1] = *(unsigned __int64 *)((char *)v3->mVec128.m128_u64 + 4);
}
