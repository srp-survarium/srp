unsigned int *__usercall stlp_std::priv::__unguarded_partition<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>@<eax>(
        unsigned int *__first@<eax>,
        unsigned int *__last@<ecx>,
        unsigned int __pivot@<edi>,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  float v4; // xmm0_4
  int v5; // edx
  unsigned int v6; // edx

  while ( 1 )
  {
    v4 = *(float *)((_DWORD)__comp.m_distances + 4 * __pivot);
    while ( v4 > *(float *)((_DWORD)__comp.m_distances + 4 * *__first) )
      ++__first;
    do
      v5 = *--__last;
    while ( *(float *)((_DWORD)__comp.m_distances + 4 * v5) > v4 );
    if ( __first >= __last )
      break;
    v6 = *__first;
    *__first = *__last;
    *__last = v6;
    ++__first;
  }
  return __first;
}


const vostok::ai::sound_item **__cdecl stlp_std::priv::__unguarded_partition<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        const vostok::ai::sound_item *__pivot,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  while ( 1 )
  {
    while ( __comp(*__first, __pivot) )
      ++__first;
    for ( --__last; __comp(__pivot, *__last); --__last )
      ;
    if ( __first >= __last )
      break;
    stlp_std::iter_swap<vostok::ai::sound_item const * *,vostok::ai::sound_item const * *>(
      (const vostok::ai::movement_target **)__first++,
      (const vostok::ai::movement_target **)__last);
  }
  return __first;
}


vostok::command_line::key **__cdecl stlp_std::priv::__unguarded_partition<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key **__first,
        vostok::command_line::key **__last,
        vostok::command_line::key *__pivot)
{
  const vostok::command_line::key *v5; // esi
  const vostok::command_line::key *v6; // edi
  const vostok::command_line::key *v7; // edi
  vostok::command_line::key *v8; // eax
  vostok::command_line::key_compare_predicate *v10; // [esp+0h] [ebp-10h]
  vostok::command_line::key_compare_predicate *v11; // [esp+0h] [ebp-10h]

  while ( 1 )
  {
    if ( vostok::command_line::key_compare_predicate::operator()(*__first, __pivot, v10) )
    {
      do
      {
        v5 = __first[1];
        ++__first;
      }
      while ( vostok::command_line::key_compare_predicate::operator()(v5, __pivot, v11) );
    }
    v6 = *--__last;
    if ( vostok::command_line::key_compare_predicate::operator()(__pivot, v6, v11) )
    {
      do
        v7 = *--__last;
      while ( vostok::command_line::key_compare_predicate::operator()(__pivot, v7, v10) );
    }
    if ( __first >= __last )
      break;
    v8 = *__first;
    *__first = *__last;
    *__last = v8;
    ++__first;
  }
  return __first;
}


vostok::resources::query_result **__usercall stlp_std::priv::__unguarded_partition<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>@<eax>(
        vostok::resources::query_result **__first@<eax>,
        vostok::resources::query_result **__last@<ecx>,
        vostok::resources::query_result *__pivot@<esi>)
{
  unsigned int m_quality_index; // edx
  vostok::resources::query_result *v4; // edi
  vostok::resources::query_result *v5; // edx

  while ( 1 )
  {
    m_quality_index = __pivot->m_quality_index;
    while ( (*__first)->m_quality_index >= m_quality_index )
      ++__first;
    do
      v4 = *--__last;
    while ( m_quality_index >= v4->m_quality_index );
    if ( __first >= __last )
      break;
    v5 = *__first;
    *__first = v4;
    *__last = v5;
    ++__first;
  }
  return __first;
}


