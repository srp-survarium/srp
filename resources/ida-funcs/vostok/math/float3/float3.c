void __usercall vostok::math::float3::float3(vostok::math::float3 *this@<ecx>, vostok::math::float3 *a2@<eax>)
{
  *a2 = *this;
}


void __thiscall vostok::math::float3::float3(
        vostok::math::float3 *this,
        unsigned int other_x,
        unsigned int other_y,
        float other_z)
{
  *(_QWORD *)&this->x = __PAIR64__(other_y, other_x);
  this->z = other_z;
}
