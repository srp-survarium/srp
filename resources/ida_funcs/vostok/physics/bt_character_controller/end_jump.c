void __usercall vostok::physics::bt_character_controller::end_jump(
        vostok::physics::bt_character_controller *this@<ecx>,
        int a2@<eax>)
{
  *(_BYTE *)(*(_DWORD *)a2 + 257) = 0;
}
