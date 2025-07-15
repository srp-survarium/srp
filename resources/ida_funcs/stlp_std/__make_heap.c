void __usercall stlp_std::__make_heap<unsigned int *,vostok::render::culling::portal_id_closer_to_point,unsigned int,int>(
        unsigned int *__first@<edi>,
        unsigned int *__last,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  int v3; // ebx
  int v4; // esi
  unsigned int v5; // ecx

  v3 = __last - __first;
  if ( v3 >= 2 )
  {
    v4 = (v3 - 2) / 2;
    stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
      __first,
      v4,
      __last - __first,
      __first[v4],
      __comp);
    while ( v4 )
    {
      v5 = __first[--v4];
      stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        __first,
        v4,
        v3,
        v5,
        __comp);
    }
  }
}


void __usercall stlp_std::__make_heap<unsigned int *,stlp_std::less<unsigned int>,unsigned int,int>(
        unsigned int *__first@<edi>,
        unsigned int *__last,
        stlp_std::less<unsigned int> __comp)
{
  int v3; // ebx
  int v4; // esi
  unsigned int v5; // edx

  v3 = __last - __first;
  if ( v3 >= 2 )
  {
    v4 = (v3 - 2) / 2;
    stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(
      __first,
      v4,
      __last - __first,
      __first[v4],
      __comp);
    while ( v4 )
    {
      v5 = __first[--v4];
      stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(__first, v4, v3, v5, __comp);
    }
  }
}


void __usercall stlp_std::__make_heap<float *,stlp_std::less<float>,float,int>(
        float *__first@<edi>,
        float *__last,
        stlp_std::less<float> __comp)
{
  int v3; // ebx
  int v4; // esi
  double v5; // st7
  float v6; // [esp+0h] [ebp-14h]

  v3 = __last - __first;
  if ( v3 >= 2 )
  {
    v4 = (v3 - 2) / 2;
    stlp_std::__adjust_heap<float *,int,float,stlp_std::less<float>>(__first, v4, __last - __first, __first[v4], __comp);
    while ( v4 )
    {
      v5 = __first[--v4];
      v6 = v5;
      stlp_std::__adjust_heap<float *,int,float,stlp_std::less<float>>(__first, v4, v3, v6, __comp);
    }
  }
}


void __usercall stlp_std::__make_heap<vostok::animation::mixing::animation_state * *,event_iterator_predicate,vostok::animation::mixing::animation_state *,int>(
        vostok::animation::mixing::animation_state **__first@<edi>,
        vostok::animation::mixing::animation_state **__last,
        event_iterator_predicate *a3)
{
  int v3; // ebx
  int v4; // esi
  vostok::animation::mixing::animation_state *v5; // eax

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  stlp_std::__adjust_heap<vostok::animation::mixing::animation_state * *,int,vostok::animation::mixing::animation_state *,event_iterator_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    *a3);
  while ( v4 )
  {
    v5 = __first[--v4];
    stlp_std::__adjust_heap<vostok::animation::mixing::animation_state * *,int,vostok::animation::mixing::animation_state *,event_iterator_predicate>(
      __first,
      v4,
      v3,
      v5,
      *a3);
  }
}


void __usercall stlp_std::__make_heap<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate,vostok::render::grass_patch *,int>(
        vostok::render::grass_patch **__first@<edi>,
        vostok::render::grass_patch **__last,
        int a3)
{
  int v3; // ebp
  int v4; // esi
  vostok::render::grass_patch *v5; // edx
  vostok::render::sort_grass_patch_predicate v6; // [esp-14h] [ebp-18h]
  vostok::render::sort_grass_patch_predicate v7; // [esp-14h] [ebp-18h]

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  *(_QWORD *)&v6.m_view_pos.x = *(_QWORD *)a3;
  v6.m_view_pos.z = *(float *)(a3 + 8);
  stlp_std::__adjust_heap<vostok::render::grass_patch * *,int,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    v6);
  while ( v4 )
  {
    v5 = __first[--v4];
    *(_QWORD *)&v7.m_view_pos.x = *(_QWORD *)a3;
    v7.m_view_pos.z = *(float *)(a3 + 8);
    stlp_std::__adjust_heap<vostok::render::grass_patch * *,int,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
      __first,
      v4,
      v3,
      v5,
      v7);
  }
}