vostok::resources::resource_base **__usercall stlp_std::priv::__unguarded_partition<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>@<eax>(
        vostok::resources::resource_base **__first@<eax>,
        vostok::resources::resource_base **__last@<edx>,
        vostok::resources::resource_base *__pivot@<esi>)
{
  float m_current_satisfaction; // xmm1_4
  int v4; // ecx
  float v5; // xmm0_4
  vostok::resources::resource_base *v6; // ecx

  m_current_satisfaction = __pivot->m_current_satisfaction;
  while ( 1 )
  {
    while ( fabs((*__first)->m_current_satisfaction - m_current_satisfaction) < 0.050000001 )
    {
      if ( (*__first)->m_reconstruction_size >= __pivot->m_reconstruction_size )
        goto LABEL_6;
LABEL_4:
      ++__first;
    }
    if ( (*__first)->m_current_satisfaction > m_current_satisfaction )
      goto LABEL_4;
    do
    {
LABEL_6:
      while ( 1 )
      {
        v4 = (int)*(__last - 1);
        v5 = *(float *)(v4 + 112);
        --__last;
        if ( fabs(m_current_satisfaction - v5) >= 0.050000001 )
          break;
        if ( __pivot->m_reconstruction_size >= *(_DWORD *)(v4 + 24) )
          goto LABEL_8;
      }
    }
    while ( m_current_satisfaction > v5 );
LABEL_8:
    if ( __first >= __last )
      return __first;
    v6 = *__first;
    *__first = *__last;
    *__last = v6;
    ++__first;
  }
}


const char **__usercall stlp_std::priv::__unguarded_partition<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>@<eax>(
        const char **__first@<ecx>,
        const char **__last@<eax>,
        const char *__pivot,
        bool (__cdecl *__comp)(const char *, const char *))
{
  const char *v6; // ecx
  const char *v7; // edx
  const char *v8; // eax
  const char *v9; // eax

  while ( 1 )
  {
    if ( __comp(*__first, __pivot) )
    {
      do
      {
        v6 = __first[1];
        ++__first;
      }
      while ( __comp(v6, __pivot) );
    }
    v7 = *--__last;
    if ( __comp(__pivot, v7) )
    {
      do
        v8 = *--__last;
      while ( __comp(__pivot, v8) );
    }
    if ( __first >= __last )
      break;
    v9 = *__first;
    *__first = *__last;
    *__last = v9;
    ++__first;
  }
  return __first;
}


const char **__usercall stlp_std::priv::__unguarded_partition<char const * *,char const *,vostok::render::shader_macros_dort_predicate>@<eax>(
        const char **__first@<eax>,
        const char **__last@<ecx>,
        const char *__pivot@<edi>)
{
  const char *v4; // ecx
  const char *v5; // edx
  const char *v6; // edx
  const char *v7; // ecx

  while ( 1 )
  {
    if ( strcmp(*__first, __pivot) < 0 )
    {
      do
      {
        v4 = __first[1];
        ++__first;
      }
      while ( strcmp(v4, __pivot) < 0 );
    }
    v5 = *--__last;
    if ( strcmp(__pivot, v5) < 0 )
    {
      do
        v6 = *--__last;
      while ( strcmp(__pivot, v6) < 0 );
    }
    if ( __first >= __last )
      break;
    v7 = *__first;
    *__first = *__last;
    *__last = v7;
    ++__first;
  }
  return __first;
}


const char **__usercall stlp_std::priv::__unguarded_partition<char const * *,char const *,vostok::tips_sorting_predicate>@<eax>(
        char *__pivot@<esi>,
        const char **__first,
        const char **__last,
        vostok::tips_sorting_predicate __comp)
{
  int v6; // eax
  int v7; // edi
  int v8; // eax
  unsigned __int8 *v9; // eax
  int v10; // eax
  int v11; // edi
  int v12; // eax
  unsigned __int8 *v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  unsigned __int8 *v17; // ecx
  int v18; // eax
  int v19; // edi
  int v20; // eax
  const char *v21; // eax
  const char **__lasta; // [esp+14h] [ebp+8h]
  const char **__lastb; // [esp+14h] [ebp+8h]
  unsigned __int8 *__lastc; // [esp+14h] [ebp+8h]
  unsigned __int8 *__lastd; // [esp+14h] [ebp+8h]

  while ( 1 )
  {
    __lasta = (const char **)*__first;
    strstr((unsigned __int8 *)*__first, (unsigned __int8 *)__comp.editor_str);
    v7 = v6;
    strstr((unsigned __int8 *)__pivot, (unsigned __int8 *)__comp.editor_str);
    if ( v7 - (int)__lasta < v8 - (int)__pivot )
    {
      do
      {
        v9 = (unsigned __int8 *)__first[1];
        ++__first;
        __lastb = (const char **)v9;
        strstr(v9, (unsigned __int8 *)__comp.editor_str);
        v11 = v10;
        strstr((unsigned __int8 *)__pivot, (unsigned __int8 *)__comp.editor_str);
      }
      while ( v11 - (int)__lastb < v12 - (int)__pivot );
    }
    v13 = (unsigned __int8 *)*--__last;
    __lastc = v13;
    strstr((unsigned __int8 *)__pivot, (unsigned __int8 *)__comp.editor_str);
    v15 = v14;
    strstr(__lastc, (unsigned __int8 *)__comp.editor_str);
    if ( v15 - (int)__pivot < v16 - (int)__lastc )
    {
      do
      {
        v17 = (unsigned __int8 *)*--__last;
        __lastd = v17;
        strstr((unsigned __int8 *)__pivot, (unsigned __int8 *)__comp.editor_str);
        v19 = v18;
        strstr(__lastd, (unsigned __int8 *)__comp.editor_str);
      }
      while ( v19 - (int)__pivot < v20 - (int)__lastd );
    }
    if ( __first >= __last )
      break;
    v21 = *__first;
    *__first = *__last;
    *__last = v21;
    ++__first;
  }
  return __first;
}


