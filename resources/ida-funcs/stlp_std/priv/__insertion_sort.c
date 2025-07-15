void __cdecl stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        unsigned int *__first,
        unsigned int *__last,
        unsigned int *__formal)
{
  unsigned __int8 *v3; // ebx
  unsigned int *v4; // esi
  unsigned int *v5; // ebp
  signed int v6; // edi
  unsigned int v7; // eax
  unsigned int *v8; // edx
  unsigned __int8 *i; // eax
  unsigned int v10; // [esp+4h] [ebp-4h]

  v3 = (unsigned __int8 *)__first;
  if ( __first != __last )
  {
    v4 = __first + 1;
    if ( __first + 1 != __last )
    {
      v5 = __formal;
      v6 = 4;
      do
      {
        v7 = *v4;
        v10 = *v4;
        if ( *(float *)&v5[*(_DWORD *)v3] <= *(float *)&v5[*v4] )
        {
          v8 = v4;
          for ( i = &v3[v6 - 4]; *(float *)&v5[*(_DWORD *)i] > *(float *)&v5[v10]; i -= 4 )
          {
            *v8 = *(_DWORD *)i;
            v8 = (unsigned int *)i;
          }
          *v8 = v10;
          v3 = (unsigned __int8 *)__first;
        }
        else
        {
          if ( v6 > 0 )
          {
            memmove((unsigned __int8 *)&v4[v6 / 0xFFFFFFFC + 1], v3, v6);
            v5 = __formal;
            v7 = v10;
          }
          *(_DWORD *)v3 = v7;
        }
        ++v4;
        v6 += 4;
      }
      while ( v4 != __last );
    }
  }
}


void __cdecl stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        unsigned int *__first,
        unsigned int *__last)
{
  unsigned int *i; // esi
  unsigned int v3; // edi
  unsigned int v4; // ecx
  unsigned int *v5; // eax
  unsigned int *j; // edx

  if ( __first != __last )
  {
    for ( i = __first + 1; i != __last; ++i )
    {
      v3 = *i;
      if ( *i >= *__first )
      {
        v4 = *(i - 1);
        v5 = i - 1;
        for ( j = i; v3 < v4; --v5 )
        {
          *j = v4;
          v4 = *(v5 - 1);
          j = v5;
        }
        *j = v3;
      }
      else
      {
        if ( (char *)i - (char *)__first > 0 )
          memmove((unsigned __int8 *)__first + 4, (unsigned __int8 *)__first, (char *)i - (char *)__first);
        *__first = v3;
      }
    }
  }
}


void __cdecl stlp_std::priv::__insertion_sort<float *,float,stlp_std::less<float>>(float *__first, float *__last)
{
  float *v3; // esi
  int v4; // edi
  float v5; // xmm1_4
  float *v6; // ecx
  float *i; // eax
  float *__lasta; // [esp+10h] [ebp+8h]

  if ( __first != __last )
  {
    v3 = __first + 1;
    if ( __first + 1 != __last )
    {
      v4 = 4;
      do
      {
        v5 = *v3;
        __lasta = *(float **)v3;
        if ( *__first <= *v3 )
        {
          v6 = v3;
          for ( i = &__first[v4 / 4u - 1]; *i > v5; --i )
          {
            *v6 = *i;
            v6 = i;
          }
          *v6 = v5;
        }
        else
        {
          if ( v4 > 0 )
          {
            memmove((unsigned __int8 *)&v3[v4 / 0xFFFFFFFC + 1], (unsigned __int8 *)__first, v4);
            v5 = *(float *)&__lasta;
          }
          *__first = v5;
        }
        ++v3;
        v4 += 4;
      }
      while ( v3 != __last );
    }
  }
}


