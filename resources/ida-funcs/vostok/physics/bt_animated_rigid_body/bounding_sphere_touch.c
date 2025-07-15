int __userpurge vostok::physics::bt_animated_rigid_body::bounding_sphere_touch@<eax>(
        vostok::physics::bt_animated_rigid_body *this@<ecx>,
        int a2@<eax>,
        void *initiator)
{
  const std::exception *v4; // eax
  stlp_std::out_of_range v6; // [esp+8h] [ebp-110h] BYREF

  if ( !*(_DWORD *)(a2 + 16) )
  {
    boost::bad_function_call::bad_function_call((boost::bad_function_call *)this, (stlp_std::runtime_error *)&v6);
    boost::throw_exception(v4);
    stlp_std::__Named_exception::~__Named_exception(&v6);
  }
  return (*(int (__cdecl **)(int, void *))((*(_DWORD *)(a2 + 16) & 0xFFFFFFFE) + 4))(a2 + 24, initiator);
}
