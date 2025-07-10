vostok::network::receive_udp_response *__thiscall vostok::network::receive_udp_response::`scalar deleting destructor'(
        vostok::network::receive_udp_response *this,
        char a2)
{
  vostok::network::receive_udp_response::~receive_udp_response(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
