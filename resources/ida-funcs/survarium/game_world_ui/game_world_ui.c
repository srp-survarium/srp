void __userpurge survarium::game_world_ui::game_world_ui(
        survarium::game_world_ui *this@<ecx>,
        int a2@<eax>,
        survarium::game_world *w)
{
  survarium::flash_external_handler::flash_external_handler(this, (_DWORD *)a2);
  *(_DWORD *)a2 = &survarium::game_world_ui::`vftable';
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = w;
  *(_DWORD *)(a2 + 24) = 0;
  *(_BYTE *)(a2 + 28) = -1;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 168) = 0;
  *(_BYTE *)(a2 + 172) = 0;
  *(_BYTE *)(a2 + 173) = 0;
  *(_BYTE *)(a2 + 174) = 0;
  *(_BYTE *)(a2 + 336) = 0;
  *(_BYTE *)(a2 + 484) = 0;
  *(_BYTE *)(a2 + 40) = 0;
  memset(a2 + 176, 0, 0xA0u);
  *(_DWORD *)(a2 + 584) = -1;
  *(_DWORD *)(a2 + 588) = -1;
  *(_DWORD *)(a2 + 488) = 0;
  *(_BYTE *)(a2 + 493) = 0;
  *(_DWORD *)(a2 + 496) = 0;
  *(_DWORD *)(a2 + 580) = 0;
  *(_DWORD *)(a2 + 592) = 3;
  *(_BYTE *)(a2 + 596) = 0;
  *(_BYTE *)(a2 + 597) = 0;
  memset(a2 + 500, 0, 0x50u);
  *(_DWORD *)(a2 + 600) = -1;
  *(_DWORD *)(a2 + 604) = 0;
  *(_DWORD *)(a2 + 608) = 0;
}
