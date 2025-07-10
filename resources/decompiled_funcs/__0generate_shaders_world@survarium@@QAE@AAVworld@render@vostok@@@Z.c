void __usercall survarium::generate_shaders_world::generate_shaders_world(
        survarium::generate_shaders_world *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)a2 = &survarium::generate_shaders_world::`vftable';
  *(_DWORD *)(a2 + 4) = this[31].m_renderer;
  *(_BYTE *)(a2 + 8) = 0;
}
