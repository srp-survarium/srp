void __cdecl vostok::ui::clear_history_container(
        vostok::vectora<vostok::ui::undo_> *v,
        vostok::memory::base_allocator *a)
{
  vostok::ui::undo_ *M_start; // esi
  vostok::ui::undo_ *M_finish; // edi

  M_start = v->_M_impl._M_start;
  M_finish = v->_M_impl._M_finish;
  if ( v->_M_impl._M_start != M_finish )
  {
    do
    {
      if ( M_start->text )
        a->call_free(a, (void *)M_start->text);
      ++M_start;
    }
    while ( M_start != M_finish );
  }
  if ( v->_M_impl._M_start != v->_M_impl._M_finish )
    v->_M_impl._M_finish = v->_M_impl._M_start;
}
