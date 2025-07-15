void __usercall stlp_std::priv::__unguarded_linear_insert<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        survarium::anomaly_state **__last@<eax>,
        survarium::anomaly_state *__val)
{
  survarium::anomaly_state **v2; // edi
  survarium::anomaly_state **i; // esi

  v2 = __last;
  for ( i = __last - 1; (unsigned __int8)survarium::state_prio(__val, *i); --i )
  {
    *v2 = *i;
    v2 = i;
  }
  *v2 = __val;
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        const char **__last,
        const char *__val)
{
  const char **v2; // ebx
  const char **i; // edi

  v2 = __last;
  for ( i = __last - 1; strcmp(__val, *i) == -1; --i )
  {
    *v2 = *i;
    v2 = i;
  }
  *v2 = __val;
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
        const char **__last,
        const char *__val)
{
  const char **v2; // ebx
  const char **i; // esi
  const char *v4; // edi
  vostok::render::shader_macros_dort_predicate *v5; // [esp+0h] [ebp-Ch]

  v2 = __last;
  for ( i = __last - 1; ; --i )
  {
    v4 = *i;
    if ( !vostok::render::shader_macros_dort_predicate::operator()(__val, *i, v5) )
      break;
    *v2 = v4;
    v2 = i;
  }
  *v2 = __val;
}


void __cdecl stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
        const char **__last,
        char *__val,
        vostok::tips_sorting_predicate __comp)
{
  vostok::tips_sorting_predicate *v3; // ecx
  const char **v4; // ebx
  char **i; // esi

  v4 = __last;
  for ( i = (char **)(__last - 1);
        vostok::tips_sorting_predicate::operator()(v3, (unsigned __int8 **)&__comp, __val, *i);
        --i )
  {
    *v4 = *i;
    v4 = (const char **)i;
  }
  *v4 = __val;
}


void __usercall stlp_std::priv::__unguarded_linear_insert<survarium::relocate_item_descr *,survarium::relocate_item_descr,survarium::ammo_slots_sort>(
        survarium::relocate_item_descr *__last@<eax>,
        survarium::relocate_item_descr __val,
        survarium::ammo_slots_sort __comp)
{
  survarium::relocate_item_descr *v3; // edi
  survarium::relocate_item_descr *i; // ebx
  _DWORD *p_item_dict_id; // edi
  _DWORD *v6; // edi

  v3 = __last;
  for ( i = __last - 1; survarium::ammo_slots_sort::operator()(&__comp, &__val, i); --i )
  {
    v3->item_id = i->item_id;
    p_item_dict_id = &v3->item_dict_id;
    *p_item_dict_id++ = *(_DWORD *)&i->item_dict_id;
    *p_item_dict_id = i->amount;
    p_item_dict_id[1] = i->amount_in_inventory;
    v3 = i;
  }
  v3->item_id = __val.item_id;
  v6 = &v3->item_dict_id;
  *v6++ = *(_DWORD *)&__val.item_dict_id;
  *v6 = __val.amount;
  v6[1] = __val.amount_in_inventory;
}


void __usercall stlp_std::priv::__unguarded_linear_insert<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__last@<eax>,
        vostok::math::curve_point<float> __val)
{
  vostok::math::curve_point<float> *v2; // edi
  vostok::math::curve_point<float> *i; // eax

  v2 = __last;
  for ( i = __last - 1; i->time > __val.time; --i )
  {
    qmemcpy(v2, i, sizeof(vostok::math::curve_point<float>));
    v2 = i;
  }
  qmemcpy(v2, &__val, sizeof(vostok::math::curve_point<float>));
}


void __usercall stlp_std::priv::__unguarded_linear_insert<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__last@<eax>,
        vostok::render::shader_constant __val)
{
  vostok::render::shader_constant *i; // esi

  for ( i = __last - 1; __val.m_host->m_name.m_pointer.m_object < i->m_host->m_name.m_pointer.m_object; --i )
  {
    vostok::render::shader_constant::operator=(i, __last);
    __last = i;
  }
  vostok::render::shader_constant::operator=(&__val, __last);
}
