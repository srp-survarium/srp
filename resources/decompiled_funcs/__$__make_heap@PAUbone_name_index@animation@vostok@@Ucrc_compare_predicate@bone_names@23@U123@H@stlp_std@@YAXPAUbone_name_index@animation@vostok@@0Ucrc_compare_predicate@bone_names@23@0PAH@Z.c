void __usercall stlp_std::__make_heap<vostok::animation::bone_name_index *,vostok::animation::bone_names::crc_compare_predicate,vostok::animation::bone_name_index,int>(
        vostok::animation::bone_name_index *__last@<eax>,
        vostok::animation::bone_name_index *__first,
        vostok::animation::bone_names::crc_compare_predicate *a3)
{
  int v3; // ebp
  int v4; // ebx
  vostok::animation::bone_name_index *i; // esi
  vostok::animation::bone_name_index v6; // [esp-4Ch] [ebp-60h] BYREF
  vostok::animation::bone_names::crc_compare_predicate v7; // [esp-4h] [ebp-18h]
  vostok::animation::bone_name_index *v8; // [esp+10h] [ebp-4h]

  v3 = __last - __first;
  v7 = *a3;
  v4 = (v3 - 2) / 2;
  v8 = &__first[v4];
  qmemcpy(&v6, v8, sizeof(v6));
  stlp_std::__adjust_heap<vostok::animation::bone_name_index *,int,vostok::animation::bone_name_index,vostok::animation::bone_names::crc_compare_predicate>(
    __first,
    v4,
    v3,
    v6,
    v7);
  if ( v4 )
  {
    for ( i = v8; ; i = v8 )
    {
      v7 = *a3;
      --v4;
      v8 = i - 1;
      qmemcpy(&v6, &i[-1], sizeof(v6));
      stlp_std::__adjust_heap<vostok::animation::bone_name_index *,int,vostok::animation::bone_name_index,vostok::animation::bone_names::crc_compare_predicate>(
        __first,
        v4,
        v3,
        v6,
        v7);
      if ( !v4 )
        break;
    }
  }
}
