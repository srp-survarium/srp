SphereTriangleDetector *__userpurge SphereTriangleDetector::SphereTriangleDetector@<eax>(
        SphereTriangleDetector *this@<ecx>,
        SphereTriangleDetector *result@<eax>,
        float a3@<xmm0>,
        btTriangleShape *triangle,
        struct btTriangleShape *a5,
        float a6)
{
  result->__vftable = (SphereTriangleDetector_vtbl *)&SphereTriangleDetector::`vftable';
  result->m_sphere = (btSphereShape *)this;
  result->m_triangle = triangle;
  result->m_contactBreakingThreshold = a3;
  return result;
}
