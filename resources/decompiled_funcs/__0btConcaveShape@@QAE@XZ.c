btConcaveShape *__usercall btConcaveShape::btConcaveShape@<eax>(
        btConcaveShape *this@<ecx>,
        btConcaveShape *result@<eax>)
{
  result->m_shapeType = 35;
  result->m_userPointer = 0;
  result->__vftable = (btConcaveShape_vtbl *)&btConcaveShape::`vftable';
  result->m_collisionMargin = 0.0;
  return result;
}
