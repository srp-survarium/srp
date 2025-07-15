void __usercall vostok::tasks::spawn_task(
        vostok::tasks::task_manager *type@<ecx>,
        vostok::tasks::task *parent@<eax>,
        vostok::tasks::task *function)
{
  vostok::tasks::task_manager::spawn_task(type, function, (vostok::tasks::task_type *)type, parent);
}
