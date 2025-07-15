void __usercall stlp_std::__push_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        unsigned int *__first@<esi>,
        int __holeIndex@<ecx>,
        unsigned int __val@<edi>,
        int __topIndex,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  int v5; // eax
  unsigned int v6; // edx

  v5 = (__holeIndex - 1) / 2;
  if ( __holeIndex <= __topIndex )
  {
    __first[__holeIndex] = __val;
  }
  else
  {
    do
    {
      v6 = __first[v5];
      if ( *(float *)((_DWORD)__comp.m_distances + 4 * __val) <= *(float *)((_DWORD)__comp.m_distances + 4 * v6) )
        break;
      __first[__holeIndex] = v6;
      __holeIndex = v5;
      v5 = (v5 - 1) / 2;
    }
    while ( __holeIndex > __topIndex );
    __first[__holeIndex] = __val;
  }
}


void __usercall stlp_std::__push_heap<vostok::render::grass_patch * *,int,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<esi>,
        int __holeIndex@<ecx>,
        int __topIndex@<edi>,
        vostok::render::grass_patch *__val,
        vostok::render::sort_grass_patch_predicate __comp)
{
  int v5; // eax
  float v6; // xmm3_4
  vostok::render::grass_patch *v7; // edx

  v5 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    v6 = (float)((float)((float)(__val->m_origin.z - __comp.m_view_pos.z)
                       * (float)(__val->m_origin.z - __comp.m_view_pos.z))
               + (float)((float)(__val->m_origin.y - __comp.m_view_pos.y)
                       * (float)(__val->m_origin.y - __comp.m_view_pos.y)))
       + (float)((float)(__val->m_origin.x - __comp.m_view_pos.x) * (float)(__val->m_origin.x - __comp.m_view_pos.x));
    do
    {
      v7 = __first[v5];
      if ( v6 <= (float)((float)((float)((float)(v7->m_origin.z - __comp.m_view_pos.z)
                                       * (float)(v7->m_origin.z - __comp.m_view_pos.z))
                               + (float)((float)(v7->m_origin.x - __comp.m_view_pos.x)
                                       * (float)(v7->m_origin.x - __comp.m_view_pos.x)))
                       + (float)((float)(v7->m_origin.y - __comp.m_view_pos.y)
                               * (float)(v7->m_origin.y - __comp.m_view_pos.y))) )
        break;
      __first[__holeIndex] = v7;
      __holeIndex = v5;
      v5 = (v5 - 1) / 2;
    }
    while ( __holeIndex > __topIndex );
  }
  __first[__holeIndex] = __val;
}


void __usercall stlp_std::__push_heap<vostok::animation::mixing::n_ary_tree_base_node * *,int,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
        vostok::animation::mixing::n_ary_tree_base_node **__first@<edi>,
        int __holeIndex,
        int __topIndex,
        vostok::animation::mixing::n_ary_tree_base_node *__val)
{
  int v4; // ebx
  int v5; // esi
  vostok::animation::mixing::n_ary_tree_base_node *v6; // ecx
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_double_dispatcher *, vostok::animation::mixing::n_ary_tree_base_node *); // eax
  bool v8; // cc
  void **v9; // [esp+10h] [ebp-Ch] BYREF
  int v10; // [esp+14h] [ebp-8h]

  v4 = __holeIndex;
  v5 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    do
    {
      v6 = __first[v5];
      accept = v6->accept;
      v9 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
      v10 = 0;
      accept(v6, (vostok::animation::mixing::n_ary_tree_double_dispatcher *)&v9, __val);
      if ( v10 != 1 )
        break;
      __first[v4] = __first[v5];
      v4 = v5;
      v8 = v5 <= __topIndex;
      v5 = (v5 - 1) / 2;
    }
    while ( !v8 );
  }
  __first[v4] = __val;
}


