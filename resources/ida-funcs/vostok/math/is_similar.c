bool __usercall vostok::math::is_similar@<al>(
        const vostok::math::float3 *left@<ecx>,
        const vostok::math::float3 *right@<eax>,
        float epsilon)
{
  return vostok::math::float3_pod::is_similar(&left->vostok::math::float3_pod, right, epsilon);
}


BOOL __usercall vostok::math::is_similar<float>@<eax>(const float *left@<eax>, const float *right@<ecx>, float epsilon)
{
  return epsilon > fabs(*left - *right);
}
