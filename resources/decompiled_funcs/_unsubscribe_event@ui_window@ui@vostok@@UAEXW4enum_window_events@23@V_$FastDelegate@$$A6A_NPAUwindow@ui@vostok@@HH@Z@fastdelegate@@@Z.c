void __thiscall vostok::ui::ui_window::unsubscribe_event(
        vostok::ui::ui_window *this,
        vostok::ui::enum_window_events ev,
        fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> handler)
{
  vostok::ui::typed_handlers *M_finish; // esi
  vostok::ui::typed_handlers *v4; // eax
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *v5; // edi
  stlp_std::priv::_Impl_vector<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>,vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> > > *p_M_impl; // ebx
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *v7; // eax

  M_finish = this->m_event_manager._M_impl._M_finish;
  v4 = stlp_std::priv::__find<vostok::ui::typed_handlers *,enum vostok::ui::enum_window_events>(
         this->m_event_manager._M_impl._M_start,
         M_finish,
         &ev);
  if ( v4 != M_finish )
  {
    v5 = v4->list._M_impl._M_finish;
    p_M_impl = &v4->list._M_impl;
    v7 = stlp_std::priv::__find<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)> *,fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>>(
           v4->list._M_impl._M_start,
           v5,
           &handler);
    if ( v7 != v5 )
      stlp_std::priv::_Impl_vector<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>>>::_M_erase(
        p_M_impl,
        v7);
  }
}
