vostok::particle::base_particle *__usercall vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object@<eax>(
        vostok::particle::base_particle *const object@<eax>)
{
  return object->next;
}
