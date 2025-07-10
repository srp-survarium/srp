void __usercall vostok::physics::bullet_character_controller::end_jump(
        vostok::physics::bullet_character_controller *this@<ecx>,
        int a2@<eax>)
{
  *(_BYTE *)(a2 + 257) = 0;
}
