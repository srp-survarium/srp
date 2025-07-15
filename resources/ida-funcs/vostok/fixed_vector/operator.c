vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **__userpurge vostok::fixed_vector<vostok::render::buffer_slot,128>::operator=@<eax>(
        const vostok::fixed_vector<vostok::render::buffer_slot,128> *other@<eax>,
        vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **this)
{
  const vostok::render::buffer_slot *end; // [esp+0h] [ebp-4h] BYREF

  end = other->m_end;
  vostok::buffer_vector<vostok::render::buffer_slot>::assign<vostok::render::buffer_slot const *>(
    (vostok::buffer_vector<vostok::render::buffer_slot> *)&end,
    this,
    other->m_begin,
    &end);
  return this;
}


vostok::fixed_vector<vostok::render::sampler_slot,16> *__userpurge vostok::fixed_vector<vostok::render::sampler_slot,16>::operator=@<eax>(
        const vostok::fixed_vector<vostok::render::sampler_slot,16> *other@<eax>,
        vostok::fixed_vector<vostok::render::sampler_slot,16> *this)
{
  vostok::render::sampler_slot *m_begin; // edi
  vostok::render::sampler_slot *v4; // esi
  vostok::render::sampler_slot *m_end; // [esp+14h] [ebp+8h]

  m_begin = other->m_begin;
  m_end = other->m_end;
  v4 = this->m_begin;
  this->m_end = &this->m_begin[m_end - other->m_begin];
  while ( m_begin != m_end )
  {
    if ( v4 )
    {
      vostok::fixed_string<64>::fixed_string<64>(&v4->name, &m_begin->name);
      v4->slot_id = m_begin->slot_id;
      v4->state = m_begin->state;
    }
    ++m_begin;
    ++v4;
  }
  return this;
}


vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **__userpurge vostok::fixed_vector<vostok::render::texture_slot,128>::operator=@<eax>(
        const vostok::fixed_vector<vostok::render::texture_slot,128> *other@<eax>,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **this)
{
  const vostok::render::texture_slot *end; // [esp+0h] [ebp-4h] BYREF

  end = other->m_end;
  vostok::buffer_vector<vostok::render::texture_slot>::assign<vostok::render::texture_slot const *>(
    (vostok::buffer_vector<vostok::render::texture_slot> *)&end,
    this,
    other->m_begin,
    &end);
  return this;
}