void __cdecl stlp_std::__push_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
        vostok::render::render_surface_instance **__first,
        int __holeIndex,
        int __topIndex,
        vostok::render::render_surface_instance *__val,
        vostok::render::sort_by_ps_predicate __comp)
{
  int v5; // ebx
  int v6; // esi
  bool v7; // cc

  v5 = __holeIndex;
  v6 = (__holeIndex - 1) / 2;
  if ( __holeIndex <= __topIndex )
  {
    __first[__holeIndex] = __val;
  }
  else
  {
    while ( vostok::render::sort_by_vs_predicate::operator()(&__comp, __first[v6], __val) )
    {
      __first[v5] = __first[v6];
      v5 = v6;
      v7 = v6 <= __topIndex;
      v6 = (v6 - 1) / 2;
      if ( v7 )
      {
        __first[v5] = __val;
        return;
      }
    }
    __first[v5] = __val;
  }
}


void __usercall stlp_std::__push_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key *__val@<eax>,
        vostok::command_line::key_compare_predicate *a2@<esi>,
        vostok::command_line::key **__first,
        int __holeIndex,
        int __topIndex)
{
  int v5; // ebp
  int v7; // ebx
  vostok::command_line::key *v8; // esi
  bool v9; // cc
  vostok::command_line::key_compare_predicate *v10; // [esp-4h] [ebp-10h]

  v5 = __holeIndex;
  v7 = (__holeIndex - 1) / 2;
  if ( __holeIndex <= __topIndex )
  {
    __first[__holeIndex] = __val;
  }
  else
  {
    v10 = a2;
    while ( 1 )
    {
      v8 = __first[v7];
      if ( !vostok::command_line::key_compare_predicate::operator()(v8, __val, v10) )
        break;
      __first[v5] = v8;
      v5 = v7;
      v9 = v7 <= __topIndex;
      v7 = (v7 - 1) / 2;
      if ( v9 )
      {
        __first[v5] = __val;
        return;
      }
    }
    __first[v5] = __val;
  }
}


void __usercall stlp_std::__push_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
        int __holeIndex@<eax>,
        vostok::resources::query_result **__first,
        int __topIndex,
        vostok::resources::query_result *__val)
{
  int v4; // edi
  int v5; // esi
  bool v6; // cc
  vostok::resources::query_result *v7; // [esp+0h] [ebp-14h]

  v4 = __holeIndex;
  v5 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    do
    {
      if ( !vostok::resources::hdd_manager_sorting_predicate::operator()(
              __first[v5],
              (vostok::resources::hdd_manager_sorting_predicate *)__val,
              v7) )
        break;
      __first[v4] = __first[v5];
      v4 = v5;
      v6 = v5 <= __topIndex;
      v5 = (v5 - 1) / 2;
    }
    while ( !v6 );
  }
  __first[v4] = __val;
}


void __usercall stlp_std::__push_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
        vostok::resources::query_result **__first@<esi>,
        int __holeIndex@<ecx>,
        vostok::resources::query_result *__val@<edi>,
        int __topIndex)
{
  int v4; // eax
  vostok::resources::query_result *v5; // edx

  v4 = (__holeIndex - 1) / 2;
  if ( __holeIndex <= __topIndex )
  {
    __first[__holeIndex] = __val;
  }
  else
  {
    do
    {
      v5 = __first[v4];
      if ( v5->m_quality_index < __val->m_quality_index )
        break;
      __first[__holeIndex] = v5;
      __holeIndex = v4;
      v4 = (v4 - 1) / 2;
    }
    while ( __holeIndex > __topIndex );
    __first[__holeIndex] = __val;
  }
}


void __usercall stlp_std::__push_heap<vostok::resources::resource_base * *,int,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        vostok::resources::resource_base **__first@<edi>,
        int __holeIndex@<ecx>,
        int __topIndex,
        vostok::resources::resource_base *__val)
{
  int v4; // eax
  float m_current_satisfaction; // xmm1_4
  vostok::resources::resource_base *v6; // esi

  v4 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    m_current_satisfaction = __val->m_current_satisfaction;
    do
    {
      v6 = __first[v4];
      if ( fabs(v6->m_current_satisfaction - m_current_satisfaction) >= 0.050000001 )
      {
        if ( v6->m_current_satisfaction <= m_current_satisfaction )
          break;
      }
      else if ( v6->m_reconstruction_size >= __val->m_reconstruction_size )
      {
        break;
      }
      __first[__holeIndex] = v6;
      __holeIndex = v4;
      v4 = (v4 - 1) / 2;
    }
    while ( __holeIndex > __topIndex );
  }
  __first[__holeIndex] = __val;
}


