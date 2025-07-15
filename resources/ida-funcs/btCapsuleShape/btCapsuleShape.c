void __userpurge btCapsuleShape::btCapsuleShape(
        btCapsuleShape *this@<eax>,
        btConvexInternalShape *a2@<ecx>,
        float a3@<xmm1>,
        float radius)
{
  btConvexInternalShape *v5; // eax

  v5 = btConvexInternalShape::btConvexInternalShape(a2, this);
  v5->__vftable = (btConvexInternalShape_vtbl *)&btCapsuleShape::`vftable';
  v5->m_shapeType = 10;
  v5[1].__vftable = (btConvexInternalShape_vtbl *)1;
  v5->m_implicitShapeDimensions.mVec128.m128_f32[0] = radius;
  v5->m_implicitShapeDimensions.mVec128.m128_f32[2] = radius;
  v5->m_implicitShapeDimensions.mVec128.m128_f32[1] = a3 * 0.5;
  v5->m_implicitShapeDimensions.mVec128.m128_i32[3] = 0;
}
