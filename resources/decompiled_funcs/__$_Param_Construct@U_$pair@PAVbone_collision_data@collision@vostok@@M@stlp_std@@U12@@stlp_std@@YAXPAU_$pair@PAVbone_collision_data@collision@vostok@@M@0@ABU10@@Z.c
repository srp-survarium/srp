void __cdecl stlp_std::_Param_Construct<stlp_std::pair<vostok::collision::bone_collision_data *,float>,stlp_std::pair<vostok::collision::bone_collision_data *,float>>(
        stlp_std::pair<vostok::collision::bone_collision_data *,float> *__p,
        const stlp_std::pair<vostok::collision::bone_collision_data *,float> *__val)
{
  stlp_std::pair<vostok::collision::bone_collision_data *,float> *v2; // [esp+4h] [ebp-8h]

  v2 = (stlp_std::pair<vostok::collision::bone_collision_data *,float> *)operator new(8u, __p);
  if ( v2 )
    *v2 = *__val;
}