void __cdecl stlp_std::__push_heap<vostok::network_core::udp_match_packet * *,int,vostok::network_core::udp_match_packet *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        int __holeIndex,
        int __topIndex,
        vostok::network_core::udp_match_packet *__val)
{
  survarium::base_project::resolve_link_object *v4; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v5; // ecx
  vostok::network_core::udp_match_packet *v6; // [esp+4h] [ebp-8h]
  int __parent; // [esp+8h] [ebp-4h]

  for ( __parent = (__holeIndex - 1) / 2; __holeIndex > __topIndex; __parent = (__parent - 1) / 2 )
  {
    v6 = __first[__parent];
    v4 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)__parent,
           (int)__val);
    if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v5,
           (int)v6) >= v4 )
      break;
    __first[__holeIndex] = __first[__parent];
    __holeIndex = __parent;
  }
  __first[__holeIndex] = __val;
}


void __usercall stlp_std::__push_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
        int __holeIndex@<eax>,
        const char **__first,
        int __topIndex,
        const char *__val,
        bool (__cdecl *__comp)(const char *, const char *))
{
  int v5; // edi
  int v6; // esi
  bool v7; // cc

  v5 = __holeIndex;
  v6 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    do
    {
      if ( !__comp(__first[v6], __val) )
        break;
      __first[v5] = __first[v6];
      v5 = v6;
      v7 = v6 <= __topIndex;
      v6 = (v6 - 1) / 2;
    }
    while ( !v7 );
  }
  __first[v5] = __val;
}


void __usercall stlp_std::__push_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
        int __holeIndex@<eax>,
        const char **__first,
        int __topIndex,
        const char *__val)
{
  int v4; // esi
  int v5; // eax

  v4 = __holeIndex;
  v5 = (__holeIndex - 1) / 2;
  if ( v4 <= __topIndex )
  {
    __first[v4] = __val;
  }
  else
  {
    while ( strcmp(__first[v5], __val) < 0 )
    {
      __first[v4] = __first[v5];
      v4 = v5;
      v5 = (v5 - 1) / 2;
      if ( v4 <= __topIndex )
      {
        __first[v4] = __val;
        return;
      }
    }
    __first[v4] = __val;
  }
}


void __usercall stlp_std::__push_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
        int __holeIndex@<eax>,
        const char **__first,
        int __topIndex,
        char *__val,
        vostok::tips_sorting_predicate __comp)
{
  int v6; // edi
  int v7; // esi
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  bool v11; // cc
  unsigned __int8 *__firsta; // [esp+10h] [ebp+4h]

  v6 = __holeIndex;
  v7 = (__holeIndex - 1) / 2;
  if ( __holeIndex <= __topIndex )
  {
    __first[__holeIndex] = __val;
  }
  else
  {
    do
    {
      __firsta = (unsigned __int8 *)__first[v7];
      strstr(__firsta, (unsigned __int8 *)__comp.editor_str);
      v9 = v8;
      strstr((unsigned __int8 *)__val, (unsigned __int8 *)__comp.editor_str);
      if ( v9 - (int)__firsta >= v10 - (int)__val )
        break;
      __first[v6] = __first[v7];
      v6 = v7;
      v11 = v7 <= __topIndex;
      v7 = (v7 - 1) / 2;
    }
    while ( !v11 );
    __first[v6] = __val;
  }
}


