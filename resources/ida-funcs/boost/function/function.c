void __userpurge boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
        boost::function<void __cdecl(char const *)> *this@<ecx>,
        _DWORD *a2@<esi>,
        void (__cdecl *f)(const char *),
        int __formal)
{
  *a2 = 0;
  if ( `boost::function1<void,char const *>::assign_to<void (__cdecl *)(char const *)>'::`2'::stored_vtable )
    `boost::function1<void,char const *>::assign_to<void (__cdecl *)(char const *)>'::`2'::stored_vtable(
      a2 + 2,
      a2 + 2,
      2);
  if ( f )
  {
    a2[2] = f;
    *a2 = (char *)&`boost::function1<void,char const *>::assign_to<void (__cdecl *)(char const *)>'::`2'::stored_vtable
        + 1;
  }
  else
  {
    *a2 = 0;
  }
}


void __userpurge boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        boost::function<void __cdecl(void)> *this@<ecx>,
        _DWORD *a2@<esi>,
        void (__cdecl *f)(),
        int __formal)
{
  *a2 = 0;
  if ( `boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable )
    `boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable(a2 + 2, a2 + 2, 2);
  if ( f )
  {
    a2[2] = f;
    *a2 = (char *)&`boost::function0<void>::assign_to<void (__cdecl *)(void)>'::`2'::stored_vtable + 1;
  }
  else
  {
    *a2 = 0;
  }
}


void __userpurge boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
        boost::function<bool __cdecl(void)> *this@<ecx>,
        _DWORD *a2@<esi>,
        bool (__cdecl *f)(),
        int __formal)
{
  *a2 = 0;
  if ( `boost::function0<bool>::assign_to<bool (__cdecl *)(void)>'::`2'::stored_vtable )
    `boost::function0<bool>::assign_to<bool (__cdecl *)(void)>'::`2'::stored_vtable(a2 + 2, a2 + 2, 2);
  if ( f )
  {
    a2[2] = f;
    *a2 = (char *)&`boost::function0<bool>::assign_to<bool (__cdecl *)(void)>'::`2'::stored_vtable + 1;
  }
  else
  {
    *a2 = 0;
  }
}


void __userpurge boost::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>(
        boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> *this@<ecx>,
        _DWORD *a2@<esi>,
        survarium::zero_time_calculator f,
        int __formal)
{
  *a2 = 0;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)this) )
    *a2 = 0;
  else
    *a2 = (char *)&`boost::function3<survarium::game_effect_time,survarium::game_effect_node const &,unsigned int,unsigned int>::assign_to<survarium::zero_time_calculator>'::`2'::stored_vtable
        + 1;
}


void __userpurge boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
        boost::function<void __cdecl(char const *)> *this@<ecx>,
        boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *a2@<esi>,
        boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> f,
        int __formal)
{
  a2->f_ = 0;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)this) )
  {
    a2->f_ = 0;
  }
  else
  {
    if ( a2 != (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)-8 )
      a2[1] = f;
    a2->f_ = (void (__cdecl *)())((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>'::`2'::stored_vtable
                                + 1);
  }
}


void __userpurge boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
        boost::function<bool __cdecl(void)> *this@<ecx>,
        boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> *a2@<esi>,
        boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> f,
        int __formal)
{
  a2->f_ = 0;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)this) )
  {
    a2->f_ = 0;
  }
  else
  {
    if ( a2 != (boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> *)-8 )
      a2[1] = f;
    a2->f_ = (bool (__cdecl *)())((char *)&`boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,bool (__cdecl *)(void),boost::_bi::list0>>'::`2'::stored_vtable
                                + 1);
  }
}
