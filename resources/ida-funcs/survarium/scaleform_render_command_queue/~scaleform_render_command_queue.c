void __usercall survarium::scaleform_render_command_queue::~scaleform_render_command_queue(
        survarium::scaleform_render_command_queue *this@<ecx>,
        _DWORD *a2@<eax>)
{
  if ( *a2 )
    (**(void (__thiscall ***)(_DWORD, int))*a2)(*a2, 1);
}
