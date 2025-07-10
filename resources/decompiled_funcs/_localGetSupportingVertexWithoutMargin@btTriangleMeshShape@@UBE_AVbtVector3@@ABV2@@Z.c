btVector3 *__thiscall btTriangleMeshShape::localGetSupportingVertexWithoutMargin(
        btTriangleMeshShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  this->localGetSupportingVertex(this, result, vec);
  return result;
}
