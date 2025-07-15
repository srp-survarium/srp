bool __usercall vostok::math::float2_pod::is_similar@<al>(
        vostok::math::float2_pod *this@<edi>,
        const vostok::math::float2_pod *other@<eax>)
{
  bool result; // al

  result = vostok::math::is_similar<float>(&this->x, &other->x, 0.0000099999997);
  if ( result )
    return vostok::math::is_similar<float>(&this->y, &other->y, 0.0000099999997);
  return result;
}
