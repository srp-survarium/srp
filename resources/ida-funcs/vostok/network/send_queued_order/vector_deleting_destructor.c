vostok::network::send_queued_order *__thiscall vostok::network::send_queued_order::`vector deleting destructor'(
        vostok::network::send_queued_order *this,
        char a2)
{
  vostok::network::send_queued_order::~send_queued_order(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
