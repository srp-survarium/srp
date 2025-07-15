void __userpurge survarium::victory_items_container_core::put_item(
        survarium::victory_items_container_core *this@<ecx>,
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > item)
{
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::push_back(&item, (int)&this->m_victory_items);
}
