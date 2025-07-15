btVector3 *__thiscall btSoftClusterCollisionShape::localGetSupportingVertexWithoutMargin(
        btSoftClusterCollisionShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  this->localGetSupportingVertex(this, result, vec);
  return result;
}
