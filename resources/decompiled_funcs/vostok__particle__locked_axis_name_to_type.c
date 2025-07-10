int __cdecl vostok::particle::locked_axis_name_to_type(const vostok::fixed_string<128> *name)
{
  if ( vostok::operator==(name, "X") )
    return 0;
  if ( vostok::operator==(name, "Y") )
    return 1;
  if ( vostok::operator==(name, "Z") )
    return 2;
  if ( vostok::operator==(name, "-X") )
    return 3;
  if ( vostok::operator==(name, "-Y") )
    return 4;
  if ( vostok::operator==(name, "-Z") )
    return 5;
  if ( vostok::operator==(name, "RotateX") )
    return 6;
  if ( vostok::operator==(name, "RotateY") )
    return 7;
  if ( vostok::operator==(name, "RotateZ") )
    return 8;
  return 9;
}
