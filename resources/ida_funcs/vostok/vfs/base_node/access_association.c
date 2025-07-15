void __thiscall vostok::vfs::base_node<1>::access_association(
        vostok::vfs::base_node<1> *this,
        boost::function1<void,vostok::ai::sensors::sensed_object const &> *callback)
{
  vostok::vfs::vfs_association *association; // [esp+138h] [ebp-4h] BYREF

  vostok::vfs::base_node<1>::lock_associated(this);
  association = this->m_association.pointer;
  boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
    callback,
    (const vostok::ai::sensors::sensed_object *)&association);
  this->m_association.pointer = association;
  vostok::vfs::base_node<1>::unlock_associated(this);
}
