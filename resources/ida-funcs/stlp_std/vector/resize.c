void __userpurge stlp_std::vector<char,stlp_std::allocator<char>>::resize(
        stlp_std::vector<char,stlp_std::allocator<char> > *this@<eax>,
        unsigned int __new_size@<edx>,
        char *__x)
{
  char *M_finish; // ecx
  char *M_start; // eax
  unsigned __int8 *v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // [esp+0h] [ebp-8h]
  bool v9; // [esp+4h] [ebp-4h]

  M_finish = this->_M_impl._M_finish;
  M_start = this->_M_impl._M_start;
  if ( __new_size >= M_finish - M_start )
  {
    v7 = __new_size + M_start - M_finish;
    if ( v7 )
    {
      if ( this->_M_impl._M_end_of_storage._M_data - M_finish < v7 )
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *)M_finish,
          (int)this,
          M_finish,
          __x,
          v7,
          v8,
          v9);
      else
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_fill_insert_aux(
          &this->_M_impl,
          M_finish,
          v7,
          __x,
          (const stlp_std::__false_type *)&__x + 3);
    }
  }
  else
  {
    v6 = (unsigned __int8 *)&M_start[__new_size];
    if ( v6 != (unsigned __int8 *)M_finish )
      this->_M_impl._M_finish = (char *)stlp_std::priv::__copy_trivial(
                                          (unsigned __int8 *)M_finish,
                                          (unsigned __int8 *)M_finish,
                                          v6);
  }
}


void __userpurge stlp_std::vector<survarium::account_list_item,vostok::vectora_allocator<void *>>::resize(
        stlp_std::vector<survarium::account_list_item,vostok::vectora_allocator<void *> > *this@<ecx>,
        int a2@<esi>,
        const stlp_std::__true_type *__new_size,
        const survarium::account_list_item *__x)
{
  survarium::account_list_item *v4; // edi
  unsigned int v5; // eax
  unsigned __int8 *v6; // ecx
  unsigned int v7; // ecx
  bool v8; // [esp+0h] [ebp-8h]

  v4 = *(survarium::account_list_item **)(a2 + 4);
  v5 = ((int)v4 - *(_DWORD *)a2) / 72;
  if ( (unsigned int)this >= v5 )
  {
    v7 = (unsigned int)this - v5;
    if ( v7 )
    {
      if ( (*(_DWORD *)(a2 + 12) - (int)v4) / 72 < v7 )
        stlp_std::priv::_Impl_vector<survarium::account_list_item,vostok::vectora_allocator<survarium::account_list_item>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<survarium::account_list_item,vostok::vectora_allocator<survarium::account_list_item> > *)v7,
          (survarium::account_list_item *)a2,
          v4,
          __new_size,
          v7,
          v8);
      else
        stlp_std::priv::_Impl_vector<survarium::account_list_item,vostok::vectora_allocator<survarium::account_list_item>>::_M_fill_insert_aux(
          (stlp_std::priv::_Impl_vector<survarium::account_list_item,vostok::vectora_allocator<survarium::account_list_item> > *)a2,
          v4,
          v7,
          (const survarium::account_list_item *)__new_size,
          (const stlp_std::__false_type *)&__new_size + 3);
    }
  }
  else
  {
    v6 = (unsigned __int8 *)(*(_DWORD *)a2 + 72 * (_DWORD)this);
    if ( v6 != (unsigned __int8 *)v4 )
      *(_DWORD *)(a2 + 4) = stlp_std::priv::__copy_trivial((unsigned __int8 *)v4, (unsigned __int8 *)v4, v6);
  }
}


void __userpurge stlp_std::vector<vostok::ui::undo_,vostok::vectora_allocator<void *>>::resize(
        stlp_std::vector<vostok::ui::undo_,vostok::vectora_allocator<void *> > *this@<eax>,
        unsigned int __new_size@<edx>,
        const vostok::ui::undo_ *__x)
{
  vostok::ui::undo_ *M_finish; // ecx
  vostok::ui::undo_ *M_start; // edi
  unsigned int v6; // eax
  unsigned int v7; // edx
  bool v8; // [esp+0h] [ebp-8h]

  M_finish = this->_M_impl._M_finish;
  M_start = this->_M_impl._M_start;
  v6 = M_finish - this->_M_impl._M_start;
  if ( __new_size >= v6 )
  {
    v7 = __new_size - v6;
    if ( v7 )
    {
      if ( this->_M_impl._M_end_of_storage._M_data - M_finish < v7 )
        stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_> > *)M_finish,
          (unsigned __int8 **)this,
          M_finish,
          __x,
          (const stlp_std::__true_type *)v7,
          0,
          v8);
      else
        stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_>>::_M_fill_insert_aux(
          &this->_M_impl,
          M_finish,
          v7,
          __x,
          (const stlp_std::__false_type *)&__x + 3);
    }
  }
  else if ( &M_start[__new_size] != M_finish )
  {
    this->_M_impl._M_finish = (vostok::ui::undo_ *)stlp_std::priv::__copy_trivial(
                                                     (unsigned __int8 *)M_finish,
                                                     (unsigned __int8 *)M_finish,
                                                     (unsigned __int8 *)&M_start[__new_size]);
  }
}