void __usercall stlp_std::priv::__insertion_sort<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<eax>,
        vostok::render::grass_patch **__last,
        int a3)
{
  vostok::render::grass_patch **i; // esi
  vostok::render::sort_grass_patch_predicate v5; // [esp-Ch] [ebp-1Ch]

  for ( i = __first + 1; i != __last; ++i )
  {
    *(_QWORD *)&v5.m_view_pos.x = *(_QWORD *)a3;
    v5.m_view_pos.z = *(float *)(a3 + 8);
    stlp_std::priv::__linear_insert<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
      __first,
      i,
      *i,
      v5);
  }
}


void __cdecl stlp_std::priv::__insertion_sort<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
        vostok::render::render_surface_instance **__first,
        vostok::render::render_surface_instance **__last,
        vostok::render::render_surface_instance **a3)
{
  const vostok::render::render_surface_instance **v3; // ecx
  vostok::render::render_surface_instance **v4; // esi
  signed int v5; // ebx
  vostok::render::enum_render_stage_type v6; // edx
  const vostok::render::render_surface_instance *v7; // ecx
  vostok::render::render_surface_instance *v8; // ebp
  vostok::render::sort_by_ps_predicate v9; // [esp+10h] [ebp-8h] BYREF

  v3 = (const vostok::render::render_surface_instance **)__first;
  v4 = __first + 1;
  if ( __first + 1 != __last )
  {
    v5 = 4;
    while ( 1 )
    {
      v6 = (vostok::render::enum_render_stage_type)*a3;
      v7 = *v3;
      v8 = *v4;
      v9.m_tech_index = (unsigned int)a3[1];
      v9.m_stage_type = v6;
      if ( vostok::render::sort_by_vs_predicate::operator()(&v9, v8, v7) )
      {
        if ( v5 > 0 )
          memmove((unsigned __int8 *)&v4[v5 / 0xFFFFFFFC + 1], (unsigned __int8 *)__first, v5);
        *__first = v8;
      }
      else
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_ps_predicate>(
          v4,
          v8,
          *(vostok::render::sort_by_ps_predicate *)a3);
      }
      ++v4;
      v5 += 4;
      if ( v4 == __last )
        break;
      v3 = (const vostok::render::render_surface_instance **)__first;
    }
  }
}


void __cdecl stlp_std::priv::__insertion_sort<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        const vostok::ai::sound_item **__formal,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  const vostok::ai::sound_item *__val; // [esp+0h] [ebp-14h]
  const vostok::ai::sound_item **__i; // [esp+10h] [ebp-4h]

  if ( __first != __last )
  {
    for ( __i = __first + 1; __i != __last; ++__i )
    {
      __val = *__i;
      if ( __comp(*__i, *__first) )
      {
        stlp_std::copy_backward<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int> *>(
          (vostok::particle::curve_point<vostok::math::float4_pod> *)__first,
          (vostok::particle::curve_point<vostok::math::float4_pod> *)__i,
          (vostok::particle::curve_point<vostok::math::float4_pod> *)(__i + 1));
        *__first = __val;
      }
      else
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
          __i,
          __val,
          __comp);
      }
    }
  }
}


void __usercall stlp_std::priv::__insertion_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key_compare_predicate *a1@<edi>,
        vostok::command_line::key **__first,
        vostok::command_line::key **__last,
        vostok::command_line::key **a4)
{
  const vostok::command_line::key *const *v4; // eax
  vostok::command_line::key **v5; // ebx
  signed int v6; // ebp
  vostok::command_line::key *v7; // esi
  vostok::command_line::key_compare_predicate *v8; // [esp-Ch] [ebp-14h]
  vostok::command_line::key_compare_predicate __comp; // [esp+4h] [ebp-4h]

  v4 = (const vostok::command_line::key *const *)__first;
  v5 = __first + 1;
  if ( __first + 1 != __last )
  {
    v8 = a1;
    v6 = 4;
    while ( 1 )
    {
      v7 = *v5;
      __comp = *(vostok::command_line::key_compare_predicate *)a4;
      if ( vostok::command_line::key_compare_predicate::operator()(*v5, *v4, v8) )
      {
        if ( v6 > 0 )
          memmove((unsigned __int8 *)&v5[v6 / 0xFFFFFFFC + 1], (unsigned __int8 *)__first, v6);
        *__first = v7;
      }
      else
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
          v5,
          v7,
          __comp);
      }
      ++v5;
      v6 += 4;
      if ( v5 == __last )
        break;
      v4 = (const vostok::command_line::key *const *)__first;
    }
  }
}


