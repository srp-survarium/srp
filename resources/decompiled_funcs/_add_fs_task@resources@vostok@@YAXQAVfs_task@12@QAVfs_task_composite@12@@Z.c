void __usercall vostok::resources::add_fs_task(vostok::resources::fs_task *const new_task@<eax>)
{
  vostok::resources::resources_manager::add_fs_task(vostok::resources::g_resources_manager.m_variable, new_task);
}
