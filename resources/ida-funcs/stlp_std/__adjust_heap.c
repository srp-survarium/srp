void __fastcall stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        int __holeIndex,
        int __len,
        unsigned int *__first,
        unsigned int __val,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  int v5; // eax
  bool v6; // zf
  int __topIndex; // [esp+8h] [ebp-4h]

  v5 = 2 * __holeIndex + 2;
  v6 = v5 == __len;
  for ( __topIndex = __holeIndex; v5 < __len; v6 = v5 == __len )
  {
    if ( *(float *)((_DWORD)__comp.m_distances + 4 * __first[v5 - 1]) > *(float *)((_DWORD)__comp.m_distances
                                                                                 + 4 * __first[v5]) )
      --v5;
    __first[__holeIndex] = __first[v5];
    __holeIndex = v5;
    v5 = 2 * v5 + 2;
  }
  if ( v6 )
  {
    __first[__holeIndex] = __first[v5 - 1];
    __holeIndex = v5 - 1;
  }
  stlp_std::__push_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
    __first,
    __holeIndex,
    __topIndex,
    __val,
    __comp);
}


void __fastcall stlp_std::__adjust_heap<float *,int,float,stlp_std::less<float>>(
        float *__first,
        int __len,
        int __holeIndex,
        float __val)
{
  int v4; // esi
  int v5; // eax
  bool i; // zf
  int v7; // eax
  float v8; // xmm0_4

  v4 = __holeIndex;
  v5 = 2 * __holeIndex + 2;
  for ( i = v5 == __len; v5 < __len; i = v5 == __len )
  {
    if ( __first[v5 - 1] > __first[v5] )
      --v5;
    __first[v4] = __first[v5];
    v4 = v5;
    v5 = 2 * v5 + 2;
  }
  if ( i )
  {
    __first[v4] = __first[v5 - 1];
    v4 = v5 - 1;
  }
  v7 = (v4 - 1) / 2;
  if ( v4 <= __holeIndex )
  {
    __first[v4] = __val;
  }
  else
  {
    do
    {
      v8 = __first[v7];
      if ( __val <= v8 )
        break;
      __first[v4] = v8;
      v4 = v7;
      v7 = (v7 - 1) / 2;
    }
    while ( v4 > __holeIndex );
    __first[v4] = __val;
  }
}


void __usercall stlp_std::__adjust_heap<vostok::render::grass_patch * *,int,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<eax>,
        int __holeIndex@<ecx>,
        int __len,
        vostok::render::grass_patch *__val,
        vostok::render::sort_grass_patch_predicate __comp)
{
  int v6; // eax
  bool v7; // zf
  int i; // edi
  vostok::render::grass_patch *v9; // edx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  vostok::render::grass_patch *v13; // edx

  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  for ( i = __holeIndex; v6 < __len; v7 = v6 == __len )
  {
    v9 = __first[v6];
    x = v9->m_origin.x;
    y = v9->m_origin.y;
    z = v9->m_origin.z;
    v13 = __first[v6 - 1];
    if ( (float)((float)((float)((float)(v13->m_origin.z - __comp.m_view_pos.z)
                               * (float)(v13->m_origin.z - __comp.m_view_pos.z))
                       + (float)((float)(v13->m_origin.y - __comp.m_view_pos.y)
                               * (float)(v13->m_origin.y - __comp.m_view_pos.y)))
               + (float)((float)(v13->m_origin.x - __comp.m_view_pos.x) * (float)(v13->m_origin.x - __comp.m_view_pos.x))) > (float)((float)((float)((float)(z - __comp.m_view_pos.z) * (float)(z - __comp.m_view_pos.z)) + (float)((float)(y - __comp.m_view_pos.y) * (float)(y - __comp.m_view_pos.y))) + (float)((float)(x - __comp.m_view_pos.x) * (float)(x - __comp.m_view_pos.x))) )
      --v6;
    __first[__holeIndex] = __first[v6];
    __holeIndex = v6;
    v6 = 2 * v6 + 2;
  }
  if ( v7 )
  {
    __first[__holeIndex] = __first[v6 - 1];
    __holeIndex = v6 - 1;
  }
  stlp_std::__push_heap<vostok::render::grass_patch * *,int,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
    __first,
    __holeIndex,
    i,
    __val,
    __comp);
}


