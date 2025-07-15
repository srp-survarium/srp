BOOL __thiscall stlp_std::less<unsigned int>::operator()(
        stlp_std::less<unsigned int> *this,
        const unsigned int *__x,
        const unsigned int *__y)
{
  return *__x < *__y;
}


BOOL __usercall stlp_std::less<vostok::physics::base_physics_object *>::operator()@<eax>(
        vostok::physics::base_physics_object *const *__x@<eax>,
        vostok::physics::base_physics_object *const *__y@<edx>,
        stlp_std::less<vostok::physics::base_physics_object *> *this)
{
  return *__x < *__y;
}
