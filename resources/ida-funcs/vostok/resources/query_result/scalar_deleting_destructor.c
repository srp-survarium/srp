vostok::resources::query_result *__thiscall vostok::resources::query_result::`scalar deleting destructor'(
        vostok::resources::query_result *this,
        char a2)
{
  vostok::resources::query_result::~query_result(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
