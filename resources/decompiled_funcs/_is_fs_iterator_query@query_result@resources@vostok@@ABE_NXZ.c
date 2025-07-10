BOOL __usercall vostok::resources::query_result::is_fs_iterator_query@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 132);
  return v2 == 1 || v2 == 2;
}
