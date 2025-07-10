unsigned int __usercall vostok::input::receiver::keyboard::is_key_down@<eax>(
        char value@<al>,
        vostok::input::receiver::keyboard *this)
{
  return ((unsigned int)value >> 7) & 1;
}
