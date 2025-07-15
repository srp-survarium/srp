int __thiscall lut_id(const vostok::math::float3 *normal)
{
  return (normal->x >= 0.0) | ~(LODWORD(normal->y) >> 30) & 2 | ~(LODWORD(normal->z) >> 29) & 4;
}
