vostok::math::float4x4 *__usercall survarium::mix_transformations@<eax>(
        const vostok::math::float4x4 *first@<ecx>,
        const vostok::math::float4x4 *second@<eax>,
        int coeff,
        float coeffa)
{
  survarium::mix_transformations(first, second, coeff, coeffa, coeffa);
  return (vostok::math::float4x4 *)coeff;
}
