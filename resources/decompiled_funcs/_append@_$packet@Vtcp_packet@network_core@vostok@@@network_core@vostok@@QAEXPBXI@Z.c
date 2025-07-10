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
