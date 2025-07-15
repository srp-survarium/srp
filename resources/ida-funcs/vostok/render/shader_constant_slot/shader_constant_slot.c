void __thiscall vostok::render::shader_constant_slot::shader_constant_slot(vostok::render::shader_constant_slot *this)
{
  *(_DWORD *)&this->m_class_id = 0xFFFF;
  this->m_buffer_index = -1;
  this->m_slot_index = -1;
}
