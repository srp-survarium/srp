vostok::network::enqueue_order *__thiscall vostok::network::enqueue_order::`scalar deleting destructor'(
        vostok::network::enqueue_order *this,
        char a2)
{
  vostok::network::enqueue_order::~enqueue_order(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