unsigned int *__fastcall stlp_std::priv::__unguarded_partition<void const * *,void const *,stlp_std::less<void const *>>(
        unsigned int *__last,
        unsigned int __pivot,
        unsigned int *__first)
{
  unsigned int *result; // eax
  unsigned int v4; // esi

  for ( result = __first; ; ++result )
  {
    for ( ; *result < __pivot; ++result )
      ;
    for ( --__last; __pivot < *__last; --__last )
      ;
    if ( result >= __last )
      break;
    v4 = *result;
    *result = *__last;
    *__last = v4;
  }
  return result;
}


float __usercall stlp_std::priv::__unguarded_partition<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>@<xmm0>(
        vostok::physics::closest_ray_result *__first@<eax>,
        vostok::physics::closest_ray_result *__last@<ecx>,
        vostok::physics::closest_ray_result __pivot,
        vostok::physics::distance_predicate __comp)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm3_4
  float *i; // edx
  float *j; // edx
  float result; // xmm0_4
  __int64 v11; // xmm0_8
  __int64 v12; // xmm1_8
  __int64 v13; // xmm3_8
  __int64 v14; // xmm2_8
  __int64 v15; // [esp+30h] [ebp-8h]

  v4 = __pivot.hit_point_world.x - __comp.m_from.x;
  v5 = __pivot.hit_point_world.y - __comp.m_from.y;
  v6 = __pivot.hit_point_world.z - __comp.m_from.z;
  while ( 1 )
  {
    v7 = (float)((float)(v6 * v6) + (float)(v5 * v5)) + (float)(v4 * v4);
    for ( i = &__first->hit_point_world.z;
          v7 > (float)((float)((float)((float)(*i - __comp.m_from.z) * (float)(*i - __comp.m_from.z))
                             + (float)((float)(*(i - 1) - __comp.m_from.y) * (float)(*(i - 1) - __comp.m_from.y)))
                     + (float)((float)(*(i - 2) - __comp.m_from.x) * (float)(*(i - 2) - __comp.m_from.x)));
          i += 10 )
    {
      ++__first;
    }
    --__last;
    for ( j = &__last->hit_point_world.z; ; j -= 10 )
    {
      result = *(j - 2) - __comp.m_from.x;
      if ( (float)((float)((float)((float)(*j - __comp.m_from.z) * (float)(*j - __comp.m_from.z))
                         + (float)((float)(*(j - 1) - __comp.m_from.y) * (float)(*(j - 1) - __comp.m_from.y)))
                 + (float)(result * result)) <= (float)((float)((float)((float)(__pivot.hit_point_world.z
                                                                              - __comp.m_from.z)
                                                                      * (float)(__pivot.hit_point_world.z
                                                                              - __comp.m_from.z))
                                                              + (float)((float)(__pivot.hit_point_world.y
                                                                              - __comp.m_from.y)
                                                                      * (float)(__pivot.hit_point_world.y
                                                                              - __comp.m_from.y)))
                                                      + (float)((float)(__pivot.hit_point_world.x - __comp.m_from.x)
                                                              * (float)(__pivot.hit_point_world.x - __comp.m_from.x))) )
        break;
      --__last;
    }
    if ( __first >= __last )
      break;
    v11 = *(_QWORD *)&__first->object;
    v12 = *(_QWORD *)&__first->hit_point_world.elements[1];
    v13 = *(_QWORD *)&__first->hit_normal_world.elements[2];
    v14 = *(_QWORD *)&__first->hit_normal_world.x;
    v15 = *(_QWORD *)&__first->is_shape_index;
    *__first = *__last;
    *(_QWORD *)&__last->object = v11;
    *(_QWORD *)&__last->hit_point_world.elements[1] = v12;
    v5 = __pivot.hit_point_world.y - __comp.m_from.y;
    *(_QWORD *)&__last->hit_normal_world.x = v14;
    *(_QWORD *)&__last->hit_normal_world.elements[2] = v13;
    v6 = __pivot.hit_point_world.z - __comp.m_from.z;
    *(_QWORD *)&__last->is_shape_index = v15;
    v4 = __pivot.hit_point_world.x - __comp.m_from.x;
    ++__first;
  }
  return result;
}


