void __usercall vostok::vfs::overlapped_node_iterator::clear(
        vostok::vfs::overlapped_node_iterator *this@<ecx>,
        _DWORD *a2@<esi>)
{
  volatile signed __int64 *v2; // eax
  vostok::threading::reader_writer_lock *v3; // [esp-4h] [ebp-4h]

  v2 = (volatile signed __int64 *)a2[3];
  if ( v2 )
  {
    v3 = (vostok::threading::reader_writer_lock *)((a2[2] != 1) + 1);
    vostok::threading::reader_writer_lock::unlock(v3, v2, (vostok::threading::lock_type_enum)v3);
  }
  a2[3] = 0;
  a2[2] = 0;
  a2[1] = 0;
}