void __usercall stlp_std::__make_heap<vostok::animation::mixing::n_ary_tree_base_node * *,node_predicate,vostok::animation::mixing::n_ary_tree_base_node *,int>(
        vostok::animation::mixing::n_ary_tree_base_node **__first@<edi>,
        vostok::animation::mixing::n_ary_tree_base_node **__last,
        node_predicate *a3)
{
  int v3; // ebx
  int v4; // esi
  vostok::animation::mixing::n_ary_tree_base_node *v5; // eax

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  stlp_std::__adjust_heap<vostok::animation::mixing::n_ary_tree_base_node * *,int,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    *a3);
  while ( v4 )
  {
    v5 = __first[--v4];
    stlp_std::__adjust_heap<vostok::animation::mixing::n_ary_tree_base_node * *,int,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
      __first,
      v4,
      v3,
      v5,
      *a3);
  }
}


void __usercall stlp_std::__make_heap<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate,vostok::render::render_surface_instance *,int>(
        vostok::render::render_surface_instance **__first@<edi>,
        vostok::render::render_surface_instance **__last,
        vostok::render::sort_by_ps_predicate *a3)
{
  int v3; // ebp
  int v4; // esi
  vostok::render::render_surface_instance *v5; // edx

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  stlp_std::__adjust_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    *a3);
  while ( v4 )
  {
    v5 = __first[--v4];
    stlp_std::__adjust_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
      __first,
      v4,
      v3,
      v5,
      *a3);
  }
}


void __usercall stlp_std::__make_heap<vostok::command_line::key * *,vostok::command_line::key_compare_predicate,vostok::command_line::key *,int>(
        vostok::command_line::key **__first@<edi>,
        vostok::command_line::key **__last,
        vostok::command_line::key_compare_predicate *a3)
{
  int v3; // ebx
  int v4; // esi
  vostok::command_line::key *v5; // eax

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  stlp_std::__adjust_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    *a3);
  while ( v4 )
  {
    v5 = __first[--v4];
    stlp_std::__adjust_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
      __first,
      v4,
      v3,
      v5,
      *a3);
  }
}


void __usercall stlp_std::__make_heap<vostok::resources::query_result * *,vostok::resources::hdd_manager_sorting_predicate,vostok::resources::query_result *,int>(
        vostok::resources::query_result **__first@<edi>,
        vostok::resources::query_result **__last,
        vostok::resources::hdd_manager_sorting_predicate *a3)
{
  int v3; // ebx
  int v4; // esi
  vostok::resources::query_result *v5; // eax

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    *a3);
  while ( v4 )
  {
    v5 = __first[--v4];
    stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
      __first,
      v4,
      v3,
      v5,
      *a3);
  }
}


void __usercall stlp_std::__make_heap<vostok::resources::query_result * *,vostok::resources::sorting_predicate,vostok::resources::query_result *,int>(
        vostok::resources::query_result **__first@<edi>,
        vostok::resources::query_result **__last,
        vostok::resources::sorting_predicate *a3)
{
  int v3; // ebx
  int v4; // esi
  vostok::resources::query_result *v5; // eax

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    *a3);
  while ( v4 )
  {
    v5 = __first[--v4];
    stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
      __first,
      v4,
      v3,
      v5,
      *a3);
  }
}


void __usercall stlp_std::__make_heap<vostok::resources::resource_base * *,vostok::resources::sorting_predicate,vostok::resources::resource_base *,int>(
        vostok::resources::resource_base **__first@<edi>,
        vostok::resources::resource_base **__last,
        vostok::resources::sorting_predicate *a3)
{
  int v3; // ebx
  int v4; // esi
  vostok::resources::resource_base *v5; // eax

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  stlp_std::__adjust_heap<vostok::resources::resource_base * *,int,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    *a3);
  while ( v4 )
  {
    v5 = __first[--v4];
    stlp_std::__adjust_heap<vostok::resources::resource_base * *,int,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
      __first,
      v4,
      v3,
      v5,
      *a3);
  }
}


void __usercall stlp_std::__make_heap<char const * *,bool (__cdecl *)(char const *,char const *),char const *,int>(
        const char **__first@<eax>,
        const char **__last,
        bool (__cdecl *__comp)(const char *, const char *))
{
  int v4; // ebx
  int v5; // esi
  const char *v6; // ecx

  v4 = __last - __first;
  v5 = (v4 - 2) / 2;
  stlp_std::__adjust_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
    __first,
    v5,
    v4,
    __first[v5],
    __comp);
  while ( v5 )
  {
    v6 = __first[--v5];
    stlp_std::__adjust_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
      __first,
      v5,
      v4,
      v6,
      __comp);
  }
}


