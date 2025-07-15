vostok::resources::fs_task *__thiscall vostok::resources::fs_task::`scalar deleting destructor'(
        vostok::resources::fs_task *this,
        char a2)
{
  this->__vftable = (vostok::resources::fs_task_vtbl *)&vostok::resources::fs_task::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
