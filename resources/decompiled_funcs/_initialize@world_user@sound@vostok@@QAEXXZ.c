void __thiscall vostok::sound::world_user::initialize(vostok::sound::world_user *this)
{
  vostok::sound::sound_order *v1; // eax
  vostok::sound::sound_order *const v2; // eax
  vostok::sound::sound_order *backward_queue_initial_value; // [esp+4h] [ebp-74h]
  vostok::vectora<unsigned __int64> *v4; // [esp+8h] [ebp-70h]
  vostok::vectora<unsigned __int64> *v5; // [esp+Ch] [ebp-6Ch]
  vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > v7; // [esp+48h] [ebp-30h] BYREF
  stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *v8; // [esp+4Ch] [ebp-2Ch]
  vostok::memory::base_allocator *v9; // [esp+50h] [ebp-28h]
  vostok::memory::base_allocator *v10; // [esp+54h] [ebp-24h]
  vostok::memory::base_allocator *v11; // [esp+58h] [ebp-20h]
  vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > __a; // [esp+5Ch] [ebp-1Ch] BYREF
  stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *v13; // [esp+60h] [ebp-18h]
  vostok::memory::base_allocator *m_allocator; // [esp+64h] [ebp-14h]
  vostok::sound::sound_order *v15; // [esp+68h] [ebp-10h]
  vostok::sound::sound_order *v16; // [esp+6Ch] [ebp-Ch]
  stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *v17; // [esp+70h] [ebp-8h]
  stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *v18; // [esp+74h] [ebp-4h]

  if ( this->m_allocator )
  {
    m_allocator = this->m_allocator;
    v13 = (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)vostok::memory::base_allocator::malloc_impl(m_allocator, 0x10u);
    v18 = v13;
    if ( v13 )
    {
      v10 = this->m_allocator;
      v11 = v10;
      __a.m_allocator = v10;
      stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
        v18,
        &__a);
      v5 = (vostok::vectora<unsigned __int64> *)v18;
    }
    else
    {
      v5 = 0;
    }
    this->m_deleted_producers = v5;
    v9 = this->m_allocator;
    v8 = (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)vostok::memory::base_allocator::malloc_impl(v9, 0x10u);
    v17 = v8;
    if ( v8 )
    {
      v7.m_allocator = this->m_allocator;
      stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
        v17,
        &v7);
      v4 = (vostok::vectora<unsigned __int64> *)v17;
    }
    else
    {
      v4 = 0;
    }
    this->m_deleted_receivers = v4;
  }
  v16 = (vostok::sound::sound_order *)vostok::memory::base_allocator::malloc_impl(this->m_allocator, 0xCu);
  if ( v16 )
  {
    vostok::sound::sound_order::sound_order(v16);
    backward_queue_initial_value = v1;
  }
  else
  {
    backward_queue_initial_value = 0;
  }
  v15 = (vostok::sound::sound_order *)vostok::memory::base_allocator::malloc_impl(this->m_allocator, 0xCu);
  if ( v15 )
  {
    vostok::sound::sound_order::sound_order(v15);
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>>::owner_initialize(
      &this->m_channel.orders,
      v2,
      backward_queue_initial_value);
  }
  else
  {
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>>::owner_initialize(
      &this->m_channel.orders,
      0,
      backward_queue_initial_value);
  }
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>>::user_initialize((vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> > *)this);
}
