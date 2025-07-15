void **__userpurge stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::insert@<eax>(
        void **__pos@<eax>,
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *__x@<ecx>,
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *this)
{
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v3; // edi
  int v4; // esi
  bool v6; // [esp+0h] [ebp-8h]

  v3 = this;
  v4 = __pos - this->_M_start;
  if ( this->_M_end_of_storage._M_data - this->_M_finish )
    stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *>>::_M_fill_insert_aux(
      (stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *> > *)this,
      __pos,
      1u,
      (void **)&__x->_M_start,
      (const stlp_std::__false_type *)&this);
  else
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      __x,
      (int)this,
      __pos,
      (void *const *)&__x->_M_start,
      (const stlp_std::__true_type *)1,
      0,
      v6);
  return &v3->_M_start[v4];
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::insert(
        stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source> > *this@<ecx>,
        const stlp_std::__true_type *__n@<esi>,
        const vostok::render::batched_vertex_source *__x@<eax>,
        vostok::render::batched_vertex_source *__pos)
{
  unsigned int v4; // [esp+0h] [ebp-8h]
  bool v5; // [esp+4h] [ebp-4h]

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < (unsigned int)__n )
      stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::_M_insert_overflow(
        this,
        __pos,
        __x,
        __n,
        v4,
        v5);
    else
      stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::_M_fill_insert_aux(
        this,
        __pos,
        (unsigned int)__n,
        __x,
        (const stlp_std::__false_type *)&__pos);
  }
}


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


vostok::ai::planning::operator_pair *__thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::insert(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair> > *this,
        vostok::ai::planning::operator_pair *__pos,
        const vostok::ai::planning::operator_pair *__x)
{
  unsigned int __n; // [esp+Ch] [ebp-4h]

  __n = __pos - this->_M_start;
  stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::_M_fill_insert(
    this,
    __pos,
    1u,
    __x);
  return &this->_M_start[__n];
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32>>>::insert(
        stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32> > > *this@<ecx>,
        const stlp_std::__false_type *__n@<esi>,
        const vostok::fixed_string<32> *__x@<eax>,
        vostok::fixed_string<32> *__pos)
{
  unsigned int v4; // [esp+0h] [ebp-8h]
  bool v5; // [esp+4h] [ebp-4h]

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < (unsigned int)__n )
      stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32>>>::_M_insert_overflow_aux(
        this,
        __pos,
        __x,
        __n,
        v4,
        v5);
    else
      stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32>>>::_M_fill_insert_aux(
        this,
        __pos,
        (unsigned int)__n,
        __x,
        (const stlp_std::__false_type *)&__pos);
  }
}
