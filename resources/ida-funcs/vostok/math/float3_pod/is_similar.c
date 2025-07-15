bool __userpurge vostok::math::float3_pod::is_similar@<al>(
        vostok::math::float3_pod *this@<edi>,
        const vostok::math::float3_pod *other@<eax>,
        float epsilon)
{
  return vostok::math::is_similar<float>(&this->x, &other->x, epsilon)
      && vostok::math::is_similar<float>(&this->y, &other->y, epsilon)
      && vostok::math::is_similar<float>(&this->z, &other->z, epsilon);
}
