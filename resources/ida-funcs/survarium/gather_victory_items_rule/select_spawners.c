void __thiscall survarium::gather_victory_items_rule::select_spawners(
        survarium::gather_victory_items_rule *this,
        survarium::victory_item_spawner **victory_items_count,
        survarium::victory_item_spawner **__comp)
{
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *v4; // esi
  survarium::victory_item_spawner **M_start; // ecx
  void **v6; // edi
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  void **v10; // eax
  unsigned int v11; // edx
  void **v12; // ecx
  unsigned int v13; // edi
  survarium::victory_item_spawner *v14; // ecx
  char *v15; // edx
  int v16; // [esp+Ch] [ebp-4h]
  survarium::victory_item_spawner **__first; // [esp+18h] [ebp+8h]
  survarium::victory_item_spawner **__firsta; // [esp+18h] [ebp+8h]
  int __compa; // [esp+1Ch] [ebp+Ch]

  v4 = (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)(victory_items_count + 76);
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::operator=(
    (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)this,
    (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)victory_items_count + 19,
    (signed int)(victory_items_count + 72));
  M_start = (survarium::victory_item_spawner **)v4->_M_start;
  v6 = (void **)victory_items_count[77];
  __first = (survarium::victory_item_spawner **)victory_items_count[76];
  if ( v4->_M_start != v6 )
  {
    v7 = ((char *)v6 - (char *)M_start) >> 2;
    v8 = 0;
    while ( v7 != 1 )
    {
      ++v8;
      v7 >>= 1;
    }
    stlp_std::priv::__introsort_loop<survarium::victory_item_spawner * *,survarium::victory_item_spawner *,int,survarium::priority_less>(
      (survarium::priority_less)v6,
      M_start,
      (survarium::victory_item_spawner **)v6,
      0,
      2 * v8,
      __comp);
    stlp_std::priv::__final_insertion_sort<survarium::victory_item_spawner * *,survarium::priority_less>(
      __first,
      (survarium::victory_item_spawner **)v6,
      __comp);
  }
  if ( __comp && (survarium::victory_item_spawner **)(v4->_M_finish - v4->_M_start) != __comp )
  {
    v9 = (int)__comp;
    if ( *((_DWORD *)v4->_M_start[(_DWORD)__comp - 1] + 6) == *((_DWORD *)v4->_M_start[(_DWORD)__comp] + 6) )
    {
      v10 = v4->_M_start;
      v11 = *((_DWORD *)v4->_M_start[v9 - 1] + 6);
      __firsta = 0;
      v16 = 0;
      v12 = (void **)victory_items_count[77];
      while ( v10 != v12 )
      {
        v13 = *((_DWORD *)*v10 + 6);
        ++v16;
        if ( v13 != v11 )
        {
          if ( v13 < v11 )
            break;
          __firsta = (survarium::victory_item_spawner **)((char *)__firsta + 1);
        }
        ++v10;
      }
      stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::erase(v4, &v4->_M_start[v16 - 1], v12);
      if ( v4->_M_finish - v4->_M_start != (_DWORD)__comp )
      {
        __compa = v4->_M_finish - v4->_M_start - (_DWORD)__comp;
        do
        {
          v14 = (survarium::victory_item_spawner *)(134775813 * (_DWORD)victory_items_count[85] + 1);
          v15 = (char *)__firsta
              + (((unsigned int)v14 * (unsigned __int64)(unsigned int)(v4->_M_finish - v4->_M_start - (_DWORD)__firsta)) >> 32);
          victory_items_count[85] = v14;
          stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::erase(v4, &v4->_M_start[(_DWORD)v15]);
          --__compa;
        }
        while ( __compa );
      }
    }
    else
    {
      stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::erase(
        v4,
        &v4->_M_start[v9],
        (void **)victory_items_count[77]);
    }
  }
}
