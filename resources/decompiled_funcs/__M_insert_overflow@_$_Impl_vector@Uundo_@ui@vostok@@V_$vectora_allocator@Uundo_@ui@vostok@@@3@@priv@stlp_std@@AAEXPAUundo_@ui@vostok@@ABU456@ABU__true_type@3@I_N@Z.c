void __userpurge stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_> > *this@<ecx>,
        int *a2@<esi>,
        vostok::ui::undo_ *__pos,
        int __x,
        const stlp_std::__true_type *__formal,
        bool __fill_len,
        bool __atend)
{
  const vostok::ui::undo_ *v7; // ebx
  int *p_x; // eax
  int v9; // eax
  unsigned __int8 *v10; // edx
  int v11; // ebp
  char *v12; // edi
  int v13; // eax
  const stlp_std::__true_type *i; // ecx
  int v15; // edi
  unsigned int v16; // ebx
  int v17; // eax
  unsigned int v18; // ecx
  unsigned int v19; // [esp+Ch] [ebp-8h] BYREF
  unsigned int size; // [esp+10h] [ebp-4h]

  v7 = (const vostok::ui::undo_ *)__x;
  size = stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_>>::_M_compute_next_size(
           (stlp_std::priv::_Impl_vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > *)this,
           a2,
           (unsigned int)__formal);
  v19 = size;
  __x = 1;
  p_x = &__x;
  if ( size )
    p_x = (int *)&v19;
  v9 = (*(int (__thiscall **)(int, _DWORD, int))(*(_DWORD *)a2[2] + 20))(a2[2], 0, 8 * *p_x);
  v10 = (unsigned __int8 *)__pos;
  v11 = v9;
  v12 = (char *)__pos - *a2;
  if ( __pos != (vostok::ui::undo_ *)*a2 )
  {
    memmove((unsigned __int8 *)v9, (unsigned __int8 *)*a2, (unsigned int)__pos - *a2);
    v10 = (unsigned __int8 *)__pos;
    v9 = (int)&v12[v13];
  }
  for ( i = __formal; i; v9 += 8 )
  {
    *(_DWORD *)v9 = v7->text;
    *(_DWORD *)(v9 + 4) = *(_DWORD *)&v7->caret;
    --i;
  }
  v15 = v9;
  if ( !__fill_len )
  {
    v16 = a2[1] - (_DWORD)v10;
    if ( v16 )
    {
      memmove((unsigned __int8 *)v9, v10, v16);
      v15 = v16 + v17;
    }
  }
  (*(void (__thiscall **)(int, int))(*(_DWORD *)a2[2] + 24))(a2[2], *a2);
  v18 = size;
  a2[1] = v15;
  *a2 = v11;
  a2[3] = v11 + 8 * v18;
}
