void __thiscall vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>::vectora_allocator<vostok::fixed_vector<unsigned int,32>>(
        vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3> > *this,
        const vostok::vectora_allocator<void *> *allocator)
{
  this->m_allocator = allocator->m_allocator;
}


void __thiscall vostok::vectora_allocator<void const *>::vectora_allocator<void const *>(
        vostok::vectora_allocator<void const *> *this,
        const vostok::vectora_allocator<vostok::ai::game_object const *> *allocator)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_allocator = allocator->m_allocator;
}
