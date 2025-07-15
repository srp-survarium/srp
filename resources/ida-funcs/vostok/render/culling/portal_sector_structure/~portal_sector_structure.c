void __thiscall vostok::render::culling::portal_sector_structure::~portal_sector_structure(
        vostok::render::culling::portal_sector_structure *this,
        vostok::resources::unmanaged_resource *a2)
{
  vostok::collision::space_partitioning_tree *m_thread_id; // esi
  vostok::memory::base_allocator *v3; // edi
  unsigned int m_reconstruction_size; // eax
  unsigned int type; // eax
  int m_reconstruction_info_actuality_tick_high; // eax

  m_thread_id = (vostok::collision::space_partitioning_tree *)a2[1].m_children_resources.m_thread_id;
  v3 = (vostok::memory::base_allocator *)a2[1].__vftable;
  a2->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&vostok::render::culling::portal_sector_structure::`vftable';
  vostok::render::culling::delete_tree(v3, m_thread_id);
  vostok::render::culling::delete_tree(
    (vostok::memory::base_allocator *)a2[1].__vftable,
    (vostok::collision::space_partitioning_tree *)a2[1].m_children_resources.m_lock);
  a2[1].m_uid = *(&a2[1].m_reconstruction_size + 1);
  m_reconstruction_size = a2[1].m_reconstruction_size;
  if ( m_reconstruction_size )
  {
    (*((void (__thiscall **)(vostok::resources::unmanaged_resource_vtbl *, unsigned int, const char *, const char *, int))a2[1].~vostok::resources::unmanaged_resource
     + 6))(
      a2[1].__vftable,
      m_reconstruction_size,
      "vostok::render::culling::portal_sector_structure::~portal_sector_structure",
      ".\\portal_sector_structure.cpp",
      60);
    a2[1].m_reconstruction_size = 0;
  }
  *((_DWORD *)&a2[1].vostok::resources::resource_flags + 3) = a2[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  type = a2[1].type;
  if ( type )
  {
    (*((void (__thiscall **)(vostok::resources::unmanaged_resource_vtbl *, unsigned int, const char *, const char *, int))a2[1].~vostok::resources::unmanaged_resource
     + 6))(
      a2[1].__vftable,
      type,
      "vostok::render::culling::portal_sector_structure::~portal_sector_structure",
      ".\\portal_sector_structure.cpp",
      62);
    a2[1].type = 0;
  }
  m_reconstruction_info_actuality_tick_high = HIDWORD(a2[1].m_reconstruction_info_actuality_tick);
  if ( m_reconstruction_info_actuality_tick_high )
  {
    (*((void (__thiscall **)(vostok::resources::unmanaged_resource_vtbl *, int, const char *, const char *, int))a2[1].~vostok::resources::unmanaged_resource
     + 6))(
      a2[1].__vftable,
      m_reconstruction_info_actuality_tick_high,
      "vostok::render::culling::portal_sector_structure::~portal_sector_structure",
      ".\\portal_sector_structure.cpp",
      63);
    HIDWORD(a2[1].m_reconstruction_info_actuality_tick) = 0;
  }
  a2[1].m_uid = *(&a2[1].m_reconstruction_size + 1);
  *((_DWORD *)&a2[1].vostok::resources::resource_flags + 3) = a2[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  vostok::resources::unmanaged_resource::~unmanaged_resource(a2);
}
