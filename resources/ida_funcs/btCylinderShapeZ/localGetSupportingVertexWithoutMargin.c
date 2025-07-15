btVector3 *__thiscall btCylinderShapeZ::localGetSupportingVertexWithoutMargin(
        btCylinderShapeZ *this,
        btVector3 *result,
        const btVector3 *vec)
{
  CylinderLocalSupportZ(&this->m_implicitShapeDimensions, vec, result);
  return result;
}
