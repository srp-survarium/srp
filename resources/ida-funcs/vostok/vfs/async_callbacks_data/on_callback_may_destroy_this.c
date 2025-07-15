void __userpurge vostok::vfs::async_callbacks_data::on_callback_may_destroy_this(
        vostok::vfs::async_callbacks_data *this@<ecx>,
        int a2@<eax>,
        vostok::vfs::result_enum in_result)
{
  int v4; // eax

  ++*(_DWORD *)(a2 + 4);
  switch ( in_result )
  {
    case result_out_of_memory:
      *(_DWORD *)(a2 + 96) = 3;
      break;
    case result_cannot_lock:
      v4 = *(_DWORD *)(a2 + 96);
      if ( v4 != 3 && v4 )
        *(_DWORD *)(a2 + 96) = 4;
      break;
    case result_fail:
      *(_DWORD *)(a2 + 96) = 0;
      break;
  }
  vostok::vfs::async_callbacks_data::try_finish_may_destroy_this((vostok::vfs::async_callbacks_data *)3, a2);
}
