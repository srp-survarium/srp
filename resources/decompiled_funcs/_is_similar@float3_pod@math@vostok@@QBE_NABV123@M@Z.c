bool __thiscall vostok::math::float3_pod::is_similar(
        vostok::math::float3_pod *this,
        const vostok::math::float3_pod *other,
        float epsilon)
{
  return epsilon > fabs(this->x - other->x) && epsilon > fabs(this->y - other->y) && epsilon > fabs(this->z - other->z);
}
