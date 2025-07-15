vostok::fs_new::native_path_string *__cdecl vostok::fs_new::native_path_string::convert(
        vostok::fs_new::native_path_string *result,
        const char *path)
{
  vostok::fs_new::native_path_string::native_path_string(result);
  vostok::fs_new::path_string_impl::assign_with_conversion<char const *>(result, &path);
  return result;
}
