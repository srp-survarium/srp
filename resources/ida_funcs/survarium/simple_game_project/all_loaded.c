BOOL __usercall survarium::simple_game_project::all_loaded@<eax>(
        survarium::simple_game_project *this@<ecx>,
        int a2@<eax>)
{
  return *(_BYTE *)(a2 + 445)
      && *(_BYTE *)(a2 + 446)
      && *(_DWORD *)(a2 + 440) == (*(_DWORD *)(a2 + 324) - *(_DWORD *)(a2 + 320)) >> 2
      && *(_BYTE *)(a2 + 444);
}
