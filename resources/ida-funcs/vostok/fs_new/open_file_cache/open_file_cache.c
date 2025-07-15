void __thiscall vostok::fs_new::open_file_cache::open_file_cache(vostok::fs_new::open_file_cache *this)
{
  vostok::fs_new::native_path_string::native_path_string(&this->name);
  this->handle = 0;
  this->counter = 0;
}
