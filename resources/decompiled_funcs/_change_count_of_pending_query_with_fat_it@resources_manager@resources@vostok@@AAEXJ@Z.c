void __thiscall vostok::resources::resources_manager::change_count_of_pending_query_with_fat_it(
        vostok::resources::resources_manager *this)
{
  unsigned int v2; // [esp+0h] [ebp-4h]

  vostok::threading::interlocked_exchange_add((volatile int *)((char *)&dword_201B8 + (_DWORD)this), v2);
}
