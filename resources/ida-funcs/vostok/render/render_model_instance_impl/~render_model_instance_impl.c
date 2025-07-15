void __usercall vostok::render::render_model_instance_impl::~render_model_instance_impl(
        vostok::render::render_model_instance_impl *this@<ecx>,
        vostok::resources::unmanaged_resource *a2@<esi>)
{
  vostok::resources::memory_type *m_memory_type_data; // ebx
  vostok::render::additional_material **m_construct_thread_id; // edi
  const char *v4; // [esp+0h] [ebp-Ch]
  const char *v5; // [esp+4h] [ebp-8h]
  unsigned int v6; // [esp+8h] [ebp-4h]

  m_memory_type_data = a2[1].m_memory_type_data;
  m_construct_thread_id = (vostok::render::additional_material **)a2[1].m_construct_thread_id;
  a2->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&vostok::render::render_model_instance_impl::`vftable';
  while ( m_construct_thread_id != (vostok::render::additional_material **)m_memory_type_data )
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::additional_material>(
      vostok::render::g_allocator,
      m_construct_thread_id++,
      v4,
      v5,
      v6);
  a2[1].m_memory_type_data = (vostok::resources::memory_type *)a2[1].m_construct_thread_id;
  LODWORD(a2[1].m_reconstruction_info_actuality_tick) = &vostok::collision::object::`vftable';
  a2->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&vostok::render::render_model_instance::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(a2);
}
