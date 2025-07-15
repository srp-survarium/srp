void __cdecl survarium::interpolate_hand_matrices(
        const vostok::math::float4x4 *locator_matrices,
        const unsigned int *bone_indices,
        float phalanges_count,
        const float iterpolation_coeff)
{
  int i; // ebx
  void *v6; // edi
  _BYTE v7[68]; // [esp+14h] [ebp-44h] BYREF

  for ( i = 0; i != 15; ++i )
  {
    survarium::mix_transformations(
      locator_matrices,
      (const vostok::math::float4x4 *)(LODWORD(iterpolation_coeff) + (bone_indices[i] << 6)),
      (int)v7,
      phalanges_count,
      phalanges_count);
    v6 = (void *)(LODWORD(iterpolation_coeff) + (bone_indices[i] << 6));
    ++locator_matrices;
    qmemcpy(v6, v7, 0x40u);
  }
}
