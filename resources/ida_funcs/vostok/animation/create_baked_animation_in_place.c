void __usercall vostok::animation::create_baked_animation_in_place(
        unsigned __int8 *raw_buffer@<ecx>,
        unsigned int buffer_size@<eax>)
{
  char *m_data; // edi
  int v3; // ecx
  char *v4; // edx
  int v5; // ecx
  char *v6; // eax
  char *v7; // ebx
  char *v8; // esi
  int v9; // ecx
  unsigned __int8 *v10; // esi
  int v11; // ebp
  int v12; // ecx
  char *v13; // eax
  int v14; // ecx
  char *event_channels; // [esp+14h] [ebp-10h]
  vostok::mutable_buffer buffer; // [esp+18h] [ebp-Ch] BYREF

  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    &buffer,
    raw_buffer,
    buffer_size);
  buffer.m_size -= 4;
  m_data = buffer.m_data;
  buffer.m_data += 4;
  v3 = 72 * *(unsigned __int16 *)m_data;
  buffer.m_size -= v3;
  v4 = buffer.m_data;
  buffer.m_data += v3;
  v5 = 16 * (unsigned __int8)m_data[2];
  buffer.m_size -= v5;
  event_channels = buffer.m_data;
  v6 = &buffer.m_data[v5];
  buffer.m_data += v5;
  v7 = &v4[72 * *(unsigned __int16 *)m_data];
  if ( v4 != v7 )
  {
    do
    {
      v8 = v4 + 72;
      do
      {
        *(_DWORD *)v4 = v6;
        buffer.m_size -= 4;
        buffer.m_data += 4;
        v9 = 8 * **(_DWORD **)v4;
        buffer.m_size -= v9;
        v6 = &buffer.m_data[v9];
        v4 += 8;
        buffer.m_data += v9;
      }
      while ( v4 != v8 );
      v4 = v8;
    }
    while ( v8 != v7 );
  }
  if ( m_data[2] )
  {
    v10 = (unsigned __int8 *)(event_channels + 10);
    v11 = (unsigned __int8)m_data[2];
    do
    {
      *(_DWORD *)(v10 - 10) = v6;
      v12 = 4 * *((unsigned __int16 *)v10 - 1);
      buffer.m_size -= v12;
      v13 = &buffer.m_data[v12];
      buffer.m_data += v12;
      v14 = *v10 + strlen((const char *)(*(_DWORD *)(v10 - 10) + *v10 + 4 * *((unsigned __int16 *)v10 - 1))) + 1;
      if ( (v14 & 3) != 0 )
        v14 = v14 - (v14 & 3) + 4;
      buffer.m_size -= v14;
      v6 = &v13[v14];
      v10 += 16;
      --v11;
      buffer.m_data = v6;
    }
    while ( v11 );
  }
}
