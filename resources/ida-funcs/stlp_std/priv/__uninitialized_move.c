vostok::ui::typed_handlers *__usercall stlp_std::priv::__uninitialized_move<vostok::ui::typed_handlers *,vostok::ui::typed_handlers *,stlp_std::__false_type>@<eax>(
        vostok::ui::typed_handlers *__last@<eax>,
        vostok::ui::typed_handlers *__result@<ecx>,
        vostok::ui::typed_handlers *__first)
{
  vostok::ui::typed_handlers *v3; // esi
  int v4; // ebx
  int v5; // eax
  char *v6; // eax
  int v8; // [esp+10h] [ebp+8h]

  v3 = __result;
  v4 = __last - __first;
  if ( v4 > 0 )
  {
    v5 = (char *)__first - (char *)__result;
    v8 = (char *)__first - (char *)__result;
    do
    {
      if ( v3 )
      {
        v6 = (char *)v3 + v5;
        v3->type = *(_DWORD *)v6;
        vostok::fixed_vector<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,16>::fixed_vector<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,16>(
          &v3->list,
          (const vostok::fixed_vector<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>,16> *)(v6 + 4));
        v5 = v8;
      }
      ++v3;
      --v4;
    }
    while ( v4 > 0 );
  }
  return v3;
}
