void __usercall stlp_std::priv::__final_insertion_sort<float *,stlp_std::less<float>>(
        float *__first@<eax>,
        float *__last)
{
  float *i; // eax
  float v5; // xmm1_4
  float *v6; // ecx
  float *j; // edx

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    stlp_std::priv::__insertion_sort<float *,float,stlp_std::less<float>>(__first, __last);
  }
  else
  {
    stlp_std::priv::__insertion_sort<float *,float,stlp_std::less<float>>(__first, __first + 16);
    for ( i = __first + 16; i != __last; ++i )
    {
      v5 = *i;
      v6 = i;
      for ( j = i - 1; *j > v5; --j )
      {
        *v6 = *j;
        v6 = j;
      }
      *v6 = v5;
    }
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<survarium::victory_item_spawner * *,survarium::priority_less>(
        survarium::victory_item_spawner **__first@<eax>,
        survarium::victory_item_spawner **__last)
{
  survarium::victory_item_spawner **v2; // esi
  survarium::victory_item_spawner *v3; // eax
  survarium::victory_item_spawner **v4; // edi
  survarium::victory_item_spawner **i; // ecx

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    stlp_std::priv::__insertion_sort<survarium::victory_item_spawner * *,survarium::victory_item_spawner *,survarium::priority_less>(
      __first,
      __last);
  }
  else
  {
    v2 = __first + 16;
    stlp_std::priv::__insertion_sort<survarium::victory_item_spawner * *,survarium::victory_item_spawner *,survarium::priority_less>(
      __first,
      __first + 16);
    for ( ; v2 != __last; *v4 = v3 )
    {
      v3 = *v2;
      v4 = v2;
      for ( i = v2 - 1; v3->priority > (*i)->priority; --i )
      {
        *v4 = *i;
        v4 = i;
      }
      ++v2;
    }
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<vostok::command_line::key * *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key **__first@<eax>,
        vostok::command_line::key **__last@<edi>,
        vostok::command_line::key *__comp)
{
  vostok::command_line::key **v3; // esi
  vostok::command_line::key *v4; // [esp+8h] [ebp-4h] BYREF

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    LOBYTE(v4) = (_BYTE)__comp;
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        (vostok::command_line::key_compare_predicate *)__last,
        __first,
        __last,
        &v4);
  }
  else
  {
    v3 = __first + 16;
    stlp_std::priv::__insertion_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
      (vostok::command_line::key_compare_predicate *)__last,
      __first,
      __first + 16,
      &__comp);
    while ( v3 != __last )
    {
      stlp_std::priv::__unguarded_linear_insert<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        *v3,
        v3);
      ++v3;
    }
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<vostok::animation::skeleton_bone * *,bone_crc_predicate>(
        vostok::animation::skeleton_bone **__first@<eax>,
        vostok::animation::skeleton_bone **__last,
        bone_crc_predicate __comp)
{
  bone_crc_predicate *v3; // ebx
  vostok::animation::skeleton_bone **v4; // esi

  v3 = (bone_crc_predicate *)__last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    LOBYTE(__last) = __comp;
    if ( __first != (vostok::animation::skeleton_bone **)v3 )
      stlp_std::priv::__insertion_sort<vostok::animation::skeleton_bone * *,vostok::animation::skeleton_bone *,bone_crc_predicate>(
        __first,
        v3,
        (vostok::animation::skeleton_bone **)v3,
        (bone_crc_predicate *)&__last);
  }
  else
  {
    v4 = __first + 16;
    stlp_std::priv::__insertion_sort<vostok::animation::skeleton_bone * *,vostok::animation::skeleton_bone *,bone_crc_predicate>(
      __first,
      (bone_crc_predicate *)__last,
      __first + 16,
      &__comp);
    LOBYTE(__last) = __comp;
    while ( v4 != (vostok::animation::skeleton_bone **)v3 )
    {
      stlp_std::priv::__unguarded_linear_insert<vostok::animation::skeleton_bone * *,vostok::animation::skeleton_bone *,bone_crc_predicate>(
        v4,
        *v4);
      ++v4;
    }
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<char const * *,bool (__cdecl *)(char const *,char const *)>(
        const char **__first@<eax>,
        const char **__last)
{
  const char **v2; // esi

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        __first,
        (bool (__cdecl *)(const char *, const char *))__last,
        __last);
  }
  else
  {
    v2 = __first + 16;
    stlp_std::priv::__insertion_sort<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
      __first,
      (bool (__cdecl *)(const char *, const char *))__last,
      __first + 16);
    while ( v2 != __last )
    {
      stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        v2,
        *v2);
      ++v2;
    }
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<char const * *,vostok::render::shader_macros_dort_predicate>(
        const char **__first@<eax>,
        vostok::render::shader_macros_dort_predicate *__last,
        vostok::render::shader_macros_dort_predicate __comp)
{
  vostok::render::shader_macros_dort_predicate *v3; // ebx
  const char **v4; // esi

  v3 = __last;
  if ( (int)((__last - (vostok::render::shader_macros_dort_predicate *)__first) & 0xFFFFFFFC) <= 64 )
  {
    LOBYTE(__last) = __comp;
    if ( __first != (const char **)v3 )
      stlp_std::priv::__insertion_sort<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
        __first,
        v3,
        (const char **)v3,
        (vostok::render::shader_macros_dort_predicate *)&__last);
  }
  else
  {
    v4 = __first + 16;
    stlp_std::priv::__insertion_sort<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
      __first,
      __last,
      __first + 16,
      &__comp);
    LOBYTE(__last) = __comp;
    while ( v4 != (const char **)v3 )
    {
      stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
        v4,
        *v4);
      ++v4;
    }
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<survarium::relocate_item_descr *,survarium::ammo_slots_sort>(
        survarium::relocate_item_descr *__first@<eax>,
        survarium::relocate_item_descr *__last,
        survarium::relocate_item_descr __comp)
{
  survarium::relocate_item_descr *v3; // ebx
  survarium::ammo_slots_sort v4; // [esp-Ch] [ebp-24h]
  survarium::relocate_item_descr varC; // [esp+Ch] [ebp-Ch] BYREF

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFF0) <= 256 )
  {
    varC.item_id = __comp.item_id;
    *(_DWORD *)&varC.item_dict_id = *(_DWORD *)&__comp.item_dict_id;
    varC.amount = __comp.amount;
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<survarium::relocate_item_descr *,survarium::relocate_item_descr,survarium::ammo_slots_sort>(
        __first,
        __last,
        &varC);
  }
  else
  {
    v3 = __first + 16;
    stlp_std::priv::__insertion_sort<survarium::relocate_item_descr *,survarium::relocate_item_descr,survarium::ammo_slots_sort>(
      __first,
      __first + 16,
      &__comp);
    varC.item_id = __comp.item_id;
    *(_DWORD *)&varC.item_dict_id = *(_DWORD *)&__comp.item_dict_id;
    varC.amount = __comp.amount;
    while ( v3 != __last )
    {
      v4.m_dict = (const survarium::items_dictionary *)varC.item_id;
      *(_QWORD *)v4.m_weapon_ids = *(_QWORD *)&varC.item_dict_id;
      stlp_std::priv::__unguarded_linear_insert<survarium::relocate_item_descr *,survarium::relocate_item_descr,survarium::ammo_slots_sort>(
        v3,
        *v3,
        v4);
      ++v3;
    }
  }
}


