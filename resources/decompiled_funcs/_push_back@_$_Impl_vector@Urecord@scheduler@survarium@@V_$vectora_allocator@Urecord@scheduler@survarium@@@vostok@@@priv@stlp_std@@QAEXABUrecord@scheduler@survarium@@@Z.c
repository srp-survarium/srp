void __userpurge stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>::push_back(
        stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record> > *this@<ecx>,
        int a2@<eax>,
        const survarium::scheduler::record *__x)
{
  survarium::scheduler::record *v4; // ebx
  const stlp_std::__false_type *v5; // [esp+0h] [ebp-Ch]
  unsigned int v6; // [esp+4h] [ebp-8h]
  bool v7; // [esp+8h] [ebp-4h]

  v4 = *(survarium::scheduler::record **)(a2 + 4);
  if ( v4 == *(survarium::scheduler::record **)(a2 + 12) )
  {
    stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>::_M_insert_overflow_aux(
      this,
      v4,
      __x,
      v5,
      v6,
      v7);
  }
  else
  {
    if ( v4 )
    {
      v4->m_id = __x->m_id;
      boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
        (boost::function4<void,unsigned int,float,float,char const *> *)&__x->m_callback,
        (int)&v4->m_callback);
      v4->survarium::scheduler::scheduler_record = __x->survarium::scheduler::scheduler_record;
    }
    *(_DWORD *)(a2 + 4) += 56;
  }
}
