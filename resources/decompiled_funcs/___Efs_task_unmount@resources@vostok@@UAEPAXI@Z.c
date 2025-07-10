vostok::resources::fs_task_unmount *__thiscall vostok::resources::fs_task_unmount::`vector deleting destructor'(
        vostok::resources::fs_task_unmount *this,
        char a2)
{
  vostok::resources::fs_task_unmount::~fs_task_unmount(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
