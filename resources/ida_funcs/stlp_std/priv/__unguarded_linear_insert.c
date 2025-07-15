void __usercall stlp_std::priv::__unguarded_linear_insert<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__last@<edx>,
        vostok::render::grass_patch *__val@<esi>,
        vostok::render::sort_grass_patch_predicate __comp)
{
  vostok::render::grass_patch **v3; // ecx
  float v4; // xmm3_4

  v3 = __last - 1;
  v4 = (float)((float)((float)(__val->m_origin.z - __comp.m_view_pos.z)
                     * (float)(__val->m_origin.z - __comp.m_view_pos.z))
             + (float)((float)(__val->m_origin.x - __comp.m_view_pos.x)
                     * (float)(__val->m_origin.x - __comp.m_view_pos.x)))
     + (float)((float)(__val->m_origin.y - __comp.m_view_pos.y) * (float)(__val->m_origin.y - __comp.m_view_pos.y));
  while ( (float)((float)((float)((float)((*v3)->m_origin.z - __comp.m_view_pos.z)
                                * (float)((*v3)->m_origin.z - __comp.m_view_pos.z))
                        + (float)((float)((*v3)->m_origin.y - __comp.m_view_pos.y)
                                * (float)((*v3)->m_origin.y - __comp.m_view_pos.y)))
                + (float)((float)((*v3)->m_origin.x - __comp.m_view_pos.x)
                        * (float)((*v3)->m_origin.x - __comp.m_view_pos.x))) > v4 )
  {
    *__last = *v3;
    __last = v3--;
  }
  *__last = __val;
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::ai::planning::goal * *,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        const vostok::ai::sound_item **__last,
        const vostok::ai::sound_item *__val,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  const vostok::ai::sound_item **__next; // [esp+0h] [ebp-4h]

  for ( __next = __last - 1; __comp(__val, *__next); --__next )
  {
    *__last = *__next;
    __last = __next;
  }
  *__last = __val;
}


void __usercall stlp_std::priv::__unguarded_linear_insert<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key *__val@<eax>,
        vostok::command_line::key **__last)
{
  vostok::command_line::key **v2; // ebp
  const vostok::command_line::key *v3; // edi
  vostok::command_line::key **v4; // ebx
  vostok::command_line::key_compare_predicate *v6; // [esp+0h] [ebp-10h]
  vostok::command_line::key_compare_predicate *v7; // [esp+0h] [ebp-10h]

  v2 = __last;
  v3 = *(__last - 1);
  v4 = __last - 1;
  if ( vostok::command_line::key_compare_predicate::operator()(__val, v3, v6) )
  {
    do
    {
      *v2 = (vostok::command_line::key *)v3;
      v3 = *(v4 - 1);
      v2 = v4--;
    }
    while ( vostok::command_line::key_compare_predicate::operator()(__val, v3, v7) );
  }
  *v2 = __val;
}


