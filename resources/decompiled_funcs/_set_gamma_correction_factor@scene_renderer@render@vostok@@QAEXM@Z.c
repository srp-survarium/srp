void __thiscall vostok::render::scene_renderer::set_gamma_correction_factor(
        vostok::render::scene_renderer *this,
        vostok::render::scene_renderer *value,
        boost::function<void __cdecl(void)> *valuea)
{
  float v3; // edi
  __int32 v4; // ebx
  int v5; // eax
  bool v6; // zf
  char v7; // bl
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,float>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<float> > > v10; // [esp-Ch] [ebp-6Ch]
  int v11; // [esp+0h] [ebp-60h]
  char v12; // [esp+10h] [ebp-50h]
  boost::function<void __cdecl(void)> *v13[2]; // [esp+14h] [ebp-4Ch]
  boost::function4<void,unsigned int,float,float,char const *> v14; // [esp+20h] [ebp-40h] BYREF
  boost::function0<void> f; // [esp+40h] [ebp-20h] BYREF

  v3 = *(float *)&value;
  v12 = 0;
  v4 = (__int32)value->m_allocator->call_malloc(value->m_allocator, 152u);
  if ( v4 )
  {
    v13[1] = (boost::function<void __cdecl(void)> *)value->m_render_engine_world;
    v13[0] = (boost::function<void __cdecl(void)> *)vostok::render::engine::world::set_gamma_correction_factor;
    *(_QWORD *)&v10.f_.f_ = *(_QWORD *)v13;
    LODWORD(v10.l_.a2_.t_) = valuea;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(valuea, (int)&f, 0, v10, v11);
    v14.vtable = 0;
    *(_BYTE *)(v4 + 12) = 0;
    *(_BYTE *)(v4 + 13) = 1;
    *(_DWORD *)(v4 + 80) = 0;
    *(_DWORD *)v4 = &vostok::render::functor_command::`vftable';
    v12 = 3;
    *(_DWORD *)(v4 + 88) = 0;
    boost::function0<void>::assign_to_own((boost::function0<void> *)(v4 + 88), &f);
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(&v14, v4 + 120);
    v3 = *(float *)&value;
  }
  else
  {
    v4 = 0;
  }
  v5 = *(_DWORD *)(LODWORD(v3) + 4);
  v6 = *(_DWORD *)(*(_DWORD *)(v5 + 64) + 4) == 0;
  *(_DWORD *)(v4 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)(*(_DWORD *)v5 + 4), v4);
  *(_DWORD *)v5 = v4;
  if ( v6 )
    SetEvent(*(HANDLE *)(v5 + 144));
  v7 = v12;
  if ( (v12 & 2) != 0 )
  {
    v7 = v12 & 0xFD;
    if ( v14.vtable )
    {
      if ( ((int)v14.vtable & 1) == 0 )
      {
        v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v14.vtable & 0xFFFFFFFE);
        if ( v8 )
          v8(&v14.functor, &v14.functor, 2);
      }
      v14.vtable = 0;
    }
  }
  if ( (v7 & 1) != 0 && f.vtable && ((int)f.vtable & 1) == 0 )
  {
    v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
    if ( v9 )
      v9(&f.functor, &f.functor, 2);
  }
}
