void __userpurge survarium::scaleform_render_command_queue::scaleform_render_command_queue(
        survarium::scaleform_render_command_queue *this@<ecx>,
        _DWORD *a2@<esi>,
        survarium::scaleform_game_engine *game_engine)
{
  _DWORD *v3; // eax

  v3 = operator new(0x18u);
  if ( v3 )
  {
    *v3 = &survarium::scaleform_render_command_queue_impl::`vftable';
    v3[5] = game_engine;
    *a2 = v3;
  }
  else
  {
    *a2 = 0;
  }
}