void __usercall stlp_std::__adjust_heap<vostok::animation::mixing::n_ary_tree_base_node * *,int,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
        vostok::animation::mixing::n_ary_tree_base_node **__first@<eax>,
        int __holeIndex,
        int __len,
        vostok::animation::mixing::n_ary_tree_base_node *__val,
        node_predicate __comp)
{
  int v5; // ebx
  int v6; // esi
  bool i; // zf
  vostok::animation::mixing::n_ary_tree_base_node *v9; // ecx
  void (__thiscall *accept)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_double_dispatcher *, vostok::animation::mixing::n_ary_tree_base_node *); // eax
  vostok::animation::mixing::n_ary_tree_base_node *v11; // [esp-4h] [ebp-20h]
  void **v12; // [esp+10h] [ebp-Ch] BYREF
  int v13; // [esp+14h] [ebp-8h]

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  for ( i = v6 == __len; v6 < __len; i = v6 == __len )
  {
    v9 = __first[v6];
    accept = v9->accept;
    v11 = __first[v6 - 1];
    v12 = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v13 = 0;
    accept(v9, (vostok::animation::mixing::n_ary_tree_double_dispatcher *)&v12, v11);
    if ( v13 == 1 )
      --v6;
    __first[v5] = __first[v6];
    v5 = v6;
    v6 = 2 * v6 + 2;
  }
  if ( i )
  {
    __first[v5] = __first[v6 - 1];
    v5 = v6 - 1;
  }
  stlp_std::__push_heap<vostok::animation::mixing::n_ary_tree_base_node * *,int,vostok::animation::mixing::n_ary_tree_base_node *,node_predicate>(
    __first,
    v5,
    __holeIndex,
    __val,
    __comp);
}


void __cdecl stlp_std::__adjust_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
        vostok::render::render_surface_instance **__first,
        int __holeIndex,
        int __len,
        vostok::render::render_surface_instance *__val,
        vostok::render::sort_by_ps_predicate __comp)
{
  int v5; // ebx
  int v6; // esi
  bool i; // zf

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  for ( i = v6 == __len; v6 < __len; i = v6 == __len )
  {
    if ( vostok::render::sort_by_vs_predicate::operator()(&__comp, __first[v6], __first[v6 - 1]) )
      --v6;
    __first[v5] = __first[v6];
    v5 = v6;
    v6 = 2 * v6 + 2;
  }
  if ( i )
  {
    __first[v5] = __first[v6 - 1];
    v5 = v6 - 1;
  }
  stlp_std::__push_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
    __first,
    v5,
    __holeIndex,
    __val,
    __comp);
}


void __cdecl stlp_std::__adjust_heap<vostok::ai::planning::goal * *,int,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        const vostok::ai::sound_item **__first,
        int __holeIndex,
        int __len,
        const vostok::ai::sound_item *__val,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  int v5; // [esp+4h] [ebp-10h]
  int i; // [esp+8h] [ebp-Ch]
  int __secondChild; // [esp+Ch] [ebp-8h]
  int __topIndex; // [esp+10h] [ebp-4h]

  __topIndex = __holeIndex;
  for ( __secondChild = 2 * __holeIndex + 2; __secondChild < __len; __secondChild = 2 * __secondChild + 2 )
  {
    if ( __comp(__first[__secondChild], __first[__secondChild - 1]) )
      --__secondChild;
    __first[__holeIndex] = __first[__secondChild];
    __holeIndex = __secondChild;
  }
  if ( __secondChild == __len )
  {
    __first[__holeIndex] = __first[__secondChild - 1];
    __holeIndex = __secondChild - 1;
  }
  v5 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v5 > __topIndex && __comp(__first[i], __val); i = (i - 1) / 2 )
  {
    __first[v5] = __first[i];
    v5 = i;
  }
  __first[v5] = __val;
}


void __usercall stlp_std::__adjust_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key_compare_predicate *a1@<edi>,
        vostok::command_line::key **__first,
        int __holeIndex,
        int __len,
        vostok::command_line::key *__val,
        vostok::command_line::key_compare_predicate __comp)
{
  int v6; // ebp
  int v7; // ebx
  bool v8; // zf
  vostok::command_line::key_compare_predicate *v9; // [esp-8h] [ebp-10h]

  v6 = __holeIndex;
  v7 = 2 * __holeIndex + 2;
  v8 = v7 == __len;
  if ( v7 < __len )
  {
    v9 = a1;
    do
    {
      if ( vostok::command_line::key_compare_predicate::operator()(__first[v7], __first[v7 - 1], v9) )
        --v7;
      __first[v6] = __first[v7];
      v6 = v7;
      v7 = 2 * v7 + 2;
      v8 = v7 == __len;
    }
    while ( v7 < __len );
  }
  if ( v8 )
  {
    __first[v6] = __first[v7 - 1];
    v6 = v7 - 1;
  }
  stlp_std::__push_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
    __first,
    v6,
    __holeIndex,
    __val,
    __comp);
}


