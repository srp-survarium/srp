vostok::network::send_order *__thiscall vostok::network::send_order::`vector deleting destructor'(
        vostok::network::send_order *this,
        char a2)
{
  vostok::network::send_order::~send_order(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
