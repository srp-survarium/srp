void __usercall vostok::physics::bt_character_controller::bt_character_controller(
        vostok::physics::bt_character_controller *this@<ecx>,
        int a2@<eax>)
{
  *(_BYTE *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 4) = this;
}
