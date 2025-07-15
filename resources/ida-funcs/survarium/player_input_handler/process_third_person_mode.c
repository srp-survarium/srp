void __usercall survarium::player_input_handler::process_third_person_mode(
        survarium::player_input_handler *this@<ecx>,
        int a2@<eax>)
{
  survarium::player_input_handler *v3; // ecx

  *(float *)(a2 + 404) = *(float *)(a2 + 388) + *(float *)(a2 + 404);
  if ( survarium::player_input_handler::alt_is_held(this, a2) || *(_DWORD *)(a2 + 416) == 16 )
  {
    *(float *)(a2 + 396) = *(float *)(a2 + 380) + *(float *)(a2 + 396);
    *(float *)(a2 + 400) = *(float *)(a2 + 384) + *(float *)(a2 + 400);
    survarium::player_input_handler::process_first_person_mode(v3, a2, 0);
    *(_DWORD *)(a2 + 380) = 0;
    *(_DWORD *)(a2 + 384) = 0;
    *(_DWORD *)(a2 + 356) = 0;
    *(_DWORD *)(a2 + 360) = 0;
    *(_DWORD *)(a2 + 364) = 0;
    *(_DWORD *)(a2 + 368) = 0;
  }
  else
  {
    survarium::player_input_handler::process_first_person_mode(v3, a2, 1);
  }
}
