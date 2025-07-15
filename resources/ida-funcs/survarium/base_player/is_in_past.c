bool __userpurge survarium::base_player::is_in_past@<al>(
        survarium::base_player *this@<ecx>,
        int a2@<eax>,
        const unsigned int time_in_ms)
{
  int v3; // eax

  v3 = *(_DWORD *)(a2 + 316);
  return v3 && *(_DWORD *)(v3 + 51192) >= time_in_ms;
}
