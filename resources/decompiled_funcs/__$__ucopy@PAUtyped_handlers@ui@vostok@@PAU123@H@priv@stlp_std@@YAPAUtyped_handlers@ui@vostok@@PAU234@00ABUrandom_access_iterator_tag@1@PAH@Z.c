vostok::ui::typed_handlers *__usercall stlp_std::priv::__ucopy<vostok::ui::typed_handlers *,vostok::ui::typed_handlers *,int>@<eax>(
        vostok::ui::typed_handlers *__last@<eax>,
        vostok::ui::typed_handlers *__result@<ecx>,
        vostok::ui::typed_handlers *__first)
{
  vostok::ui::typed_handlers *v3; // edi
  int v4; // ebp
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> **p_M_finish; // ebx
  stlp_std::priv::_STLP_alloc_proxy<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *,fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>,vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> > > *p_M_end_of_storage; // esi
  vostok::memory::base_allocator *v7; // eax
  int v8; // edi
  int *v9; // eax
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *v10; // eax
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *v11; // eax
  vostok::ui::typed_handlers *__cur; // [esp+8h] [ebp-Ch]
  int v14; // [esp+Ch] [ebp-8h] BYREF
  int v15; // [esp+10h] [ebp-4h] BYREF

  v3 = __first;
  v4 = __last - __first;
  __cur = __result;
  if ( v4 > 0 )
  {
    p_M_finish = &__first->list._M_impl._M_finish;
    p_M_end_of_storage = &__result->list._M_impl._M_end_of_storage;
    do
    {
      if ( __result )
      {
        __result->type = v3->type;
        v7 = (vostok::memory::base_allocator *)p_M_finish[1];
        v8 = *p_M_finish - *(p_M_finish - 1);
        p_M_end_of_storage[-1].m_allocator = 0;
        p_M_end_of_storage[-1]._M_data = 0;
        p_M_end_of_storage->m_allocator = v7;
        p_M_end_of_storage->_M_data = 0;
        v15 = v8;
        v14 = 1;
        v9 = &v14;
        if ( v8 )
          v9 = &v15;
        v10 = (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *)((int (__stdcall *)(_DWORD, int))p_M_end_of_storage->m_allocator->call_realloc)(
                                                                                          0,
                                                                                          8 * *v9);
        p_M_end_of_storage[-1].m_allocator = (vostok::memory::base_allocator *)v10;
        p_M_end_of_storage[-1]._M_data = v10;
        p_M_end_of_storage->_M_data = &v10[v8];
        v11 = stlp_std::priv::__ucopy<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)> *,fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)> *,int>(
                *p_M_finish,
                *(p_M_finish - 1),
                v10);
        __result = __cur;
        v3 = __first;
        p_M_end_of_storage[-1]._M_data = v11;
      }
      ++v3;
      ++__result;
      --v4;
      p_M_finish += 5;
      p_M_end_of_storage = (stlp_std::priv::_STLP_alloc_proxy<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *,fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>,vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> > > *)((char *)p_M_end_of_storage + 20);
      __first = v3;
      __cur = __result;
    }
    while ( v4 > 0 );
  }
  return __result;
}
