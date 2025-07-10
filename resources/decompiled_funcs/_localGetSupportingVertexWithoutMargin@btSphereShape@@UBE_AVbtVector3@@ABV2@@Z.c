btVector3 *__thiscall btSphereShape::localGetSupportingVertexWithoutMargin(
        btSphereShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  btVector3 *v3; // eax

  v3 = result;
  result->mVec128.m128_u64[0] = 0;
  result->mVec128.m128_u64[1] = 0;
  return v3;
}
