BOOL __usercall vostok::physics::bt_character_controller::can_jump@<eax>(
        vostok::physics::bt_character_controller *this@<ecx>,
        int *a2@<eax>)
{
  int v2; // eax

  v2 = *a2;
  return !*(_BYTE *)(v2 + 224) && COERCE_FLOAT(*(_DWORD *)(v2 + 232) & 0x7FFFFFFF) < 0.001 && !*(_BYTE *)(v2 + 260);
}
