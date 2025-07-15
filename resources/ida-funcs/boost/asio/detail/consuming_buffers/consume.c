void __usercall boost::asio::detail::consuming_buffers<boost::asio::const_buffer,boost::asio::const_buffers_1>::consume(
        boost::asio::detail::consuming_buffers<boost::asio::const_buffer,boost::asio::const_buffers_1> *this@<ecx>,
        int a2@<esi>)
{
  _BYTE *v2; // ebx
  unsigned int v3; // eax
  _DWORD *v4; // eax
  _BYTE *v5; // ecx
  _DWORD *v6; // eax
  boost::asio::mutable_buffer v7; // [esp+8h] [ebp-Ch] BYREF

  if ( this )
  {
    v2 = (_BYTE *)(a2 + 8);
    do
    {
      if ( *v2 )
        break;
      v3 = *(_DWORD *)(a2 + 16);
      if ( v3 > (unsigned int)this )
      {
        *(boost::asio::mutable_buffer *)(a2 + 12) = *boost::asio::operator+(
                                                       (const boost::asio::mutable_buffer *)(a2 + 12),
                                                       &v7,
                                                       (unsigned int)this);
        this = 0;
      }
      else
      {
        this = (boost::asio::detail::consuming_buffers<boost::asio::const_buffer,boost::asio::const_buffers_1> *)((char *)this - v3);
        v4 = *(_DWORD **)(a2 + 20);
        if ( v4 == (_DWORD *)v2 )
        {
          *v2 = 1;
        }
        else
        {
          *(_DWORD *)(a2 + 12) = *v4;
          *(_DWORD *)(a2 + 16) = v4[1];
          *(_DWORD *)(a2 + 20) = v4 + 2;
        }
      }
    }
    while ( this );
  }
  v5 = (_BYTE *)(a2 + 8);
  while ( !*v5 && !*(_DWORD *)(a2 + 16) )
  {
    v6 = *(_DWORD **)(a2 + 20);
    if ( v6 == (_DWORD *)v5 )
    {
      *v5 = 1;
    }
    else
    {
      *(_DWORD *)(a2 + 12) = *v6;
      *(_DWORD *)(a2 + 16) = v6[1];
      *(_DWORD *)(a2 + 20) = v6 + 2;
    }
  }
}
