vostok::math::float3 *__usercall vostok::network_core::packet_reader::r<vostok::math::float3>@<eax>(
        vostok::network_core::packet_reader *this@<ecx>,
        vostok::math::float3 *a2@<eax>,
        int a3@<edx>)
{
  int v3; // eoff
  float v4; // esi

  v3 = *(_DWORD *)(a3 + 4);
  v4 = *(float *)(v3 + 8);
  *(_QWORD *)&a2->x = *(_QWORD *)v3;
  a2->z = v4;
  *(_DWORD *)(a3 + 4) = v3 + 12;
  return a2;
}