void __cdecl stlp_std::priv::__insertion_sort<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
        vostok::resources::query_result **__first,
        vostok::resources::query_result **__last,
        vostok::resources::query_result **__formal)
{
  vostok::resources::query_result **v3; // esi
  signed int v4; // edi
  vostok::resources::query_result *v5; // [esp+0h] [ebp-18h]
  vostok::resources::query_result *__val; // [esp+10h] [ebp-8h]

  if ( __first != __last )
  {
    v3 = __first + 1;
    if ( __first + 1 != __last )
    {
      v4 = 4;
      do
      {
        __val = *v3;
        if ( vostok::resources::hdd_manager_sorting_predicate::operator()(
               *v3,
               (vostok::resources::hdd_manager_sorting_predicate *)*__first,
               v5) )
        {
          if ( v4 > 0 )
            memmove((unsigned __int8 *)&v3[v4 / 0xFFFFFFFC + 1], (unsigned __int8 *)__first, v4);
          *__first = __val;
        }
        else
        {
          stlp_std::priv::__unguarded_linear_insert<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
            v3,
            __val,
            (vostok::resources::hdd_manager_sorting_predicate)__formal);
        }
        ++v3;
        v4 += 4;
      }
      while ( v3 != __last );
    }
  }
}


void __cdecl stlp_std::priv::__insertion_sort<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
        vostok::resources::query_result **__first,
        vostok::resources::query_result **__last)
{
  unsigned __int8 *v2; // ebp
  vostok::resources::query_result **v3; // esi
  signed int v4; // edi
  vostok::resources::query_result *v5; // ebx
  vostok::resources::query_result **v6; // ecx
  int i; // eax

  v2 = (unsigned __int8 *)__first;
  v3 = __first + 1;
  if ( __first + 1 != __last )
  {
    v4 = 4;
    do
    {
      v5 = *v3;
      if ( (*v3)->m_quality_index < *(_DWORD *)(*(_DWORD *)v2 + 680) )
      {
        v6 = v3;
        for ( i = (int)&v2[v4 - 4]; v5->m_quality_index >= *(_DWORD *)(*(_DWORD *)i + 680); i -= 4 )
        {
          *v6 = *(vostok::resources::query_result **)i;
          v6 = (vostok::resources::query_result **)i;
        }
        v2 = (unsigned __int8 *)__first;
        *v6 = v5;
      }
      else
      {
        if ( v4 > 0 )
          memmove((unsigned __int8 *)&v3[v4 / 0xFFFFFFFC + 1], v2, v4);
        *(_DWORD *)v2 = v5;
      }
      ++v3;
      v4 += 4;
    }
    while ( v3 != __last );
  }
}


void __cdecl stlp_std::priv::__insertion_sort<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        vostok::resources::resource_base **__first,
        vostok::resources::resource_base **__last,
        vostok::resources::resource_base **a3)
{
  vostok::resources::resource_base **v3; // esi
  signed int v4; // ebx
  vostok::resources::resource_base *v5; // edi
  float m_current_satisfaction; // xmm1_4

  v3 = __first + 1;
  if ( __first + 1 != __last )
  {
    v4 = 4;
    do
    {
      v5 = *v3;
      m_current_satisfaction = (*__first)->m_current_satisfaction;
      if ( fabs((*v3)->m_current_satisfaction - m_current_satisfaction) >= 0.050000001 )
      {
        if ( (*v3)->m_current_satisfaction > m_current_satisfaction )
        {
LABEL_5:
          if ( v4 > 0 )
            memmove((unsigned __int8 *)&v3[v4 / 0xFFFFFFFC + 1], (unsigned __int8 *)__first, v4);
          *__first = v5;
          goto LABEL_10;
        }
      }
      else if ( v5->m_reconstruction_size < (*__first)->m_reconstruction_size )
      {
        goto LABEL_5;
      }
      stlp_std::priv::__unguarded_linear_insert<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        v3,
        v5,
        *(vostok::resources::sorting_predicate *)a3);
LABEL_10:
      ++v3;
      v4 += 4;
    }
    while ( v3 != __last );
  }
}


