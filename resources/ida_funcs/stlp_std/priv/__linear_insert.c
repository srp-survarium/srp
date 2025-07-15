void __usercall stlp_std::priv::__linear_insert<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<edi>,
        vostok::render::grass_patch **__last@<edx>,
        vostok::render::grass_patch *__val@<eax>,
        vostok::render::sort_grass_patch_predicate __comp)
{
  if ( (float)((float)((float)((float)((*__first)->m_origin.z - __comp.m_view_pos.z)
                             * (float)((*__first)->m_origin.z - __comp.m_view_pos.z))
                     + (float)((float)((*__first)->m_origin.y - __comp.m_view_pos.y)
                             * (float)((*__first)->m_origin.y - __comp.m_view_pos.y)))
             + (float)((float)((*__first)->m_origin.x - __comp.m_view_pos.x)
                     * (float)((*__first)->m_origin.x - __comp.m_view_pos.x))) <= (float)((float)((float)((float)(__val->m_origin.z - __comp.m_view_pos.z) * (float)(__val->m_origin.z - __comp.m_view_pos.z))
                                                                                                + (float)((float)(__val->m_origin.y - __comp.m_view_pos.y) * (float)(__val->m_origin.y - __comp.m_view_pos.y)))
                                                                                        + (float)((float)(__val->m_origin.x - __comp.m_view_pos.x)
                                                                                                * (float)(__val->m_origin.x - __comp.m_view_pos.x))) )
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
      __last,
      __val,
      __comp);
  }
  else
  {
    if ( (char *)__last - (char *)__first > 0 )
      memmove((unsigned __int8 *)__first + 4, (unsigned __int8 *)__first, (char *)__last - (char *)__first);
    *__first = __val;
  }
}


void __usercall stlp_std::priv::__linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        const char **__first@<edi>,
        const char **__last@<eax>,
        const char *__val)
{
  bool (__cdecl *v4)(const char *, const char *); // [esp+0h] [ebp-8h]

  if ( strcmp(__val, *__first) == -1 )
  {
    if ( (char *)__last - (char *)__first > 0 )
      memmove((unsigned __int8 *)__first + 4, (unsigned __int8 *)__first, (char *)__last - (char *)__first);
    *__first = __val;
  }
  else
  {
    stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
      __last,
      __val,
      v4);
  }
}


void __usercall stlp_std::priv::__linear_insert<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
        const char **__first@<edi>,
        const char **__last@<eax>,
        const char *__val,
        vostok::render::shader_macros_dort_predicate __comp)
{
  if ( strcmp(__val, *__first) >= 0 )
  {
    stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
      __last,
      __val,
      __comp);
  }
  else
  {
    if ( (char *)__last - (char *)__first > 0 )
      memmove((unsigned __int8 *)__first + 4, (unsigned __int8 *)__first, (char *)__last - (char *)__first);
    *__first = __val;
  }
}


void __usercall stlp_std::priv::__linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
        const char **__last@<eax>,
        const char **__first,
        char *__val,
        vostok::tips_sorting_predicate __comp)
{
  unsigned __int8 *v4; // ebx
  int v6; // eax
  int v7; // esi
  int v8; // eax

  v4 = (unsigned __int8 *)*__first;
  strstr((unsigned __int8 *)__val, (unsigned __int8 *)__comp.editor_str);
  v7 = v6;
  strstr(v4, (unsigned __int8 *)__comp.editor_str);
  if ( v7 - (int)__val >= v8 - (int)v4 )
  {
    stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
      __last,
      __val,
      __comp);
  }
  else
  {
    if ( (char *)__last - (char *)__first > 0 )
      memmove((unsigned __int8 *)__first + 4, (unsigned __int8 *)__first, (char *)__last - (char *)__first);
    *__first = __val;
  }
}


void __usercall stlp_std::priv::__linear_insert<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<esi>,
        vostok::physics::closest_ray_result *__last@<ecx>,
        vostok::physics::closest_ray_result __val,
        vostok::physics::distance_predicate __comp)
{
  if ( (float)((float)((float)((float)(__first->hit_point_world.z - __comp.m_from.z)
                             * (float)(__first->hit_point_world.z - __comp.m_from.z))
                     + (float)((float)(__first->hit_point_world.y - __comp.m_from.y)
                             * (float)(__first->hit_point_world.y - __comp.m_from.y)))
             + (float)((float)(__first->hit_point_world.x - __comp.m_from.x)
                     * (float)(__first->hit_point_world.x - __comp.m_from.x))) <= (float)((float)((float)((float)(__val.hit_point_world.z - __comp.m_from.z) * (float)(__val.hit_point_world.z - __comp.m_from.z))
                                                                                                + (float)((float)(__val.hit_point_world.y - __comp.m_from.y) * (float)(__val.hit_point_world.y - __comp.m_from.y)))
                                                                                        + (float)((float)(__val.hit_point_world.x - __comp.m_from.x)
                                                                                                * (float)(__val.hit_point_world.x - __comp.m_from.x))) )
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      __last,
      __val,
      __comp);
  }
  else
  {
    if ( (char *)__last - (char *)__first > 0 )
      memmove((unsigned __int8 *)&__first[1], (unsigned __int8 *)__first, (char *)__last - (char *)__first);
    *__first = __val;
  }
}


