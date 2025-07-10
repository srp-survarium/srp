int __cdecl vostok::particle::sub_uv_method_name_to_type(const vostok::fixed_string<128> *name)
{
  if ( vostok::operator==(name, "Linear") )
    return 0;
  if ( vostok::operator==(name, "LinearSmooth") )
    return 1;
  if ( vostok::operator==(name, "Random") )
    return 2;
  if ( vostok::operator==(name, "RandomSmooth") )
    return 3;
  return 0;
}
