vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *__thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::`vector deleting destructor'(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this,
        char a2)
{
  vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::~fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware> *__thiscall vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware>::`vector deleting destructor'(
        vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware> *this,
        char a2)
{
  this->__vftable = (vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware>_vtbl *)&vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware>::`vftable';
  this->m_allocator.m_initialized = 0;
  this->__vftable = (vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware>_vtbl *)&vostok::memory::base_allocator::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
