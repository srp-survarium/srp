void __thiscall vostok::collision::animated_object::update(
        vostok::collision::animated_object *this,
        vostok::collision::animated_object *bones_matrices_begin,
        const vostok::math::float4x4 *const bones_matrices_end)
{
  float v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // eax
  int v6; // edx
  int childIndex; // [esp+60h] [ebp-50h]
  int i; // [esp+64h] [ebp-4Ch]
  bool shouldRecalculateLocalAabb; // [esp+68h] [ebp-48h]
  float v10; // [esp+6Ch] [ebp-44h]
  btTransform newChildTransform; // [esp+70h] [ebp-40h] BYREF

  v3 = *(float *)&bones_matrices_begin->m_geometries_data.m_begin;
  v4 = 0;
  v5 = bones_matrices_begin->m_geometries_data.m_end - bones_matrices_begin->m_geometries_data.m_begin;
  childIndex = 0;
  if ( v5 )
  {
    v6 = 0;
    for ( i = 0; ; v6 = i )
    {
      if ( bones_matrices_begin->m_geometry )
      {
        (*(void (__thiscall **)(_DWORD, const vostok::math::float4x4 *))(**(_DWORD **)(v6 + LODWORD(v3) + 108) + 4))(
          *(_DWORD *)(v6 + LODWORD(v3) + 108),
          &bones_matrices_end[*(_DWORD *)(v6 + LODWORD(v3) + 104)]);
      }
      else
      {
        shouldRecalculateLocalAabb = v4 == v5 - 1;
        v10 = *(float *)&bones_matrices_begin->m_body;
        vostok::physics::from_vostok(
          &bones_matrices_end[*(_DWORD *)(v6 + LODWORD(v3) + 104)],
          (vostok::math::quaternion *)&newChildTransform);
        btCompoundShape::updateChildTransform(
          childIndex,
          &newChildTransform,
          *(btCompoundShape **)(LODWORD(v10) + 16),
          shouldRecalculateLocalAabb);
        v4 = childIndex;
      }
      v3 = *(float *)&bones_matrices_begin->m_geometries_data.m_begin;
      i += 112;
      ++v4;
      v5 = bones_matrices_begin->m_geometries_data.m_end - bones_matrices_begin->m_geometries_data.m_begin;
      childIndex = v4;
      if ( v4 >= v5 )
        break;
    }
  }
}
