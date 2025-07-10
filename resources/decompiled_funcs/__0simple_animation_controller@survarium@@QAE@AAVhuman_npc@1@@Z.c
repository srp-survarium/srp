void __userpurge survarium::simple_animation_controller::simple_animation_controller(
        survarium::simple_animation_controller *this@<ecx>,
        int a2@<eax>,
        survarium::human_npc *owner)
{
  *(_DWORD *)a2 = &survarium::simple_animation_controller::`vftable';
  *(_DWORD *)(a2 + 4) = &result.m_buffer[60];
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = &result.m_buffer[60];
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = owner;
  *(_BYTE *)(a2 + 24) = 0;
}
