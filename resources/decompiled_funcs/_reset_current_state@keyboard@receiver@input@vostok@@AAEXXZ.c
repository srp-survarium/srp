void __usercall vostok::input::receiver::keyboard::reset_current_state(
        vostok::input::receiver::keyboard *this@<ecx>,
        int a2@<eax>)
{
  memset(a2 + 4, 0, 0x400u);
}
