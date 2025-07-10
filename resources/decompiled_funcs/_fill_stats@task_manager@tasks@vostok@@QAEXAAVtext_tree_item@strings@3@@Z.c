void __usercall vostok::tasks::task_manager::fill_stats(
        vostok::strings::text_tree_item *stats@<eax>,
        vostok::tasks::thread_pool *a2@<ecx>,
        vostok::tasks::task_manager *this)
{
  vostok::tasks::thread_pool::fill_stats(a2, stats);
}
