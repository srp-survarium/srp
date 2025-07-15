void __thiscall btTriangleShape::getVertex(btTriangleShape *this, int index, btVector3 *vert)
{
  btVector3 *v3; // esi

  v3 = &this->m_vertices1[index];
  vert->mVec128.m128_i32[0] = v3->mVec128.m128_i32[0];
  v3 = (btVector3 *)((char *)v3 + 4);
  vert->mVec128.m128_i32[1] = v3->mVec128.m128_i32[0];
  vert->mVec128.m128_u64[1] = *(unsigned __int64 *)((char *)v3->mVec128.m128_u64 + 4);
}