void __cdecl stlp_std::priv::__final_insertion_sort<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__last)
{
  vostok::math::curve_point<float> *v1; // ecx
  vostok::math::curve_point<float> *v2; // ebx
  vostok::math::curve_point<float> v3; // [esp-18h] [ebp-24h] BYREF

  if ( __last - v1 <= 16 )
  {
    if ( v1 != __last )
      stlp_std::priv::__insertion_sort<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        v1,
        __last);
  }
  else
  {
    v2 = v1 + 16;
    stlp_std::priv::__insertion_sort<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      v1,
      v1 + 16);
    for ( ; v2 != __last; ++v2 )
    {
      qmemcpy(&v3, v2, sizeof(v3));
      stlp_std::priv::__unguarded_linear_insert<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        v2,
        v3);
    }
  }
}


void __usercall stlp_std::priv::__final_insertion_sort<vostok::render::shader_constant *,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first@<eax>,
        vostok::render::shader_constant *__last)
{
  vostok::render::shader_constant *v2; // esi
  vostok::render::shader_constant v3; // [esp-18h] [ebp-24h]

  if ( __last - __first <= 16 )
  {
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        __first,
        __last);
  }
  else
  {
    v2 = __first + 16;
    stlp_std::priv::__insertion_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      __first,
      __first + 16);
    while ( v2 != __last )
    {
      v3.m_slot.m_value = v2->m_slot.m_value;
      v3.m_source.m_pointer = v2->m_source.m_pointer;
      v3.m_source.m_size = v2->m_source.m_size;
      v3.m_host = v2->m_host;
      stlp_std::priv::__unguarded_linear_insert<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        v2++,
        v3);
    }
  }
}
