void __userpurge vostok::animation::legs_ik_solver::leg_params::set_user(
        vostok::animation::legs_ik_solver::leg_params *this@<ecx>,
        int *a2@<esi>,
        const vostok::animation::skeleton *skeleton,
        char *foot_bone_name)
{
  int bone_index; // eax

  bone_index = vostok::animation::skeleton::get_bone_index(
                 (vostok::animation::skeleton *)this,
                 (int)skeleton,
                 foot_bone_name);
  *a2 = 28 * bone_index / 28;
  a2[1] = (*((_DWORD *)&skeleton[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
           + 7 * bone_index)
         - (int)skeleton
         - 272)
        / 28;
  a2[2] = (signed int)(*(&skeleton[1].type + 7 * bone_index) - (int)skeleton - 272) / 28;
  a2[3] = (*(_DWORD *)(*(&skeleton[1].type + 7 * bone_index) + 4) - (int)skeleton - 272) / 28;
  a2[4] = (*(_DWORD *)(*(_DWORD *)(*(&skeleton[1].type + 7 * bone_index) + 4) + 4) - (int)skeleton - 272) / 28;
}
