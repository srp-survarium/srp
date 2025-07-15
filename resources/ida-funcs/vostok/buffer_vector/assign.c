void __userpurge vostok::buffer_vector<unsigned short>::assign<unsigned short const *>(
        unsigned __int16 *begin@<eax>,
        unsigned __int16 **end@<ecx>,
        vostok::buffer_vector<unsigned short> *this)
{
  unsigned __int16 *m_begin; // edx

  m_begin = this->m_begin;
  this->m_end = &this->m_begin[*end - begin];
  while ( begin != *end )
  {
    if ( m_begin )
      *m_begin = *begin;
    ++begin;
    ++m_begin;
  }
}


void __thiscall vostok::buffer_vector<vostok::render::ray>::assign<vostok::render::ray const *>(
        vostok::buffer_vector<vostok::render::ray> *this,
        const vostok::render::ray *begin,
        const vostok::render::ray **end)
{
  vostok::render::ray *m_begin; // esi
  vostok::render::ray *v4; // eax
  const vostok::render::ray *v5; // esi

  m_begin = this->m_begin;
  this->m_end = &this->m_begin[*end - begin];
  v4 = m_begin;
  v5 = begin;
  while ( v5 != *end )
  {
    if ( v4 )
      qmemcpy(v4, v5, sizeof(vostok::render::ray));
    v5 = ++begin;
    ++v4;
  }
}


void __userpurge vostok::buffer_vector<vostok::render::buffer_slot>::assign<vostok::render::buffer_slot const *>(
        vostok::buffer_vector<vostok::render::buffer_slot> *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **a2@<eax>,
        const vostok::render::buffer_slot *begin,
        const vostok::render::buffer_slot *const *end)
{
  const vostok::render::buffer_slot *v4; // ebx
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *i; // edi
  const vostok::render::buffer_slot *const *v7; // ecx
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v8; // eax
  vostok::fixed_string<64> *v9; // esi
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v10; // [esp+18h] [ebp+8h]

  v4 = begin;
  for ( i = *a2; i != a2[1]; i += 21 )
    vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(i + 20);
  v7 = end;
  v8 = *a2;
  a2[1] = &(*a2)[21 * (*end - begin)];
  v9 = (vostok::fixed_string<64> *)v8;
  v10 = v8;
  while ( v4 != *v7 )
  {
    if ( v9 )
    {
      vostok::fixed_string<64>::fixed_string<64>(v9, &v4->name);
      v9[1].m_begin = (char *)v4->slot_id;
      vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        v10 + 20,
        &v4->buffer);
      v7 = end;
    }
    ++v4;
    v9 = (vostok::fixed_string<64> *)&v10[21];
    v10 += 21;
  }
}


void __usercall vostok::buffer_vector<vostok::render::shader_constant>::assign<vostok::render::shader_constant const *>(
        vostok::buffer_vector<vostok::render::shader_constant> *this@<edi>,
        const vostok::render::shader_constant *begin@<ecx>,
        const vostok::render::shader_constant *const *end@<esi>)
{
  vostok::render::shader_constant *m_begin; // eax

  m_begin = this->m_begin;
  this->m_end = &this->m_begin[*end - begin];
  while ( begin != *end )
  {
    if ( m_begin )
      *m_begin = *begin;
    ++begin;
    ++m_begin;
  }
}


void __userpurge vostok::buffer_vector<vostok::render::texture_slot>::assign<vostok::render::texture_slot const *>(
        vostok::buffer_vector<vostok::render::texture_slot> *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **a2@<eax>,
        const vostok::render::texture_slot *begin,
        const vostok::render::texture_slot *const *end)
{
  const vostok::render::texture_slot *v4; // ebx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *i; // edi
  const vostok::render::texture_slot *const *v7; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v8; // eax
  vostok::fixed_string<64> *v9; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v10; // [esp+18h] [ebp+8h]

  v4 = begin;
  for ( i = *a2; i != a2[1]; i += 21 )
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(i + 20);
  v7 = end;
  v8 = *a2;
  a2[1] = &(*a2)[21 * (*end - begin)];
  v9 = (vostok::fixed_string<64> *)v8;
  v10 = v8;
  while ( v4 != *v7 )
  {
    if ( v9 )
    {
      vostok::fixed_string<64>::fixed_string<64>(v9, &v4->name);
      v9[1].m_begin = (char *)v4->slot_id;
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        v10 + 20,
        &v4->texture);
      v7 = end;
    }
    ++v4;
    v9 = (vostok::fixed_string<64> *)&v10[21];
    v10 += 21;
  }
}
