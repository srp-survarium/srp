vostok::network::connect_order *__thiscall vostok::network::connect_order::`scalar deleting destructor'(
        vostok::network::connect_order *this,
        char a2)
{
  vostok::network::connect_order::~connect_order(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
