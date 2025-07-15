_iobuf *__usercall vostok::core::get_stdstream_handle@<eax>(vostok::core::stdstream_enum stream@<eax>)
{
  if ( stream == stdstream_out )
    return __iob_func() + 1;
  if ( stream == stdstream_error )
    return __iob_func() + 2;
  return 0;
}
