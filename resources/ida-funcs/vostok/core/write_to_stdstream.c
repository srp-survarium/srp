void vostok::core::write_to_stdstream(vostok::core::stdstream_enum stream, char *format, ...)
{
  _iobuf *v2; // eax
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, format);
  if ( stream )
  {
    if ( stream == stdstream_error )
      v2 = __iob_func() + 2;
    else
      v2 = 0;
  }
  else
  {
    v2 = __iob_func() + 1;
  }
  if ( v2 )
    vfprintf(v2, format, ap);
}
