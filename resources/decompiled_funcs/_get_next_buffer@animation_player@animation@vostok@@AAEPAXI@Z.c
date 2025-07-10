char *__usercall vostok::animation::animation_player::get_next_buffer@<eax>(
        vostok::animation::animation_player *this@<ecx>,
        char *result@<eax>)
{
  if ( result == *((char **)result + 8524) )
  {
    *((_DWORD *)result + 8524) = result + 0x4000;
    result += 0x4000;
  }
  else
  {
    *((_DWORD *)result + 8524) = result;
  }
  return result;
}
