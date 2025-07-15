void __usercall ppmd_compressor_impl::rcRemoveSubrange(ppmd_compressor_impl *this@<ecx>, _DWORD *a2@<eax>)
{
  int v2; // esi
  int v3; // edx

  v2 = a2[1901];
  v3 = a2[1906];
  a2[1904] += v3 * v2;
  a2[1906] = v3 * (a2[1902] - v2);
}
