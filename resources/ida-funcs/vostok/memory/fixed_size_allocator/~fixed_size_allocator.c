void __usercall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::~fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this@<ecx>,
        int a2@<edi>)
{
  *(_DWORD *)a2 = &vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::`vftable';
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    *(int **)(a2 + 80));
  *(_DWORD *)(a2 + 84) = 0;
  *(_DWORD *)a2 = &vostok::memory::base_allocator::`vftable';
}


void __usercall vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::~fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>(
        vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *this@<ecx>,
        _DWORD *a2@<edi>)
{
  *a2 = &vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::`vftable';
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)a2[20]);
  a2[21] = 0;
  *a2 = &vostok::memory::base_allocator::`vftable';
}