void __usercall stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
        int __holeIndex@<eax>,
        vostok::resources::query_result **__first,
        int __len,
        vostok::resources::query_result *__val,
        vostok::resources::hdd_manager_sorting_predicate __comp)
{
  int v6; // edi
  int v7; // esi
  bool i; // zf
  vostok::resources::query_result *v10; // [esp+0h] [ebp-14h]

  v6 = __holeIndex;
  v7 = 2 * __holeIndex + 2;
  for ( i = v7 == __len; v7 < __len; i = v7 == __len )
  {
    if ( vostok::resources::hdd_manager_sorting_predicate::operator()(
           __first[v7],
           (vostok::resources::hdd_manager_sorting_predicate *)__first[v7 - 1],
           v10) )
    {
      --v7;
    }
    __first[v6] = __first[v7];
    v6 = v7;
    v7 = 2 * v7 + 2;
  }
  if ( i )
  {
    __first[v6] = __first[v7 - 1];
    v6 = v7 - 1;
  }
  stlp_std::__push_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
    __first,
    v6,
    __holeIndex,
    __val,
    __comp);
}


void __fastcall stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
        int __holeIndex,
        int __len,
        vostok::resources::query_result **__first,
        vostok::resources::query_result *__val,
        vostok::resources::sorting_predicate __comp)
{
  int v5; // eax
  bool v6; // zf
  int i; // edi

  v5 = 2 * __holeIndex + 2;
  v6 = v5 == __len;
  for ( i = __holeIndex; v5 < __len; v6 = v5 == __len )
  {
    if ( __first[v5]->m_quality_index >= __first[v5 - 1]->m_quality_index )
      --v5;
    __first[__holeIndex] = __first[v5];
    __holeIndex = v5;
    v5 = 2 * v5 + 2;
  }
  if ( v6 )
  {
    __first[__holeIndex] = __first[v5 - 1];
    __holeIndex = v5 - 1;
  }
  stlp_std::__push_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
    __first,
    __holeIndex,
    i,
    __val,
    __comp);
}


void __usercall stlp_std::__adjust_heap<vostok::resources::resource_base * *,int,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        vostok::resources::resource_base **__first@<eax>,
        int __holeIndex@<ecx>,
        int __len,
        vostok::resources::resource_base *__val,
        vostok::resources::sorting_predicate __comp)
{
  int v6; // eax
  bool v7; // zf
  vostok::resources::resource_base *v8; // esi
  vostok::resources::resource_base *v9; // edx
  float m_current_satisfaction; // xmm1_4
  int __topIndex; // [esp+Ch] [ebp-4h]

  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  __topIndex = __holeIndex;
  if ( v6 < __len )
  {
    while ( 1 )
    {
      v8 = __first[v6];
      v9 = __first[v6 - 1];
      m_current_satisfaction = v9->m_current_satisfaction;
      if ( fabs(v8->m_current_satisfaction - m_current_satisfaction) >= 0.050000001 )
        break;
      if ( v8->m_reconstruction_size < v9->m_reconstruction_size )
        goto LABEL_4;
LABEL_5:
      __first[__holeIndex] = __first[v6];
      __holeIndex = v6;
      v6 = 2 * v6 + 2;
      v7 = v6 == __len;
      if ( v6 >= __len )
        goto LABEL_6;
    }
    if ( v8->m_current_satisfaction <= m_current_satisfaction )
      goto LABEL_5;
LABEL_4:
    --v6;
    goto LABEL_5;
  }
LABEL_6:
  if ( v7 )
  {
    __first[__holeIndex] = __first[v6 - 1];
    __holeIndex = v6 - 1;
  }
  stlp_std::__push_heap<vostok::resources::resource_base * *,int,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
    __first,
    __holeIndex,
    __topIndex,
    __val,
    __comp);
}


void __cdecl stlp_std::__adjust_heap<vostok::network_core::udp_match_packet * *,int,vostok::network_core::udp_match_packet *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        int __holeIndex,
        int __len,
        vostok::network_core::udp_match_packet *__val,
        packets_predicate __comp)
{
  survarium::base_project::resolve_link_object *v5; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v6; // ecx
  vostok::network_core::udp_match_packet *v7; // [esp+10h] [ebp-Ch]
  int __secondChild; // [esp+14h] [ebp-8h]
  int __topIndex; // [esp+18h] [ebp-4h]

  __topIndex = __holeIndex;
  for ( __secondChild = 2 * __holeIndex + 2; __secondChild < __len; __secondChild = 2 * __secondChild + 2 )
  {
    v7 = __first[__secondChild];
    v5 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)__secondChild,
           (int)__first[__secondChild - 1]);
    if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v6,
           (int)v7) < v5 )
      --__secondChild;
    __first[__holeIndex] = __first[__secondChild];
    __holeIndex = __secondChild;
  }
  if ( __secondChild == __len )
  {
    __first[__holeIndex] = __first[__secondChild - 1];
    __holeIndex = __secondChild - 1;
  }
  stlp_std::__push_heap<vostok::network_core::udp_match_packet * *,int,vostok::network_core::udp_match_packet *,packets_predicate>(
    __first,
    __holeIndex,
    __topIndex,
    __val,
    __comp);
}


