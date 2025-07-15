char *vostok::render::_dynamic_initializer_for__s_r_resolution_value__()
{
  char *result; // eax
  const char *v1; // ecx
  bool v2; // zf

  result = s_r_resolution_value.m_end;
  v1 = "1280x720";
  do
  {
    if ( result >= s_r_resolution_value.m_max_end )
      break;
    *result = *v1;
    result = s_r_resolution_value.m_end + 1;
    v2 = *++v1 == 0;
    ++s_r_resolution_value.m_end;
  }
  while ( !v2 );
  *result = 0;
  return result;
}
