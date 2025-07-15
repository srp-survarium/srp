void __usercall vostok::render::light::set_position(
        vostok::render::light *this@<eax>,
        const vostok::math::float3 *P@<edi>)
{
  vostok::math::float3 *p_position; // esi

  p_position = &this->position;
  if ( !vostok::math::float3_pod::is_similar(&this->position, P, 0.0000001) )
    *p_position = *P;
}
