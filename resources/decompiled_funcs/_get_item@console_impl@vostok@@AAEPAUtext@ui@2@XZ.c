vostok::ui::text *__usercall vostok::console_impl::get_item@<eax>(
        vostok::console_impl *this@<ecx>,
        const stlp_std::__true_type *a2@<ebx>,
        int a3@<edi>,
        unsigned int a4@<esi>)
{
  unsigned int v4; // ecx
  unsigned __int8 **v5; // esi
  vostok::ui::text *v6; // ebx
  vostok::ui::text **v7; // eax
  vostok::ui::text *v8; // eax
  vostok::ui::text *result; // [esp+0h] [ebp-4h] BYREF

  result = (vostok::ui::text *)this;
  v4 = *(_DWORD *)(a3 + 8);
  v5 = (unsigned __int8 **)(a3 + 36);
  if ( v4 < (*(_DWORD *)(a3 + 40) - *(_DWORD *)(a3 + 36)) >> 2 )
  {
    v8 = *(vostok::ui::text **)&(*v5)[4 * v4];
    *(_DWORD *)(a3 + 8) = v4 + 1;
  }
  else
  {
    v6 = (vostok::ui::text *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a3 + 32) + 16))(*(_DWORD *)(a3 + 32));
    v7 = *(vostok::ui::text ***)(a3 + 40);
    result = v6;
    if ( v7 == *(vostok::ui::text ***)(a3 + 48) )
    {
      stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)&result,
        v5,
        (int)v7,
        (const unsigned int *)&result,
        a2,
        a4,
        (bool)result);
    }
    else
    {
      *v7 = v6;
      *(_DWORD *)(a3 + 40) += 4;
    }
    ++*(_DWORD *)(a3 + 8);
    return v6;
  }
  return v8;
}
