void __userpurge vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
        vostok::network_core::packet<vostok::network_core::tcp_packet> *this@<ecx>,
        int a2@<edi>,
        unsigned __int8 *buffer,
        unsigned int buffer_size)
{
  unsigned int *v4; // esi
  unsigned int v5; // edx
  unsigned int v6; // eax
  unsigned int *v7; // ecx
  int v8; // edx

  v4 = (unsigned int *)(a2 + 4);
  v5 = buffer_size + *(_DWORD *)(a2 + 4);
  v6 = *(_DWORD *)(a2 + 12);
  v7 = (unsigned int *)(a2 + 12);
  if ( v5 > v6 )
  {
    if ( !v6 )
      v6 = buffer_size;
    if ( v6 < v5 )
    {
      do
        v6 *= 2;
      while ( v6 < buffer_size + *v4 );
    }
    *v7 = v6;
    if ( v6 >= *v4 )
      v7 = (unsigned int *)(a2 + 4);
    *v4 = *v7;
    if ( *(_DWORD *)a2 )
      v8 = *(_DWORD *)a2 - 3;
    else
      v8 = 0;
    *(_DWORD *)a2 = (*(int (__thiscall **)(_DWORD, int, unsigned int))(**(_DWORD **)(a2 + 8) + 20))(
                      *(_DWORD *)(a2 + 8),
                      v8,
                      v6 + 3)
                  + 3;
  }
  memcpy((unsigned __int8 *)(*v4 + *(_DWORD *)a2), buffer, buffer_size);
  *v4 += buffer_size;
}


void __usercall vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
        vostok::network_core::packet<vostok::network_core::udp_match_packet> *this@<ecx>,
        vostok::math::float2 *value@<eax>)
{
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(8u, this, (unsigned __int8 *)value);
}


void __usercall vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
        vostok::network_core::packet<vostok::network_core::udp_match_packet> *this@<ecx>,
        vostok::math::float3 *value@<eax>)
{
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(0xCu, this, (unsigned __int8 *)value);
}


void __thiscall vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
        vostok::network_core::packet<vostok::network_core::udp_match_packet> *this,
        unsigned __int8 value)
{
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(1u, this, &value);
}


void __thiscall vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
        vostok::network_core::packet<vostok::network_core::udp_match_packet> *this,
        unsigned __int16 value)
{
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(2u, this, (unsigned __int8 *)&value);
}


void __thiscall vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
        vostok::network_core::packet<vostok::network_core::udp_match_packet> *this,
        float value)
{
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(4u, this, (unsigned __int8 *)&value);
}


// positive sp value has been detected, the output may be wrong!
void __userpurge vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
        unsigned int buffer_size@<esi>,
        vostok::network_core::packet<vostok::network_core::udp_match_packet> *this,
        unsigned __int8 *buffer)
{
  unsigned int v3; // eax
  vostok::animation::skeleton_animation_cook *v4; // ecx
  vostok::resources::resource_base *v5; // [esp-4h] [ebp-8h]
  _DWORD *retaddr; // [esp+4h] [ebp+0h]

  v3 = 256 - (unsigned __int8)(*(_BYTE *)retaddr - (_BYTE)retaddr - 43);
  v4 = (vostok::animation::skeleton_animation_cook *)retaddr[1];
  if ( (unsigned int)v4 + buffer_size > v3 )
  {
    if ( !v3 )
      v3 = buffer_size;
    if ( v3 < (unsigned int)v4 + buffer_size )
    {
      v4 = (vostok::animation::skeleton_animation_cook *)((char *)v4 + buffer_size);
      do
        v3 *= 2;
      while ( v3 < (unsigned int)v4 );
    }
    survarium::booby_trap_set_core::transform(v4, v5);
  }
  memcpy((unsigned __int8 *)v4 + *retaddr, buffer, buffer_size);
  retaddr[1] += buffer_size;
}
