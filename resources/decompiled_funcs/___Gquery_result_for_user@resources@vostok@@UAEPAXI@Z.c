vostok::resources::query_result_for_user *__thiscall vostok::resources::query_result_for_user::`scalar deleting destructor'(
        vostok::resources::query_result_for_user *this,
        char a2)
{
  vostok::resources::query_result_for_user::~query_result_for_user(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