void __usercall stlp_std::__make_heap<char const * *,vostok::render::shader_macros_dort_predicate,char const *,int>(
        const char **__first@<eax>,
        const char **__last,
        vostok::render::shader_macros_dort_predicate *a3)
{
  int v4; // ebx
  int v5; // esi
  const char *v6; // eax

  v4 = __last - __first;
  v5 = (v4 - 2) / 2;
  stlp_std::__adjust_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
    __first,
    v5,
    v4,
    __first[v5],
    *a3);
  while ( v5 )
  {
    v6 = __first[--v5];
    stlp_std::__adjust_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
      __first,
      v5,
      v4,
      v6,
      *a3);
  }
}


void __usercall stlp_std::__make_heap<char const * *,vostok::tips_sorting_predicate,char const *,int>(
        const char **__first@<eax>,
        const char **__last,
        vostok::tips_sorting_predicate *a3)
{
  int v4; // ebx
  int v5; // esi
  const char *v6; // eax

  v4 = __last - __first;
  v5 = (v4 - 2) / 2;
  stlp_std::__adjust_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
    __first,
    v5,
    v4,
    __first[v5],
    (vostok::tips_sorting_predicate)a3->editor_str);
  while ( v5 )
  {
    v6 = __first[--v5];
    stlp_std::__adjust_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
      __first,
      v5,
      v4,
      v6,
      (vostok::tips_sorting_predicate)a3->editor_str);
  }
}


void __usercall stlp_std::__make_heap<void const * *,stlp_std::less<void const *>,void const *,int>(
        const void **__first@<edi>,
        const void **__last,
        stlp_std::less<void const *> __comp)
{
  int v3; // ebx
  int v4; // esi
  const void *v5; // eax

  v3 = __last - __first;
  if ( v3 >= 2 )
  {
    v4 = (v3 - 2) / 2;
    stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(
      (unsigned int *)__first,
      v4,
      __last - __first,
      (unsigned int)__first[v4],
      (stlp_std::less<unsigned int>)__comp.gap0);
    while ( v4 )
    {
      v5 = __first[--v4];
      stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(
        (unsigned int *)__first,
        v4,
        v3,
        (unsigned int)v5,
        (stlp_std::less<unsigned int>)__comp.gap0);
    }
  }
}


void __usercall stlp_std::__make_heap<vostok::animation::bone_name_index *,vostok::animation::bone_names::crc_compare_predicate,vostok::animation::bone_name_index,int>(
        vostok::animation::bone_name_index *__last@<eax>,
        vostok::animation::bone_name_index *__first,
        vostok::animation::bone_names::crc_compare_predicate *a3)
{
  int v3; // ebp
  int v4; // ebx
  vostok::animation::bone_name_index *i; // esi
  vostok::animation::bone_name_index v6; // [esp-4Ch] [ebp-60h] BYREF
  vostok::animation::bone_names::crc_compare_predicate v7; // [esp-4h] [ebp-18h]
  vostok::animation::bone_name_index *v8; // [esp+10h] [ebp-4h]

  v3 = __last - __first;
  v7 = *a3;
  v4 = (v3 - 2) / 2;
  v8 = &__first[v4];
  qmemcpy(&v6, v8, sizeof(v6));
  stlp_std::__adjust_heap<vostok::animation::bone_name_index *,int,vostok::animation::bone_name_index,vostok::animation::bone_names::crc_compare_predicate>(
    __first,
    v4,
    v3,
    v6,
    v7);
  if ( v4 )
  {
    for ( i = v8; ; i = v8 )
    {
      v7 = *a3;
      --v4;
      v8 = i - 1;
      qmemcpy(&v6, &i[-1], sizeof(v6));
      stlp_std::__adjust_heap<vostok::animation::bone_name_index *,int,vostok::animation::bone_name_index,vostok::animation::bone_names::crc_compare_predicate>(
        __first,
        v4,
        v3,
        v6,
        v7);
      if ( !v4 )
        break;
    }
  }
}


