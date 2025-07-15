void __thiscall btTriangleShape::getPlaneEquation(
        btTriangleShape *this,
        int i,
        btTriangleShape *planeNormal,
        btVector3 *planeSupport)
{
  btTriangleShape *v4; // esi

  v4 = this;
  btTriangleShape::calcNormal(planeNormal, (float *)this);
  v4 = (btTriangleShape *)((char *)v4 + 80);
  planeSupport->mVec128.m128_i32[0] = (int)v4->__vftable;
  v4 = (btTriangleShape *)((char *)v4 + 4);
  planeSupport->mVec128.m128_i32[1] = (int)v4->__vftable;
  planeSupport->mVec128.m128_u64[1] = *(_QWORD *)&v4->m_shapeType;
}