void __usercall stlp_std::priv::__linear_insert<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<esi>,
        vostok::render::grass_patch::sort_info *__last@<ecx>,
        vostok::render::grass_patch::sort_info __val,
        vostok::render::sort_indices_predicate __comp)
{
  unsigned int num_indices; // eax

  if ( (float)((float)((float)((float)(__first->position.z - __comp.m_view_pos.z)
                             * (float)(__first->position.z - __comp.m_view_pos.z))
                     + (float)((float)(__first->position.y - __comp.m_view_pos.y)
                             * (float)(__first->position.y - __comp.m_view_pos.y)))
             + (float)((float)(__first->position.x - __comp.m_view_pos.x)
                     * (float)(__first->position.x - __comp.m_view_pos.x))) <= (float)((float)((float)((float)(__val.position.z - __comp.m_view_pos.z) * (float)(__val.position.z - __comp.m_view_pos.z))
                                                                                             + (float)((float)(__val.position.y - __comp.m_view_pos.y) * (float)(__val.position.y - __comp.m_view_pos.y)))
                                                                                     + (float)((float)(__val.position.x - __comp.m_view_pos.x)
                                                                                             * (float)(__val.position.x - __comp.m_view_pos.x))) )
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
      __last,
      __val,
      __comp);
  }
  else
  {
    if ( (char *)__last - (char *)__first > 0 )
      memmove((unsigned __int8 *)&__first[1], (unsigned __int8 *)__first, (char *)__last - (char *)__first);
    num_indices = __val.num_indices;
    *(_QWORD *)&__first->position.x = *(_QWORD *)&__val.position.x;
    *(_QWORD *)&__first->position.elements[2] = *(_QWORD *)&__val.position.elements[2];
    __first->num_indices = num_indices;
  }
}


void __usercall stlp_std::priv::__linear_insert<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first@<edi>,
        vostok::math::curve_point<float> *__last@<eax>,
        vostok::math::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  bool (__cdecl *v4)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *); // ebx

  v4 = __comp;
  if ( ((unsigned __int8 (__cdecl *)(vostok::math::curve_point<float> *))__comp)(&__val) )
  {
    if ( (char *)__last - (char *)__first > 0 )
      memmove((unsigned __int8 *)&__first[1], (unsigned __int8 *)__first, (char *)__last - (char *)__first);
    *__first = __val;
  }
  else
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      __last,
      __val,
      v4);
  }
}


void __cdecl stlp_std::priv::__linear_insert<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        stlp_std::pair<vostok::ai::npc const *,float> __val,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  _DWORD v4[8]; // [esp-Ch] [ebp-20h] BYREF

  if ( __comp(&__val, __first) )
  {
    stlp_std::copy_backward<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int> *>(
      (vostok::particle::curve_point<vostok::math::float4_pod> *)__first,
      (vostok::particle::curve_point<vostok::math::float4_pod> *)__last,
      (vostok::particle::curve_point<vostok::math::float4_pod> *)&__last[1]);
    *__first = __val;
  }
  else
  {
    v4[3] = v4;
    stlp_std::priv::__unguarded_linear_insert<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
      (stlp_std::pair<vostok::ai::weapon const *,unsigned int> *)__last,
      (stlp_std::pair<vostok::ai::weapon const *,unsigned int>)__val,
      (bool (__cdecl *)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))__comp);
  }
}


void __cdecl stlp_std::priv::__linear_insert<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> __val,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  _DWORD v4[8]; // [esp-Ch] [ebp-20h] BYREF

  if ( __comp(&__val, __first) )
  {
    stlp_std::copy_backward<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int> *>(
      (vostok::particle::curve_point<vostok::math::float4_pod> *)__first,
      (vostok::particle::curve_point<vostok::math::float4_pod> *)__last,
      (vostok::particle::curve_point<vostok::math::float4_pod> *)&__last[1]);
    *__first = __val;
  }
  else
  {
    v4[3] = v4;
    stlp_std::priv::__unguarded_linear_insert<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
      __last,
      __val,
      __comp);
  }
}
