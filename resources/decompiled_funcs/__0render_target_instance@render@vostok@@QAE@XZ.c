void __thiscall vostok::render::render_target_instance::render_target_instance(
        vostok::render::render_target_instance *this)
{
  char *m_buffer; // ecx

  m_buffer = this->orig_name.m_buffer;
  this->orig_name.m_max_end = m_buffer + 64;
  this->orig_name.m_begin = m_buffer;
  this->orig_name.m_end = m_buffer;
  *m_buffer = 0;
  this->name.m_max_end = (char *)&this->target;
  this->name.m_begin = this->name.m_buffer;
  this->name.m_end = this->name.m_buffer;
  this->name.m_buffer[0] = 0;
  this->target.m_object = 0;
  this->texture.m_object = 0;
}
