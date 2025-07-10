// positive sp value has been detected, the output may be wrong!
void __usercall survarium::game_options::tick(
        survarium::game_options *this@<esi>,
        const unsigned int frame_delta@<eax>)
{
  float v2; // [esp+10h] [ebp-Ch]
  int v3; // [esp+14h] [ebp-8h]
  int deltaTime; // [esp+18h] [ebp-4h]
  void *retaddr; // [esp+1Ch] [ebp+0h]

  v2 = (double)frame_delta * 0.001;
  ((void (__stdcall *)(_DWORD, _DWORD, int, _DWORD, int, int))this->m_options_ui.m_object->movie->m_movie->Advance)(
    LODWORD(v2),
    0,
    1,
    LODWORD(v2),
    v3,
    deltaTime);
  ((void (__cdecl *)(void *, _DWORD, int))this->m_cursor_ui.m_object->movie->m_movie->Advance)(retaddr, 0, 1);
}
