void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::push_back(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned int *__x)
{
  stlp_std::__true_type __formal; // [esp+Bh] [ebp-1h] BYREF

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_insert_overflow(
      this,
      (unsigned __int8 *)this->_M_finish,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    stlp_std::_Copy_Construct<unsigned int>(this->_M_finish, __x);
    ++this->_M_finish;
  }
}


void __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::push_back(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        void *const *__x)
{
  stlp_std::__true_type __formal; // [esp+Bh] [ebp-1h] BYREF

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_insert_overflow(
      this,
      this->_M_finish,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    stlp_std::_Copy_Construct<void *>(this->_M_finish, __x);
    ++this->_M_finish;
  }
}


void __usercall stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::push_back(
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this@<ecx>,
        int a2@<eax>)
{
  void **v3; // eax
  bool v4; // [esp+0h] [ebp-4h]

  v3 = *(void ***)(a2 + 4);
  if ( v3 == *(void ***)(a2 + 8) )
  {
    stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_insert_overflow(
      this,
      v3,
      (void *const *)&this->_M_start,
      (const stlp_std::__true_type *)1,
      1u,
      v4);
  }
  else
  {
    *v3 = this->_M_start;
    *(_DWORD *)(a2 + 4) += 4;
  }
}


void __thiscall stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::push_back(
        stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info> > *this,
        const survarium::hit_receiver_info *__x)
{
  stlp_std::__true_type __formal; // [esp+Fh] [ebp-1h] BYREF

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data> > *)this,
      (survarium::game_material_manager_cook::query_ext_data *)this->_M_finish,
      (const survarium::game_material_manager_cook::query_ext_data *)__x,
      &__formal,
      1u,
      1);
  }
  else
  {
    stlp_std::_Copy_Construct<vostok::ai::planning::world_state_property>(
      (vostok::ai::planning::world_state_property *)this->_M_finish,
      (const vostok::ai::planning::world_state_property *)__x);
    ++this->_M_finish;
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter>>::push_back(
        stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter> > *this,
        const vostok::logging::initiator_filter *__x)
{
  vostok::logging::initiator_filter *__pos; // [esp+4h] [ebp-28h]
  stlp_std::__false_type __formal; // [esp+Ah] [ebp-22h] BYREF
  char v5; // [esp+2Bh] [ebp-1h]

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    v5 = 0;
    __pos = this->_M_finish;
    __formal = 0;
    stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter>>::_M_insert_overflow_aux(
      this,
      __pos,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    stlp_std::_Param_Construct<vostok::logging::initiator_filter,vostok::logging::initiator_filter>(
      this->_M_finish,
      __x);
    ++this->_M_finish;
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info>>::push_back(
        stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info> > *this,
        const vostok::sound::propagator_info *__x)
{
  stlp_std::__true_type __formal; // [esp+Fh] [ebp-1h] BYREF

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info>>::_M_insert_overflow(
      this,
      this->_M_finish,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    *this->_M_finish++ = *__x;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>::push_back(
        stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record> > *this@<ecx>,
        int a2@<eax>,
        const survarium::scheduler::record *__x)
{
  survarium::scheduler::record *v4; // ebx
  const stlp_std::__false_type *v5; // [esp+0h] [ebp-Ch]
  unsigned int v6; // [esp+4h] [ebp-8h]
  bool v7; // [esp+8h] [ebp-4h]

  v4 = *(survarium::scheduler::record **)(a2 + 4);
  if ( v4 == *(survarium::scheduler::record **)(a2 + 12) )
  {
    stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>::_M_insert_overflow_aux(
      this,
      v4,
      __x,
      v5,
      v6,
      v7);
  }
  else
  {
    if ( v4 )
    {
      v4->m_id = __x->m_id;
      boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
        (boost::function4<void,unsigned int,float,float,char const *> *)&__x->m_callback,
        (int)&v4->m_callback);
      v4->survarium::scheduler::scheduler_record = __x->survarium::scheduler::scheduler_record;
    }
    *(_DWORD *)(a2 + 4) += 56;
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>::push_back(
        stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params> > *this,
        const vostok::sound::sound_voice_params *__x)
{
  stlp_std::__true_type __formal; // [esp+Fh] [ebp-1h] BYREF

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>::_M_insert_overflow(
      this,
      this->_M_finish,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    *this->_M_finish++ = *__x;
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::push_back(
        stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info> > *this,
        const vostok::sound::unique_propagator_info *__x)
{
  vostok::sound::unique_propagator_info *__pos; // [esp+4h] [ebp-28h]
  stlp_std::__false_type __formal; // [esp+Bh] [ebp-21h] BYREF
  char v5; // [esp+2Bh] [ebp-1h]

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    v5 = 0;
    __pos = this->_M_finish;
    __formal = 0;
    stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_insert_overflow_aux(
      this,
      __pos,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    stlp_std::_Copy_Construct<vostok::sound::unique_propagator_info>(this->_M_finish, __x);
    ++this->_M_finish;
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action>>::push_back(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *this,
        const vostok::ai::planning::specified_action *__x)
{
  vostok::ai::planning::specified_action *__pos; // [esp+4h] [ebp-30h]
  stlp_std::__false_type __formal; // [esp+Bh] [ebp-29h] BYREF
  char v5; // [esp+33h] [ebp-1h]

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    v5 = 0;
    __pos = this->_M_finish;
    __formal = 0;
    stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action>>::_M_insert_overflow_aux(
      this,
      __pos,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    stlp_std::_Copy_Construct<vostok::ai::planning::specified_action>(this->_M_finish, __x);
    ++this->_M_finish;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>::push_back(
        const stlp_std::__false_type *__x@<eax>,
        stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string> > *a2@<ecx>,
        stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string> > *this)
{
  vostok::fs_new::virtual_path_string *M_finish; // esi
  unsigned __int8 *v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // edi
  unsigned int v7; // [esp+0h] [ebp-8h]
  bool v8; // [esp+4h] [ebp-4h]

  M_finish = this->_M_finish;
  if ( M_finish == this->_M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>::_M_insert_overflow_aux(
      a2,
      (vostok::fs_new::virtual_path_string *)this,
      M_finish,
      __x,
      v7,
      v8);
  }
  else
  {
    if ( M_finish )
    {
      v4 = *(unsigned __int8 **)__x;
      v5 = *(_DWORD *)&__x[4] - *(_DWORD *)__x;
      M_finish->m_string.m_max_end = &M_finish->m_separator;
      v6 = v5;
      M_finish->m_string.m_begin = M_finish->m_string.m_buffer;
      M_finish->m_string.m_end = M_finish->m_string.m_buffer;
      memcpy((unsigned __int8 *)M_finish->m_string.m_buffer, v4, v5);
      M_finish->m_string.m_end += v6;
      *M_finish->m_string.m_end = 0;
      M_finish->m_separator = 47;
    }
    ++this->_M_finish;
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16>>>::push_back(
        stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > *this,
        const vostok::fixed_string<16> *__x)
{
  vostok::fixed_string<16> *__pos; // [esp+4h] [ebp-28h]
  stlp_std::__false_type __formal; // [esp+Ah] [ebp-22h] BYREF
  char v5; // [esp+2Bh] [ebp-1h]

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    v5 = 0;
    __pos = this->_M_finish;
    __formal = 0;
    stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16>>>::_M_insert_overflow_aux(
      this,
      __pos,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    stlp_std::_Param_Construct<vostok::fixed_string<16>,vostok::fixed_string<16>>(this->_M_finish, __x);
    ++this->_M_finish;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260>>>::push_back(
        const stlp_std::__false_type *__x@<eax>,
        stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260> > > *a2@<ecx>,
        stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260> > > *this)
{
  vostok::fixed_string<260> *M_finish; // esi
  unsigned __int8 *v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // edi
  unsigned int v7; // [esp+0h] [ebp-8h]
  bool v8; // [esp+4h] [ebp-4h]

  M_finish = this->_M_finish;
  if ( M_finish == this->_M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260>>>::_M_insert_overflow_aux(
      a2,
      (vostok::fixed_string<260> *)this,
      M_finish,
      __x,
      v7,
      v8);
  }
  else
  {
    if ( M_finish )
    {
      v4 = *(unsigned __int8 **)__x;
      v5 = *(_DWORD *)&__x[4] - *(_DWORD *)__x;
      M_finish->m_max_end = (char *)&M_finish[1];
      v6 = v5;
      M_finish->m_begin = M_finish->m_buffer;
      M_finish->m_end = M_finish->m_buffer;
      memcpy((unsigned __int8 *)M_finish->m_buffer, v4, v5);
      M_finish->m_end += v6;
      *M_finish->m_end = 0;
    }
    ++this->_M_finish;
  }
}


void __thiscall stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::push_back(
        stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *this,
        const unsigned __int64 *__x)
{
  stlp_std::__true_type __formal; // [esp+Fh] [ebp-1h] BYREF

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::_M_insert_overflow(
      this,
      this->_M_finish,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    *this->_M_finish++ = *__x;
  }
}
