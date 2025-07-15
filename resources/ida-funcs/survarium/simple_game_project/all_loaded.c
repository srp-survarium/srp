BOOL __usercall survarium::simple_game_project::all_loaded@<eax>(
        survarium::simple_game_project *this@<ecx>,
        int a2@<eax>)
{
  return *(_BYTE *)(a2 + 480)
      && *(_BYTE *)(a2 + 481)
      && *(_BYTE *)(a2 + 482)
      && *(_BYTE *)(a2 + 483)
      && *(_BYTE *)(a2 + 485)
      && *(_BYTE *)(a2 + 486)
      && *(_DWORD *)(a2 + 476) == (*(_DWORD *)(a2 + 376) - *(_DWORD *)(a2 + 372)) >> 2;
}
