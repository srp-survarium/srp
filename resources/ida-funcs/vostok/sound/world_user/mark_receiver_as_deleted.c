void __thiscall vostok::sound::world_user::mark_receiver_as_deleted(
        vostok::sound::world_user *this,
        unsigned __int64 receiver_address)
{
  stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::push_back(
    &this->m_deleted_receivers->_M_impl,
    &receiver_address);
}