void __usercall stlp_std::__push_heap<vostok::physics::closest_ray_result *,int,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<edi>,
        int __holeIndex@<eax>,
        int __topIndex,
        vostok::physics::closest_ray_result __val,
        vostok::physics::distance_predicate __comp)
{
  int v5; // esi
  int i; // eax
  vostok::physics::closest_ray_result *v7; // ecx
  vostok::physics::closest_ray_result *v8; // edx

  v5 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v5 > __topIndex; i = (i - 1) / 2 )
  {
    v7 = &__first[i];
    if ( (float)((float)((float)((float)(__val.hit_point_world.z - __comp.m_from.z)
                               * (float)(__val.hit_point_world.z - __comp.m_from.z))
                       + (float)((float)(__val.hit_point_world.y - __comp.m_from.y)
                               * (float)(__val.hit_point_world.y - __comp.m_from.y)))
               + (float)((float)(__val.hit_point_world.x - __comp.m_from.x)
                       * (float)(__val.hit_point_world.x - __comp.m_from.x))) <= (float)((float)((float)((float)(v7->hit_point_world.z - __comp.m_from.z) * (float)(v7->hit_point_world.z - __comp.m_from.z))
                                                                                               + (float)((float)(v7->hit_point_world.x - __comp.m_from.x) * (float)(v7->hit_point_world.x - __comp.m_from.x)))
                                                                                       + (float)((float)(v7->hit_point_world.y - __comp.m_from.y)
                                                                                               * (float)(v7->hit_point_world.y - __comp.m_from.y))) )
      break;
    *(_QWORD *)&__first[v5].object = *(_QWORD *)&v7->object;
    v8 = &__first[v5];
    *(_QWORD *)&v8->hit_point_world.elements[1] = *(_QWORD *)&v7->hit_point_world.elements[1];
    *(_QWORD *)&v8->hit_normal_world.x = *(_QWORD *)&v7->hit_normal_world.x;
    v5 = i;
    *(_QWORD *)&v8->hit_normal_world.elements[2] = *(_QWORD *)&v7->hit_normal_world.elements[2];
    *(_QWORD *)&v8->is_shape_index = *(_QWORD *)&v7->is_shape_index;
  }
  __first[v5] = __val;
}


void __usercall stlp_std::__push_heap<vostok::render::grass_patch::sort_info *,int,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<edi>,
        int __holeIndex@<eax>,
        int __topIndex,
        vostok::render::grass_patch::sort_info __val,
        vostok::render::sort_indices_predicate __comp)
{
  int v5; // esi
  int i; // eax
  vostok::render::grass_patch::sort_info *v7; // ecx
  vostok::render::grass_patch::sort_info *v8; // edx

  v5 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v5 > __topIndex; i = (i - 1) / 2 )
  {
    v7 = &__first[i];
    if ( (float)((float)((float)((float)(__val.position.z - __comp.m_view_pos.z)
                               * (float)(__val.position.z - __comp.m_view_pos.z))
                       + (float)((float)(__val.position.y - __comp.m_view_pos.y)
                               * (float)(__val.position.y - __comp.m_view_pos.y)))
               + (float)((float)(__val.position.x - __comp.m_view_pos.x)
                       * (float)(__val.position.x - __comp.m_view_pos.x))) <= (float)((float)((float)((float)(v7->position.x - __comp.m_view_pos.x) * (float)(v7->position.x - __comp.m_view_pos.x))
                                                                                            + (float)((float)(v7->position.y - __comp.m_view_pos.y) * (float)(v7->position.y - __comp.m_view_pos.y)))
                                                                                    + (float)((float)(v7->position.z - __comp.m_view_pos.z)
                                                                                            * (float)(v7->position.z - __comp.m_view_pos.z))) )
      break;
    v8 = &__first[v5];
    *(_QWORD *)&v8->position.x = *(_QWORD *)&v7->position.x;
    v5 = i;
    *(_QWORD *)&v8->position.elements[2] = *(_QWORD *)&v7->position.elements[2];
    v8->num_indices = v7->num_indices;
  }
  __first[v5] = __val;
}


void __usercall stlp_std::__push_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        int __holeIndex@<eax>,
        vostok::math::curve_point<float> *__first,
        int __topIndex,
        vostok::math::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  int v5; // edi
  int v6; // esi
  const vostok::math::curve_point<float> *v7; // ebx
  bool v8; // cc

  v5 = __holeIndex;
  v6 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    do
    {
      v7 = &__first[v6];
      if ( !__comp(v7, &__val) )
        break;
      __first[v5] = *v7;
      v5 = v6;
      v8 = v6 <= __topIndex;
      v6 = (v6 - 1) / 2;
    }
    while ( !v8 );
  }
  __first[v5] = __val;
}