void __usercall stlp_std::__adjust_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
        const char **__first@<edi>,
        int __holeIndex,
        int __len,
        const char *__val,
        bool (__cdecl *__comp)(const char *, const char *))
{
  int v5; // ebx
  int v6; // esi
  bool i; // zf

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  for ( i = v6 == __len; v6 < __len; i = v6 == __len )
  {
    if ( __comp(__first[v6], __first[v6 - 1]) )
      --v6;
    __first[v5] = __first[v6];
    v5 = v6;
    v6 = 2 * v6 + 2;
  }
  if ( i )
  {
    __first[v5] = __first[v6 - 1];
    v5 = v6 - 1;
  }
  stlp_std::__push_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
    __first,
    v5,
    __holeIndex,
    __val,
    __comp);
}


void __usercall stlp_std::__adjust_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
        const char **__first@<edi>,
        int __holeIndex@<eax>,
        int __len,
        const char *__val,
        vostok::render::shader_macros_dort_predicate __comp)
{
  int v6; // esi
  bool v7; // zf
  bool v8; // cc
  int __topIndex; // [esp+Ch] [ebp+4h]

  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  v8 = v6 < __len;
  __topIndex = __holeIndex;
  if ( v8 )
  {
    do
    {
      if ( strcmp(__first[v6], __first[v6 - 1]) < 0 )
        --v6;
      __first[__holeIndex] = __first[v6];
      __holeIndex = v6;
      v6 = 2 * v6 + 2;
      v7 = v6 == __len;
    }
    while ( v6 < __len );
  }
  if ( v7 )
  {
    __first[__holeIndex] = __first[v6 - 1];
    __holeIndex = v6 - 1;
  }
  stlp_std::__push_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
    __first,
    __holeIndex,
    __topIndex,
    __val,
    __comp);
}


void __usercall stlp_std::__adjust_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
        const char **__first@<edi>,
        int __holeIndex,
        int __len,
        const char *__val,
        vostok::tips_sorting_predicate __comp)
{
  int v5; // eax
  int v6; // esi
  bool v7; // zf
  unsigned __int8 *v8; // ebp
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // ecx
  const char *v13; // eax
  unsigned __int8 *v14; // [esp+4h] [ebp-8h]
  int __topIndex; // [esp+8h] [ebp-4h]

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  __topIndex = __holeIndex;
  if ( v6 < __len )
  {
    do
    {
      v8 = (unsigned __int8 *)__first[v6 - 1];
      v14 = (unsigned __int8 *)__first[v6];
      strstr(v14, (unsigned __int8 *)__comp.editor_str);
      v10 = v9;
      strstr(v8, (unsigned __int8 *)__comp.editor_str);
      if ( v10 - (int)v14 < v11 - (int)v8 )
        --v6;
      v12 = __holeIndex;
      v13 = __first[v6];
      __holeIndex = v6;
      v6 = 2 * v6 + 2;
      v7 = v6 == __len;
      __first[v12] = v13;
    }
    while ( v6 < __len );
    v5 = __holeIndex;
  }
  if ( v7 )
  {
    __first[v5] = __first[v6 - 1];
    v5 = v6 - 1;
  }
  stlp_std::__push_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
    __first,
    v5,
    __topIndex,
    __val,
    __comp);
}


void __fastcall stlp_std::__adjust_heap<void const * *,int,void const *,stlp_std::less<void const *>>(
        unsigned int *__first,
        int __len,
        int __holeIndex,
        unsigned int __val)
{
  int v4; // esi
  int v5; // eax
  bool i; // zf
  int j; // eax
  unsigned int v8; // edx

  v4 = __holeIndex;
  v5 = 2 * __holeIndex + 2;
  for ( i = v5 == __len; v5 < __len; i = v5 == __len )
  {
    if ( __first[v5] < __first[v5 - 1] )
      --v5;
    __first[v4] = __first[v5];
    v4 = v5;
    v5 = 2 * v5 + 2;
  }
  if ( i )
  {
    __first[v4] = __first[v5 - 1];
    v4 = v5 - 1;
  }
  for ( j = (v4 - 1) / 2; v4 > __holeIndex; j = (j - 1) / 2 )
  {
    v8 = __first[j];
    if ( v8 >= __val )
      break;
    __first[v4] = v8;
    v4 = j;
  }
  __first[v4] = __val;
}


