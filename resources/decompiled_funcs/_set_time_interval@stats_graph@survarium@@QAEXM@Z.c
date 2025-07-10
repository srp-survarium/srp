void __usercall survarium::stats_graph::set_time_interval(
        survarium::stats_graph *this@<ecx>,
        float *a2@<eax>,
        int a3@<xmm0>)
{
  *((_DWORD *)a2 + 2) = a3;
  survarium::stats_graph::adjust_time_interval(this, a2);
}
