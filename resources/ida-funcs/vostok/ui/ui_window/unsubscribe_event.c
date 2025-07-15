void __thiscall vostok::ui::ui_window::unsubscribe_event(
        vostok::ui::ui_window *this,
        fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *ev,
        fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> handler)
{
  vostok::ui::typed_handlers *M_finish; // esi
  vostok::ui::typed_handlers *v4; // eax
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *m_end; // edi
  vostok::buffer_vector<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> > *p_list; // esi

  M_finish = this->m_event_manager._M_impl._M_finish;
  v4 = stlp_std::find<vostok::ui::typed_handlers *,enum vostok::ui::enum_window_events>(
         this->m_event_manager._M_impl._M_start,
         (const vostok::ui::enum_window_events *)&ev,
         M_finish);
  if ( v4 != M_finish )
  {
    m_end = v4->list.m_end;
    p_list = &v4->list;
    ev = stlp_std::priv::__find<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)> *,fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>>(
           v4->list.m_begin,
           &handler,
           m_end);
    if ( ev != m_end )
      vostok::buffer_vector<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>>::erase(p_list, &ev);
  }
}
