void __userpurge survarium::fingers_to_weapon_corrector::initialize_bones_indices(
        survarium::fingers_to_weapon_corrector *this@<ecx>,
        int a2@<eax>,
        const vostok::animation::skeleton *character_skeleton)
{
  const vostok::animation::skeleton_bone *v4; // esi
  _DWORD *v5; // ebx
  bone_id_predicate *v6; // edi
  const char **v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+14h] [ebp-Ch]
  int v9; // [esp+18h] [ebp-8h]
  const vostok::animation::skeleton *character_skeletona; // [esp+24h] [ebp+4h]

  v4 = (const vostok::animation::skeleton_bone *)&character_skeleton[1];
  v7 = s_arm_fingers_phalanges[0];
  character_skeletona = (const vostok::animation::skeleton *)(a2 + 960);
  v9 = 2;
  do
  {
    v5 = &character_skeletona->__vftable;
    v6 = (bone_id_predicate *)v7;
    v8 = 15;
    do
    {
      *v5 = stlp_std::priv::__find_if<vostok::animation::skeleton_bone const *,bone_id_predicate>(
              v4,
              (const vostok::animation::skeleton_bone *)&character_skeleton[1] + character_skeleton->m_bones_count,
              (bone_id_predicate)v6->m_bone_name)
          - v4
          - (v4->m_children_begin
           - v4);
      ++v6;
      ++v5;
      --v8;
    }
    while ( v8 );
    character_skeletona = (const vostok::animation::skeleton *)((char *)character_skeletona + 1028);
    v7 += 16;
    --v9;
  }
  while ( v9 );
}