void __usercall stlp_std::__adjust_heap<vostok::physics::closest_ray_result *,int,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<ecx>,
        int __holeIndex@<eax>,
        int __len@<esi>,
        vostok::physics::closest_ray_result __val,
        vostok::physics::distance_predicate __comp)
{
  int v6; // ecx
  bool v7; // zf
  int v8; // ebx
  float z; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  vostok::physics::closest_ray_result *v16; // edx
  int v17; // eax
  vostok::physics::closest_ray_result *v18; // eax
  vostok::physics::closest_ray_result *v19; // edx
  int v20; // eax
  vostok::physics::closest_ray_result *v21; // eax

  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  v8 = __holeIndex;
  if ( v6 < __len )
  {
    z = __comp.m_from.z;
    do
    {
      v10 = __first[v6].hit_point_world.x - __comp.m_from.x;
      v11 = __first[v6].hit_point_world.z - z;
      v12 = v11 * v11;
      v13 = v10 * v10;
      v14 = __first[v6 - 1].hit_point_world.x - __comp.m_from.x;
      v15 = __first[v6].hit_point_world.y - __comp.m_from.y;
      if ( (float)((float)((float)((float)(__first[v6 - 1].hit_point_world.z - z)
                                 * (float)(__first[v6 - 1].hit_point_world.z - z))
                         + (float)((float)(__first[v6 - 1].hit_point_world.y - __comp.m_from.y)
                                 * (float)(__first[v6 - 1].hit_point_world.y - __comp.m_from.y)))
                 + (float)(v14 * v14)) > (float)((float)(v12 + v13) + (float)(v15 * v15)) )
        --v6;
      v16 = &__first[v6];
      v17 = __holeIndex;
      *(_QWORD *)&__first[v17].object = *(_QWORD *)&v16->object;
      v18 = &__first[v17];
      *(_QWORD *)&v18->hit_point_world.elements[1] = *(_QWORD *)&v16->hit_point_world.elements[1];
      *(_QWORD *)&v18->hit_normal_world.x = *(_QWORD *)&v16->hit_normal_world.x;
      *(_QWORD *)&v18->hit_normal_world.elements[2] = *(_QWORD *)&v16->hit_normal_world.elements[2];
      *(_QWORD *)&v18->is_shape_index = *(_QWORD *)&v16->is_shape_index;
      __holeIndex = v6;
      v6 = 2 * v6 + 2;
      v7 = v6 == __len;
    }
    while ( v6 < __len );
  }
  if ( v7 )
  {
    v19 = &__first[v6 - 1];
    v20 = __holeIndex;
    *(_QWORD *)&__first[v20].object = *(_QWORD *)&v19->object;
    v21 = &__first[v20];
    *(_QWORD *)&v21->hit_point_world.elements[1] = *(_QWORD *)&v19->hit_point_world.elements[1];
    *(_QWORD *)&v21->hit_normal_world.x = *(_QWORD *)&v19->hit_normal_world.x;
    *(_QWORD *)&v21->hit_normal_world.elements[2] = *(_QWORD *)&v19->hit_normal_world.elements[2];
    *(_QWORD *)&v21->is_shape_index = *(_QWORD *)&v19->is_shape_index;
    __holeIndex = v6 - 1;
  }
  stlp_std::__push_heap<vostok::physics::closest_ray_result *,int,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
    __first,
    __holeIndex,
    v8,
    __val,
    __comp);
}


void __cdecl stlp_std::__adjust_heap<vostok::sound::propagator_info *,int,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        int __holeIndex,
        int __len,
        vostok::sound::propagator_info __val,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  vostok::sound::propagator_info *v5; // edx
  vostok::sound::propagator_info *v6; // eax
  vostok::sound::propagator_info *v7; // ecx
  vostok::sound::propagator_info *v8; // edx
  vostok::sound::propagator_info *v9; // ecx
  vostok::sound::propagator_info *v10; // edx
  vostok::sound::propagator_info v11; // [esp+0h] [ebp-24h] BYREF
  int v12; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]
  int __secondChild; // [esp+1Ch] [ebp-8h]
  int __topIndex; // [esp+20h] [ebp-4h]

  __topIndex = __holeIndex;
  for ( __secondChild = 2 * __holeIndex + 2; __secondChild < __len; __secondChild = 2 * __secondChild + 2 )
  {
    if ( __comp(&__first[__secondChild], &__first[__secondChild - 1]) )
      --__secondChild;
    v5 = &__first[__secondChild];
    v6 = &__first[__holeIndex];
    v6->in_graph_position.x = v5->in_graph_position.x;
    v6->in_graph_position.y = v5->in_graph_position.y;
    v6->in_graph_position.z = v5->in_graph_position.z;
    v6->distance_to_listener = v5->distance_to_listener;
    v6->prop = v5->prop;
    __holeIndex = __secondChild;
  }
  if ( __secondChild == __len )
  {
    v7 = &__first[__secondChild - 1];
    v8 = &__first[__holeIndex];
    v8->in_graph_position.x = v7->in_graph_position.x;
    v8->in_graph_position.y = v7->in_graph_position.y;
    v8->in_graph_position.z = v7->in_graph_position.z;
    v8->distance_to_listener = v7->distance_to_listener;
    v8->prop = v7->prop;
    __holeIndex = __secondChild - 1;
  }
  v11 = __val;
  v12 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v12 > __topIndex && __comp(&__first[i], &v11); i = (i - 1) / 2 )
  {
    v9 = &__first[i];
    v10 = &__first[v12];
    v10->in_graph_position.x = v9->in_graph_position.x;
    v10->in_graph_position.y = v9->in_graph_position.y;
    v10->in_graph_position.z = v9->in_graph_position.z;
    v10->distance_to_listener = v9->distance_to_listener;
    v10->prop = v9->prop;
    v12 = i;
  }
  __first[v12] = v11;
}


