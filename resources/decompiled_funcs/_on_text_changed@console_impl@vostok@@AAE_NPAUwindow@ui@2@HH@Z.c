bool __thiscall vostok::console_impl::on_text_changed(
        vostok::console_impl *this,
        vostok::ui::window *w,
        int p1,
        int p2)
{
  vostok::ui::text *v5; // eax
  char *v6; // esi
  unsigned int v7; // eax
  unsigned int similar; // ebp
  unsigned __int8 *M_finish; // ecx
  const void **M_start; // eax
  vostok::vectora<char const *> *p_m_tips; // ebx
  unsigned int i; // edi
  const void **v13; // eax
  const void **p_M_start; // esi
  const char **m_current_command_info; // edi
  int v16; // eax
  int j; // ecx
  vostok::ui::text *v18; // eax
  const char *v19; // eax
  unsigned int v20; // eax
  vostok::console_commands::console_command *v21; // eax
  const void **v22; // eax
  const stlp_std::__true_type *v24; // [esp+0h] [ebp-648h]
  unsigned int v25; // [esp+4h] [ebp-644h]
  int v26; // [esp+8h] [ebp-640h]
  int v27; // [esp+Ch] [ebp-63Ch]
  int v28; // [esp+10h] [ebp-638h]
  unsigned int __x; // [esp+18h] [ebp-630h] BYREF
  const char *text; // [esp+1Ch] [ebp-62Ch]
  vostok::console_commands::console_command *storage[10]; // [esp+20h] [ebp-628h] BYREF
  char cmd_name[512]; // [esp+48h] [ebp-600h] BYREF
  char status_str[512]; // [esp+248h] [ebp-400h] BYREF
  char info_str[512]; // [esp+448h] [ebp-200h] BYREF

  v5 = this->m_text_edit->text(this->m_text_edit);
  v6 = (char *)v5->get_text(v5);
  text = v6;
  v7 = strlen(v6);
  if ( this->m_tips_mode )
  {
    if ( v7 )
      return 0;
  }
  else if ( v7 )
  {
    similar = vostok::console_commands::get_similar(v6, storage);
    goto LABEL_4;
  }
  similar = 0;
LABEL_4:
  M_finish = (unsigned __int8 *)this->m_tips._M_impl._M_finish;
  M_start = this->m_tips._M_impl._M_start;
  p_m_tips = &this->m_tips;
  if ( M_start != (const void **)M_finish )
    p_m_tips->_M_impl._M_finish = M_start;
  for ( i = 0; i < similar; ++i )
  {
    v13 = p_m_tips->_M_impl._M_finish;
    M_finish = (unsigned __int8 *)storage[i]->m_name;
    __x = (unsigned int)M_finish;
    if ( v13 == p_m_tips->_M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)&__x,
        (unsigned __int8 **)p_m_tips,
        (int)v13,
        &__x,
        v24,
        v25,
        v26);
    }
    else
    {
      *v13 = M_finish;
      ++p_m_tips->_M_impl._M_finish;
    }
  }
  p_M_start = this->m_tips._M_impl._M_finish;
  m_current_command_info = (const char **)p_m_tips->_M_impl._M_start;
  if ( p_m_tips->_M_impl._M_start != p_M_start )
  {
    v16 = ((char *)p_M_start - (char *)m_current_command_info) >> 2;
    for ( j = 0; v16 != 1; ++j )
      v16 >>= 1;
    stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::tips_sorting_predicate>(
      (vostok::tips_sorting_predicate)p_M_start,
      m_current_command_info,
      (const char **)p_M_start,
      0,
      2 * j,
      (vostok::tips_sorting_predicate)text);
    stlp_std::priv::__final_insertion_sort<char const * *,vostok::tips_sorting_predicate>(
      m_current_command_info,
      (const char **)p_M_start,
      (vostok::tips_sorting_predicate)text);
  }
  if ( !similar )
  {
    v18 = this->m_text_edit->text(this->m_text_edit);
    v19 = v18->get_text(v18);
    strcpy_s(cmd_name, 0x200u, v19);
    v20 = strlen(cmd_name);
    while ( v20 )
    {
      if ( cmd_name[--v20] == 32 )
        cmd_name[v20] = 0;
    }
    v21 = vostok::console_commands::find(cmd_name);
    p_M_start = (const void **)&v21->__vftable;
    if ( v21 )
    {
      v21->info(v21, (char (*)[512])info_str);
      (*((void (__thiscall **)(const void **, char *))*p_M_start + 2))(p_M_start, status_str);
      m_current_command_info = (const char **)this->m_current_command_info;
      vostok::sprintf<512>((char (*)[512])this->m_current_command_info, "%s current is <%s>", info_str, status_str);
      M_finish = (unsigned __int8 *)p_m_tips->_M_impl._M_start;
      if ( p_m_tips->_M_impl._M_start != p_m_tips->_M_impl._M_finish )
      {
        p_M_start = 0;
        p_m_tips->_M_impl._M_finish = p_m_tips->_M_impl._M_start;
      }
      v22 = p_m_tips->_M_impl._M_finish;
      __x = (unsigned int)this->m_current_command_info;
      if ( v22 == p_m_tips->_M_impl._M_end_of_storage._M_data )
      {
        p_M_start = (const void **)&p_m_tips->_M_impl._M_start;
        stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)M_finish,
          (unsigned __int8 **)p_m_tips,
          (int)v22,
          &__x,
          v24,
          v25,
          v26);
      }
      else
      {
        *v22 = m_current_command_info;
        ++p_m_tips->_M_impl._M_finish;
      }
    }
  }
  vostok::console_impl::fill_tips_view(
    (vostok::console_impl *)M_finish,
    (int)p_m_tips,
    (int)m_current_command_info,
    (int)p_M_start,
    this,
    (int)v24,
    v25,
    v26,
    v27,
    v28,
    this);
  return 0;
}
