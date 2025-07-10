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
