bool __cdecl vostok::logging::has_passed_filters(vostok::logging::filter_tree *initiator_raw, const char *verbosity)
{
  vostok::logging::filter_tree *v2; // edi
  unsigned int v3; // kr00_4
  void *v4; // esp
  vostok::threading::reader_writer_lock *v5; // ecx
  bool v6; // bl
  vostok::threading::reader_writer_lock *v7; // ecx
  char v9[12]; // [esp+0h] [ebp-30h] BYREF
  vostok::logging::path_parts path; // [esp+Ch] [ebp-24h] BYREF

  v2 = vostok::core::g_log_filter_tree;
  v3 = strlen((const char *)initiator_raw);
  v4 = alloca(v3 + 2);
  vostok::strings::copy(v9, v3 + 2, (char *)initiator_raw);
  strcat_s(v9, v3 + 2, ":");
  vostok::logging::path_parts::path_parts((vostok::logging::path_parts *)v9, &path);
  vostok::threading::reader_writer_lock::lock_read_impl(v5, (volatile signed __int64 *)v2);
  v6 = vostok::logging::node::get_verbosity(v2->initiator_tree, &path, silent) >= (int)verbosity;
  vostok::threading::reader_writer_lock::unlock(v7, (volatile signed __int64 *)v2, lock_type_read);
  return v6;
}
