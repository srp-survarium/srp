void __usercall vostok::render::light::set_scale(
        vostok::render::light *this@<ecx>,
        const vostok::math::float3 *scale@<eax>)
{
  this->scale = *scale;
}
