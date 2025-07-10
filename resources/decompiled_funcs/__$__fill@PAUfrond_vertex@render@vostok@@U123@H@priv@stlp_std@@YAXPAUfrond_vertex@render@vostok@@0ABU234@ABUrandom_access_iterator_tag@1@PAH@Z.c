void __usercall stlp_std::priv::__fill<vostok::render::frond_vertex *,vostok::render::frond_vertex,int>(
        vostok::render::frond_vertex *__last@<eax>,
        vostok::render::frond_vertex *__first,
        const vostok::render::frond_vertex *__x)
{
  vostok::render::frond_vertex *v3; // ebx
  int i; // eax
  vostok::render::frond_vertex *v5; // edi

  v3 = __first;
  for ( i = __last - __first; i > 0; --i )
  {
    v5 = v3++;
    qmemcpy(v5, __x, sizeof(vostok::render::frond_vertex));
  }
}