vostok::sound::propagator_info *__cdecl stlp_std::priv::__unguarded_partition<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        vostok::sound::propagator_info __pivot,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  while ( 1 )
  {
    while ( __comp(__first, &__pivot) )
      ++__first;
    for ( --__last; __comp(&__pivot, __last); --__last )
      ;
    if ( __first >= __last )
      break;
    stlp_std::iter_swap<vostok::sound::propagator_info *,vostok::sound::propagator_info *>(__first++, __last);
  }
  return __first;
}


vostok::math::curve_point<float> *__cdecl stlp_std::priv::__unguarded_partition<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> *__last,
        vostok::math::curve_point<float> __pivot,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  bool (__cdecl *v4)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *); // ebx
  __int64 v7; // xmm0_8
  __int64 v8; // xmm1_8
  __int64 v9; // xmm2_8

  v4 = __comp;
  while ( 1 )
  {
    for ( ; v4(__first, &__pivot); ++__first )
      ;
    for ( --__last; v4(&__pivot, __last); --__last )
      ;
    if ( __first >= __last )
      break;
    v7 = *(_QWORD *)&__first->upper_value;
    v8 = *(_QWORD *)&__first->tangent_in;
    v9 = *(_QWORD *)&__first->time;
    *(_QWORD *)&__first->upper_value = *(_QWORD *)&__last->upper_value;
    *(_QWORD *)&__first->tangent_in = *(_QWORD *)&__last->tangent_in;
    *(_QWORD *)&__first->time = *(_QWORD *)&__last->time;
    *(_QWORD *)&__last->upper_value = v7;
    *(_QWORD *)&__last->tangent_in = v8;
    *(_QWORD *)&__last->time = v9;
    ++__first;
  }
  return __first;
}


vostok::particle::curve_point<float> *__cdecl stlp_std::priv::__unguarded_partition<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        vostok::particle::curve_point<float> *__last,
        vostok::particle::curve_point<float> __pivot,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  while ( 1 )
  {
    while ( __comp(__first, &__pivot) )
      ++__first;
    for ( --__last; __comp(&__pivot, __last); --__last )
      ;
    if ( __first >= __last )
      break;
    stlp_std::iter_swap<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float> *>(
      __first++,
      __last);
  }
  return __first;
}


stlp_std::pair<vostok::ai::npc const *,float> *__cdecl stlp_std::priv::__unguarded_partition<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        stlp_std::pair<vostok::ai::npc const *,float> __pivot,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  while ( 1 )
  {
    while ( __comp(__first, &__pivot) )
      ++__first;
    for ( --__last; __comp(&__pivot, __last); --__last )
      ;
    if ( __first >= __last )
      break;
    stlp_std::iter_swap<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float> *>(
      __first++,
      __last);
  }
  return __first;
}


stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__cdecl stlp_std::priv::__unguarded_partition<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> __pivot,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  while ( 1 )
  {
    while ( __comp(__first, &__pivot) )
      ++__first;
    for ( --__last; __comp(&__pivot, __last); --__last )
      ;
    if ( __first >= __last )
      break;
    stlp_std::iter_swap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int> *>(
      __first++,
      __last);
  }
  return __first;
}


