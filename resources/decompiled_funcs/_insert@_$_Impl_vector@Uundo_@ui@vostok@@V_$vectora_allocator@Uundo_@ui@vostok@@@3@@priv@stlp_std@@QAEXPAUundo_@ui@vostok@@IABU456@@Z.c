void __userpurge stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_>>::insert(
        const stlp_std::__true_type *__n@<eax>,
        const vostok::ui::undo_ *__x@<edx>,
        bool a3@<dil>,
        stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_> > *this,
        vostok::ui::undo_ *__pos)
{
  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < (unsigned int)__n )
      stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_>>::_M_insert_overflow(
        this,
        __pos,
        __x,
        __n,
        0,
        a3);
    else
      stlp_std::priv::_Impl_vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request>>::_M_fill_insert_aux(
        (stlp_std::priv::_Impl_vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > *)this,
        (vostok::resources::request *)__pos,
        (unsigned int)__n,
        (const vostok::resources::request *)__x,
        (const stlp_std::__false_type *)&__pos);
  }
}
