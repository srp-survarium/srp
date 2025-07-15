void __userpurge vostok::render::culling::portal_sector_structure::portal_sector_structure(
        vostok::render::culling::portal_sector_structure *this@<esi>,
        unsigned int sectors_count@<eax>,
        vostok::memory::base_allocator *portals_count)
{
  vostok::memory::base_allocator *m_object; // ebx
  vostok::render::culling::portal *v5; // eax
  vostok::memory::base_allocator *m_allocator; // ecx
  vostok::render::culling::spatial_sector *v7; // eax
  vostok::collision::space_partitioning_tree *v8; // eax
  vostok::memory::base_allocator *v9; // edx

  m_object = (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object;
  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  this->__vftable = (vostok::render::culling::portal_sector_structure_vtbl *)&vostok::render::culling::portal_sector_structure::`vftable';
  this->m_allocator = m_object;
  v5 = (vostok::render::culling::portal *)m_object->call_malloc(m_object, 76 * (_DWORD)portals_count);
  this->m_portals_buffer = v5;
  this->m_portals.m_begin = v5;
  this->m_portals.m_end = v5;
  m_allocator = this->m_allocator;
  this->m_portal_ids_buffer = 0;
  v7 = (vostok::render::culling::spatial_sector *)m_allocator->call_malloc(m_allocator, 32 * sectors_count);
  this->m_sectors_buffer = v7;
  this->m_sectors.m_begin = v7;
  this->m_sectors.m_end = v7;
  v8 = vostok::collision::new_space_partitioning_tree(this->m_allocator, 1.0);
  v9 = this->m_allocator;
  this->m_sectors_spatial_tree = v8;
  this->m_portals_spatial_tree = vostok::collision::new_space_partitioning_tree(v9, 1.0);
  this->m_portals_geometry = 0;
}
