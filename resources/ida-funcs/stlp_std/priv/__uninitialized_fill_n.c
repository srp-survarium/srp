unsigned int *__usercall stlp_std::priv::__uninitialized_fill_n<unsigned int *,unsigned int,unsigned int>@<eax>(
        unsigned int *__first@<edx>,
        unsigned int __n@<eax>,
        unsigned int *__x@<esi>)
{
  unsigned int *result; // eax
  int i; // ecx

  result = &__first[__n];
  for ( i = result - __first; i > 0; ++__first )
  {
    *__first = *__x;
    --i;
  }
  return result;
}


float *__cdecl stlp_std::priv::__uninitialized_fill_n<float *,unsigned int,float>(
        float *__first,
        unsigned int __n,
        const float *__x)
{
  int i; // [esp+4h] [ebp-10h]
  float *v5; // [esp+8h] [ebp-Ch]

  v5 = __first;
  for ( i = (int)(4 * __n) >> 2; i > 0; --i )
    *v5++ = *__x;
  return &__first[__n];
}


void **__cdecl stlp_std::priv::__uninitialized_fill_n<void * *,unsigned int,void *>(
        void **__first,
        unsigned int __n,
        void *const *__x)
{
  int i; // [esp+4h] [ebp-10h]
  void **v5; // [esp+8h] [ebp-Ch]

  v5 = __first;
  for ( i = (int)(4 * __n) >> 2; i > 0; --i )
  {
    survarium::generate_shaders_world::is_loading();
    survarium::generate_shaders_world::is_loading();
    *v5++ = *__x;
  }
  return &__first[__n];
}


vostok::render::leafmesh_vertex *__usercall stlp_std::priv::__uninitialized_fill_n<vostok::render::leafmesh_vertex *,unsigned int,vostok::render::leafmesh_vertex>@<eax>(
        unsigned int __n@<eax>,
        vostok::render::leafmesh_vertex *__first,
        const vostok::render::leafmesh_vertex *__x)
{
  vostok::render::leafmesh_vertex *v3; // ebx
  vostok::render::leafmesh_vertex *result; // eax
  int i; // edx
  vostok::render::leafmesh_vertex *v6; // edi

  v3 = __first;
  result = &__first[__n];
  for ( i = result - __first; i > 0; --i )
  {
    v6 = v3++;
    qmemcpy(v6, __x, sizeof(vostok::render::leafmesh_vertex));
  }
  return result;
}


vostok::render::vertex_colored *__usercall stlp_std::priv::__uninitialized_fill_n<vostok::render::vertex_colored *,unsigned int,vostok::render::vertex_colored>@<eax>(
        vostok::render::vertex_colored *__first@<edx>,
        unsigned int __n@<eax>,
        const vostok::render::vertex_colored *__x@<esi>)
{
  vostok::render::vertex_colored *result; // eax
  int i; // ecx

  result = &__first[__n];
  for ( i = result - __first; i > 0; ++__first )
  {
    if ( __first )
      *__first = *__x;
    --i;
  }
  return result;
}


vostok::sound::search::vertex_id_type *__cdecl stlp_std::priv::__uninitialized_fill_n<vostok::sound::search::vertex_id_type *,unsigned int,vostok::sound::search::vertex_id_type>(
        vostok::sound::search::vertex_id_type *__first,
        unsigned int __n,
        const vostok::sound::search::vertex_id_type *__x)
{
  int i; // [esp+Ch] [ebp-10h]
  vostok::sound::search::vertex_id_type *v5; // [esp+10h] [ebp-Ch]

  v5 = __first;
  for ( i = (int)(12 * __n) / 12; i > 0; --i )
  {
    if ( v5 )
      *v5 = *__x;
    ++v5;
  }
  return &__first[__n];
}


survarium::zone_group::zone_wrapper *__cdecl stlp_std::priv::__uninitialized_fill_n<survarium::zone_group::zone_wrapper *,unsigned int,survarium::zone_group::zone_wrapper>(
        survarium::zone_group::zone_wrapper *__first,
        unsigned int __n,
        const survarium::zone_group::zone_wrapper *__x)
{
  int v4; // [esp+4h] [ebp-18h]
  int i; // [esp+Ch] [ebp-10h]
  survarium::zone_group::zone_wrapper *v6; // [esp+10h] [ebp-Ch]

  v6 = __first;
  for ( i = (int)(8 * __n) >> 3; i > 0; --i )
  {
    v4 = *(_DWORD *)&__x->active;
    v6->zone = __x->zone;
    *(_DWORD *)&v6->active = v4;
    ++v6;
  }
  return &__first[__n];
}


vostok::math::float4x4 *__usercall stlp_std::priv::__uninitialized_fill_n<vostok::math::float4x4 *,unsigned int,vostok::math::float4x4>@<eax>(
        unsigned int __n@<eax>,
        vostok::math::float4x4 *__first,
        const vostok::math::float4x4 *__x)
{
  vostok::math::float4x4 *v3; // ebx
  vostok::math::float4x4 *result; // eax
  int i; // edx

  v3 = __first;
  result = &__first[__n];
  for ( i = result - __first; i > 0; ++v3 )
  {
    if ( v3 )
      qmemcpy((void *)v3, __x, sizeof(vostok::math::float4x4));
    --i;
  }
  return result;
}