void __usercall stlp_std::__adjust_heap<vostok::render::grass_patch::sort_info *,int,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<ecx>,
        int __holeIndex@<eax>,
        int __len@<esi>,
        vostok::render::grass_patch::sort_info __val,
        vostok::render::sort_indices_predicate __comp)
{
  int v6; // ecx
  bool v7; // zf
  int v8; // ebx
  float z; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  vostok::render::grass_patch::sort_info *v13; // edx
  vostok::render::grass_patch::sort_info *v14; // eax
  vostok::render::grass_patch::sort_info *v15; // edx
  vostok::render::grass_patch::sort_info *v16; // eax

  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  v8 = __holeIndex;
  if ( v6 < __len )
  {
    z = __comp.m_view_pos.z;
    do
    {
      v10 = __first[v6].position.z - z;
      v11 = __first[v6 - 1].position.x - __comp.m_view_pos.x;
      v12 = __first[v6].position.y - __comp.m_view_pos.y;
      if ( (float)((float)((float)((float)(__first[v6 - 1].position.z - z) * (float)(__first[v6 - 1].position.z - z))
                         + (float)(v11 * v11))
                 + (float)((float)(__first[v6 - 1].position.y - __comp.m_view_pos.y)
                         * (float)(__first[v6 - 1].position.y - __comp.m_view_pos.y))) > (float)((float)((float)(v10 * v10) + (float)((float)(__first[v6].position.x - __comp.m_view_pos.x) * (float)(__first[v6].position.x - __comp.m_view_pos.x)))
                                                                                               + (float)(v12 * v12)) )
        --v6;
      v13 = &__first[v6];
      v14 = &__first[__holeIndex];
      *(_QWORD *)&v14->position.x = *(_QWORD *)&v13->position.x;
      *(_QWORD *)&v14->position.elements[2] = *(_QWORD *)&v13->position.elements[2];
      v14->num_indices = v13->num_indices;
      __holeIndex = v6;
      v6 = 2 * v6 + 2;
      v7 = v6 == __len;
    }
    while ( v6 < __len );
  }
  if ( v7 )
  {
    v15 = &__first[v6 - 1];
    v16 = &__first[__holeIndex];
    *(_QWORD *)&v16->position.x = *(_QWORD *)&v15->position.x;
    *(_QWORD *)&v16->position.elements[2] = *(_QWORD *)&v15->position.elements[2];
    v16->num_indices = v15->num_indices;
    __holeIndex = v6 - 1;
  }
  stlp_std::__push_heap<vostok::render::grass_patch::sort_info *,int,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
    __first,
    __holeIndex,
    v8,
    __val,
    __comp);
}


void __cdecl stlp_std::__adjust_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        int __holeIndex,
        int __len,
        vostok::math::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  int v5; // edi
  int v6; // esi
  bool i; // zf
  vostok::math::curve_point<float> *v8; // eax
  vostok::math::curve_point<float> *v9; // ecx
  vostok::math::curve_point<float> *v10; // eax

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  for ( i = v6 == __len; v6 < __len; *(_QWORD *)&v9->time = *(_QWORD *)&v8->time )
  {
    if ( __comp(&__first[v6], &__first[v6 - 1]) )
      --v6;
    v8 = &__first[v6];
    v9 = &__first[v5];
    *(_QWORD *)&v9->upper_value = *(_QWORD *)&v8->upper_value;
    v5 = v6;
    *(_QWORD *)&v9->tangent_in = *(_QWORD *)&v8->tangent_in;
    v6 = 2 * v6 + 2;
    i = v6 == __len;
  }
  if ( i )
  {
    v10 = &__first[v6 - 1];
    __first[v5] = *v10;
    v5 = v6 - 1;
  }
  stlp_std::__push_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
    __first,
    v5,
    __holeIndex,
    __val,
    __comp);
}


