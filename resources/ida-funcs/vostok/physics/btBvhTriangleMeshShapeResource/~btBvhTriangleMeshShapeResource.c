void __usercall vostok::physics::btBvhTriangleMeshShapeResource::~btBvhTriangleMeshShapeResource(
        vostok::physics::btBvhTriangleMeshShapeResource *this@<ecx>,
        int a2@<esi>)
{
  bool v2; // zf
  void *v3; // eax

  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 104));
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 100));
  v2 = *(_BYTE *)(a2 + 73) == 0;
  *(_DWORD *)a2 = &btBvhTriangleMeshShape::`vftable';
  if ( !v2 )
  {
    (***(void (__thiscall ****)(_DWORD, _DWORD))(a2 + 64))(*(_DWORD *)(a2 + 64), 0);
    v3 = *(void **)(a2 + 64);
    if ( v3 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v3);
    }
  }
  *(_DWORD *)a2 = &btCollisionShape::`vftable';
}
