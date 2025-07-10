BOOL __usercall vostok::physics::bullet_character_controller::can_jump@<eax>(
        vostok::physics::bullet_character_controller *this@<ecx>,
        int a2@<eax>)
{
  return !*(_BYTE *)(a2 + 224) && COERCE_FLOAT(*(_DWORD *)(a2 + 232) & 0x7FFFFFFF) < 0.001 && !*(_BYTE *)(a2 + 260);
}
