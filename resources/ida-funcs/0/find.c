char __usercall find@<al>(vostok::animation::EtCurve *animCurve@<ecx>, int *index@<edi>, float a3@<xmm1>)
{
  int v3; // esi
  int v4; // eax
  vostok::animation::EtKey *M_start; // ecx
  int v6; // edx
  int v7; // eax
  float time; // xmm0_4

  v3 = 0;
  if ( !animCurve )
    return 0;
  if ( !index )
    return 0;
  v4 = animCurve->keyList._M_impl._M_finish - animCurve->keyList._M_impl._M_start;
  *index = 0;
  if ( v4 <= 0 )
    return 0;
  M_start = animCurve->keyList._M_impl._M_start;
  v6 = v4 - 1;
  while ( 1 )
  {
    v7 = (v6 + v3) >> 1;
    time = M_start[v7].time;
    if ( time <= a3 )
      break;
    v6 = v7 - 1;
LABEL_9:
    if ( v3 > v6 )
    {
      *index = v3;
      return 0;
    }
  }
  if ( a3 > time )
  {
    v3 = v7 + 1;
    goto LABEL_9;
  }
  *index = v7;
  return 1;
}
