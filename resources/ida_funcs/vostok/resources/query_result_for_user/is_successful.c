BOOL __usercall vostok::resources::query_result_for_user::is_successful@<eax>(
        vostok::resources::query_result_for_user *this@<ecx>,
        int a2@<eax>)
{
  return !*(_DWORD *)(a2 + 256) && *(_DWORD *)(a2 + 260) != 1;
}
