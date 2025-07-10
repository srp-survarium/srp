BOOL __usercall vostok::physics::bt_character_controller::on_ground@<eax>(
        vostok::physics::bt_character_controller *this@<ecx>,
        int a2@<eax>)
{
  return COERCE_FLOAT(*(_DWORD *)(*(_DWORD *)a2 + 232) & 0x7FFFFFFF) < 0.001;
}
