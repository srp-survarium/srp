void __userpurge vostok::collision::triangle_mesh_geometry::triangle_mesh_geometry(
        vostok::collision::triangle_mesh_geometry *this@<ecx>,
        int a2@<esi>,
        vostok::memory::base_allocator *allocator)
{
  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)a2 = &stru_955E40.m_children_resources.m_thread_id;
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = allocator;
  *(_DWORD *)(a2 + 276) = 0;
  *(_QWORD *)(a2 + 280) = 0;
  *(_QWORD *)(a2 + 292) = 0;
  *(_DWORD *)(a2 + 288) = 0;
  *(_DWORD *)(a2 + 300) = 0;
  *(_DWORD *)(a2 + 304) = 0;
  *(_DWORD *)(a2 + 308) = 0;
  *(_DWORD *)(a2 + 312) = 0;
}
