void __usercall survarium::stats_graph::adjust_time_interval(survarium::stats_graph *this@<ecx>, float *a2@<eax>)
{
  float *v2; // edx
  float v3; // xmm1_4
  float **v4; // edx
  float *v5; // ecx
  int v6; // edx

  v2 = **(float ***)a2;
  v3 = a2[2];
  if ( v3 < (float)(*(float *)(*(_DWORD *)a2 + 8) - v2[2])
    && (float)(*(float *)(*(_DWORD *)a2 + 8) - *(float *)(*(_DWORD *)v2 + 8)) >= v3 )
  {
    do
    {
      v4 = *(float ***)a2;
      v5 = **(float ***)a2;
      a2[6] = a2[6] - v5[3];
      *v4 = *(float **)v5;
      *(float *)(*(_DWORD *)v5 + 4) = *a2;
      v6 = *((_DWORD *)a2 + 1);
      --*((_DWORD *)a2 + 8);
      if ( v6 )
      {
        *(_DWORD *)v5 = v6;
        *((_DWORD *)a2 + 1) = v5;
      }
      else
      {
        *((_DWORD *)a2 + 1) = v5;
        *v5 = 0.0;
      }
    }
    while ( (float)(*(float *)(*(_DWORD *)a2 + 8) - *(float *)(***(_DWORD ***)a2 + 8)) >= a2[2] );
  }
}
