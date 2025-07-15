void __thiscall vostok::render::backend::~backend(
        vostok::render::backend *this,
        vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *a2)
{
  vostok::render::untyped_buffer *i; // edi
  unsigned int m_reference_count; // esi
  vostok::memory::doug_lea_allocator *v5; // ecx
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v6; // esi
  vostok::render::untyped_buffer *m_object; // eax
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32> *v8; // ecx
  vostok::render::untyped_buffer *v9; // eax
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64> *v10; // ecx
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32> *v11; // ecx
  vostok::render::untyped_buffer *v12; // eax
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64> *v13; // ecx
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32> *v14; // ecx
  vostok::render::untyped_buffer *v15; // eax
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64> *v16; // ecx
  const char *v17; // [esp+0h] [ebp-Ch]
  const char *v18; // [esp+4h] [ebp-8h]
  unsigned int v19; // [esp+8h] [ebp-4h]
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v20; // [esp+14h] [ebp+8h]

  for ( i = a2[1324].m_object; i < a2[1325].m_object; i = (vostok::render::untyped_buffer *)((char *)i + 4) )
  {
    m_reference_count = i->m_reference_count;
    v20 = (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)vostok::render::g_allocator;
    if ( i->m_reference_count )
    {
      vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)(m_reference_count + 32));
      vostok::memory::doug_lea_allocator::free_impl(v5, (int)v20, (char *)m_reference_count, v17, v18, v19);
      i->m_reference_count = 0;
    }
  }
  v6 = a2 + 81;
  m_object = a2[81].m_object;
  if ( m_object )
  {
    (*(void (__stdcall **)(vostok::render::untyped_buffer *))(m_object->m_reference_count + 8))(a2[81].m_object);
    v6->m_object = 0;
  }
  v6->m_object = 0;
  vostok::intrusive_ptr<vostok::render::res_render_output const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_render_output const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_render_output const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)&a2[1847]);
  a2[1325].m_object = a2[1324].m_object;
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32>::~fixed_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32>(
    v8,
    (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&a2[1289]);
  v9 = a2[1156].m_object;
  if ( v9 )
    --v9->m_reference_count;
  vostok::intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_sampler_list const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)&a2[1154]);
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64>::~fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64>(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&a2[1068]);
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_texture_list const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)&a2[935]);
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)&a2[920]);
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32>::~fixed_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32>(
    v11,
    (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&a2[883]);
  v12 = a2[750].m_object;
  if ( v12 )
    --v12->m_reference_count;
  vostok::intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_sampler_list const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)&a2[748]);
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64>::~fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64>(
    v13,
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&a2[662]);
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_texture_list const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)&a2[529]);
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)&a2[514]);
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32>::~fixed_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32>(
    v14,
    (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&a2[477]);
  v15 = a2[344].m_object;
  if ( v15 )
    --v15->m_reference_count;
  vostok::intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_sampler_list const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)&a2[342]);
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64>::~fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64>(
    v16,
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&a2[256]);
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_texture_list const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)&a2[123]);
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)&a2[108]);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    a2 + 17,
    (vostok::render::hw_buffer_pool *)&a2[123]);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    a2 + 11,
    (vostok::render::hw_buffer_pool *)&a2[123]);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    a2 + 6,
    (vostok::render::hw_buffer_pool *)&a2[123]);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    a2,
    (vostok::render::hw_buffer_pool *)&a2[123]);
  vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z = 0.0;
}
