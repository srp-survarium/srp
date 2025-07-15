void __usercall stlp_std::sort_heap<unsigned int *,vostok::render::culling::portal_id_closer_to_point>(
        char *__first@<esi>,
        char *__last@<eax>,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  int v3; // eax
  unsigned int v4; // ecx
  int v5; // edi

  v3 = __last - __first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(_DWORD *)&__first[v3 - 4];
      *(_DWORD *)&__first[v3 - 4] = *(_DWORD *)__first;
      v5 = v3 - 4;
      stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        (unsigned int *)__first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<unsigned int *,stlp_std::less<unsigned int>>(
        char *__first@<esi>,
        char *__last@<eax>,
        stlp_std::less<unsigned int> __comp)
{
  int v3; // eax
  unsigned int v4; // ecx
  int v5; // edi

  v3 = __last - __first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(_DWORD *)&__first[v3 - 4];
      *(_DWORD *)&__first[v3 - 4] = *(_DWORD *)__first;
      v5 = v3 - 4;
      stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(
        (unsigned int *)__first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<float *,stlp_std::less<float>>(
        float *__first@<esi>,
        float *__last@<eax>,
        stlp_std::less<float> __comp)
{
  int v3; // eax
  double v4; // st7
  int v5; // edi
  float __val; // [esp+0h] [ebp-10h]

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(float *)((char *)__first + v3 - 4);
      *(float *)((char *)__first + v3 - 4) = *__first;
      v5 = v3 - 4;
      __val = v4;
      stlp_std::__adjust_heap<float *,int,float,stlp_std::less<float>>(__first, 0, (v3 - 4) >> 2, __val, __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<vostok::animation::mixing::animation_state * *,event_iterator_predicate>(
        vostok::animation::mixing::animation_state **__first@<esi>,
        vostok::animation::mixing::animation_state **__last@<eax>,
        event_iterator_predicate __comp)
{
  int v3; // eax
  vostok::animation::mixing::animation_state *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::animation::mixing::animation_state **)((char *)__first + v3 - 4);
      v5 = v3 - 4;
      *(vostok::animation::mixing::animation_state **)((char *)__first + v3 - 4) = *__first;
      stlp_std::__adjust_heap<vostok::animation::mixing::animation_state * *,int,vostok::animation::mixing::animation_state *,event_iterator_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<esi>,
        vostok::render::grass_patch **__last@<eax>,
        vostok::render::sort_grass_patch_predicate __comp)
{
  int v3; // eax
  vostok::render::grass_patch *v4; // ecx
  __int64 v5; // xmm0_8
  int v6; // edi
  vostok::render::sort_grass_patch_predicate v7; // [esp-Ch] [ebp-10h]

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::render::grass_patch **)((char *)__first + v3 - 4);
      v5 = *(_QWORD *)&__comp.m_view_pos.x;
      *(vostok::render::grass_patch **)((char *)__first + v3 - 4) = *__first;
      v6 = v3 - 4;
      *(_QWORD *)&v7.m_view_pos.x = v5;
      v7.m_view_pos.z = __comp.m_view_pos.z;
      stlp_std::__adjust_heap<vostok::render::grass_patch * *,int,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        v7);
      v3 = v6;
    }
    while ( (int)(v6 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<vostok::animation::mixing::n_ary_tree_base_node * *,node_predicate>(
        vostok::animation::mixing::n_ary_tree_base_node **__first@<esi>,
        vostok::animation::mixing::n_ary_tree_base_node **__last@<eax>,
        node_predicate __comp)
{
  int v3; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::animation::mixing::n_ary_tree_base_node **)((char *)__first + v3 - 4);
      v5 = v3 - 4;
      *(vostok::animation::mixing::n_ary_tree_base_node **)((char *)__first + v3 - 4) = *__first;
      stlp_std::__adjust_heap<vostok::animation::mixing::n_ary_tree_base_node * *,int,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<vostok::render::render_surface_instance * *,vostok::render::sort_by_distance_predicate>(
        vostok::render::render_surface_instance **__first@<esi>,
        vostok::render::render_surface_instance **__last@<eax>,
        vostok::render::sort_by_distance_predicate __comp)
{
  int v3; // eax
  vostok::render::render_surface_instance *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::render::render_surface_instance **)((char *)__first + v3 - 4);
      *(vostok::render::render_surface_instance **)((char *)__first + v3 - 4) = *__first;
      v5 = v3 - 4;
      stlp_std::__adjust_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_distance_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<vostok::render::render_surface_instance * *,vostok::render::sort_by_texture_predicate>(
        vostok::render::render_surface_instance **__first@<esi>,
        vostok::render::render_surface_instance **__last@<eax>,
        vostok::render::sort_by_texture_predicate __comp)
{
  int v3; // eax
  vostok::render::render_surface_instance *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::render::render_surface_instance **)((char *)__first + v3 - 4);
      *(vostok::render::render_surface_instance **)((char *)__first + v3 - 4) = *__first;
      v5 = v3 - 4;
      stlp_std::__adjust_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_texture_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate>(
        vostok::render::render_surface_instance **__first@<esi>,
        vostok::render::render_surface_instance **__last@<eax>,
        vostok::render::sort_by_ps_predicate __comp)
{
  int v3; // eax
  vostok::render::render_surface_instance *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::render::render_surface_instance **)((char *)__first + v3 - 4);
      *(vostok::render::render_surface_instance **)((char *)__first + v3 - 4) = *__first;
      v5 = v3 - 4;
      stlp_std::__adjust_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<vostok::console_commands::console_command * *,vostok::console_commands::starts_from_predicate>(
        vostok::console_commands::console_command **__first@<esi>,
        vostok::console_commands::console_command **__last@<eax>,
        vostok::console_commands::starts_from_predicate __comp)
{
  int v3; // eax
  vostok::console_commands::console_command *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::console_commands::console_command **)((char *)__first + v3 - 4);
      *(vostok::console_commands::console_command **)((char *)__first + v3 - 4) = *__first;
      v5 = v3 - 4;
      stlp_std::__adjust_heap<vostok::console_commands::console_command * *,int,vostok::console_commands::console_command *,vostok::console_commands::starts_from_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<vostok::command_line::key * *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key **__first@<esi>,
        vostok::command_line::key **__last@<eax>,
        vostok::command_line::key_compare_predicate __comp)
{
  int v3; // eax
  vostok::command_line::key *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::command_line::key **)((char *)__first + v3 - 4);
      v5 = v3 - 4;
      *(vostok::command_line::key **)((char *)__first + v3 - 4) = *__first;
      stlp_std::__adjust_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<vostok::resources::query_result * *,vostok::resources::hdd_manager_sorting_predicate>(
        vostok::resources::query_result **__first@<esi>,
        vostok::resources::query_result **__last@<eax>,
        vostok::resources::hdd_manager_sorting_predicate __comp)
{
  int v3; // eax
  vostok::resources::query_result *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::resources::query_result **)((char *)__first + v3 - 4);
      v5 = v3 - 4;
      *(vostok::resources::query_result **)((char *)__first + v3 - 4) = *__first;
      stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<vostok::resources::query_result * *,vostok::resources::sorting_predicate>(
        vostok::resources::query_result **__first@<esi>,
        vostok::resources::query_result **__last@<eax>,
        vostok::resources::sorting_predicate __comp)
{
  int v3; // eax
  vostok::resources::query_result *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::resources::query_result **)((char *)__first + v3 - 4);
      *(vostok::resources::query_result **)((char *)__first + v3 - 4) = *__first;
      v5 = v3 - 4;
      stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<vostok::resources::resource_base * *,vostok::resources::sorting_predicate>(
        vostok::resources::resource_base **__first@<esi>,
        vostok::resources::resource_base **__last@<eax>,
        vostok::resources::sorting_predicate __comp)
{
  int v3; // eax
  vostok::resources::resource_base *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::resources::resource_base **)((char *)__first + v3 - 4);
      v5 = v3 - 4;
      *(vostok::resources::resource_base **)((char *)__first + v3 - 4) = *__first;
      stlp_std::__adjust_heap<vostok::resources::resource_base * *,int,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<char const * *,bool (__cdecl *)(char const *,char const *)>(
        const char **__first@<ecx>,
        const char **__last@<eax>,
        bool (__cdecl *__comp)(const char *, const char *))
{
  int v4; // eax
  const char *v5; // ecx
  int v6; // esi

  v4 = (char *)__last - (char *)__first;
  if ( (int)(v4 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v5 = *(const char **)((char *)__first + v4 - 4);
      v6 = v4 - 4;
      *(const char **)((char *)__first + v4 - 4) = *__first;
      stlp_std::__adjust_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
        __first,
        0,
        (v4 - 4) >> 2,
        v5,
        __comp);
      v4 = v6;
    }
    while ( (int)(v6 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<char const * *,vostok::render::shader_macros_dort_predicate>(
        const char **__first@<ecx>,
        const char **__last@<eax>,
        vostok::render::shader_macros_dort_predicate __comp)
{
  int v4; // eax
  const char *v5; // ecx
  int v6; // esi

  v4 = (char *)__last - (char *)__first;
  if ( (int)(v4 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v5 = *(const char **)((char *)__first + v4 - 4);
      v6 = v4 - 4;
      *(const char **)((char *)__first + v4 - 4) = *__first;
      stlp_std::__adjust_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
        __first,
        0,
        (v4 - 4) >> 2,
        v5,
        __comp);
      v4 = v6;
    }
    while ( (int)(v6 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<char const * *,vostok::tips_sorting_predicate>(
        const char **__first@<ecx>,
        const char **__last@<eax>,
        vostok::tips_sorting_predicate __comp)
{
  int v4; // eax
  const char *v5; // ecx
  int v6; // esi

  v4 = (char *)__last - (char *)__first;
  if ( (int)(v4 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v5 = *(const char **)((char *)__first + v4 - 4);
      v6 = v4 - 4;
      *(const char **)((char *)__first + v4 - 4) = *__first;
      stlp_std::__adjust_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
        __first,
        0,
        (v4 - 4) >> 2,
        v5,
        __comp);
      v4 = v6;
    }
    while ( (int)(v6 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::sort_heap<void const * *,stlp_std::less<void const *>>(
        const void **__first@<esi>,
        const void **__last@<eax>,
        stlp_std::less<void const *> __comp)
{
  int v3; // eax
  unsigned int v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(unsigned int *)((char *)__first + v3 - 4);
      *(const void **)((char *)__first + v3 - 4) = *__first;
      v5 = v3 - 4;
      stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(
        (unsigned int *)__first,
        0,
        (v3 - 4) >> 2,
        v4,
        (stlp_std::less<unsigned int>)__comp.gap0);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}


void __cdecl stlp_std::sort_heap<vostok::animation::bone_name_index *,vostok::animation::bone_names::crc_compare_predicate>(
        vostok::animation::bone_name_index *__first,
        vostok::animation::bone_name_index *__last,
        vostok::animation::bone_names::crc_compare_predicate __comp)
{
  int i; // ebx
  char *v4; // eax
  vostok::animation::bone_name_index v5; // [esp-4Ch] [ebp-A4h] BYREF
  vostok::animation::bone_names::crc_compare_predicate v6; // [esp-4h] [ebp-5Ch]
  _BYTE v7[72]; // [esp+10h] [ebp-48h] BYREF

  for ( i = (char *)__last - (char *)__first;
        i / 72 > 1;
        stlp_std::__adjust_heap<vostok::animation::bone_name_index *,int,vostok::animation::bone_name_index,vostok::animation::bone_names::crc_compare_predicate>(
          __first,
          0,
          i / 72,
          v5,
          v6) )
  {
    v4 = &__first[-1].name[i];
    v6 = __comp;
    qmemcpy(v7, v4, sizeof(v7));
    i -= 72;
    qmemcpy(v4, __first, 0x48u);
    qmemcpy(&v5, v7, sizeof(v5));
  }
}


void __usercall stlp_std::sort_heap<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<edi>,
        vostok::physics::closest_ray_result *__last@<eax>,
        vostok::physics::distance_predicate __comp)
{
  vostok::physics::closest_ray_result *v3; // esi

  if ( __last - __first > 1 )
  {
    v3 = __last - 1;
    do
    {
      stlp_std::__pop_heap<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate,int>(
        v3,
        v3,
        __first,
        *v3,
        __comp);
      --v3;
    }
    while ( ((int)v3 + 40 - (int)__first) / 40 > 1 );
  }
}


void __usercall stlp_std::sort_heap<vostok::collision::ray_object_result *,vostok::collision::colliders::object::distance_predicate>(
        vostok::collision::ray_object_result *__first@<esi>,
        vostok::collision::ray_object_result *__last@<eax>,
        unsigned int __comp)
{
  int v3; // eax
  unsigned int v4; // ecx
  int v5; // edi
  int v6; // [esp-4h] [ebp-Ch]

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFF8) > 8 )
  {
    do
    {
      v4 = *(unsigned int *)((char *)&__first[-1].object + v3);
      v6 = *(_DWORD *)((char *)__first + v3 - 4);
      *(vostok::collision::ray_object_result *)((char *)__first + v3 - 8) = *__first;
      v5 = v3 - 8;
      stlp_std::__adjust_heap<vostok::collision::ray_object_result *,int,vostok::collision::ray_object_result,vostok::collision::colliders::object::distance_predicate>(
        __first,
        0,
        (v3 - 8) >> 3,
        (vostok::collision::ray_object_result)__PAIR64__(v4, __comp),
        (vostok::collision::colliders::object::distance_predicate)v6);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFF8) > 8 );
  }
}


void __usercall stlp_std::sort_heap<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<edi>,
        vostok::render::grass_patch::sort_info *__last@<eax>,
        vostok::render::sort_indices_predicate __comp)
{
  vostok::render::grass_patch::sort_info *v3; // esi

  if ( __last - __first > 1 )
  {
    v3 = __last - 1;
    do
    {
      stlp_std::__pop_heap<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate,int>(
        v3,
        v3,
        __first,
        *v3,
        __comp);
      --v3;
    }
    while ( ((int)v3 + 20 - (int)__first) / 20 > 1 );
  }
}


void __usercall stlp_std::sort_heap<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first@<edi>,
        vostok::math::curve_point<float> *__last@<eax>,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  vostok::math::curve_point<float> *v3; // esi

  if ( __last - __first > 1 )
  {
    v3 = __last - 1;
    do
    {
      stlp_std::__pop_heap<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),int>(
        v3,
        v3,
        __first,
        *v3,
        __comp);
      --v3;
    }
    while ( ((int)v3 + 24 - (int)__first) / 24 > 1 );
  }
}


void __cdecl stlp_std::sort_heap<vostok::math::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        vostok::math::curve_point<vostok::math::float4_pod> *__last,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  int i; // ebx
  char *v4; // edi
  vostok::math::curve_point<vostok::math::float4_pod> v5; // [esp-4Ch] [ebp-A4h] BYREF
  bool (__cdecl *v6)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *); // [esp-4h] [ebp-5Ch]
  _BYTE v7[72]; // [esp+10h] [ebp-48h] BYREF

  for ( i = (char *)__last - (char *)__first;
        i / 72 > 1;
        stlp_std::__adjust_heap<vostok::math::curve_point<vostok::math::float4_pod> *,int,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
          __first,
          0,
          i / 72,
          v5,
          v6) )
  {
    v6 = __comp;
    qmemcpy(v7, (char *)&__first[-1] + i, sizeof(v7));
    v4 = (char *)&__first[-1] + i;
    i -= 72;
    qmemcpy(v4, __first, 0x48u);
    qmemcpy(&v5, v7, sizeof(v5));
  }
}


void __usercall stlp_std::sort_heap<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value *__first@<esi>,
        vostok::render::custom_config_value *__last@<ecx>,
        bool (__cdecl *__comp)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))
{
  int v3; // ecx
  const void *v4; // edx
  __int64 v5; // xmm0_8
  __int64 v6; // xmm1_8
  int v7; // edi
  vostok::render::custom_config_value v8; // [esp-18h] [ebp-20h]

  v3 = (char *)__last - (char *)__first;
  if ( v3 / 20 > 1 )
  {
    do
    {
      v4 = *(const void **)((char *)__first + v3 - 4);
      v5 = *(_QWORD *)((char *)&__first[-1].id + v3);
      v6 = *(_QWORD *)((char *)__first + v3 - 12);
      *(vostok::render::custom_config_value *)((char *)__first + v3 - 20) = *__first;
      *(_QWORD *)&v8.id = v5;
      *(_QWORD *)&v8.id_crc = v6;
      v8.destroyer = v4;
      v7 = v3 - 20;
      stlp_std::__adjust_heap<vostok::render::custom_config_value *,int,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        __first,
        0,
        (v3 - 20) / 20,
        v8,
        __comp);
      v3 = v7;
    }
    while ( v7 / 20 > 1 );
  }
}


void __usercall stlp_std::sort_heap<vostok::render::shader_constant *,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first@<edi>,
        vostok::render::shader_constant *__last@<eax>,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  vostok::render::shader_constant *v3; // esi
  vostok::render::shader_constant v4; // [esp-1Ch] [ebp-28h]

  if ( __last - __first > 1 )
  {
    v3 = __last - 1;
    do
    {
      v4.m_slot.m_value = v3->m_slot.m_value;
      v4.m_source.m_pointer = v3->m_source.m_pointer;
      v4.m_source.m_size = v3->m_source.m_size;
      v4.m_host = v3->m_host;
      stlp_std::__pop_heap<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &),int>(
        v3,
        v3,
        __first,
        v4,
        __comp);
      --v3;
    }
    while ( ((int)v3 + 24 - (int)__first) / 24 > 1 );
  }
}
