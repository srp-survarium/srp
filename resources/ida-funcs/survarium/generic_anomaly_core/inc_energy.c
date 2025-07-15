int __usercall survarium::generic_anomaly_core::inc_energy@<eax>(
        survarium::generic_anomaly_core *this@<ecx>,
        int result@<eax>,
        float a3@<xmm0>)
{
  if ( *(_BYTE *)(result + 328) )
  {
    result += 332;
    *(float *)result = a3 + *(float *)result;
  }
  return result;
}