void __usercall stlp_std::__make_heap<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate,vostok::physics::closest_ray_result,int>(
        vostok::physics::closest_ray_result *__last@<eax>,
        vostok::physics::closest_ray_result *__first,
        int a3)
{
  int v3; // esi
  int v4; // edi
  vostok::physics::closest_ray_result *v5; // ebx
  __int64 v6; // xmm0_8
  vostok::physics::closest_ray_result v7; // [esp-3Ch] [ebp-44h]
  vostok::physics::distance_predicate v8; // [esp-14h] [ebp-1Ch]
  vostok::physics::distance_predicate v9; // [esp-14h] [ebp-1Ch]

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  v5 = &__first[v4];
  *(_QWORD *)&v8.m_from.x = *(_QWORD *)a3;
  v8.m_from.z = *(float *)(a3 + 8);
  stlp_std::__adjust_heap<vostok::physics::closest_ray_result *,int,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
    __first,
    v4,
    v3,
    *v5,
    v8);
  while ( v4 )
  {
    *(_QWORD *)&v9.m_from.x = *(_QWORD *)a3;
    v6 = *(_QWORD *)&v5[-1].object;
    v9.m_from.z = *(float *)(a3 + 8);
    --v5;
    *(_QWORD *)&v7.object = v6;
    *(_QWORD *)&v7.hit_point_world.elements[1] = *(_QWORD *)&v5->hit_point_world.elements[1];
    *(_QWORD *)&v7.hit_normal_world.x = *(_QWORD *)&v5->hit_normal_world.x;
    *(_QWORD *)&v7.hit_normal_world.elements[2] = *(_QWORD *)&v5->hit_normal_world.elements[2];
    --v4;
    *(_QWORD *)&v7.is_shape_index = *(_QWORD *)&v5->is_shape_index;
    stlp_std::__adjust_heap<vostok::physics::closest_ray_result *,int,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      __first,
      v4,
      v3,
      v7,
      v9);
  }
}


void __usercall stlp_std::__make_heap<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate,vostok::render::grass_patch::sort_info,int>(
        vostok::render::grass_patch::sort_info *__last@<eax>,
        vostok::render::grass_patch::sort_info *__first,
        _QWORD *a3)
{
  int v3; // esi
  int v4; // edi
  vostok::render::grass_patch::sort_info *v5; // ebx
  unsigned int num_indices; // ecx
  __int64 v7; // xmm0_8
  vostok::render::grass_patch::sort_info v8; // [esp-2Ch] [ebp-34h]
  vostok::render::sort_indices_predicate v9; // [esp-18h] [ebp-20h]
  vostok::render::sort_indices_predicate v10; // [esp-18h] [ebp-20h]

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  v5 = &__first[v4];
  *(_QWORD *)&v9.m_patch = *a3;
  *(_QWORD *)&v9.m_view_pos.elements[1] = a3[1];
  stlp_std::__adjust_heap<vostok::render::grass_patch::sort_info *,int,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
    __first,
    v4,
    v3,
    *v5,
    v9);
  while ( v4 )
  {
    num_indices = v5[-1].num_indices;
    *(_QWORD *)&v10.m_patch = *a3;
    *(_QWORD *)&v10.m_view_pos.elements[1] = a3[1];
    v7 = *(_QWORD *)&v5[-1].position.x;
    --v5;
    *(_QWORD *)&v8.position.x = v7;
    *(_QWORD *)&v8.position.elements[2] = *(_QWORD *)&v5->position.elements[2];
    v8.num_indices = num_indices;
    stlp_std::__adjust_heap<vostok::render::grass_patch::sort_info *,int,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
      __first,
      --v4,
      v3,
      v8,
      v10);
  }
}


void __usercall stlp_std::__make_heap<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),vostok::math::curve_point<float>,int>(
        vostok::math::curve_point<float> *__last@<eax>,
        vostok::math::curve_point<float> *__first,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  int v3; // edi
  int v4; // esi
  vostok::math::curve_point<float> *v5; // ebx
  __int64 v6; // xmm0_8
  vostok::math::curve_point<float> v7; // [esp-1Ch] [ebp-2Ch]

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  v5 = &__first[v4];
  stlp_std::__adjust_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
    __first,
    v4,
    v3,
    *v5,
    __comp);
  while ( v4 )
  {
    v6 = *(_QWORD *)&v5[-1].upper_value;
    --v5;
    *(_QWORD *)&v7.upper_value = v6;
    --v4;
    *(_QWORD *)&v7.tangent_in = *(_QWORD *)&v5->tangent_in;
    *(_QWORD *)&v7.time = *(_QWORD *)&v5->time;
    stlp_std::__adjust_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      __first,
      v4,
      v3,
      v7,
      __comp);
  }
}


void __usercall stlp_std::__make_heap<vostok::math::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &),vostok::math::curve_point<vostok::math::float4_pod>,int>(
        vostok::math::curve_point<vostok::math::float4_pod> *__last@<eax>,
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  int v3; // ebp
  int v4; // ebx
  vostok::math::curve_point<vostok::math::float4_pod> *i; // esi
  vostok::math::curve_point<vostok::math::float4_pod> v6; // [esp-4Ch] [ebp-60h] BYREF
  vostok::math::curve_point<vostok::math::float4_pod> *v7; // [esp+10h] [ebp-4h]

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  v7 = &__first[v4];
  qmemcpy(&v6, v7, sizeof(v6));
  stlp_std::__adjust_heap<vostok::math::curve_point<vostok::math::float4_pod> *,int,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
    __first,
    v4,
    v3,
    v6,
    __comp);
  if ( v4 )
  {
    for ( i = v7; ; i = v7 )
    {
      --v4;
      v7 = i - 1;
      qmemcpy(&v6, &i[-1], sizeof(v6));
      stlp_std::__adjust_heap<vostok::math::curve_point<vostok::math::float4_pod> *,int,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        __first,
        v4,
        v3,
        v6,
        __comp);
      if ( !v4 )
        break;
    }
  }
}


