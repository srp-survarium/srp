void __userpurge survarium::stats::set_fps_stats(survarium::stats *this@<ecx>, float a2@<xmm0>, float thisa)
{
  char buff[64]; // [esp+8h] [ebp-40h] BYREF

  vostok::sprintf<64>((char (*)[64])buff, "FPS: %3.2f", a2);
  (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)(LODWORD(thisa) + 8) + 8))(
    *(_DWORD *)(LODWORD(thisa) + 8),
    buff);
}
