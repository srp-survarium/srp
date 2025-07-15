void __thiscall vostok::ui::ui_window::subscribe_event(
        vostok::ui::ui_window *this,
        vostok::ui::enum_window_events ev,
        fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> handler)
{
  stlp_std::reverse_iterator<vostok::ui::typed_handlers *> *p_m_event_manager; // esi
  vostok::ui::typed_handlers *v5; // eax
  vostok::ui::typed_handlers *current; // eax
  vostok::buffer_vector<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> > *p_list; // esi
  const stlp_std::__false_type *v8; // [esp+0h] [ebp-A0h]
  unsigned int v9; // [esp+4h] [ebp-9Ch]
  bool v10; // [esp+8h] [ebp-98h]
  vostok::ui::typed_handlers __x; // [esp+10h] [ebp-90h] BYREF
  char vars0; // [esp+A0h] [ebp+0h] BYREF

  p_m_event_manager = (stlp_std::reverse_iterator<vostok::ui::typed_handlers *> *)&this->m_event_manager;
  v5 = stlp_std::find<vostok::ui::typed_handlers *,enum vostok::ui::enum_window_events>(
         this->m_event_manager._M_impl._M_start,
         &ev,
         this->m_event_manager._M_impl._M_finish);
  if ( v5 == this->m_event_manager._M_impl._M_finish )
  {
    __x.list.m_begin = (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *)__x.list.m_buffer;
    __x.list.m_end = (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *)__x.list.m_buffer;
    __x.list.m_max_end = (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *)&vars0;
    current = p_m_event_manager[1].current;
    if ( current == p_m_event_manager[3].current )
    {
      stlp_std::priv::_Impl_vector<vostok::ui::typed_handlers,vostok::vectora_allocator<vostok::ui::typed_handlers>>::_M_insert_overflow_aux(
        (stlp_std::priv::_Impl_vector<vostok::ui::typed_handlers,vostok::vectora_allocator<vostok::ui::typed_handlers> > *)&__x,
        p_m_event_manager,
        current,
        &__x,
        v8,
        v9,
        v10);
    }
    else
    {
      if ( current )
      {
        current->type = __x.type;
        vostok::fixed_vector<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,16>::fixed_vector<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,16>(
          &current->list,
          &__x.list);
      }
      ++p_m_event_manager[1].current;
    }
    this->m_event_manager._M_impl._M_finish[-1].type = ev;
    p_list = &this->m_event_manager._M_impl._M_finish[-1].list;
  }
  else
  {
    p_list = &v5->list;
  }
  vostok::buffer_vector<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>>::push_back(
    p_list,
    &handler);
}
