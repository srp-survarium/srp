float __usercall survarium::artefact_base::spawn_progress@<st0>(survarium::artefact_base *this@<ecx>, int a2@<eax>)
{
  unsigned int v2; // ecx
  double v3; // st7

  v2 = *(_DWORD *)(a2 + 292);
  if ( v2 )
    return 1.0 - (double)*(unsigned int *)(a2 + 308) / (double)v2;
  return v3;
}
