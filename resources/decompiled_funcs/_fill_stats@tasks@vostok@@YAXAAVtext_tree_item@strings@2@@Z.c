void __usercall vostok::tasks::fill_stats(
        vostok::strings::text_tree_item *stats@<eax>,
        vostok::tasks::thread_pool *a2@<ecx>)
{
  vostok::tasks::thread_pool::fill_stats(a2, stats);
}
