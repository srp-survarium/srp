void __userpurge vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76>::push(
        vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76> *this@<ecx>,
        int a2@<esi>,
        survarium::bullet_manager::bullet_functor *const value)
{
  signed __int64 v3; // rax
  unsigned int v4; // ecx

  do
  {
    LODWORD(v3) = *(_DWORD *)a2;
    v4 = *(_DWORD *)(a2 + 4);
    value->next = *(survarium::bullet_manager::bullet_functor **)a2;
    HIDWORD(v3) = v4;
  }
  while ( _InterlockedCompareExchange64((volatile signed __int64 *)a2, __SPAIR64__(v4, (unsigned int)value), v3) != __PAIR64__(v4, v3) );
}
