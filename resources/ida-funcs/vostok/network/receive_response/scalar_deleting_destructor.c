vostok::network::receive_response *__thiscall vostok::network::receive_response::`scalar deleting destructor'(
        vostok::network::receive_response *this,
        char a2)
{
  vostok::network::receive_response::~receive_response(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
