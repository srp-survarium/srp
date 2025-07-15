void __userpurge vostok::sound::proxy_statistic::fill_text_tree(
        vostok::sound::proxy_statistic *this@<ecx>,
        int a2@<edi>,
        vostok::strings::text_tree_item *item,
        bool __formal)
{
  _DWORD *v4; // esi
  vostok::strings::text_tree_item *v5; // ebx
  vostok::strings::text_tree_item *v6; // ecx
  int v7; // eax

  v4 = *(_DWORD **)(a2 + 36);
  v5 = 0;
  while ( v4 )
  {
    if ( !v5 )
    {
      v5 = vostok::strings::text_tree_item::new_child(
             (vostok::strings::text_tree_item *)this,
             (const char *)item,
             "emitter type");
      v7 = *(_DWORD *)(a2 + 52);
      if ( v7 )
      {
        if ( v7 == 1 )
          vostok::strings::text_tree_item::add_column_impl(v6, (const char *)v5, "composite");
        else
          vostok::strings::text_tree_item::add_column_impl(v6, (const char *)v5, (char *)&stru_7FF1F0.m_max_end);
      }
      else
      {
        vostok::strings::text_tree_item::add_column_impl(v6, (const char *)v5, "single");
      }
    }
    vostok::sound::propagator_statistic::fill_text_tree((vostok::sound::propagator_statistic *)this, (int)v4, v5);
    v4 = (_DWORD *)*v4;
  }
}
