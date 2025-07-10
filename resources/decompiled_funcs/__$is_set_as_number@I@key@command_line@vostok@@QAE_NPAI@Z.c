bool __thiscall vostok::command_line::key::is_set_as_number<unsigned int>(
        vostok::command_line::key *this,
        unsigned int *out_value)
{
  bool result; // al
  float float_value; // [esp+4h] [ebp-Ch] BYREF

  float_value = 0.0;
  result = vostok::command_line::key::is_set_as_number(this, &float_value);
  if ( result )
  {
    result = 1;
    *out_value = (__int64)float_value;
  }
  return result;
}
