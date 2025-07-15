int __userpurge survarium::stats_graph::stats_graph@<eax>(
        survarium::stats_graph *this@<ecx>,
        int result@<eax>,
        int a3@<xmm0>,
        float invalid_value,
        float important_value0,
        float important_value1,
        float color,
        unsigned int a8)
{
  *(_DWORD *)(result + 8) = a3;
  *(float *)(result + 12) = invalid_value;
  *(float *)(result + 16) = important_value0;
  *(_DWORD *)result = 0;
  *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(result + 32) = 0;
  *(float *)(result + 20) = important_value1;
  *(_DWORD *)(result + 24) = 0;
  *(float *)(result + 36) = color;
  return result;
}