void __usercall stlp_std::__push_heap<vostok::math::curve_point<vostok::math::float4_pod> *,int,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        int __holeIndex@<eax>,
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        int __topIndex,
        vostok::math::curve_point<vostok::math::float4_pod> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  int v5; // edi
  int v6; // ebx
  bool v7; // cc

  v5 = __holeIndex;
  v6 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    do
    {
      if ( !__comp(&__first[v6], &__val) )
        break;
      qmemcpy(&__first[v5], &__first[v6], sizeof(vostok::math::curve_point<vostok::math::float4_pod>));
      v5 = v6;
      v7 = v6 <= __topIndex;
      v6 = (v6 - 1) / 2;
    }
    while ( !v7 );
  }
  qmemcpy(&__first[v5], &__val, sizeof(vostok::math::curve_point<vostok::math::float4_pod>));
}


void __usercall stlp_std::__push_heap<vostok::render::custom_config_value *,int,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        int __holeIndex@<eax>,
        vostok::render::custom_config_value *__first,
        int __topIndex,
        vostok::render::custom_config_value __val,
        bool (__cdecl *__comp)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))
{
  int v5; // edi
  int v6; // esi
  const vostok::render::custom_config_value *v7; // ebx
  bool v8; // cc
  const void *destroyer; // ecx
  vostok::render::custom_config_value *v10; // eax

  v5 = __holeIndex;
  v6 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    do
    {
      v7 = &__first[v6];
      if ( !__comp(v7, &__val) )
        break;
      __first[v5] = *v7;
      v5 = v6;
      v8 = v6 <= __topIndex;
      v6 = (v6 - 1) / 2;
    }
    while ( !v8 );
  }
  destroyer = __val.destroyer;
  v10 = &__first[v5];
  *(_QWORD *)&v10->id = *(_QWORD *)&__val.id;
  *(_QWORD *)&v10->id_crc = *(_QWORD *)&__val.id_crc;
  v10->destroyer = destroyer;
}


void __usercall stlp_std::__push_heap<vostok::render::shader_constant *,int,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        int __holeIndex@<eax>,
        vostok::render::shader_constant *__first,
        int __topIndex,
        vostok::render::shader_constant __val,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  int v5; // edi
  int v6; // esi
  vostok::render::shader_constant *v7; // ebx
  vostok::render::shader_constant *v8; // eax
  bool v9; // cc
  vostok::render::shader_constant *v10; // eax
  int m_value_high; // edx
  void *m_pointer; // ecx
  unsigned int m_size; // edx
  const vostok::render::shader_constant_host *m_host; // ecx

  v5 = __holeIndex;
  v6 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    do
    {
      v7 = &__first[v6];
      if ( !__comp(v7, &__val) )
        break;
      v8 = &__first[v5];
      if ( v8 )
      {
        *(_DWORD *)&v8->m_slot.m_class_id = *(_DWORD *)&v7->m_slot.m_class_id;
        HIDWORD(v8->m_slot.m_value) = HIDWORD(v7->m_slot.m_value);
        v8->m_source.m_pointer = v7->m_source.m_pointer;
        v8->m_source.m_size = v7->m_source.m_size;
        v8->m_host = v7->m_host;
      }
      v5 = v6;
      v9 = v6 <= __topIndex;
      v6 = (v6 - 1) / 2;
    }
    while ( !v9 );
  }
  v10 = &__first[v5];
  if ( v10 )
  {
    m_value_high = HIDWORD(__val.m_slot.m_value);
    *(_DWORD *)&v10->m_slot.m_class_id = *(_DWORD *)&__val.m_slot.m_class_id;
    m_pointer = __val.m_source.m_pointer;
    HIDWORD(v10->m_slot.m_value) = m_value_high;
    m_size = __val.m_source.m_size;
    v10->m_source.m_pointer = m_pointer;
    m_host = __val.m_host;
    v10->m_source.m_size = m_size;
    v10->m_host = m_host;
  }
}
