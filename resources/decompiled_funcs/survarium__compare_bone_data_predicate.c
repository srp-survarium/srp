bool __cdecl survarium::compare_bone_data_predicate(
        const stlp_std::pair<vostok::collision::bone_collision_data *,float> *lhs,
        const stlp_std::pair<vostok::collision::bone_collision_data *,float> *rhs)
{
  return lhs->first->skeleton_bone_index == rhs->first->skeleton_bone_index;
}
