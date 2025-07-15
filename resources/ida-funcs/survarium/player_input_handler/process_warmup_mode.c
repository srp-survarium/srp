void __usercall survarium::player_input_handler::process_warmup_mode(
        survarium::player_input_handler *this@<ecx>,
        float *a2@<eax>)
{
  a2[215] = a2[212] + a2[215];
  a2[213] = a2[213] + a2[206];
  a2[214] = a2[207] + a2[214];
  a2[206] = 0.0;
  a2[207] = 0.0;
}
