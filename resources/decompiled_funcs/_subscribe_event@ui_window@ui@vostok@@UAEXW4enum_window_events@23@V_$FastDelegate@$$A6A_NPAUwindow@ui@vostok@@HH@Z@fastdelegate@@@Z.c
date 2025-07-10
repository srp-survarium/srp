void __thiscall vostok::ui::ui_window::subscribe_event(
        vostok::ui::ui_window *this,
        vostok::ui::enum_window_events ev,
        fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> handler)
{
  vostok::ui::typed_handlers *M_finish; // esi
  vostok::ui::typed_handlers *v5; // eax
  stlp_std::priv::_Impl_vector<vostok::ui::typed_handlers,vostok::vectora_allocator<vostok::ui::typed_handlers> > *v6; // ecx
  vostok::ui::typed_handlers *v7; // eax
  vostok::ui::typed_handlers *v8; // esi
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *v9; // eax
  vostok::vectora<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> > *p_list; // esi
  vostok::vectora<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> > *v11; // esi
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *v12; // eax
  const stlp_std::__false_type *v13; // [esp+0h] [ebp-24h]
  unsigned int v14; // [esp+4h] [ebp-20h]
  bool v15; // [esp+8h] [ebp-1Ch]
  vostok::ui::typed_handlers __x; // [esp+10h] [ebp-14h] BYREF

  M_finish = this->m_event_manager._M_impl._M_finish;
  v5 = stlp_std::priv::__find<vostok::ui::typed_handlers *,enum vostok::ui::enum_window_events>(
         this->m_event_manager._M_impl._M_start,
         M_finish,
         &ev);
  if ( v5 == M_finish )
  {
    __x.list._M_impl._M_end_of_storage.m_allocator = this->m_allocator;
    v7 = this->m_event_manager._M_impl._M_finish;
    __x.list._M_impl._M_start = 0;
    __x.list._M_impl._M_finish = 0;
    __x.list._M_impl._M_end_of_storage._M_data = 0;
    if ( v7 == this->m_event_manager._M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::ui::typed_handlers,vostok::vectora_allocator<vostok::ui::typed_handlers>>::_M_insert_overflow_aux(
        v6,
        (stlp_std::reverse_iterator<vostok::ui::typed_handlers *> *)&this->m_event_manager,
        v7,
        &__x,
        v13,
        v14,
        v15);
    }
    else
    {
      if ( v7 )
        vostok::ui::typed_handlers::typed_handlers(&__x, v7, &__x);
      ++this->m_event_manager._M_impl._M_finish;
    }
    if ( __x.list._M_impl._M_start )
      __x.list._M_impl._M_end_of_storage.m_allocator->call_free(
        __x.list._M_impl._M_end_of_storage.m_allocator,
        __x.list._M_impl._M_start);
    this->m_event_manager._M_impl._M_finish[-1].type = ev;
    v8 = this->m_event_manager._M_impl._M_finish;
    v9 = v8[-1].list._M_impl._M_finish;
    p_list = &v8[-1].list;
    if ( v9 == p_list->_M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>>>::_M_insert_overflow_aux(
        (stlp_std::priv::_Impl_vector<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>,vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> > > *)&handler,
        &p_list->_M_impl._M_start,
        v9,
        &handler,
        v13,
        v14,
        v15);
    }
    else
    {
      if ( v9 )
      {
        v9->m_Closure.m_pthis = 0;
        v9->m_Closure.m_pFunction = 0;
        *v9 = handler;
      }
      ++p_list->_M_impl._M_finish;
    }
  }
  else
  {
    v11 = &v5->list;
    v12 = v5->list._M_impl._M_finish;
    if ( v12 == v11->_M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>>>::_M_insert_overflow_aux(
        (stlp_std::priv::_Impl_vector<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>,vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> > > *)v6,
        &v11->_M_impl._M_start,
        v12,
        &handler,
        v13,
        v14,
        v15);
    }
    else
    {
      if ( v12 )
      {
        v12->m_Closure.m_pthis = 0;
        v12->m_Closure.m_pFunction = 0;
        *v12 = handler;
      }
      ++v11->_M_impl._M_finish;
    }
  }
}
