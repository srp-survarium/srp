btVector3 *__thiscall btCylinderShape::localGetSupportingVertexWithoutMargin(
        btCylinderShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  CylinderLocalSupportY(&this->m_implicitShapeDimensions, vec, result);
  return result;
}
