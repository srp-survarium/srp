vostok::ai::perceptors::pickup_item_perceptor *__thiscall vostok::ai::perceptors::pickup_item_perceptor::`vector deleting destructor'(
        vostok::ai::perceptors::pickup_item_perceptor *this,
        char a2)
{
  vostok::ai::perceptors::pickup_item_perceptor::~pickup_item_perceptor(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
