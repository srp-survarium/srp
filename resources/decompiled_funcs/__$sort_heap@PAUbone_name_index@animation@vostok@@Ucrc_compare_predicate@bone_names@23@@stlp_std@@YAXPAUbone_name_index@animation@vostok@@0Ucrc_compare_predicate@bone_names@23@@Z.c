void __cdecl stlp_std::sort_heap<vostok::animation::bone_name_index *,vostok::animation::bone_names::crc_compare_predicate>(
        vostok::animation::bone_name_index *__first,
        vostok::animation::bone_name_index *__last,
        vostok::animation::bone_names::crc_compare_predicate __comp)
{
  int i; // ebx
  char *v4; // eax
  vostok::animation::bone_name_index v5; // [esp-4Ch] [ebp-A4h] BYREF
  vostok::animation::bone_names::crc_compare_predicate v6; // [esp-4h] [ebp-5Ch]
  _BYTE v7[72]; // [esp+10h] [ebp-48h] BYREF

  for ( i = (char *)__last - (char *)__first;
        i / 72 > 1;
        stlp_std::__adjust_heap<vostok::animation::bone_name_index *,int,vostok::animation::bone_name_index,vostok::animation::bone_names::crc_compare_predicate>(
          __first,
          0,
          i / 72,
          v5,
          v6) )
  {
    v4 = &__first[-1].name[i];
    v6 = __comp;
    qmemcpy(v7, v4, sizeof(v7));
    i -= 72;
    qmemcpy(v4, __first, 0x48u);
    qmemcpy(&v5, v7, sizeof(v5));
  }
}
