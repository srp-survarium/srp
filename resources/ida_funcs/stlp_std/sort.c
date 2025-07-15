void __usercall stlp_std::sort<unsigned int *>(
        unsigned int *__first@<edi>,
        stlp_std::less<unsigned int> a2@<sil>,
        unsigned int *__last)
{
  int v3; // eax
  int i; // ecx
  stlp_std::less<unsigned int> v5; // [esp-10h] [ebp-14h]

  if ( __first != __last )
  {
    v3 = __last - __first;
    for ( i = 0; v3 != 1; ++i )
      v3 >>= 1;
    stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,stlp_std::less<unsigned int>>(
      __first,
      __last,
      0,
      2 * i,
      (stlp_std::less<unsigned int>)__last);
    if ( __last - __first <= 16 )
    {
      stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        __first,
        __last,
        __last,
        a2);
    }
    else
    {
      stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        __first,
        __first + 16,
        __last,
        a2);
      stlp_std::priv::__unguarded_insertion_sort_aux<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        __first + 16,
        __last,
        __last,
        v5);
    }
  }
}


void __usercall stlp_std::sort<unsigned int *,vostok::render::culling::portal_id_closer_to_point>(
        unsigned int *__first@<edi>,
        vostok::render::culling::portal_id_closer_to_point a2@<ebp>,
        unsigned int *__last,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  int v4; // eax
  int i; // ecx
  vostok::render::culling::portal_id_closer_to_point v6; // [esp-14h] [ebp-18h]

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,vostok::render::culling::portal_id_closer_to_point>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    if ( __last - __first <= 16 )
    {
      stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        __first,
        __last,
        (unsigned int *)__comp.m_distances,
        a2);
    }
    else
    {
      stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        __first,
        __first + 16,
        (unsigned int *)__comp.m_distances,
        a2);
      stlp_std::priv::__unguarded_insertion_sort_aux<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        __first + 16,
        __last,
        (unsigned int *)__comp.m_distances,
        v6);
    }
  }
}


void __usercall stlp_std::sort<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<esi>,
        vostok::render::grass_patch **__last@<eax>,
        vostok::render::sort_grass_patch_predicate __comp)
{
  int v4; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::render::grass_patch * *,vostok::render::grass_patch *,int,vostok::render::sort_grass_patch_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate>(
      __first,
      __last,
      __comp);
  }
}


void __usercall stlp_std::sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_node_comparer>(
        vostok::animation::mixing::n_ary_tree_base_node **__first@<edi>,
        vostok::animation::mixing::n_ary_tree_base_node **__last@<eax>,
        vostok::animation::mixing::n_ary_tree_node_comparer __comp)
{
  int v4; // eax
  int i; // ecx
  vostok::animation::mixing::n_ary_tree_node_comparer v6; // [esp-8h] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_node_comparer v7; // [esp-8h] [ebp-Ch]

  if ( __first != __last )
  {
    v6.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v6.result = __comp.result;
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_base_node *,int,vostok::animation::mixing::n_ary_tree_node_comparer>(
      __first,
      __last,
      0,
      2 * i,
      v6);
    v7.__vftable = (vostok::animation::mixing::n_ary_tree_node_comparer_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v7.result = __comp.result;
    stlp_std::priv::__final_insertion_sort<vostok::animation::mixing::n_ary_tree_base_node * *,vostok::animation::mixing::n_ary_tree_node_comparer>(
      __first,
      __last,
      v7);
  }
}


void __usercall stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_distance_predicate>(
        vostok::render::render_surface_instance **__first@<edi>,
        vostok::render::render_surface_instance **__last@<esi>,
        vostok::render::sort_by_distance_predicate __comp)
{
  int v3; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v3 = __last - __first;
    for ( i = 0; v3 != 1; ++i )
      v3 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,int,vostok::render::sort_by_distance_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_distance_predicate>(
      __first,
      __last,
      __comp);
  }
}


void __usercall stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_texture_predicate>(
        vostok::render::render_surface_instance **__first@<esi>,
        vostok::render::render_surface_instance **__last@<eax>,
        vostok::render::sort_by_texture_predicate __comp)
{
  int v4; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,int,vostok::render::sort_by_texture_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_texture_predicate>(
      __first,
      __last,
      __comp);
  }
}


