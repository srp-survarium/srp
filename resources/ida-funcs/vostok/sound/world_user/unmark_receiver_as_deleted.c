void __thiscall vostok::sound::world_user::unmark_receiver_as_deleted(
        vostok::sound::world_user *this,
        unsigned __int64 receiver_address)
{
  vostok::vectora<unsigned __int64> *v3; // [esp+4h] [ebp-38h]
  stlp_std::__false_type __formal; // [esp+27h] [ebp-15h] BYREF
  vostok::vectora<unsigned __int64> *m_deleted_receivers; // [esp+28h] [ebp-14h]
  unsigned __int64 *__first; // [esp+2Ch] [ebp-10h]
  unsigned __int64 *__last; // [esp+30h] [ebp-Ch]
  char v8; // [esp+37h] [ebp-5h]
  unsigned __int64 *elem; // [esp+38h] [ebp-4h]

  __last = this->m_deleted_receivers->_M_impl._M_finish;
  m_deleted_receivers = this->m_deleted_receivers;
  __first = m_deleted_receivers->_M_impl._M_start;
  elem = stlp_std::find<unsigned __int64 *,unsigned __int64>(__first, __last, &receiver_address);
  v8 = 0;
  v3 = this->m_deleted_receivers;
  __formal = 0;
  stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::_M_erase(
    &v3->_M_impl,
    elem,
    &__formal);
}
