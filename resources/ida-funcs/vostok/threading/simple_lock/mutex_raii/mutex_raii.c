void __usercall vostok::threading::simple_lock::mutex_raii::mutex_raii(
        vostok::threading::simple_lock::mutex_raii *this@<esi>,
        const vostok::threading::simple_lock *lock@<eax>,
        vostok::threading::simple_lock *a3@<ecx>)
{
  this->lock = lock;
  vostok::threading::simple_lock::lock(a3);
  this->locked = 1;
}
