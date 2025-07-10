void __thiscall vostok::sound::world_user::mark_producer_as_deleted(
        vostok::sound::world_user *this,
        unsigned __int64 producer_address)
{
  stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::push_back(
    &this->m_deleted_producers->_M_impl,
    &producer_address);
}
