void __userpurge vostok::network_core::packet_reader::r(
        vostok::network_core::packet_reader *this@<esi>,
        unsigned int size@<edi>,
        unsigned __int8 *destination,
        unsigned int destination_size)
{
  unsigned int v4; // [esp+0h] [ebp-4h]

  memcpy(destination, (unsigned __int8 *)this->m_pointer, v4);
  this->m_pointer += size;
}


unsigned __int8 __fastcall vostok::network_core::packet_reader::r<unsigned char>(
        vostok::network_core::packet_reader *this,
        int a2)
{
  unsigned __int8 *v2; // ecx
  unsigned __int8 result; // al

  v2 = *(unsigned __int8 **)(a2 + 4);
  result = *v2;
  *(_DWORD *)(a2 + 4) = v2 + 1;
  return result;
}


unsigned __int16 __fastcall vostok::network_core::packet_reader::r<unsigned short>(
        vostok::network_core::packet_reader *this,
        int a2)
{
  unsigned __int16 *v2; // ecx
  unsigned __int16 result; // ax

  v2 = *(unsigned __int16 **)(a2 + 4);
  result = *v2;
  *(_DWORD *)(a2 + 4) = v2 + 1;
  return result;
}


unsigned int __fastcall vostok::network_core::packet_reader::r<unsigned int>(
        vostok::network_core::packet_reader *this,
        int a2)
{
  unsigned int *v2; // ecx
  unsigned int result; // eax

  v2 = *(unsigned int **)(a2 + 4);
  result = *v2;
  *(_DWORD *)(a2 + 4) = v2 + 1;
  return result;
}


void __thiscall vostok::network_core::packet_reader::r<float>(vostok::network_core::packet_reader *this)
{
  this->m_pointer += 4;
}


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
