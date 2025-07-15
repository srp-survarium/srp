void __userpurge vostok::resources::managed_resource::managed_resource(
        vostok::resources::managed_resource *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int size,
        vostok::resources::class_id_enum class_id)
{
  unsigned int v5; // [esp+0h] [ebp-4h]

  vostok::resources::resource_base::resource_base((vostok::resources::resource_base *)1, (int)a2, class_id, 1u, v5);
  a2[55] = 0;
  a2[56] = 0;
  a2[52] = &vostok::memory::managed_node_owner::`vftable';
  a2[53] = 0;
  a2[54] = &vostok::memory::g_resources_managed_allocator;
  a2[52] = &vostok::resources::managed_resource::`vftable'{for `vostok::memory::managed_node_owner'};
  *a2 = &vostok::resources::managed_resource::`vftable'{for `vostok::resources::resource_base'};
  a2[57] = 0;
  a2[58] = 0;
  a2[23] = size;
  a2[59] = 0;
  a2[22] = &vostok::resources::managed_memory;
}