void __usercall stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate>(
        vostok::render::render_surface_instance **__first@<esi>,
        vostok::render::render_surface_instance **__last@<eax>,
        vostok::render::sort_by_ps_predicate __comp)
{
  int v4; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,int,vostok::render::sort_by_ps_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_ps_predicate>(
      __first,
      __last,
      __comp);
  }
}


void __cdecl stlp_std::sort<vostok::physics::base_physics_object * *>(
        vostok::physics::base_physics_object **__first,
        vostok::physics::base_physics_object **__last)
{
  int v2; // eax
  survarium::game_camera *v3; // ecx
  stlp_std::less<vostok::physics::base_physics_object *> *v4; // eax
  survarium::game_camera *v5; // ecx
  stlp_std::less<vostok::physics::base_physics_object *> v6; // [esp-4h] [ebp-Ch]
  stlp_std::less<vostok::physics::base_physics_object *> v7; // [esp+6h] [ebp-2h] BYREF
  stlp_std::less<vostok::physics::base_physics_object *> result; // [esp+7h] [ebp-1h] BYREF

  if ( __first != __last )
  {
    v6.gap0 = stlp_std::priv::__less<vostok::physics::base_physics_object *>(&result, 0)->gap0;
    v2 = stlp_std::priv::__lg<int>(__last - __first);
    stlp_std::priv::__introsort_loop<vostok::physics::base_physics_object * *,vostok::physics::base_physics_object *,int,stlp_std::less<vostok::physics::base_physics_object *>>(
      __first,
      __last,
      0,
      2 * v2,
      v6);
    survarium::weapon_user_dead_state::finalize(v3);
    v4 = stlp_std::priv::__less<vostok::physics::base_physics_object *>(&v7, 0);
    stlp_std::priv::__final_insertion_sort<vostok::physics::base_physics_object * *,stlp_std::less<vostok::physics::base_physics_object *>>(
      __first,
      __last,
      (stlp_std::less<vostok::physics::base_physics_object *>)v4->gap0);
    survarium::weapon_user_dead_state::finalize(v5);
  }
}


void __usercall stlp_std::sort<vostok::command_line::key * *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key **__first@<esi>,
        vostok::command_line::key **__last@<eax>,
        vostok::command_line::key_compare_predicate __comp)
{
  int v4; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::command_line::key * *,vostok::command_line::key *,int,vostok::command_line::key_compare_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::command_line::key * *,vostok::command_line::key_compare_predicate>(
      __first,
      __last,
      __comp);
  }
}


void __cdecl stlp_std::sort<vostok::network_core::udp_match_packet * *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        packets_predicate __comp)
{
  int v3; // eax

  if ( __first != __last )
  {
    v3 = stlp_std::priv::__lg<int>(__last - __first);
    stlp_std::priv::__introsort_loop<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,int,packets_predicate>(
      __first,
      __last,
      0,
      2 * v3,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::network_core::udp_match_packet * *,packets_predicate>(
      __first,
      __last,
      __comp);
  }
}


void __cdecl stlp_std::sort<vostok::ai::animation_item const * *,bool (__cdecl *)(vostok::ai::animation_item const *,vostok::ai::animation_item const *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  int v3; // eax

  if ( __first != __last )
  {
    v3 = stlp_std::priv::__lg<int>(__last - __first);
    stlp_std::priv::__introsort_loop<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,int,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
      __first,
      __last,
      0,
      2 * v3,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::ai::sound_item const * *,bool (__cdecl *)(vostok::ai::sound_item const *,vostok::ai::sound_item const *)>(
      __first,
      __last,
      __comp);
  }
}


void __cdecl stlp_std::sort<vostok::ai::movement_target const * *,vostok::ai::selectors::sort_by_distance_predicate>(
        const vostok::ai::movement_target **__first,
        const vostok::ai::movement_target **__last,
        vostok::ai::selectors::sort_by_distance_predicate __comp)
{
  int v3; // eax

  if ( __first != __last )
  {
    v3 = stlp_std::priv::__lg<int>(__last - __first);
    stlp_std::priv::__introsort_loop<vostok::ai::movement_target const * *,vostok::ai::movement_target const *,int,vostok::ai::selectors::sort_by_distance_predicate>(
      __first,
      __last,
      0,
      2 * v3,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::ai::movement_target const * *,vostok::ai::selectors::sort_by_distance_predicate>(
      __first,
      __last,
      __comp);
  }
}


void __usercall stlp_std::sort<void const * *>(const void **__first@<edi>, const void **__last)
{
  int v2; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v2 = __last - __first;
    for ( i = 0; v2 != 1; ++i )
      v2 >>= 1;
    stlp_std::priv::__introsort_loop<void const * *,void const *,int,stlp_std::less<void const *>>(
      __first,
      __last,
      0,
      2 * i,
      (stlp_std::less<void const *>)__last);
    if ( __last - __first <= 16 )
    {
      stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        (unsigned int *)__first,
        (unsigned int *)__last);
    }
    else
    {
      stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        (unsigned int *)__first,
        (unsigned int *)__first + 16);
      stlp_std::priv::__unguarded_insertion_sort_aux<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        (unsigned int *)__first + 16,
        (unsigned int *)__last);
    }
  }
}


