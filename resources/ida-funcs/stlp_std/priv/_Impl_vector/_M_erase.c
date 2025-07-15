void **__thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_erase(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        void **__pos,
        const stlp_std::__false_type *__formal)
{
  if ( __pos + 1 != this->_M_finish )
    stlp_std::priv::__copy_trivial(
      (unsigned __int8 *)__pos + 4,
      (unsigned __int8 *)this->_M_finish,
      (unsigned __int8 *)__pos);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)--this->_M_finish);
  return __pos;
}


vostok::ai::planning::world_state_property *__thiscall stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::_M_erase(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *this,
        vostok::ai::planning::world_state_property *__first,
        vostok::ai::planning::world_state_property *__last,
        const stlp_std::__false_type *__formal)
{
  this->_M_finish = (vostok::ai::planning::world_state_property *)stlp_std::priv::__copy_trivial(
                                                                    (unsigned __int8 *)__last,
                                                                    (unsigned __int8 *)this->_M_finish,
                                                                    (unsigned __int8 *)__first);
  return __first;
}


survarium::hit_receiver_info *__thiscall stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::_M_erase(
        stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info> > *this,
        survarium::hit_receiver_info *__pos,
        const stlp_std::__false_type *__formal)
{
  if ( &__pos[1] != this->_M_finish )
    stlp_std::priv::__copy_trivial(
      (unsigned __int8 *)&__pos[1],
      (unsigned __int8 *)this->_M_finish,
      (unsigned __int8 *)__pos);
  --this->_M_finish;
  return __pos;
}


vostok::render::light_data *__userpurge stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data>>::_M_erase@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data> > *this@<ecx>,
        int a2@<eax>,
        vostok::render::light_data *__pos,
        const stlp_std::__false_type *__formal)
{
  vostok::render::light_data *v5; // edx
  _DWORD **v6; // esi
  _DWORD *v7; // eax
  _DWORD *v9; // edi
  vostok::render::grass_render_model *m_object; // esi
  const stlp_std::random_access_iterator_tag *v12; // [esp+0h] [ebp-10h]
  int *v13; // [esp+4h] [ebp-Ch]

  v5 = *(vostok::render::light_data **)(a2 + 4);
  if ( &__pos[1] != v5 )
    stlp_std::priv::__copy<vostok::render::light_data *,vostok::render::light_data *,int>(
      __pos + 1,
      v5,
      __pos,
      v12,
      v13);
  *(_DWORD *)(a2 + 4) -= 8;
  v6 = *(_DWORD ***)(a2 + 4);
  v7 = *v6;
  if ( *v6 )
  {
    if ( (*v7)-- == 1 )
    {
      v9 = *v6;
      m_object = vostok::render::g_allocator.m_object;
      if ( v9 )
      {
        vostok::render::light::~light((vostok::render::light *)this);
        BYTE2(m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), v9);
      }
    }
  }
  return __pos;
}


vostok::fixed_vector<unsigned int,32> *__thiscall stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_M_erase(
        stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *this,
        vostok::fixed_vector<unsigned int,32> *__first,
        vostok::fixed_vector<unsigned int,32> *__last,
        const stlp_std::__false_type *__formal)
{
  vostok::fixed_vector<unsigned int,32> *v6; // [esp+18h] [ebp-30h]
  vostok::fixed_vector<unsigned int,32> *v7; // [esp+1Ch] [ebp-2Ch]
  unsigned int *end; // [esp+38h] [ebp-10h] BYREF
  int i; // [esp+3Ch] [ebp-Ch]
  char v10; // [esp+43h] [ebp-5h]
  vostok::fixed_vector<unsigned int,32> *__i; // [esp+44h] [ebp-4h]

  v10 = 0;
  v6 = __first;
  v7 = __last;
  for ( i = this->_M_finish - __last; i > 0; --i )
  {
    end = v7->m_end;
    vostok::buffer_vector<unsigned int>::assign<unsigned int const *>(
      v6,
      v7->m_begin,
      (const unsigned int *const *)&end);
    ++v7;
    ++v6;
  }
  __i = v6;
  stlp_std::__destroy_range<vostok::fixed_vector<unsigned int,32> *,vostok::fixed_vector<unsigned int,32>>(
    v6,
    this->_M_finish,
    0);
  this->_M_finish = __i;
  return __first;
}


vostok::variant<32> *__thiscall stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_M_erase(
        stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *this,
        vostok::variant<32> *__first,
        vostok::variant<32> *__last,
        const stlp_std::__false_type *__formal)
{
  vostok::variant<32> *v6; // [esp+10h] [ebp-14h]
  vostok::variant<32> *other; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]

  v6 = __first;
  other = __last;
  for ( i = this->_M_finish - __last; i > 0; --i )
    vostok::variant<32>::operator=(v6++, other++);
  stlp_std::_Destroy_Range<vostok::variant<32> *>(v6, this->_M_finish);
  this->_M_finish = v6;
  return __first;
}


unsigned __int8 *__thiscall stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::_M_erase(
        stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *this,
        unsigned __int8 *__pos,
        const stlp_std::__false_type *__formal)
{
  unsigned __int64 *M_finish; // [esp+10h] [ebp-14h]

  if ( __pos + 8 != (unsigned __int8 *)this->_M_finish )
  {
    M_finish = this->_M_finish;
    if ( M_finish != (unsigned __int64 *)(__pos + 8) )
      memmove(__pos, __pos + 8, (char *)M_finish - (char *)(__pos + 8));
  }
  --this->_M_finish;
  return __pos;
}
