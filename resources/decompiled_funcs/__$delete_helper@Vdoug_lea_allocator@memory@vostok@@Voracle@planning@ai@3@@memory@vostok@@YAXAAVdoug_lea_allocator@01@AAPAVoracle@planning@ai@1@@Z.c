void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::oracle>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::oracle **pointer)
{
  void *v2; // [esp+4h] [ebp-8h]

  if ( *pointer )
  {
    v2 = __RTCastToVoid(*pointer);
    ((void (__thiscall *)(_DWORD, _DWORD))(*pointer)->~vostok::ai::planning::oracle)(*pointer, 0);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
