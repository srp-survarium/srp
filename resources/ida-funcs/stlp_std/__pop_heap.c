void __usercall stlp_std::__pop_heap<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate,int>(
        vostok::physics::closest_ray_result *__last@<edx>,
        vostok::physics::closest_ray_result *__result@<eax>,
        vostok::physics::closest_ray_result *__first,
        vostok::physics::closest_ray_result __val,
        vostok::physics::distance_predicate __comp)
{
  unsigned int v5; // edx

  *__result = *__first;
  v5 = (int)((unsigned __int64)(1717986919LL * ((char *)__last - (char *)__first)) >> 32) >> 4;
  stlp_std::__adjust_heap<vostok::physics::closest_ray_result *,int,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
    __first,
    0,
    v5 + (v5 >> 31),
    __val,
    __comp);
}


void __usercall stlp_std::__pop_heap<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate,int>(
        vostok::render::grass_patch::sort_info *__last@<edx>,
        vostok::render::grass_patch::sort_info *__result@<eax>,
        vostok::render::grass_patch::sort_info *__first,
        vostok::render::grass_patch::sort_info __val,
        vostok::render::sort_indices_predicate __comp)
{
  __int64 v5; // xmm0_8
  unsigned int v6; // edx
  vostok::render::sort_indices_predicate v7; // [esp-14h] [ebp-14h]

  *(_QWORD *)&__result->position.x = *(_QWORD *)&__first->position.x;
  *(_QWORD *)&__result->position.elements[2] = *(_QWORD *)&__first->position.elements[2];
  v5 = *(_QWORD *)&__comp.m_patch;
  __result->num_indices = __first->num_indices;
  *(_QWORD *)&v7.m_patch = v5;
  *(_QWORD *)&v7.m_view_pos.elements[1] = *(_QWORD *)&__comp.m_view_pos.elements[1];
  v6 = (int)((unsigned __int64)(1717986919LL * ((char *)__last - (char *)__first)) >> 32) >> 3;
  stlp_std::__adjust_heap<vostok::render::grass_patch::sort_info *,int,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
    __first,
    0,
    v6 + (v6 >> 31),
    __val,
    v7);
}


void __usercall stlp_std::__pop_heap<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),int>(
        vostok::math::curve_point<float> *__last@<edx>,
        vostok::math::curve_point<float> *__result@<eax>,
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  unsigned int v5; // edx

  *__result = *__first;
  v5 = (int)((unsigned __int64)(715827883LL * ((char *)__last - (char *)__first)) >> 32) >> 2;
  stlp_std::__adjust_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
    __first,
    0,
    v5 + (v5 >> 31),
    __val,
    __comp);
}


void __usercall stlp_std::__pop_heap<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &),int>(
        vostok::render::custom_config_value *__last@<edx>,
        vostok::render::custom_config_value *__result@<eax>,
        vostok::render::custom_config_value *__first,
        vostok::render::custom_config_value __val,
        bool (__cdecl *__comp)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))
{
  unsigned int v5; // edx

  *__result = *__first;
  v5 = (int)((unsigned __int64)(1717986919LL * ((char *)__last - (char *)__first)) >> 32) >> 3;
  stlp_std::__adjust_heap<vostok::render::custom_config_value *,int,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
    __first,
    0,
    v5 + (v5 >> 31),
    __val,
    __comp);
}


void __usercall stlp_std::__pop_heap<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &),int>(
        vostok::render::shader_constant *__last@<edx>,
        vostok::render::shader_constant *__result@<eax>,
        vostok::render::shader_constant *__first,
        vostok::render::shader_constant __val,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  unsigned int v5; // edx

  if ( __result )
    *__result = *__first;
  v5 = (int)((unsigned __int64)(715827883LL * ((char *)__last - (char *)__first)) >> 32) >> 2;
  stlp_std::__adjust_heap<vostok::render::shader_constant *,int,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
    __first,
    0,
    v5 + (v5 >> 31),
    __val,
    __comp);
}
