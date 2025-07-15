void __thiscall vostok::console_commands::unique_filters_collector::operator()(
        vostok::console_commands::unique_filters_collector *this,
        const vostok::logging::filter *filter)
{
  const vostok::logging::filter *v2; // ebx
  const void **M_finish; // edi
  const vostok::logging::filter **v5; // eax
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *v6; // [esp-4h] [ebp-10h]
  const stlp_std::__true_type *v7; // [esp+0h] [ebp-Ch]
  unsigned int v8; // [esp+4h] [ebp-8h]
  bool v9; // [esp+8h] [ebp-4h]

  v2 = filter;
  M_finish = this->filters._M_impl._M_finish;
  v5 = stlp_std::priv::__find_if<vostok::logging::filter const * *,vostok::console_commands::filter_name_eq>(
         (const vostok::logging::filter **)this->filters._M_impl._M_start,
         (const vostok::logging::filter **)M_finish,
         filter->initiator);
  if ( v5 == (const vostok::logging::filter **)M_finish )
  {
    filter = v2;
    if ( M_finish == this->filters._M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::_M_insert_overflow(
        v6,
        (stlp_std::priv::_STLP_alloc_proxy<void const * *,void const *,vostok::vectora_allocator<void const *> > *)this,
        M_finish,
        (const void **)&filter,
        v7,
        v8,
        v9);
    }
    else
    {
      *M_finish = v2;
      ++this->filters._M_impl._M_finish;
    }
  }
  else
  {
    *v5 = v2;
  }
}
