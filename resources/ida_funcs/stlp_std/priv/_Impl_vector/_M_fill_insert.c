void __thiscall stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this,
        char *__pos,
        unsigned int __n,
        const char *__x)
{
  stlp_std::__true_type v4; // [esp+6h] [ebp-2h] BYREF
  stlp_std::__false_type __formal; // [esp+7h] [ebp-1h] BYREF

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
    {
      v4 = 0;
      stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_insert_overflow(this, __pos, __x, &v4, __n, 0);
    }
    else
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_fill_insert_aux(this, __pos, __n, __x, &__formal);
    }
  }
}


void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned __int8 *__pos,
        unsigned int __n,
        unsigned int *__x)
{
  stlp_std::__true_type v4; // [esp+6h] [ebp-2h] BYREF
  stlp_std::__false_type __formal; // [esp+7h] [ebp-1h] BYREF

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
    {
      v4 = 0;
      stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_insert_overflow(
        this,
        __pos,
        __x,
        &v4,
        __n,
        0);
    }
    else
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_fill_insert_aux(
        this,
        (unsigned int *)__pos,
        __n,
        __x,
        &__formal);
    }
  }
}


void __thiscall stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *this,
        float *__pos,
        unsigned int __n,
        const float *__x)
{
  stlp_std::__true_type v4; // [esp+6h] [ebp-2h] BYREF
  stlp_std::__false_type __formal; // [esp+7h] [ebp-1h] BYREF

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
    {
      v4 = 0;
      stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_insert_overflow(
        this,
        __pos,
        __x,
        &v4,
        __n,
        0);
    }
    else
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_fill_insert_aux(
        this,
        __pos,
        __n,
        __x,
        &__formal);
    }
  }
}


void __thiscall stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this,
        void **__pos,
        const stlp_std::__true_type *__n,
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *__x)
{
  bool v4; // [esp+0h] [ebp-Ch]
  stlp_std::__false_type __formal; // [esp+Bh] [ebp-1h] BYREF

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < (unsigned int)__n )
    {
      stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_insert_overflow(
        __x,
        (unsigned __int8 **)this,
        __pos,
        (void *const *)&__x->_M_start,
        __n,
        0,
        v4);
    }
    else
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_fill_insert_aux(
        this,
        __pos,
        (unsigned int)__n,
        (void *const *)&__x->_M_start,
        &__formal);
    }
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::branch_vertex,vostok::render::std_allocator<vostok::render::branch_vertex>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<vostok::render::frond_vertex,vostok::render::std_allocator<vostok::render::frond_vertex> > *this@<ecx>,
        unsigned int __n@<edi>,
        vostok::render::frond_vertex *__pos,
        const vostok::render::frond_vertex *__x)
{
  bool v4; // [esp+0h] [ebp-Ch]

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
      stlp_std::priv::_Impl_vector<vostok::render::frond_vertex,vostok::render::std_allocator<vostok::render::frond_vertex>>::_M_insert_overflow(
        __n,
        this,
        this,
        __pos,
        __x,
        0,
        v4);
    else
      stlp_std::priv::_Impl_vector<vostok::render::frond_vertex,vostok::render::std_allocator<vostok::render::frond_vertex>>::_M_fill_insert_aux(
        this,
        __pos,
        __n,
        __x,
        (const stlp_std::__false_type *)&__x);
  }
}


