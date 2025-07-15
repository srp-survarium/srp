void __thiscall vostok::sound::sound_buffer::sound_buffer(vostok::sound::sound_buffer *this)
{
  this->parent_ = 0;
  this->left_ = 0;
  this->right_ = 0;
  this->m_hook.parent_ = 0;
  this->m_hook.left_ = 0;
  this->m_hook.right_ = 0;
  this->m_encoded_sound.m_object = 0;
  this->m_cached_offset = 0;
  this->m_cached_offset_after_decompress = 0;
  this->m_users = 0;
  this->m_reference_count = 0;
  this->m_last_value_in_buffer = 0;
}
