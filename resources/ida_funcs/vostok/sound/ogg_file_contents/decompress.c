unsigned int __thiscall vostok::sound::ogg_file_contents::decompress(
        vostok::sound::ogg_file_contents *this,
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
