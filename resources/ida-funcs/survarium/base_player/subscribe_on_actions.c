void __userpurge survarium::base_player::subscribe_on_actions(
        survarium::base_player *this@<ecx>,
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > subscriber)
{
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::push_back(
    &subscriber,
    (int)&dword_10D74 + (_DWORD)this);
}
