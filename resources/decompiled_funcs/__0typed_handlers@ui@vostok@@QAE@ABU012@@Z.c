void __thiscall vostok::ui::typed_handlers::typed_handlers(
        vostok::ui::typed_handlers *this,
        const vostok::ui::typed_handlers *__that,
        const vostok::ui::typed_handlers *__thata)
{
  const vostok::ui::typed_handlers *v3; // ebx
  unsigned int v4; // edi
  const stlp_std::random_access_iterator_tag *v5; // [esp+0h] [ebp-10h]
  int *v6; // [esp+4h] [ebp-Ch]

  v3 = __thata;
  __that->type = __thata->type;
  v4 = v3->list._M_impl._M_finish - v3->list._M_impl._M_start;
  __thata = (const vostok::ui::typed_handlers *)v3->list._M_impl._M_end_of_storage.m_allocator;
  stlp_std::priv::_Vector_base<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>>>::_Vector_base<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>>>(
    &__that->list._M_impl,
    v4,
    (const vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> > *)&__thata);
  __that->list._M_impl._M_finish = stlp_std::priv::__ucopy<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)> *,fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)> *,int>(
                                     v3->list._M_impl._M_start,
                                     v3->list._M_impl._M_finish,
                                     __that->list._M_impl._M_start,
                                     v5,
                                     v6);
}
