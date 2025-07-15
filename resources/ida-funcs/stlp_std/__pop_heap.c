void __usercall stlp_std::__pop_heap<survarium::relocate_item_descr *,survarium::relocate_item_descr,survarium::ammo_slots_sort,int>(
        survarium::relocate_item_descr *__last@<eax>,
        survarium::relocate_item_descr *__result@<ecx>,
        survarium::relocate_item_descr *__first,
        survarium::relocate_item_descr __val,
        survarium::ammo_slots_sort __comp)
{
  __int128 v5; // [esp-Ch] [ebp-14h]

  *__result = *__first;
  *(survarium::ammo_slots_sort *)&v5 = __comp;
  stlp_std::__adjust_heap<survarium::relocate_item_descr *,int,survarium::relocate_item_descr,survarium::ammo_slots_sort>(
    __first,
    0,
    __last - __first,
    __val,
    v5);
}


void __usercall stlp_std::__pop_heap<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),int>(
        vostok::math::curve_point<float> *__last@<eax>,
        vostok::math::curve_point<float> *__result@<edx>,
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  vostok::math::curve_point<float> v5; // [esp-1Ch] [ebp-24h] BYREF
  bool (__cdecl *v6)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *); // [esp-4h] [ebp-Ch]

  v6 = __comp;
  qmemcpy(__result, __first, sizeof(vostok::math::curve_point<float>));
  qmemcpy(&v5, &__val, sizeof(v5));
  stlp_std::__adjust_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
    __first,
    0,
    __last - __first,
    v5,
    v6);
}


void __usercall stlp_std::__pop_heap<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &),int>(
        vostok::render::shader_constant *__result@<eax>,
        vostok::render::shader_constant *__first,
        vostok::render::shader_constant *__last,
        vostok::render::shader_constant __val,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  vostok::render::shader_constant::operator=(__first, __result);
  stlp_std::__adjust_heap<vostok::render::shader_constant *,int,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
    0,
    __first,
    __last - __first,
    __val,
    __comp);
}
