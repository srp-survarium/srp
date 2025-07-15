void __userpurge vostok::animation::hand_to_weapon_ik_solver::activate(
        vostok::animation::hand_to_weapon_ik_solver *this@<ecx>,
        _DWORD *a2@<esi>,
        const vostok::animation::skeleton *item_skeleton)
{
  int bone_index; // eax
  int v4; // ebx
  vostok::animation::skeleton *v5; // ecx
  int v6; // eax
  vostok::animation::skeleton *v7; // ecx
  vostok::animation::skeleton *v8; // ecx
  int v9; // eax
  int v10; // eax

  a2[318] = item_skeleton;
  bone_index = vostok::animation::skeleton::get_bone_index(
                 (vostok::animation::skeleton *)this,
                 (int)item_skeleton,
                 "left_hand_cont");
  v4 = a2[317];
  v5 = (vostok::animation::skeleton *)(bone_index
                                     - (item_skeleton[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                                      - (int)&item_skeleton[1])
                                     / 28);
  a2[153] = v5;
  v6 = vostok::animation::skeleton::get_bone_index(v5, v4, "LeftHand");
  a2[151] = v6;
  v7 = (vostok::animation::skeleton *)(v6 - (*(_DWORD *)(v4 + 280) - (v4 + 272)) / 28);
  a2[152] = v7;
  v8 = (vostok::animation::skeleton *)(vostok::animation::skeleton::get_bone_index(
                                         v7,
                                         (int)item_skeleton,
                                         "right_hand_cont")
                                     - (item_skeleton[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                                      - (int)&item_skeleton[1])
                                     / 28);
  v9 = a2[317];
  a2[310] = v8;
  v10 = vostok::animation::skeleton::get_bone_index(v8, v9, "RightHand");
  a2[308] = v10;
  a2[309] = v10 - (*(_DWORD *)(v4 + 280) - (v4 + 272)) / 28;
}