vostok::render::custom_config_value *__usercall stlp_std::priv::__unguarded_partition<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>@<eax>(
        vostok::render::custom_config_value *__first@<ecx>,
        vostok::render::custom_config_value *__last@<eax>,
        vostok::render::custom_config_value __pivot,
        bool (__cdecl *__comp)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))
{
  bool (__cdecl *v4)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *); // ebx
  __int64 v7; // xmm0_8
  __int64 v8; // xmm1_8
  const void *destroyer; // eax

  v4 = __comp;
  while ( 1 )
  {
    for ( ; v4(__first, &__pivot); ++__first )
      ;
    for ( --__last; v4(&__pivot, __last); --__last )
      ;
    if ( __first >= __last )
      break;
    v7 = *(_QWORD *)&__first->id;
    v8 = *(_QWORD *)&__first->id_crc;
    destroyer = __first->destroyer;
    *(_QWORD *)&__first->id = *(_QWORD *)&__last->id;
    *(_QWORD *)&__first->id_crc = *(_QWORD *)&__last->id_crc;
    __first->destroyer = __last->destroyer;
    *(_QWORD *)&__last->id = v7;
    *(_QWORD *)&__last->id_crc = v8;
    __last->destroyer = destroyer;
    ++__first;
  }
  return __first;
}


vostok::render::shader_constant *__usercall stlp_std::priv::__unguarded_partition<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>@<eax>(
        vostok::render::shader_constant *__first@<ecx>,
        vostok::render::shader_constant *__last@<eax>,
        vostok::render::shader_constant __pivot)
{
  unsigned __int8 (__cdecl *v3)(vostok::render::shader_constant *, char *); // ebx
  vostok::render::shader_constant *v5; // esi
  char i; // al
  unsigned int m_size; // ebx
  void *m_pointer; // edx
  int v9; // eax
  int m_value_high; // ecx
  const vostok::render::shader_constant_host *m_host; // [esp+20h] [ebp-8h]

  v3 = *(unsigned __int8 (__cdecl **)(vostok::render::shader_constant *, char *))&__pivot.m_slot.m_class_id;
  v5 = __first;
  for ( i = (*(int (__cdecl **)(vostok::render::shader_constant *, char *))&__pivot.m_slot.m_class_id)(
              __first,
              (char *)&__pivot.m_slot.m_value + 4);
        ;
        i = (*(int (__cdecl **)(vostok::render::shader_constant *, char *))&__pivot.m_slot.m_class_id)(
              v5,
              (char *)&__pivot.m_slot.m_value + 4) )
  {
    if ( i )
    {
      do
        ++v5;
      while ( v3(v5, (char *)&__pivot.m_slot.m_value + 4) );
    }
    for ( --__last; v3((vostok::render::shader_constant *)((char *)&__pivot.m_slot.m_value + 4), (char *)__last); --__last )
      ;
    if ( v5 >= __last )
      break;
    m_size = v5->m_source.m_size;
    m_pointer = v5->m_source.m_pointer;
    v9 = *(_DWORD *)&v5->m_slot.m_class_id;
    m_value_high = HIDWORD(v5->m_slot.m_value);
    m_host = v5->m_host;
    *(_DWORD *)&v5->m_slot.m_class_id = *(_DWORD *)&__last->m_slot.m_class_id;
    HIDWORD(v5->m_slot.m_value) = HIDWORD(__last->m_slot.m_value);
    v5->m_source.m_pointer = __last->m_source.m_pointer;
    v5->m_source.m_size = __last->m_source.m_size;
    v5->m_host = __last->m_host;
    HIDWORD(__last->m_slot.m_value) = m_value_high;
    *(_DWORD *)&__last->m_slot.m_class_id = v9;
    __last->m_source.m_size = m_size;
    v3 = *(unsigned __int8 (__cdecl **)(vostok::render::shader_constant *, char *))&__pivot.m_slot.m_class_id;
    __last->m_source.m_pointer = m_pointer;
    __last->m_host = m_host;
    ++v5;
  }
  return v5;
}
