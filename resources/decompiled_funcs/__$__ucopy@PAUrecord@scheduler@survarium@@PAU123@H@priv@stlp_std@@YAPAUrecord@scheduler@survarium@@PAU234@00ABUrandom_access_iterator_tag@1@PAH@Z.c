survarium::scheduler::record *__usercall stlp_std::priv::__ucopy<survarium::scheduler::record *,survarium::scheduler::record *,int>@<eax>(
        survarium::scheduler::record *__first@<ecx>,
        survarium::scheduler::record *__last@<eax>,
        survarium::scheduler::record *__result)
{
  survarium::scheduler::record *v4; // edi
  int i; // ebp
  boost::detail::function::vtable_base *vtable; // eax

  v4 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
    {
      __result->m_id = v4->m_id;
      __result->m_callback.vtable = 0;
      vtable = v4->m_callback.vtable;
      if ( vtable )
      {
        __result->m_callback.vtable = vtable;
        if ( ((unsigned __int8)vtable & 1) != 0 )
        {
          *(_QWORD *)&__result->m_callback.functor.obj_ptr = *(_QWORD *)&v4->m_callback.functor.obj_ptr;
          *((_QWORD *)&__result->m_callback.functor.data + 1) = *((_QWORD *)&v4->m_callback.functor.data + 1);
          *((_QWORD *)&__result->m_callback.functor.data + 2) = *((_QWORD *)&v4->m_callback.functor.data + 2);
        }
        else
        {
          (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, _DWORD))((unsigned int)vtable & 0xFFFFFFFE))(
            &v4->m_callback.functor,
            &__result->m_callback.functor,
            0);
        }
      }
      *(_QWORD *)&__result->survarium::scheduler::scheduler_record = v4->survarium::scheduler::scheduler_record;
      __result->m_last_update_time = v4->m_last_update_time;
    }
    --i;
    ++v4;
  }
  return __result;
}
