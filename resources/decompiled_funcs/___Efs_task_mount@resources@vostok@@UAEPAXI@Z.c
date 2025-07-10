vostok::resources::fs_task_mount *__thiscall vostok::resources::fs_task_mount::`vector deleting destructor'(
        vostok::resources::fs_task_mount *this,
        char a2)
{
  vostok::resources::fs_task_mount::~fs_task_mount(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
