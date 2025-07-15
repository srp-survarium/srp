void __userpurge vostok::collision::animated_object::update(
        vostok::collision::animated_object *this@<ecx>,
        _DWORD *a2@<esi>,
        const vostok::math::float4x4 *const bones_matrices_begin,
        const vostok::math::float4x4 *const bones_matrices_end)
{
  unsigned int v4; // ebx
  int v5; // edi
  int v6; // [esp+8h] [ebp-48h]
  bool shouldRecalculateLocalAabb; // [esp+Ch] [ebp-44h]
  btTransform newChildTransform; // [esp+10h] [ebp-40h] BYREF

  v4 = 0;
  if ( (a2[73] - a2[72]) / 108 )
  {
    v6 = 0;
    do
    {
      v5 = a2[75];
      shouldRecalculateLocalAabb = v4 == (a2[73] - a2[72]) / 108 - 1;
      vostok::physics::from_vostok(&bones_matrices_begin[*(_DWORD *)(v6 + a2[72] + 104)], &newChildTransform.m_basis);
      btCompoundShape::updateChildTransform(
        v4,
        &newChildTransform,
        *(btCompoundShape **)(v5 + 52),
        shouldRecalculateLocalAabb);
      v6 += 108;
      ++v4;
    }
    while ( v4 < (a2[73] - a2[72]) / 108 );
  }
}
