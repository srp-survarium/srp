int __cdecl vostok::particle::screen_alignment_name_to_type(const vostok::fixed_string<128> *name)
{
  if ( vostok::operator==(name, "Square") )
    return 0;
  if ( vostok::operator==(name, "Rectangle") )
    return 1;
  if ( vostok::operator==(name, "ToPath") )
    return 2;
  if ( vostok::operator==(name, "ToAxis") )
    return 3;
  return 1;
}
