vostok::network::string_response *__thiscall vostok::network::string_response::`scalar deleting destructor'(
        vostok::network::string_response *this,
        char a2)
{
  vostok::network::string_response::~string_response(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
