void __userpurge vostok::animation::fingers_to_weapon_corrector::initialize_bones_indices(
        vostok::animation::fingers_to_weapon_corrector *this@<ecx>,
        int a2@<eax>,
        const vostok::animation::skeleton *character_skeleton)
{
  char **v3; // edi
  int bone_index; // eax
  vostok::animation::fingers_to_weapon_corrector **v5; // eax
  bool v6; // zf
  int v7; // [esp+Ch] [ebp-14h]
  int v8; // [esp+10h] [ebp-10h]
  const char **v9; // [esp+14h] [ebp-Ch]
  vostok::animation::fingers_to_weapon_corrector **v10; // [esp+18h] [ebp-8h]
  vostok::animation::fingers_to_weapon_corrector **v11; // [esp+1Ch] [ebp-4h]

  v9 = s_arm_fingers_phalanges[0];
  v10 = (vostok::animation::fingers_to_weapon_corrector **)(a2 + 2880);
  v7 = 2;
  do
  {
    v3 = (char **)v9;
    v11 = v10;
    v8 = 15;
    do
    {
      bone_index = vostok::animation::skeleton::get_bone_index(
                     (vostok::animation::skeleton *)this,
                     (int)character_skeleton,
                     *v3++);
      this = (vostok::animation::fingers_to_weapon_corrector *)(bone_index
                                                              - (character_skeleton[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                                                               - (int)&character_skeleton[1])
                                                              / 28);
      v5 = v11++;
      v6 = v8-- == 1;
      *v5 = this;
    }
    while ( !v6 );
    v10 += 739;
    v9 += 16;
    --v7;
  }
  while ( v7 );
}
