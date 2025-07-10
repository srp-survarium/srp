void __thiscall survarium::victory_items_container_core::put_item(
        survarium::victory_items_container_core *this,
        survarium::victory_item_core *item)
{
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *v2; // eax

  v2 = (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref((boost::arg<1> *)&item);
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::push_back(
    v2,
    (void *const *)&this->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable);
}
