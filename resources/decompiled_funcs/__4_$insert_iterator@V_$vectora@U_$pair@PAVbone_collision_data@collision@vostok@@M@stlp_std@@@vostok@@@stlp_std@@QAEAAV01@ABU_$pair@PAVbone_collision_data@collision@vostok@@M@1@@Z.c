stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > > *__thiscall stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float>>>::operator=(
        stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > > *this,
        const stlp_std::pair<vostok::collision::bone_collision_data *,float> *__val)
{
  this->_M_iter = stlp_std::priv::_Impl_vector<stlp_std::pair<vostok::collision::bone_collision_data *,float>,vostok::vectora_allocator<stlp_std::pair<vostok::collision::bone_collision_data *,float>>>::insert(
                    &this->container->_M_impl,
                    this->_M_iter,
                    __val);
  ++this->_M_iter;
  return this;
}
