void __usercall stlp_std::fill<unsigned int *,unsigned int>(
        unsigned int *__last@<eax>,
        unsigned int *__val@<edx>,
        unsigned int *__first)
{
  unsigned int *v3; // ecx
  int i; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    *v3 = *__val;
    --i;
  }
}


void __cdecl stlp_std::fill<void * *,void *>(void **__first, void **__last, void *const *__val)
{
  void **v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  v3 = __first;
  for ( i = __last - __first; i > 0; --i )
    *v3++ = *__val;
}


void __fastcall stlp_std::fill<vostok::render::data_indexer *,vostok::render::data_indexer>(
        vostok::resources::request *__last,
        const vostok::resources::request *__val,
        vostok::resources::request *__first)
{
  vostok::resources::request *v3; // eax
  int i; // ecx

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    *v3 = *__val;
    --i;
  }
}


void __fastcall stlp_std::fill<survarium::inventory_item_instance *,survarium::inventory_item_instance>(
        vostok::render::vertex_colored *__last,
        const vostok::render::vertex_colored *__val,
        vostok::render::vertex_colored *__first)
{
  vostok::render::vertex_colored *v3; // eax
  int i; // ecx

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    *v3 = *__val;
    --i;
  }
}


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
