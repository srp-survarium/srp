BOOL __usercall vostok::physics::bullet_character_controller::on_ground@<eax>(
        vostok::physics::bullet_character_controller *this@<ecx>,
        int a2@<eax>)
{
  return COERCE_FLOAT(*(_DWORD *)(a2 + 232) & 0x7FFFFFFF) < 0.001;
}
