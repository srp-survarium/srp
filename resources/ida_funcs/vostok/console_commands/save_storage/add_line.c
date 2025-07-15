void __userpurge vostok::console_commands::save_storage::add_line(
        vostok::console_commands::save_storage *this@<ecx>,
        int a2@<eax>,
        char *str)
{
  unsigned __int8 *v3; // ebp
  int v5; // ecx
  unsigned int v6; // kr00_4
  unsigned __int8 *v7; // edi
  unsigned __int8 **v8; // eax
  const stlp_std::__true_type *v9; // [esp+0h] [ebp-10h]
  unsigned int v10; // [esp+4h] [ebp-Ch]
  bool v11; // [esp+8h] [ebp-8h]

  v3 = (unsigned __int8 *)str;
  v5 = *(_DWORD *)(a2 + 16);
  v6 = strlen(str);
  v7 = (unsigned __int8 *)(*(int (__thiscall **)(int, unsigned int))(*(_DWORD *)v5 + 16))(v5, v6 + 1);
  memcpy(v7, v3, v6 + 1);
  v8 = *(unsigned __int8 ***)(a2 + 4);
  str = (char *)v7;
  if ( v8 == *(unsigned __int8 ***)(a2 + 12) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)&str,
      (unsigned __int8 **)a2,
      (int)v8,
      (const unsigned int *)&str,
      v9,
      v10,
      v11);
  }
  else
  {
    *v8 = v7;
    *(_DWORD *)(a2 + 4) += 4;
  }
}