void __usercall stlp_std::sort<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result *__first@<eax>,
        vostok::physics::closest_ray_result *__last@<edi>,
        vostok::physics::distance_predicate __comp)
{
  int v4; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,int,vostok::physics::distance_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate>(
      __first,
      __last,
      __comp);
  }
}


void __cdecl stlp_std::sort<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  int v3; // [esp+0h] [ebp-8h]
  int v4; // [esp+4h] [ebp-4h]

  if ( __first != __last )
  {
    v3 = __last - __first;
    v4 = 0;
    while ( v3 != 1 )
    {
      ++v4;
      v3 >>= 1;
    }
    stlp_std::priv::__introsort_loop<vostok::sound::propagator_info *,vostok::sound::propagator_info,int,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __first,
      __last,
      0,
      2 * v4,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __first,
      __last,
      __comp);
  }
}


void __usercall stlp_std::sort<vostok::collision::ray_object_result *,vostok::collision::colliders::object::distance_predicate>(
        vostok::collision::ray_object_result *__first@<esi>,
        vostok::collision::ray_object_result *__last@<eax>,
        vostok::collision::colliders::object::distance_predicate __comp)
{
  int v4; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::collision::ray_object_result *,vostok::collision::ray_object_result,int,vostok::collision::colliders::object::distance_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::collision::ray_object_result *,vostok::collision::colliders::object::distance_predicate>(
      __first,
      __last,
      __comp);
  }
}


void __usercall stlp_std::sort<vostok::collision::ray_triangle_result *,vostok::collision::colliders::object::distance_predicate>(
        vostok::collision::ray_triangle_result *__first@<eax>,
        vostok::collision::ray_triangle_result *__last@<edi>,
        vostok::collision::colliders::object::distance_predicate __comp)
{
  int v4; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::collision::ray_triangle_result *,vostok::collision::ray_triangle_result,int,vostok::collision::colliders::object::distance_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::collision::ray_triangle_result *,vostok::collision::colliders::object::distance_predicate>(
      __first,
      __last,
      __comp);
  }
}


void __usercall stlp_std::sort<vostok::memory::platform::region *>(
        vostok::memory::platform::region *__first@<edi>,
        vostok::memory::platform::region *__last@<esi>,
        stlp_std::less<vostok::memory::platform::region> a3@<cl>)
{
  int v3; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v3 = __last - __first;
    for ( i = 0; v3 != 1; ++i )
      v3 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::memory::platform::region *,vostok::memory::platform::region,int,stlp_std::less<vostok::memory::platform::region>>(
      __first,
      __last,
      0,
      2 * i,
      a3);
    stlp_std::priv::__final_insertion_sort<vostok::memory::platform::region *,stlp_std::less<vostok::memory::platform::region>>(
      __first,
      __last,
      a3);
  }
}


void __usercall stlp_std::sort<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<eax>,
        vostok::render::grass_patch::sort_info *__last@<edi>,
        vostok::render::sort_indices_predicate __comp)
{
  int v4; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,int,vostok::render::sort_indices_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate>(
      __first,
      __last,
      __comp);
  }
}


