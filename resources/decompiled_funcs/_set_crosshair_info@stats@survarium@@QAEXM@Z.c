void __usercall survarium::stats::set_crosshair_info(survarium::stats *this@<ecx>, int a2@<eax>, int a3@<xmm0>)
{
  *(_DWORD *)(a2 + 60) = a3;
}