void __cdecl stlp_std::priv::__insertion_sort<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        vostok::network_core::udp_match_packet **__formal,
        packets_predicate __comp)
{
  survarium::base_project::resolve_link_object *v4; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v5; // ecx
  vostok::network_core::udp_match_packet *__val; // [esp+8h] [ebp-18h]
  vostok::network_core::udp_match_packet **__i; // [esp+1Ch] [ebp-4h]

  if ( __first != __last )
  {
    for ( __i = __first + 1; __i != __last; ++__i )
    {
      __val = *__i;
      v4 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
             (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)__first,
             (int)*__first);
      if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
             v5,
             (int)__val) >= v4 )
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
          __i,
          __val,
          __comp);
      }
      else
      {
        stlp_std::copy_backward<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int> *>(
          (vostok::particle::curve_point<vostok::math::float4_pod> *)__first,
          (vostok::particle::curve_point<vostok::math::float4_pod> *)__i,
          (vostok::particle::curve_point<vostok::math::float4_pod> *)(__i + 1));
        *__first = __val;
      }
    }
  }
}


void __usercall stlp_std::priv::__insertion_sort<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<eax>,
        vostok::physics::closest_ray_result *__last,
        int a3)
{
  vostok::physics::closest_ray_result *i; // edi
  vostok::physics::distance_predicate v5; // [esp-Ch] [ebp-1Ch]

  for ( i = __first + 1; i != __last; ++i )
  {
    *(_QWORD *)&v5.m_from.x = *(_QWORD *)a3;
    v5.m_from.z = *(float *)(a3 + 8);
    stlp_std::priv::__linear_insert<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      __first,
      i,
      *i,
      v5);
  }
}


void __cdecl stlp_std::priv::__insertion_sort<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        vostok::sound::propagator_info *__formal,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  vostok::sound::propagator_info v4; // [esp+0h] [ebp-24h] BYREF
  vostok::sound::propagator_info *__i; // [esp+20h] [ebp-4h]

  if ( __first != __last )
  {
    for ( __i = __first + 1; __i != __last; ++__i )
    {
      v4 = *__i;
      if ( __comp(&v4, __first) )
      {
        stlp_std::copy_backward<vostok::sound::propagator_info *,vostok::sound::propagator_info *>(
          __first,
          __i,
          __i + 1);
        *__first = v4;
      }
      else
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
          __i,
          v4,
          __comp);
      }
    }
  }
}


void __usercall stlp_std::priv::__insertion_sort<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<eax>,
        vostok::render::grass_patch::sort_info *__last,
        _QWORD *a3)
{
  vostok::render::grass_patch::sort_info *i; // edi
  vostok::render::sort_indices_predicate v5; // [esp-10h] [ebp-20h]

  for ( i = __first + 1; i != __last; ++i )
  {
    *(_QWORD *)&v5.m_patch = *a3;
    *(_QWORD *)&v5.m_view_pos.elements[1] = a3[1];
    stlp_std::priv::__linear_insert<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
      __first,
      i,
      *i,
      v5);
  }
}


void __cdecl stlp_std::priv::__insertion_sort<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> *__last,
        vostok::math::curve_point<float> *__formal,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  vostok::math::curve_point<float> *i; // esi

  if ( __first != __last )
  {
    for ( i = __first + 1; i != __last; ++i )
      stlp_std::priv::__linear_insert<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        __first,
        i,
        *i,
        __comp);
  }
}


