void __usercall survarium::game_statistics_handler::clear(survarium::game_statistics_handler *this@<ecx>, int a2@<esi>)
{
  survarium::shared_statistics::clear((survarium::shared_statistics *)this, a2 + 8);
  memset((void *)(a2 + 6168), 0, 0x28u);
  *(_DWORD *)(a2 + 6240) = 0;
  *(_DWORD *)(a2 + 6244) = 0;
  *(_BYTE *)(a2 + 6248) = 0;
}
