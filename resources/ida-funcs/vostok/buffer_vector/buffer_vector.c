void __fastcall vostok::buffer_vector<vostok::render::vertex_colored>::buffer_vector<vostok::render::vertex_colored>(
        const unsigned int max_count,
        vostok::render::vertex_colored *buffer,
        vostok::buffer_vector<vostok::render::vertex_colored> *this,
        const vostok::render::vertex_colored **begin,
        const vostok::render::vertex_colored **end)
{
  const vostok::render::vertex_colored *v5; // ecx

  this->m_max_end = &buffer[max_count];
  this->m_end = buffer;
  this->m_begin = buffer;
  v5 = *begin;
  for ( this->m_end = &buffer[*end - *begin]; v5 != *end; ++buffer )
  {
    if ( buffer )
      *buffer = *v5;
    ++v5;
  }
}


void __usercall vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
        vostok::buffer_vector<unsigned int> *this@<esi>,
        unsigned int *buffer@<eax>,
        const vostok::buffer_vector<unsigned int> *other@<edx>)
{
  vostok::render::render_surface_instance **end; // [esp+0h] [ebp-4h] BYREF

  this->m_begin = buffer;
  this->m_end = buffer;
  this->m_max_end = buffer + 4;
  end = (vostok::render::render_surface_instance **)other->m_end;
  vostok::buffer_vector<vostok::render::render_surface_instance *>::assign<vostok::render::render_surface_instance * *>(
    (vostok::render::render_surface_instance **)other->m_begin,
    &end,
    (vostok::buffer_vector<vostok::render::render_surface_instance *> *)this);
}


void __fastcall vostok::buffer_vector<float>::buffer_vector<float>(
        float *buffer,
        const vostok::buffer_vector<float> *other,
        vostok::buffer_vector<float> *this,
        unsigned int max_count)
{
  float *m_end; // esi
  float *m_begin; // edx

  this->m_end = buffer;
  this->m_begin = buffer;
  this->m_max_end = &buffer[max_count];
  m_end = other->m_end;
  m_begin = other->m_begin;
  this->m_end = &buffer[m_end - m_begin];
  while ( m_begin != m_end )
  {
    if ( buffer )
      *buffer = *m_begin;
    ++m_begin;
    ++buffer;
  }
}


void __fastcall vostok::buffer_vector<vostok::render::render_surface_instance *>::buffer_vector<vostok::render::render_surface_instance *>(
        vostok::render::render_surface_instance **buffer,
        const vostok::buffer_vector<vostok::render::render_surface_instance *> *other,
        vostok::buffer_vector<vostok::render::render_surface_instance *> *this,
        unsigned int max_count)
{
  vostok::render::render_surface_instance **m_end; // esi
  vostok::render::render_surface_instance **m_begin; // edx

  this->m_end = buffer;
  this->m_begin = buffer;
  this->m_max_end = &buffer[max_count];
  m_end = other->m_end;
  m_begin = other->m_begin;
  this->m_end = &buffer[m_end - m_begin];
  while ( m_begin != m_end )
  {
    if ( buffer )
      *buffer = *m_begin;
    ++m_begin;
    ++buffer;
  }
}


void __userpurge vostok::buffer_vector<vostok::variant<32> const *>::buffer_vector<vostok::variant<32> const *>(
        vostok::buffer_vector<vostok::variant<32> const *> *this@<ecx>,
        vostok::buffer_vector<vostok::variant<32> const *> **a2@<eax>,
        void *buffer,
        unsigned int max_count,
        const vostok::variant<32> ***count,
        const vostok::variant<32> *const *value)
{
  vostok::buffer_vector<vostok::variant<32> const *> *v6; // edx

  a2[2] = (vostok::buffer_vector<vostok::variant<32> const *> *)((char *)this + 4 * (_DWORD)buffer);
  v6 = (vostok::buffer_vector<vostok::variant<32> const *> *)((char *)this + 4 * max_count);
  *a2 = this;
  for ( a2[1] = v6; this != a2[1]; this = (vostok::buffer_vector<vostok::variant<32> const *> *)((char *)this + 4) )
  {
    if ( this )
      this->m_begin = *count;
  }
}


void __userpurge vostok::buffer_vector<vostok::variant<32>>::buffer_vector<vostok::variant<32>>(
        vostok::buffer_vector<vostok::variant<32> > *this@<edi>,
        unsigned int max_count@<eax>,
        unsigned int count@<ecx>,
        vostok::variant<32> *buffer,
        const vostok::variant<32> *value)
{
  vostok::variant<32> *v5; // ecx
  vostok::variant<32> *v6; // esi

  v5 = (vostok::variant<32> *)(48 * count);
  this->m_max_end = &buffer[max_count];
  this->m_begin = buffer;
  this->m_end = (vostok::variant<32> *)((char *)buffer + (_DWORD)v5);
  v6 = buffer;
  if ( v6 != (vostok::variant<32> *)((char *)v6 + (_DWORD)v5) )
  {
    do
    {
      if ( v6 )
        vostok::variant<32>::variant<32>(v6, value, v5);
      ++v6;
    }
    while ( v6 != this->m_end );
  }
}
