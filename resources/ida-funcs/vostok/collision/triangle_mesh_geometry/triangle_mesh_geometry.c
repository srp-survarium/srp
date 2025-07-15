void __userpurge vostok::collision::triangle_mesh_geometry::triangle_mesh_geometry(
        vostok::collision::triangle_mesh_geometry *this@<ecx>,
        int a2@<esi>,
        vostok::memory::base_allocator *allocator)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, (_DWORD *)a2, fs_iterator_class);
  *(_DWORD *)a2 = &vostok::collision::triangle_mesh_geometry::`vftable';
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = allocator;
  *(_DWORD *)(a2 + 276) = 0;
  vostok::math::create_zero_aabb((vostok::math::aabb *)(a2 + 280));
  *(_DWORD *)(a2 + 304) = 0;
  *(_DWORD *)(a2 + 308) = 0;
  *(_DWORD *)(a2 + 312) = 0;
}
