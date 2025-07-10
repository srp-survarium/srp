void __userpurge survarium::game_options::game_options(
        survarium::game_options *this@<ecx>,
        _DWORD *a2@<edi>,
        survarium::game *g)
{
  survarium::flash_external_handler::flash_external_handler((survarium::flash_external_handler *)this, a2 + 1);
  a2[1] = &survarium::game_options::`vftable'{for `survarium::flash_external_handler'};
  *a2 = &survarium::game_options::`vftable'{for `vostok::input::handler'};
  a2[4] = 0;
  a2[5] = 0;
  a2[10] = g;
  a2[11] = 0;
  a2[12] = 0;
  a2[14] = 64;
  a2[17] = 0;
  a2[18] = 0;
  a2[19] = 0;
}
