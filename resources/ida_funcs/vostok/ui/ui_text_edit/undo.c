void __usercall vostok::ui::ui_text_edit::undo(vostok::ui::ui_text_edit *this@<ecx>, bool a2@<sil>)
{
  vostok::ui::undo_ *M_finish; // eax
  int *p_m_redo_history; // esi
  stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_> > *v5; // ecx
  vostok::ui::undo_ *v6; // eax
  vostok::ui::undo_ *v7; // esi

  if ( this->m_undo_history._M_impl._M_start != this->m_undo_history._M_impl._M_finish )
  {
    M_finish = this->m_undo_history._M_impl._M_finish;
    p_m_redo_history = (int *)&this->m_redo_history;
    this->m_b_undo = 1;
    v5 = (stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_> > *)this->m_redo_history._M_impl._M_finish;
    v6 = M_finish - 1;
    if ( v5 == (stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_> > *)this->m_redo_history._M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_>>::_M_insert_overflow(
        v5,
        p_m_redo_history,
        (vostok::ui::undo_ *)v5,
        (int)v6,
        (const stlp_std::__true_type *)1,
        1,
        a2);
    }
    else
    {
      v5->_M_start = (vostok::ui::undo_ *)v6->text;
      v5->_M_finish = *(vostok::ui::undo_ **)&v6->caret;
      ++this->m_redo_history._M_impl._M_finish;
    }
    if ( this->m_undo_history._M_impl._M_start != --this->m_undo_history._M_impl._M_finish )
    {
      v7 = this->m_undo_history._M_impl._M_finish;
      this->set_text(&this->vostok::ui::ui_text<vostok::ui::dynamic_text>, v7[-1].text);
      this->set_caret_position(this, v7[-1].caret, 0);
    }
    this->m_b_undo = 0;
  }
}