void __cdecl stlp_std::priv::__insertion_sort<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        vostok::particle::curve_point<float> *__last,
        vostok::particle::curve_point<float> *__formal,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  vostok::particle::curve_point<float> v4; // [esp+0h] [ebp-28h] BYREF
  vostok::particle::curve_point<float> *__i; // [esp+24h] [ebp-4h]

  if ( __first != __last )
  {
    for ( __i = __first + 1; __i != __last; ++__i )
    {
      v4 = *__i;
      if ( __comp(&v4, __first) )
      {
        stlp_std::copy_backward<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int> *>(
          (vostok::particle::curve_point<vostok::math::float4_pod> *)__first,
          (vostok::particle::curve_point<vostok::math::float4_pod> *)__i,
          (vostok::particle::curve_point<vostok::math::float4_pod> *)&__i[1]);
        *__first = v4;
      }
      else
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
          __i,
          v4,
          __comp);
      }
    }
  }
}


void __cdecl stlp_std::priv::__insertion_sort<vostok::math::curve_point<vostok::math::float4_pod> *,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        vostok::math::curve_point<vostok::math::float4_pod> *__last,
        vostok::math::curve_point<vostok::math::float4_pod> *__formal,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  vostok::math::curve_point<vostok::math::float4_pod> *i; // ebx
  vostok::math::curve_point<vostok::math::float4_pod> v5; // [esp-48h] [ebp-58h] BYREF

  if ( __first != __last )
  {
    for ( i = __first + 1; i != __last; ++i )
    {
      qmemcpy(&v5, i, sizeof(v5));
      stlp_std::priv::__linear_insert<vostok::math::curve_point<vostok::math::float4_pod> *,vostok::math::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        __first,
        i,
        v5,
        __comp);
    }
  }
}


void __cdecl stlp_std::priv::__insertion_sort<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        stlp_std::pair<vostok::ai::npc const *,float> *__formal,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  _DWORD v4[10]; // [esp-Ch] [ebp-2Ch] BYREF
  stlp_std::pair<vostok::ai::npc const *,float> *__i; // [esp+1Ch] [ebp-4h]

  if ( __first != __last )
  {
    for ( __i = __first + 1; __i != __last; ++__i )
    {
      v4[2] = __comp;
      v4[8] = v4;
      stlp_std::priv::__linear_insert<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        __first,
        __i,
        *__i,
        __comp);
    }
  }
}


void __cdecl stlp_std::priv::__insertion_sort<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__formal,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  _DWORD v4[10]; // [esp-Ch] [ebp-2Ch] BYREF
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__i; // [esp+1Ch] [ebp-4h]

  if ( __first != __last )
  {
    for ( __i = __first + 1; __i != __last; ++__i )
    {
      v4[2] = __comp;
      v4[8] = v4;
      stlp_std::priv::__linear_insert<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        __first,
        __i,
        *__i,
        __comp);
    }
  }
}


void __usercall stlp_std::priv::__insertion_sort<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value *__first@<eax>,
        vostok::render::custom_config_value *__last)
{
  vostok::render::custom_config_value *i; // edi
  bool (__cdecl *v4)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *); // [esp+0h] [ebp-Ch]

  for ( i = __first + 1; i != __last; ++i )
    stlp_std::priv::__linear_insert<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      __first,
      i,
      *i,
      v4);
}


void __usercall stlp_std::priv::__insertion_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first@<eax>,
        vostok::render::shader_constant *__last)
{
  vostok::render::shader_constant *i; // edi
  vostok::render::shader_constant v4; // [esp-18h] [ebp-24h]
  bool (__cdecl *v5)(const vostok::render::shader_constant *, const vostok::render::shader_constant *); // [esp+0h] [ebp-Ch]

  for ( i = __first + 1; i != __last; ++i )
  {
    v4.m_slot.m_value = i->m_slot.m_value;
    v4.m_source.m_pointer = i->m_source.m_pointer;
    v4.m_source.m_size = i->m_source.m_size;
    v4.m_host = i->m_host;
    stlp_std::priv::__linear_insert<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      __first,
      i,
      v4,
      v5);
  }
}