void __usercall stlp_std::priv::__unguarded_linear_insert<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        vostok::resources::resource_base **__last@<eax>,
        vostok::resources::resource_base *__val@<edi>)
{
  float m_current_satisfaction; // xmm1_4
  vostok::resources::resource_base **v3; // esi
  vostok::resources::resource_base **i; // ecx
  vostok::resources::resource_base *v5; // eax
  float v6; // xmm0_4

  m_current_satisfaction = __val->m_current_satisfaction;
  v3 = __last;
  for ( i = __last - 1; ; --i )
  {
    v5 = *i;
    v6 = (*i)->m_current_satisfaction;
    if ( fabs(m_current_satisfaction - v6) >= 0.050000001 )
      break;
    if ( __val->m_reconstruction_size >= v5->m_reconstruction_size )
      goto LABEL_6;
LABEL_4:
    *v3 = v5;
    v3 = i;
  }
  if ( m_current_satisfaction > v6 )
    goto LABEL_4;
LABEL_6:
  *v3 = __val;
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
        vostok::network_core::udp_match_packet **__last,
        vostok::network_core::udp_match_packet *__val)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v2; // ecx
  survarium::base_project::resolve_link_object *v3; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v4; // ecx
  vostok::network_core::udp_match_packet **__next; // [esp+8h] [ebp-4h]

  v2 = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)(__last - 1);
  for ( __next = __last - 1; ; --__next )
  {
    v3 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v2,
           (int)*__next);
    if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v4,
           (int)__val) >= v3 )
      break;
    *__last = *__next;
    __last = __next;
    v2 = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)(__next - 1);
  }
  *__last = __val;
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        const char **__last,
        const char *__val)
{
  const char **v2; // ebx
  const char **i; // edi

  v2 = __last;
  for ( i = __last - 1; strcmp(__val, *i) == -1; --i )
  {
    *v2 = *i;
    v2 = i;
  }
  *v2 = __val;
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
        const char **__last,
        const char *__val)
{
  const char **v2; // ebx
  const char **v3; // esi
  const char *i; // edi

  v2 = __last;
  v3 = __last - 1;
  for ( i = *(__last - 1); strcmp(__val, i) < 0; --v3 )
  {
    *v2 = i;
    i = *(v3 - 1);
    v2 = v3;
  }
  *v2 = __val;
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
        const char **__last,
        char *__val,
        vostok::tips_sorting_predicate __comp)
{
  const char **v3; // ebp
  const char **v4; // esi
  int v5; // eax
  int v6; // edi
  int v7; // eax
  unsigned __int8 *v8; // ebp
  int v9; // eax
  int v10; // edi
  int v11; // eax
  unsigned __int8 *__lastb; // [esp+14h] [ebp+4h]
  const char **__lasta; // [esp+14h] [ebp+4h]

  v3 = __last;
  v4 = __last - 1;
  __lastb = (unsigned __int8 *)*(__last - 1);
  strstr((unsigned __int8 *)__val, (unsigned __int8 *)__comp.editor_str);
  v6 = v5;
  strstr(__lastb, (unsigned __int8 *)__comp.editor_str);
  if ( v6 - (int)__val < v7 - (int)__lastb )
  {
    while ( 1 )
    {
      __lasta = v4;
      *v3 = *v4;
      v8 = (unsigned __int8 *)*--v4;
      strstr((unsigned __int8 *)__val, (unsigned __int8 *)__comp.editor_str);
      v10 = v9;
      strstr(v8, (unsigned __int8 *)__comp.editor_str);
      if ( v10 - (int)__val >= v11 - (int)v8 )
        break;
      v3 = __lasta;
    }
    *__lasta = __val;
  }
  else
  {
    *v3 = __val;
  }
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
        vostok::physics::closest_ray_result __val,
        vostok::physics::distance_predicate __comp)
{
  vostok::physics::closest_ray_result *__last; // ecx
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  vostok::physics::closest_ray_result *v6; // eax
  float v7; // xmm3_4
  float *i; // edx

  x = __comp.m_from.x;
  y = __comp.m_from.y;
  z = __comp.m_from.z;
  v6 = __last - 1;
  v7 = (float)((float)((float)(__val.hit_point_world.z - __comp.m_from.z)
                     * (float)(__val.hit_point_world.z - __comp.m_from.z))
             + (float)((float)(__val.hit_point_world.x - __comp.m_from.x)
                     * (float)(__val.hit_point_world.x - __comp.m_from.x)))
     + (float)((float)(__val.hit_point_world.y - __comp.m_from.y) * (float)(__val.hit_point_world.y - __comp.m_from.y));
  for ( i = &__last[-1].hit_point_world.z;
        (float)((float)((float)((float)(*i - z) * (float)(*i - z))
                      + (float)((float)(*(i - 1) - y) * (float)(*(i - 1) - y)))
              + (float)((float)(*(i - 2) - x) * (float)(*(i - 2) - x))) > v7;
        i -= 10 )
  {
    *__last = *v6;
    __last = v6--;
  }
  *__last = __val;
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__last,
        vostok::sound::propagator_info __val,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  vostok::sound::propagator_info *__next; // [esp+0h] [ebp-4h]

  for ( __next = __last - 1; __comp(&__val, __next); --__next )
  {
    *__last = *__next;
    __last = __next;
  }
  *__last = __val;
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__last,
        vostok::math::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  bool (__cdecl *v3)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *); // ebx
  vostok::math::curve_point<float> *v4; // edi
  vostok::math::curve_point<float> *i; // esi

  v3 = __comp;
  v4 = __last;
  for ( i = __last - 1; v3(&__val, i); --i )
  {
    *(_QWORD *)&v4->upper_value = *(_QWORD *)&i->upper_value;
    *(_QWORD *)&v4->tangent_in = *(_QWORD *)&i->tangent_in;
    *(_QWORD *)&v4->time = *(_QWORD *)&i->time;
    v4 = i;
  }
  *v4 = __val;
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__last,
        vostok::particle::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  vostok::particle::curve_point<float> *__next; // [esp+0h] [ebp-4h]

  for ( __next = __last - 1; __comp(&__val, __next); --__next )
  {
    *__last = *__next;
    __last = __next;
  }
  *__last = __val;
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> __val,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  unsigned int second; // ecx
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__next; // [esp+0h] [ebp-4h]

  for ( __next = __last - 1; __comp(&__val, __next); --__next )
  {
    second = __next->second;
    __last->first = __next->first;
    __last->second = second;
    __last = __next;
  }
  *__last = __val;
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value __val)
{
  vostok::render::custom_config_value *__last; // ecx
  unsigned int id_crc; // edx
  vostok::render::custom_config_value *v3; // eax
  const void *destroyer; // eax

  id_crc = __val.id_crc;
  v3 = __last - 1;
  if ( __val.id_crc < __last[-1].id_crc )
  {
    do
    {
      *__last = *v3;
      __last = v3--;
    }
    while ( id_crc < v3->id_crc );
  }
  destroyer = __val.destroyer;
  *(_QWORD *)&__last->id = *(_QWORD *)&__val.id;
  *(_QWORD *)&__last->id_crc = *(_QWORD *)&__val.id_crc;
  __last->destroyer = destroyer;
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant __val)
{
  vostok::render::shader_constant *__last; // ecx
  vostok::render::shader_constant *v2; // eax
  const vostok::render::shader_constant_host *m_host; // esi

  v2 = __last - 1;
  if ( __val.m_host->m_name.m_pointer.m_object < __last[-1].m_host->m_name.m_pointer.m_object )
  {
    do
    {
      if ( __last )
        *__last = *v2;
      m_host = v2[-1].m_host;
      __last = v2--;
    }
    while ( __val.m_host->m_name.m_pointer.m_object < m_host->m_name.m_pointer.m_object );
  }
  if ( __last )
    *__last = __val;
}
