void __thiscall vostok::render::grass_patch::~grass_patch(
        vostok::render::grass_patch *this,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *a2)
{
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // ebx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **v3; // esi
  vostok::collision::geometry_instance *m_object; // esi
  int v5; // [esp+10h] [ebp-4h]

  v2 = a2;
  v3 = (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&a2[16];
  v5 = 3;
  do
  {
    if ( *(v3 - 3) )
    {
      a2 = *(v3 - 3);
      if ( vostok::memory::g_mt_allocator.m_use_memory_monitor )
        vostok::memory::monitor::on_free((void **)&a2, (vostok::command_line::key *)this);
      pt3free((int)this, (char *)a2);
      *(v3 - 3) = 0;
    }
    if ( *v3 )
    {
      a2 = *v3;
      if ( vostok::memory::g_mt_allocator.m_use_memory_monitor )
        vostok::memory::monitor::on_free((void **)&a2, (vostok::command_line::key *)this);
      pt3free((int)this, (char *)a2);
      *v3 = 0;
    }
    ++v3;
    --v5;
  }
  while ( v5 );
  if ( v2[20].m_object && v2[22].m_object )
    (*(void (__thiscall **)(vostok::render::render_target *, vostok::render::render_target *))(v2[20].m_object->m_reference_count
                                                                                             + 4))(
      v2[20].m_object,
      v2[22].m_object);
  vostok::collision::delete_object(&vostok::memory::g_mt_allocator, (vostok::collision::object *)v2[22].m_object);
  m_object = (vostok::collision::geometry_instance *)v2[21].m_object;
  vostok::collision::delete_geometry_instance(&vostok::memory::g_mt_allocator, m_object);
  `vector destructor iterator'(
    (char *)&v2[10],
    4u,
    3,
    (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
  `vector destructor iterator'(
    (char *)&v2[7],
    4u,
    3,
    (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v2[2],
    (vostok::render::hw_buffer_pool *)m_object);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v2[1]);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(v2);
}
