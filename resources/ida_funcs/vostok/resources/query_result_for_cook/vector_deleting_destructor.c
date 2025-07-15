vostok::resources::query_result_for_cook *__thiscall vostok::resources::query_result_for_cook::`vector deleting destructor'(
        vostok::resources::query_result_for_cook *this,
        char a2)
{
  vostok::resources::query_result_for_cook::~query_result_for_cook(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
