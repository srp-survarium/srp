BOOL __fastcall vostok::math::operator==(const vostok::math::float3_pod *right, const vostok::math::float3_pod *left)
{
  return left->x == right->x && left->y == right->y && left->z == right->z;
}
