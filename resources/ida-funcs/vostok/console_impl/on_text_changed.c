bool __thiscall vostok::console_impl::on_text_changed(
        vostok::console_impl *this,
        vostok::ui::window *w,
        int p1,
        int p2)
{
  vostok::ui::text *v5; // eax
  unsigned int v6; // eax
  stlp_std::vector<char const *,vostok::vectora_allocator<void *> > *v7; // ecx
  vostok::tips_sorting_predicate v8; // edi
  vostok::tips_sorting_predicate *M_finish; // ecx
  vostok::vectora<char const *> *M_start; // esi
  int editor_str; // edx
  int v12; // eax
  int similar; // eax
  vostok::ui::text *v14; // eax
  const char *v15; // eax
  unsigned int v16; // eax
  vostok::console_commands::console_command *v17; // eax
  stlp_std::vector<char const *,vostok::vectora_allocator<void *> > *v18; // ecx
  stlp_std::vector<char const *,vostok::vectora_allocator<void *> > *v20; // [esp-4h] [ebp-650h]
  vostok::tips_sorting_predicate *v21; // [esp-4h] [ebp-650h]
  const char *const *v22; // [esp+0h] [ebp-64Ch]
  char v23[512]; // [esp+10h] [ebp-63Ch] BYREF
  char v24[512]; // [esp+210h] [ebp-43Ch] BYREF
  char _Dst[516]; // [esp+410h] [ebp-23Ch] BYREF
  vostok::console_commands::console_command *dst[10]; // [esp+614h] [ebp-38h] BYREF
  unsigned int v27; // [esp+63Ch] [ebp-10h]
  stlp_std::vector<char const *,vostok::vectora_allocator<void *> > varC; // [esp+640h] [ebp-Ch] BYREF

  v5 = this->m_text_edit->text(this->m_text_edit);
  varC._M_impl._M_finish = (const void **)v5->get_text(v5);
  v6 = strlen((const char *)varC._M_impl._M_finish);
  v8.editor_str = 0;
  if ( this->m_tips_mode )
  {
    if ( v6 )
      return 0;
  }
  else if ( v6 )
  {
    similar = vostok::console_commands::get_similar((char *)varC._M_impl._M_finish, dst);
    v7 = v20;
    v27 = similar;
    goto LABEL_4;
  }
  v27 = 0;
LABEL_4:
  stlp_std::vector<char const *,vostok::vectora_allocator<void *>>::clear(v7, (int)&this->m_tips);
  if ( v27 )
  {
    do
    {
      varC._M_impl._M_start = (const void **)dst[(int)v8.editor_str]->m_name;
      stlp_std::vector<char const *,vostok::vectora_allocator<void *>>::push_back(&varC, v22);
      ++v8.editor_str;
    }
    while ( (unsigned int)v8.editor_str < v27 );
  }
  M_finish = (vostok::tips_sorting_predicate *)this->m_tips._M_impl._M_finish;
  M_start = (vostok::vectora<char const *> *)this->m_tips._M_impl._M_start;
  varC._M_impl._M_start = (const void **)&M_finish->editor_str;
  if ( M_start != (vostok::vectora<char const *> *)M_finish )
  {
    v8.editor_str = (const char *)(((char *)M_finish - (char *)M_start) >> 2);
    editor_str = (int)v8.editor_str;
    v12 = 0;
    while ( editor_str != 1 )
    {
      ++v12;
      editor_str >>= 1;
    }
    stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::tips_sorting_predicate>(
      M_finish,
      v8,
      (char **)M_start,
      &M_finish->editor_str,
      0,
      2 * v12,
      (vostok::tips_sorting_predicate)varC._M_impl._M_finish);
    if ( (int)v8.editor_str <= 16 )
    {
      stlp_std::priv::__insertion_sort<char const * *,char const *,vostok::tips_sorting_predicate>(
        (const char **)M_start,
        (const char **)varC._M_impl._M_start,
        (const char ***)&varC._M_impl._M_finish);
    }
    else
    {
      v8.editor_str = (const char *)&M_start[4];
      stlp_std::priv::__insertion_sort<char const * *,char const *,vostok::tips_sorting_predicate>(
        (const char **)M_start,
        (const char **)&M_start[4],
        (const char ***)&varC._M_impl._M_finish);
      for ( M_start += 4;
            M_start != (vostok::vectora<char const *> *)varC._M_impl._M_start;
            M_start = (vostok::vectora<char const *> *)((char *)M_start + 4) )
      {
        stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
          (const char **)M_start,
          (char *)M_start->_M_impl._M_start,
          (vostok::tips_sorting_predicate)varC._M_impl._M_finish);
      }
    }
  }
  if ( !v27 )
  {
    v14 = this->m_text_edit->text(this->m_text_edit);
    v15 = v14->get_text(v14);
    strcpy_s(_Dst, 0x200u, v15);
    v16 = strlen(_Dst);
    while ( v16 )
    {
      if ( _Dst[--v16] == 32 )
        _Dst[v16] = 0;
    }
    v17 = vostok::console_commands::find(_Dst);
    M_start = (vostok::vectora<char const *> *)v17;
    M_finish = v21;
    if ( v17 )
    {
      v17->info(v17, (char (*)[512])v23);
      (*((void (__thiscall **)(vostok::vectora<char const *> *, char *))M_start->_M_impl._M_start + 2))(M_start, v24);
      v8.editor_str = this->m_current_command_info;
      vostok::sprintf<512>((char (*)[512])this->m_current_command_info, "%s current is <%s>", v23, v24);
      M_start = &this->m_tips;
      stlp_std::vector<char const *,vostok::vectora_allocator<void *>>::clear(v18, (int)&this->m_tips);
      varC._M_impl._M_start = (const void **)this->m_current_command_info;
      stlp_std::vector<char const *,vostok::vectora_allocator<void *>>::push_back(&varC, v22);
    }
  }
  vostok::console_impl::fill_tips_view(
    (vostok::console_impl *)M_finish,
    (int)this,
    (int)this,
    (int)v8.editor_str,
    (int)M_start);
  return 0;
}
