vostok::render::shadow_vertex *__usercall stlp_std::priv::__ucopy<vostok::render::shadow_vertex *,vostok::render::shadow_vertex *,int>@<eax>(
        vostok::render::shadow_vertex *__last@<ecx>,
        vostok::render::shadow_vertex *__result@<eax>,
        vostok::render::shadow_vertex *__first)
{
  vostok::render::shadow_vertex *v3; // esi
  int v4; // edi
  vostok::math::float3 *p_object_position; // edx
  vostok::math::float3 *v6; // ecx

  v3 = __first;
  v4 = __last - __first;
  if ( v4 > 0 )
  {
    p_object_position = &__result->object_position;
    v6 = &__first->object_position;
    do
    {
      if ( __result )
      {
        *(_QWORD *)&__result->position.x = *(_QWORD *)&v3->position.x;
        __result->position.z = v3->position.z;
        *(_QWORD *)&p_object_position->x = *(_QWORD *)&v6->x;
        p_object_position->z = v6->z;
        p_object_position[1].x = v6[1].x;
        p_object_position[1].y = v6[1].y;
      }
      --v4;
      ++v3;
      v6 = (vostok::math::float3 *)((char *)v6 + 32);
      ++__result;
      p_object_position = (vostok::math::float3 *)((char *)p_object_position + 32);
    }
    while ( v4 > 0 );
  }
  return __result;
}
