vostok::ui::text *__usercall vostok::console_impl::get_item@<eax>(vostok::console_impl *this@<ecx>, int a2@<esi>)
{
  unsigned int v2; // ecx
  vostok::ui::text *result; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(a2 + 8);
  if ( v2 < (*(_DWORD *)(a2 + 40) - *(_DWORD *)(a2 + 36)) >> 2 )
  {
    result = *(vostok::ui::text **)(*(_DWORD *)(a2 + 36) + 4 * v2);
    *(_DWORD *)(a2 + 8) = v2 + 1;
  }
  else
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 32) + 16))(*(_DWORD *)(a2 + 32));
    stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::push_back(
      (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)&v4,
      a2 + 36);
    ++*(_DWORD *)(a2 + 8);
    return (vostok::ui::text *)v4;
  }
  return result;
}
