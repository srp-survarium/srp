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
