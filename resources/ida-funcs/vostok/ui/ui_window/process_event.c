char __userpurge vostok::ui::ui_window::process_event@<al>(
        vostok::ui::ui_window *ev@<eax>,
        vostok::ui::ui_window *this,
        int p1,
        int p2)
{
  vostok::ui::ui_window *v4; // ebx
  vostok::ui::typed_handlers *M_finish; // esi
  vostok::ui::typed_handlers *v6; // eax
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *m_begin; // esi
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *m_end; // edi
  vostok::fixed_vector<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>,16> v10; // [esp+Ch] [ebp-8Ch] BYREF

  v4 = this;
  M_finish = this->m_event_manager._M_impl._M_finish;
  this = ev;
  v6 = stlp_std::find<vostok::ui::typed_handlers *,enum vostok::ui::enum_window_events>(
         v4->m_event_manager._M_impl._M_start,
         (const vostok::ui::enum_window_events *)&this,
         M_finish);
  if ( v6 != M_finish )
  {
    vostok::fixed_vector<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,16>::fixed_vector<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,16>(
      &v10,
      &v6->list);
    m_begin = v10.m_begin;
    m_end = v10.m_end;
    while ( m_begin != m_end )
    {
      if ( ((unsigned __int8 (__thiscall *)(fastdelegate::detail::GenericClass *, vostok::ui::ui_window *, int, int))m_begin->m_Closure.m_pFunction)(
             m_begin->m_Closure.m_pthis,
             v4,
             p1,
             p2) )
      {
        return 1;
      }
      ++m_begin;
    }
  }
  return 0;
}
