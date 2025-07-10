unsigned int __thiscall vostok::sound::ogg_encoded_sound_interface::decompress(
        vostok::sound::ogg_encoded_sound_interface *this,
        unsigned __int8 *dest,
        unsigned int pcm_pointer,
        unsigned int *pcm_pointer_after_decompress,
        unsigned int bytes_needed)
{
  unsigned int result; // eax

  result = vostok::sound::ogg_utils::decompress(&this->m_ovf, dest, &pcm_pointer, bytes_needed);
  *pcm_pointer_after_decompress = pcm_pointer;
  return result;
}
