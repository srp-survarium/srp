void __usercall survarium::player::set_near_plane_factor(survarium::player *this@<ecx>, int a2@<eax>, float a3@<xmm0>)
{
  int v3; // eax

  v3 = *(int *)((char *)&dword_10EF4 + a2);
  if ( v3 )
    *(float *)(v3 + 76) = a3 * 0.050000001;
}
