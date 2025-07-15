vostok::buffer_string *__thiscall vostok::buffer_string::assign<char const *>(
        vostok::buffer_string *this,
        char **begin_src,
        const char **end_src)
{
  vostok::fs_new::path_string_impl::clear(this);
  return vostok::buffer_string::append(this, *begin_src, *end_src);
}
