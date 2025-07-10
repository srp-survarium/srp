void __userpurge survarium::stats::set_player_linear_speed(survarium::stats *this@<ecx>, float a2@<xmm0>, float thisa)
{
  char buff[64]; // [esp+8h] [ebp-40h] BYREF

  vostok::sprintf<64>((char (*)[64])buff, "linear speed: %3.2f", a2);
  (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)(LODWORD(thisa) + 32) + 8))(
    *(_DWORD *)(LODWORD(thisa) + 32),
    buff);
}