void __cdecl stlp_std::__adjust_heap<vostok::particle::curve_point<float> *,int,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        int __holeIndex,
        int __len,
        vostok::particle::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  vostok::particle::curve_point<float> *v5; // edx
  vostok::particle::curve_point<float> *v6; // eax
  vostok::particle::curve_point<float> *v7; // ecx
  vostok::particle::curve_point<float> *v8; // edx
  vostok::particle::curve_point<float> *v9; // edx
  vostok::particle::curve_point<float> *v10; // eax
  vostok::particle::curve_point<float> v11; // [esp+0h] [ebp-28h] BYREF
  int v12; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  int __secondChild; // [esp+20h] [ebp-8h]
  int __topIndex; // [esp+24h] [ebp-4h]

  __topIndex = __holeIndex;
  for ( __secondChild = 2 * __holeIndex + 2; __secondChild < __len; __secondChild = 2 * __secondChild + 2 )
  {
    if ( __comp(&__first[__secondChild], &__first[__secondChild - 1]) )
      --__secondChild;
    v5 = &__first[__secondChild];
    v6 = &__first[__holeIndex];
    v6->upper_value = v5->upper_value;
    v6->lower_value = v5->lower_value;
    v6->tangent_in = v5->tangent_in;
    v6->tangent_out = v5->tangent_out;
    v6->time = v5->time;
    v6->interp_type = v5->interp_type;
    __holeIndex = __secondChild;
  }
  if ( __secondChild == __len )
  {
    v7 = &__first[__secondChild - 1];
    v8 = &__first[__holeIndex];
    v8->upper_value = v7->upper_value;
    v8->lower_value = v7->lower_value;
    v8->tangent_in = v7->tangent_in;
    v8->tangent_out = v7->tangent_out;
    v8->time = v7->time;
    v8->interp_type = v7->interp_type;
    __holeIndex = __secondChild - 1;
  }
  v11 = __val;
  v12 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v12 > __topIndex && __comp(&__first[i], &v11); i = (i - 1) / 2 )
  {
    v9 = &__first[i];
    v10 = &__first[v12];
    v10->upper_value = v9->upper_value;
    v10->lower_value = v9->lower_value;
    v10->tangent_in = v9->tangent_in;
    v10->tangent_out = v9->tangent_out;
    v10->time = v9->time;
    v10->interp_type = v9->interp_type;
    v12 = i;
  }
  __first[v12] = v11;
}


void __cdecl stlp_std::__adjust_heap<vostok::math::curve_point<vostok::math::float4_pod> *,int,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        int __holeIndex,
        int __len,
        vostok::math::curve_point<vostok::math::float4_pod> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  int v5; // ebp
  int v6; // ebx
  bool v7; // zf
  int v8; // eax
  vostok::math::curve_point<vostok::math::float4_pod> *v9; // esi
  vostok::math::curve_point<vostok::math::float4_pod> v10; // [esp-4Ch] [ebp-5Ch] BYREF

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  while ( v6 < __len )
  {
    if ( __comp(&__first[v6], &__first[v6 - 1]) )
      --v6;
    v8 = v5;
    v9 = &__first[v6];
    v5 = v6;
    v6 = 2 * v6 + 2;
    v7 = v6 == __len;
    qmemcpy(&__first[v8], v9, sizeof(vostok::math::curve_point<vostok::math::float4_pod>));
  }
  if ( v7 )
  {
    qmemcpy(&__first[v5], &__first[v6 - 1], sizeof(vostok::math::curve_point<vostok::math::float4_pod>));
    v5 = v6 - 1;
  }
  qmemcpy(&v10, &__val, sizeof(v10));
  stlp_std::__push_heap<vostok::math::curve_point<vostok::math::float4_pod> *,int,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
    __first,
    v5,
    __holeIndex,
    v10,
    __comp);
}


void __cdecl stlp_std::__adjust_heap<stlp_std::pair<vostok::ai::npc const *,float> *,int,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        int __holeIndex,
        int __len,
        stlp_std::pair<vostok::ai::npc const *,float> __val,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  float second; // eax
  float v6; // eax
  float v7; // edx
  int v8; // [esp+4h] [ebp-20h]
  stlp_std::pair<vostok::ai::npc const *,float> v9; // [esp+8h] [ebp-1Ch] BYREF
  int i; // [esp+10h] [ebp-14h]
  stlp_std::pair<vostok::ai::npc const *,float> *v11; // [esp+14h] [ebp-10h]
  int __secondChild; // [esp+1Ch] [ebp-8h]
  int __topIndex; // [esp+20h] [ebp-4h]

  __topIndex = __holeIndex;
  for ( __secondChild = 2 * __holeIndex + 2; __secondChild < __len; __secondChild = 2 * __secondChild + 2 )
  {
    if ( __comp(&__first[__secondChild], &__first[__secondChild - 1]) )
      --__secondChild;
    second = __first[__secondChild].second;
    __first[__holeIndex].first = __first[__secondChild].first;
    __first[__holeIndex].second = second;
    __holeIndex = __secondChild;
  }
  if ( __secondChild == __len )
  {
    v6 = __first[__secondChild - 1].second;
    __first[__holeIndex].first = __first[__secondChild - 1].first;
    __first[__holeIndex].second = v6;
    __holeIndex = __secondChild - 1;
  }
  v11 = &v9;
  v9 = __val;
  v8 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v8 > __topIndex && __comp(&__first[i], &v9); i = (i - 1) / 2 )
  {
    v7 = __first[i].second;
    __first[v8].first = __first[i].first;
    __first[v8].second = v7;
    v8 = i;
  }
  __first[v8] = v9;
}


