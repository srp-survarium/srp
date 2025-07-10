void __thiscall vostok::sound::unique_propagator_info::unique_propagator_info(
        vostok::sound::unique_propagator_info *this)
{
  vostok::memory::base_allocator *m_object; // [esp+10h] [ebp-4h]

  m_object = (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object;
  this->voice_params._M_impl._M_start = 0;
  this->voice_params._M_impl._M_finish = 0;
  this->voice_params._M_impl._M_end_of_storage.m_allocator = m_object;
  this->voice_params._M_impl._M_end_of_storage._M_data = 0;
  this->prop = 0;
}
