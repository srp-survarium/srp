void __usercall stlp_std::fill<vostok::render::leafmesh_vertex *,vostok::render::leafmesh_vertex>(
        vostok::render::leafmesh_vertex *__first@<edx>,
        vostok::render::leafmesh_vertex *__last@<eax>,
        const vostok::render::leafmesh_vertex *__val)
{
  int i; // eax
  vostok::render::leafmesh_vertex *v4; // edi

  for ( i = __last - __first; i > 0; --i )
  {
    v4 = __first++;
    qmemcpy(v4, __val, sizeof(vostok::render::leafmesh_vertex));
  }
}