void __userpurge stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC> > *this@<ecx>,
        const D3D11_INPUT_ELEMENT_DESC *__x@<eax>,
        D3D11_INPUT_ELEMENT_DESC *__pos,
        const stlp_std::__true_type *__n)
{
  unsigned int v4; // [esp+0h] [ebp-Ch]
  bool v5; // [esp+4h] [ebp-8h]

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < (unsigned int)__n )
      stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC>>::_M_insert_overflow(
        this,
        __pos,
        __x,
        __n,
        v4,
        v5);
    else
      stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC>>::_M_fill_insert_aux(
        this,
        __pos,
        (unsigned int)__n,
        __x,
        (const stlp_std::__false_type *)&__n);
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::leafcard_vertex,vostok::render::std_allocator<vostok::render::leafcard_vertex>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<vostok::render::leafcard_vertex,vostok::render::std_allocator<vostok::render::leafcard_vertex> > *this@<ecx>,
        unsigned int __n@<edi>,
        vostok::render::leafcard_vertex *__pos,
        const vostok::render::leafcard_vertex *__x)
{
  bool v4; // [esp+0h] [ebp-8h]

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
      stlp_std::priv::_Impl_vector<vostok::render::leafcard_vertex,vostok::render::std_allocator<vostok::render::leafcard_vertex>>::_M_insert_overflow(
        __n,
        this,
        this,
        __pos,
        __x,
        0,
        v4);
    else
      stlp_std::priv::_Impl_vector<vostok::render::leafcard_vertex,vostok::render::std_allocator<vostok::render::leafcard_vertex>>::_M_fill_insert_aux(
        this,
        __pos,
        __n,
        __x,
        (const stlp_std::__false_type *)&__x);
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex> > *this@<ecx>,
        const vostok::render::ui::vertex *__x@<eax>,
        vostok::render::ui::vertex *__pos,
        const stlp_std::__true_type *__n)
{
  unsigned int v4; // [esp+0h] [ebp-Ch]
  bool v5; // [esp+4h] [ebp-8h]

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < (unsigned int)__n )
      stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_insert_overflow(
        this,
        __pos,
        __x,
        __n,
        v4,
        v5);
    else
      stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_fill_insert_aux(
        this,
        __pos,
        (unsigned int)__n,
        __x,
        (const stlp_std::__false_type *)&__n);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper> > *this,
        survarium::zone_group::zone_wrapper *__pos,
        unsigned int __n,
        const survarium::zone_group::zone_wrapper *__x)
{
  stlp_std::__true_type v4; // [esp+6h] [ebp-2h] BYREF
  stlp_std::__false_type __formal; // [esp+7h] [ebp-1h] BYREF

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
    {
      v4 = 0;
      stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper>>::_M_insert_overflow(
        this,
        __pos,
        __x,
        &v4,
        __n,
        0);
    }
    else
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper>>::_M_fill_insert_aux(
        this,
        __pos,
        __n,
        __x,
        &__formal);
    }
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair> > *this,
        vostok::ai::planning::operator_pair *__pos,
        unsigned int __n,
        const vostok::ai::planning::operator_pair *__x)
{
  stlp_std::__true_type v4; // [esp+6h] [ebp-2h] BYREF
  stlp_std::__false_type __formal; // [esp+7h] [ebp-1h] BYREF

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
    {
      v4 = 0;
      stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::_M_insert_overflow(
        this,
        __pos,
        __x,
        &v4,
        __n,
        0);
    }
    else
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::_M_fill_insert_aux(
        this,
        __pos,
        __n,
        __x,
        &__formal);
    }
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *this,
        vostok::fixed_vector<unsigned int,32> *__pos,
        unsigned int __n,
        const vostok::fixed_vector<unsigned int,32> *__x)
{
  stlp_std::__false_type v4; // [esp+5h] [ebp-3h] BYREF
  char v5; // [esp+6h] [ebp-2h]
  stlp_std::__false_type __formal; // [esp+7h] [ebp-1h] BYREF

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
    {
      v5 = 0;
      v4 = 0;
      stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_M_insert_overflow_aux(
        this,
        __pos,
        __x,
        &v4,
        __n,
        0);
    }
    else
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_M_fill_insert_aux(
        this,
        __pos,
        __n,
        __x,
        &__formal);
    }
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *this,
        vostok::variant<32> *__pos,
        unsigned int __n,
        const vostok::variant<32> *__x)
{
  stlp_std::__false_type v4; // [esp+5h] [ebp-3h] BYREF
  char v5; // [esp+6h] [ebp-2h]
  stlp_std::__false_type __formal; // [esp+7h] [ebp-1h] BYREF

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
    {
      v5 = 0;
      v4 = 0;
      stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_M_insert_overflow_aux(
        this,
        __pos,
        __x,
        &v4,
        __n,
        0);
    }
    else
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_M_fill_insert_aux(
        this,
        __pos,
        __n,
        __x,
        &__formal);
    }
  }
}
