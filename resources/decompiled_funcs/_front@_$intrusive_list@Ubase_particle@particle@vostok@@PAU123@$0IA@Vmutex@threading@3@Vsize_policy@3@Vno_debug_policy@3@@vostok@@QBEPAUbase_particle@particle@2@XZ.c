vostok::particle::base_particle *__usercall vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::front@<eax>(
        vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        int a2@<eax>)
{
  return *(vostok::particle::base_particle **)(a2 + 36);
}