void __cdecl stlp_std::__adjust_heap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,int,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        int __holeIndex,
        int __len,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> __val,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  unsigned int second; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  int v8; // [esp+4h] [ebp-20h]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> v9; // [esp+8h] [ebp-1Ch] BYREF
  int i; // [esp+10h] [ebp-14h]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *v11; // [esp+14h] [ebp-10h]
  int __secondChild; // [esp+1Ch] [ebp-8h]
  int __topIndex; // [esp+20h] [ebp-4h]

  __topIndex = __holeIndex;
  for ( __secondChild = 2 * __holeIndex + 2; __secondChild < __len; __secondChild = 2 * __secondChild + 2 )
  {
    if ( __comp(&__first[__secondChild], &__first[__secondChild - 1]) )
      --__secondChild;
    second = __first[__secondChild].second;
    __first[__holeIndex].first = __first[__secondChild].first;
    __first[__holeIndex].second = second;
    __holeIndex = __secondChild;
  }
  if ( __secondChild == __len )
  {
    v6 = __first[__secondChild - 1].second;
    __first[__holeIndex].first = __first[__secondChild - 1].first;
    __first[__holeIndex].second = v6;
    __holeIndex = __secondChild - 1;
  }
  v11 = &v9;
  v9 = __val;
  v8 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v8 > __topIndex && __comp(&__first[i], &v9); i = (i - 1) / 2 )
  {
    v7 = __first[i].second;
    __first[v8].first = __first[i].first;
    __first[v8].second = v7;
    v8 = i;
  }
  __first[v8] = v9;
}


void __usercall stlp_std::__adjust_heap<vostok::render::custom_config_value *,int,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        int __holeIndex@<eax>,
        vostok::render::custom_config_value *__first,
        int __len,
        vostok::render::custom_config_value __val,
        bool (__cdecl *__comp)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))
{
  int v6; // edi
  int v7; // esi
  bool i; // zf
  vostok::render::custom_config_value *v10; // eax
  vostok::render::custom_config_value *v11; // ecx
  vostok::render::custom_config_value *v12; // eax

  v6 = __holeIndex;
  v7 = 2 * __holeIndex + 2;
  for ( i = v7 == __len; v7 < __len; v11->destroyer = v10->destroyer )
  {
    if ( __comp(&__first[v7], &__first[v7 - 1]) )
      --v7;
    v10 = &__first[v7];
    v11 = &__first[v6];
    *(_QWORD *)&v11->id = *(_QWORD *)&v10->id;
    *(_QWORD *)&v11->id_crc = *(_QWORD *)&v10->id_crc;
    v6 = v7;
    v7 = 2 * v7 + 2;
    i = v7 == __len;
  }
  if ( i )
  {
    v12 = &__first[v7 - 1];
    __first[v6] = *v12;
    v6 = v7 - 1;
  }
  stlp_std::__push_heap<vostok::render::custom_config_value *,int,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
    __first,
    v6,
    __holeIndex,
    __val,
    __comp);
}


void __usercall stlp_std::__adjust_heap<vostok::render::shader_constant *,int,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        int __holeIndex@<eax>,
        vostok::render::shader_constant *__first,
        int __len,
        vostok::render::shader_constant __val,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  int v6; // edi
  int v7; // esi
  bool i; // zf
  vostok::render::shader_constant *v10; // eax
  vostok::render::shader_constant *v11; // ecx
  vostok::render::shader_constant *v12; // ecx
  vostok::render::shader_constant *v13; // eax

  v6 = __holeIndex;
  v7 = 2 * __holeIndex + 2;
  for ( i = v7 == __len; v7 < __len; i = v7 == __len )
  {
    if ( __comp(&__first[v7], &__first[v7 - 1]) )
      --v7;
    v10 = &__first[v6];
    v11 = &__first[v7];
    if ( v10 )
    {
      *(_DWORD *)&v10->m_slot.m_class_id = *(_DWORD *)&v11->m_slot.m_class_id;
      HIDWORD(v10->m_slot.m_value) = HIDWORD(v11->m_slot.m_value);
      v10->m_source.m_pointer = v11->m_source.m_pointer;
      v10->m_source.m_size = v11->m_source.m_size;
      v10->m_host = v11->m_host;
    }
    v6 = v7;
    v7 = 2 * v7 + 2;
  }
  if ( i )
  {
    v12 = &__first[v7 - 1];
    v13 = &__first[v6];
    if ( v13 )
    {
      *(_DWORD *)&v13->m_slot.m_class_id = *(_DWORD *)&v12->m_slot.m_class_id;
      HIDWORD(v13->m_slot.m_value) = HIDWORD(v12->m_slot.m_value);
      v13->m_source.m_pointer = v12->m_source.m_pointer;
      v13->m_source.m_size = v12->m_source.m_size;
      v13->m_host = v12->m_host;
    }
    v6 = v7 - 1;
  }
  stlp_std::__push_heap<vostok::render::shader_constant *,int,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
    __first,
    v6,
    __holeIndex,
    __val,
    __comp);
}
