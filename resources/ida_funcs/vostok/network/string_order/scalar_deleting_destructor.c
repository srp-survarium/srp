vostok::network::string_order *__thiscall vostok::network::string_order::`scalar deleting destructor'(
        vostok::network::string_order *this,
        char a2)
{
  vostok::network::string_order::~string_order(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