void __cdecl stlp_std::sort<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> *__last,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  int v3; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v3 = __last - __first;
    for ( i = 0; v3 != 1; ++i )
      v3 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,int,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      __first,
      __last,
      __comp);
  }
}


void __cdecl stlp_std::sort<vostok::particle::curve_point<float> *,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        vostok::particle::curve_point<float> *__last,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  int v3; // eax

  if ( __first != __last )
  {
    v3 = stlp_std::priv::__lg<int>(__last - __first);
    stlp_std::priv::__introsort_loop<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,int,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
      __first,
      __last,
      0,
      2 * v3,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::particle::curve_point<float> *,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
      __first,
      __last,
      __comp);
  }
}


void __cdecl stlp_std::sort<vostok::math::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
        vostok::math::curve_point<vostok::math::float4_pod> *__first,
        vostok::math::curve_point<vostok::math::float4_pod> *__last,
        bool (__cdecl *__comp)(const vostok::math::curve_point<vostok::math::float4_pod> *, const vostok::math::curve_point<vostok::math::float4_pod> *))
{
  int v3; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v3 = __last - __first;
    for ( i = 0; v3 != 1; ++i )
      v3 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::math::curve_point<vostok::math::float4_pod> *,vostok::math::curve_point<vostok::math::float4_pod>,int,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::math::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::math::curve_point<vostok::math::float4_pod> const &,vostok::math::curve_point<vostok::math::float4_pod> const &)>(
      __first,
      __last,
      __comp);
  }
}


void __cdecl stlp_std::sort<vostok::particle::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::particle::curve_point<vostok::math::float4_pod> const &,vostok::particle::curve_point<vostok::math::float4_pod> const &)>(
        vostok::particle::curve_point<vostok::math::float4_pod> *__first,
        vostok::particle::curve_point<vostok::math::float4_pod> *__last,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<vostok::math::float4_pod> *, const vostok::particle::curve_point<vostok::math::float4_pod> *))
{
  int v3; // eax

  if ( __first != __last )
  {
    v3 = stlp_std::priv::__lg<int>(__last - __first);
    stlp_std::priv::__introsort_loop<vostok::particle::curve_point<vostok::math::float4_pod> *,vostok::particle::curve_point<vostok::math::float4_pod>,int,bool (__cdecl *)(vostok::particle::curve_point<vostok::math::float4_pod> const &,vostok::particle::curve_point<vostok::math::float4_pod> const &)>(
      __first,
      __last,
      0,
      2 * v3,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::particle::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::particle::curve_point<vostok::math::float4_pod> const &,vostok::particle::curve_point<vostok::math::float4_pod> const &)>(
      __first,
      __last,
      __comp);
  }
}


void __cdecl stlp_std::sort<stlp_std::pair<vostok::ai::npc const *,float> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  int v3; // eax

  if ( __first != __last )
  {
    v3 = stlp_std::priv::__lg<int>(__last - __first);
    stlp_std::priv::__introsort_loop<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,int,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
      __first,
      __last,
      0,
      2 * v3,
      __comp);
    stlp_std::priv::__final_insertion_sort<stlp_std::pair<vostok::ai::npc const *,float> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
      __first,
      __last,
      __comp);
  }
}


void __cdecl stlp_std::sort<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  int v3; // eax

  if ( __first != __last )
  {
    v3 = stlp_std::priv::__lg<int>(__last - __first);
    stlp_std::priv::__introsort_loop<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,int,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
      __first,
      __last,
      0,
      2 * v3,
      __comp);
    stlp_std::priv::__final_insertion_sort<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
      __first,
      __last,
      __comp);
  }
}


void __usercall stlp_std::sort<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value *__first@<eax>,
        vostok::render::custom_config_value *__last@<edi>)
{
  int v3; // eax
  int i; // ecx
  bool (__cdecl *v5)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *); // [esp+0h] [ebp-4h]

  if ( __first != __last )
  {
    v3 = __last - __first;
    for ( i = 0; v3 != 1; ++i )
      v3 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::render::custom_config_value *,vostok::render::custom_config_value,int,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      __first,
      __last,
      0,
      2 * i,
      vostok::render::sort_by_crc_vostok::render::custom_config_value__::_5_::predicate::compare);
    stlp_std::priv::__final_insertion_sort<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      __first,
      __last,
      v5);
  }
}
