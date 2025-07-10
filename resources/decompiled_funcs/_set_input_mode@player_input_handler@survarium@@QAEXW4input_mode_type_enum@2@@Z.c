void __usercall survarium::player_input_handler::set_input_mode(
        survarium::player_input_handler *this@<ecx>,
        int a2@<eax>)
{
  if ( *(_BYTE *)(a2 + 412) || *(survarium::player_input_handler **)(a2 + 408) != this )
  {
    *(_DWORD *)(a2 + 408) = this;
    *(_BYTE *)(a2 + 412) = 1;
  }
  else
  {
    *(_DWORD *)(a2 + 408) = this;
    *(_BYTE *)(a2 + 412) = 0;
  }
}
