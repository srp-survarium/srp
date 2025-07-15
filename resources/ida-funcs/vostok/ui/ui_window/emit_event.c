char __userpurge vostok::ui::ui_window::emit_event@<al>(
        vostok::ui::ui_window *this@<ecx>,
        int a2@<eax>,
        vostok::ui::enum_window_events ev,
        vostok::ui::window *w,
        int p1,
        int p2)
{
  vostok::ui::typed_handlers *v6; // esi
  vostok::ui::typed_handlers *v7; // eax
  vostok::ui::typed_handlers *v8; // ebx
  int v9; // edi
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *M_start; // edi
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *v11; // ebx
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *v12; // esi
  vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> > __a; // [esp+Ch] [ebp-14h] BYREF
  vostok::vectora<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> > l; // [esp+10h] [ebp-10h] BYREF

  v6 = *(vostok::ui::typed_handlers **)(a2 + 32);
  v7 = stlp_std::priv::__find<vostok::ui::typed_handlers *,enum vostok::ui::enum_window_events>(
         *(vostok::ui::typed_handlers **)(a2 + 28),
         v6,
         &ev);
  v8 = v7;
  if ( v7 == v6 )
    return 0;
  v9 = (char *)v7->list._M_impl._M_finish - (char *)v7->list._M_impl._M_start;
  __a.m_allocator = v7->list._M_impl._M_end_of_storage.m_allocator;
  stlp_std::priv::_Vector_base<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>>>::_Vector_base<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>>>(
    &l._M_impl,
    v9 >> 3,
    &__a);
  M_start = l._M_impl._M_start;
  v11 = stlp_std::priv::__ucopy<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)> *,fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)> *,int>(
          v8->list._M_impl._M_finish,
          v8->list._M_impl._M_start,
          l._M_impl._M_start);
  v12 = M_start;
  if ( M_start == v11 )
  {
LABEL_5:
    if ( M_start )
      l._M_impl._M_end_of_storage.m_allocator->call_free(l._M_impl._M_end_of_storage.m_allocator, M_start);
    return 0;
  }
  while ( !((unsigned __int8 (__thiscall *)(fastdelegate::detail::GenericClass *, vostok::ui::window *, int, int))v12->m_Closure.m_pFunction)(
             v12->m_Closure.m_pthis,
             w,
             p1,
             p2) )
  {
    if ( ++v12 == v11 )
      goto LABEL_5;
  }
  if ( M_start )
    l._M_impl._M_end_of_storage.m_allocator->call_free(l._M_impl._M_end_of_storage.m_allocator, M_start);
  return 1;
}
