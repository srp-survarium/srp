void __usercall boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        boost::function<void __cdecl(void)> *this@<ecx>,
        void (__cdecl *f)()@<eax>)
{
  int v2; // [esp+0h] [ebp-4h]

  boost::function0<void>::function0<void>(this, f, v2);
}


void __thiscall boost::function<void __cdecl (unsigned int,float,float,char const *)>::function<void __cdecl (unsigned int,float,float,char const *)>(
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *this)
{
  const boost::function4<void,unsigned int,float,float,char const *> *v1; // [esp+0h] [ebp-4h]

  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(this, v1);
}


void __thiscall boost::function<void __cdecl (vostok::memory::writer *,vostok::memory::writer *)>::function<void __cdecl (vostok::memory::writer *,vostok::memory::writer *)>(
        boost::_bi::value<boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> > *this,
        const boost::_bi::value<boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> > *__that)
{
  this->t_.vtable = 0;
  boost::function1<void,vostok::sound::create_sound_propagator_params const &>::assign_to_own(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (const boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)__that);
}


void __thiscall boost::function<void __cdecl (vostok::vfs::mount_result)>::function<void __cdecl (vostok::vfs::mount_result)>(
        boost::function<void __cdecl(vostok::vfs::mount_result)> *this,
        boost::function<void __cdecl(vostok::vfs::mount_result)>::clear_type *__formal)
{
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>((boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this);
}


void __thiscall boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        boost::function<void __cdecl(void)> *this,
        const boost::function<void __cdecl(void)> *f)
{
  this->vtable = 0;
  boost::function0<void>::assign_to_own(this, f);
}


void __thiscall boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        boost::function<void __cdecl(void)> *this,
        boost::function<void __cdecl(void)>::clear_type *__formal)
{
  this->vtable = 0;
}


void __usercall boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  *a2 = 0;
}
