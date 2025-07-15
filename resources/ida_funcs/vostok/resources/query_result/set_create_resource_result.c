void __userpurge vostok::resources::query_result::set_create_resource_result(
        vostok::resources::query_result *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::resources::query_result_for_user::error_type_enum result,
        vostok::resources::query_result_for_user::error_type_enum error_type)
{
  if ( this == (vostok::resources::query_result *)2 )
  {
    if ( (((unsigned int)&loc_1FFFFE + 2) & a2[172]) == 0 )
      a2[65] = 2;
  }
  else
  {
    a2[64] = result;
    a2[65] = this;
  }
}
