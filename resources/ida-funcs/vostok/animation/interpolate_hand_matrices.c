void __usercall vostok::animation::interpolate_hand_matrices(
        const vostok::math::float4x4 *locator_matrices@<eax>,
        const vostok::math::float4x4 *previous_locator_matrices,
        const unsigned int *bone_indices,
        struct vostok::math::float4x4 *phalanges_count,
        const float iterpolation_coeff)
{
  const vostok::math::float4x4 *v5; // ecx
  int v6; // ebx
  int v7; // eax
  unsigned int v8; // edi
  vostok::math::float4x4 v9; // [esp+14h] [ebp-48h] BYREF
  int v10; // [esp+54h] [ebp-8h]
  const vostok::math::float4x4 *v11; // [esp+58h] [ebp-4h]

  v5 = previous_locator_matrices;
  v6 = 0;
  v7 = (char *)locator_matrices - (char *)previous_locator_matrices;
  v11 = previous_locator_matrices;
  v10 = v7;
  while ( 1 )
  {
    vostok::animation::mix_transformations(
      v5,
      (const vostok::math::float4x4 *)((char *)v5 + v7),
      *(float *)&phalanges_count,
      &v9,
      phalanges_count);
    v8 = bone_indices[v6];
    ++v11;
    ++v6;
    qmemcpy((void *)(LODWORD(iterpolation_coeff) + (v8 << 6)), &v9, 0x40u);
    if ( v6 == 15 )
      break;
    v7 = v10;
    v5 = v11;
  }
}


void __usercall vostok::animation::interpolate_hand_matrices(
        const vostok::math::float4x4 *locator_matrices@<eax>,
        const unsigned int *bone_indices,
        struct vostok::math::float4x4 *phalanges_count,
        const float iterpolation_coeff)
{
  int v4; // ebx
  const unsigned int *v5; // edi
  unsigned int v6; // edi
  vostok::math::float4x4 v7; // [esp+10h] [ebp-48h] BYREF
  const vostok::math::float4x4 *v8; // [esp+50h] [ebp-8h]

  v4 = 0;
  v8 = locator_matrices;
  do
  {
    v5 = &bone_indices[v4];
    vostok::animation::mix_transformations(
      v8,
      (const vostok::math::float4x4 *)(LODWORD(iterpolation_coeff) + (*v5 << 6)),
      *(float *)&phalanges_count,
      &v7,
      phalanges_count);
    v6 = *v5;
    ++v8;
    ++v4;
    qmemcpy((void *)(LODWORD(iterpolation_coeff) + (v6 << 6)), &v7, 0x40u);
  }
  while ( v4 != 15 );
}
