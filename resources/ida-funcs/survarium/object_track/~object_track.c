void __thiscall survarium::object_track::~object_track(survarium::object_track *this)
{
  vostok::memory::doug_lea_allocator *v1; // esi
  char *m_track; // ebx
  vostok::memory::doug_lea_allocator *v4; // ecx
  const char *v5; // [esp+0h] [ebp-Ch]
  const char *v6; // [esp+4h] [ebp-8h]
  unsigned int v7; // [esp+8h] [ebp-4h]

  v1 = survarium::g_allocator;
  this->__vftable = (survarium::object_track_vtbl *)&survarium::object_track::`vftable';
  m_track = (char *)this->m_track;
  if ( m_track )
  {
    vostok::animation::anm_track::~anm_track((vostok::animation::anm_track *)this, (int *)this->m_track);
    vostok::memory::doug_lea_allocator::free_impl(v4, (int)v1, m_track, v5, v6, v7);
    this->m_track = 0;
  }
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
