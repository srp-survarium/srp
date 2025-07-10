bool __thiscall vostok::sound::world_user::is_receiver_deleted(
        vostok::sound::world_user *this,
        unsigned __int64 receiver_address)
{
  unsigned __int64 *M_finish; // [esp+4h] [ebp-10h]

  M_finish = this->m_deleted_receivers->_M_impl._M_finish;
  return stlp_std::find<unsigned __int64 *,unsigned __int64>(
           this->m_deleted_receivers->_M_impl._M_start,
           M_finish,
           &receiver_address) != M_finish;
}
