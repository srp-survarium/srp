int sscanf(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return vscan_fn(string, _input_l, format, 0, arglist);
}
