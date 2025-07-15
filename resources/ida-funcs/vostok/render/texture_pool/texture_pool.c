void __fastcall vostok::render::texture_pool::texture_pool(
        int a1,
        char *string_desc,
        vostok::render::texture_pool *this,
        const vostok::render::texture_pool_key *desc,
        unsigned int num_textures,
        unsigned int calculate_memory_only)
{
  char *m_begin; // eax
  unsigned int i; // esi

  this->m_string_desc.m_begin = this->m_string_desc.m_buffer;
  this->m_string_desc.m_end = this->m_string_desc.m_buffer;
  this->m_string_desc.m_max_end = (char *)&this->m_desc;
  this->m_string_desc.m_buffer[0] = 0;
  this->m_string_desc.m_buffer[0] = 0;
  qmemcpy(&this->m_desc, desc, sizeof(this->m_desc));
  this->m_slots.m_begin = (vostok::render::texture_pool_slot *)this->m_slots.m_buffer;
  this->m_slots.m_end = (vostok::render::texture_pool_slot *)this->m_slots.m_buffer;
  this->m_slots.m_max_end = (vostok::render::texture_pool_slot *)&this[1];
  m_begin = this->m_string_desc.m_begin;
  if ( this->m_string_desc.m_begin != string_desc )
  {
    this->m_string_desc.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&this->m_string_desc, string_desc);
  }
  for ( i = num_textures; i; --i )
    vostok::render::texture_pool::add_texture(desc, this, 0, calculate_memory_only);
}
