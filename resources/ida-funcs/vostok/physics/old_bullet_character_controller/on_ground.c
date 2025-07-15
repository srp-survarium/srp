BOOL __usercall vostok::physics::old_bullet_character_controller::on_ground@<eax>(
        vostok::physics::old_bullet_character_controller *this@<ecx>,
        int a2@<eax>)
{
  return s_cc_on_ground_max_vertical_speed_0 > COERCE_FLOAT(*(_DWORD *)(a2 + 628) & 0x7FFFFFFF);
}
