void __thiscall vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>::vectora_allocator<vostok::fixed_vector<unsigned int,32>>(
        vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3> > *this,
        const vostok::vectora_allocator<void *> *allocator)
{
  this->m_allocator = allocator->m_allocator;
}