void __cdecl stlp_std::__make_heap<stlp_std::pair<vostok::ai::npc const *,float> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &),stlp_std::pair<vostok::ai::npc const *,float>,int>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  _DWORD v3[3]; // [esp-Ch] [ebp-20h] BYREF
  stlp_std::pair<vostok::ai::npc const *,float> *v4; // [esp+0h] [ebp-14h]
  _DWORD *v5; // [esp+4h] [ebp-10h]
  int __parent; // [esp+Ch] [ebp-8h]
  int __len; // [esp+10h] [ebp-4h]

  if ( __last - __first >= 2 )
  {
    __len = __last - __first;
    for ( __parent = (__len - 2) / 2; ; --__parent )
    {
      v3[2] = __comp;
      v4 = &__first[__parent];
      v5 = v3;
      stlp_std::__adjust_heap<stlp_std::pair<vostok::ai::npc const *,float> *,int,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        __first,
        __parent,
        __len,
        *v4,
        __comp);
      if ( !__parent )
        break;
    }
  }
}


void __cdecl stlp_std::__make_heap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &),stlp_std::pair<vostok::ai::weapon const *,unsigned int>,int>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  _DWORD v3[3]; // [esp-Ch] [ebp-20h] BYREF
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *v4; // [esp+0h] [ebp-14h]
  _DWORD *v5; // [esp+4h] [ebp-10h]
  int __parent; // [esp+Ch] [ebp-8h]
  int __len; // [esp+10h] [ebp-4h]

  if ( __last - __first >= 2 )
  {
    __len = __last - __first;
    for ( __parent = (__len - 2) / 2; ; --__parent )
    {
      v3[2] = __comp;
      v4 = &__first[__parent];
      v5 = v3;
      stlp_std::__adjust_heap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,int,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        __first,
        __parent,
        __len,
        *v4,
        __comp);
      if ( !__parent )
        break;
    }
  }
}


void __usercall stlp_std::__make_heap<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &),vostok::render::custom_config_value,int>(
        vostok::render::custom_config_value *__last@<eax>,
        vostok::render::custom_config_value *__first,
        bool (__cdecl *__comp)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))
{
  int v3; // edi
  int v4; // esi
  vostok::render::custom_config_value *v5; // ebx
  __int64 v6; // xmm0_8
  const void *destroyer; // ecx
  vostok::render::custom_config_value v8; // [esp-18h] [ebp-28h]

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  v5 = &__first[v4];
  stlp_std::__adjust_heap<vostok::render::custom_config_value *,int,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
    __first,
    v4,
    v3,
    *v5,
    __comp);
  while ( v4 )
  {
    v6 = *(_QWORD *)&v5[-1].id;
    destroyer = v5[-1].destroyer;
    --v5;
    *(_QWORD *)&v8.id = v6;
    *(_QWORD *)&v8.id_crc = *(_QWORD *)&v5->id_crc;
    --v4;
    v8.destroyer = destroyer;
    stlp_std::__adjust_heap<vostok::render::custom_config_value *,int,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      __first,
      v4,
      v3,
      v8,
      __comp);
  }
}


void __usercall stlp_std::__make_heap<vostok::render::shader_constant *,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &),vostok::render::shader_constant,int>(
        vostok::render::shader_constant *__last@<eax>,
        vostok::render::shader_constant *__first,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  int v3; // ebx
  int v4; // edi
  vostok::render::shader_constant_source *i; // esi
  vostok::render::shader_constant v6; // [esp-1Ch] [ebp-2Ch]

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  for ( i = &__first[v4].m_source; ; i -= 3 )
  {
    v6.m_slot = (vostok::render::shader_constant_slot)i[-1];
    v6.m_source.m_pointer = i->m_pointer;
    v6.m_source.m_size = i->m_size;
    v6.m_host = (const vostok::render::shader_constant_host *)i[1].m_pointer;
    stlp_std::__adjust_heap<vostok::render::shader_constant *,int,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      __first,
      v4,
      v3,
      v6,
      __comp);
    if ( !v4 )
      break;
    --v4;
  }
}
