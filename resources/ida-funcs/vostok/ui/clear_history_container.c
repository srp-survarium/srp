void __usercall vostok::ui::clear_history_container(
        vostok::vectora<vostok::ui::undo_> *v@<esi>,
        vostok::memory::base_allocator *a)
{
  vostok::ui::undo_ *M_finish; // ebx
  vostok::ui::undo_ *i; // edi
  unsigned __int8 *v4; // eax

  M_finish = v->_M_impl._M_finish;
  for ( i = v->_M_impl._M_start; i != M_finish; ++i )
  {
    if ( i->text )
      a->call_free(a, (void *)i->text, "vostok::ui::clear_history_container", ".\\ui_text_edit.cpp", 21u);
  }
  v4 = (unsigned __int8 *)v->_M_impl._M_finish;
  if ( (unsigned __int8 *)v->_M_impl._M_start != v4 )
    v->_M_impl._M_finish = (vostok::ui::undo_ *)stlp_std::priv::__copy_trivial(
                                                  v4,
                                                  v4,
                                                  (unsigned __int8 *)v->_M_impl._M_start);
}
