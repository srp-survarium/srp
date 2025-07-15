void __usercall stlp_std::priv::__partial_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        char *__first@<esi>,
        char *__middle,
        unsigned int *__last,
        unsigned int *__formal)
{
  int v4; // ecx
  int v5; // edi
  unsigned int *i; // edi
  unsigned int v7; // ecx
  int v8; // eax
  unsigned int v9; // ecx
  int v10; // edi
  int __len; // [esp+Ch] [ebp-4h]

  v4 = (__middle - __first) >> 2;
  __len = v4;
  if ( v4 >= 2 )
  {
    v5 = (v4 - 2) / 2;
    stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
      (unsigned int *)__first,
      v5,
      (__middle - __first) >> 2,
      *(_DWORD *)&__first[4 * v5],
      (vostok::render::culling::portal_id_closer_to_point)__formal);
    while ( v5 )
    {
      --v5;
      stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        (unsigned int *)__first,
        v5,
        __len,
        *(_DWORD *)&__first[4 * v5],
        (vostok::render::culling::portal_id_closer_to_point)__formal);
    }
  }
  for ( i = (unsigned int *)__middle; i < __last; ++i )
  {
    v7 = *i;
    if ( *(float *)&__formal[*(_DWORD *)__first] > *(float *)&__formal[*i] )
    {
      *i = *(_DWORD *)__first;
      stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        (unsigned int *)__first,
        0,
        __len,
        v7,
        (vostok::render::culling::portal_id_closer_to_point)__formal);
    }
  }
  if ( __len > 1 )
  {
    v8 = __middle - __first;
    do
    {
      v9 = *(_DWORD *)&__first[v8 - 4];
      v10 = v8 - 4;
      *(_DWORD *)&__first[v8 - 4] = *(_DWORD *)__first;
      stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        (unsigned int *)__first,
        0,
        (v8 - 4) >> 2,
        v9,
        (vostok::render::culling::portal_id_closer_to_point)__formal);
      v8 = v10;
    }
    while ( (int)(v10 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::priv::__partial_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        char *__first@<esi>,
        char *__middle,
        unsigned int *__last)
{
  int v3; // ebx
  int i; // edi
  unsigned int *j; // edi
  unsigned int v6; // ecx
  int v7; // eax
  unsigned int v8; // ecx
  int v9; // edi

  v3 = (__middle - __first) >> 2;
  if ( v3 >= 2 )
  {
    for ( i = (v3 - 2) / 2; ; --i )
    {
      stlp_std::__adjust_heap<survarium::single_game_effect * *,int,survarium::single_game_effect *,stlp_std::less<survarium::single_game_effect *>>(
        (unsigned int *)__first,
        i,
        v3,
        *(_DWORD *)&__first[4 * i]);
      if ( !i )
        break;
    }
  }
  for ( j = (unsigned int *)__middle; j < __last; ++j )
  {
    v6 = *j;
    if ( *j < *(_DWORD *)__first )
    {
      *j = *(_DWORD *)__first;
      stlp_std::__adjust_heap<survarium::single_game_effect * *,int,survarium::single_game_effect *,stlp_std::less<survarium::single_game_effect *>>(
        (unsigned int *)__first,
        0,
        v3,
        v6);
    }
  }
  if ( v3 > 1 )
  {
    v7 = __middle - __first;
    do
    {
      v8 = *(_DWORD *)&__first[v7 - 4];
      v9 = v7 - 4;
      *(_DWORD *)&__first[v7 - 4] = *(_DWORD *)__first;
      stlp_std::__adjust_heap<survarium::single_game_effect * *,int,survarium::single_game_effect *,stlp_std::less<survarium::single_game_effect *>>(
        (unsigned int *)__first,
        0,
        (v7 - 4) >> 2,
        v8);
      v7 = v9;
    }
    while ( (int)(v9 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::priv::__partial_sort<float *,float,stlp_std::less<float>>(
        float *__first@<esi>,
        float *__middle,
        float *__last)
{
  int v3; // ebx
  int i; // edi
  float *j; // edi
  int v6; // eax
  double v7; // st7
  int v8; // edi
  float __val; // [esp+0h] [ebp-14h]
  int v10; // [esp+10h] [ebp-4h]
  float v11; // [esp+1Ch] [ebp+8h]

  v10 = (char *)__middle - (char *)__first;
  v3 = __middle - __first;
  if ( v3 >= 2 )
  {
    for ( i = (v3 - 2) / 2; ; --i )
    {
      stlp_std::__adjust_heap<float *,int,float,stlp_std::less<float>>(__first, i, v3, __first[i]);
      if ( !i )
        break;
    }
  }
  for ( j = __middle; j < __last; ++j )
  {
    v11 = *j;
    if ( *__first > *j )
    {
      *j = *__first;
      stlp_std::__adjust_heap<float *,int,float,stlp_std::less<float>>(__first, 0, v3, v11);
    }
  }
  if ( v3 > 1 )
  {
    v6 = v10;
    do
    {
      v7 = *(float *)((char *)__first + v6 - 4);
      v8 = v6 - 4;
      *(float *)((char *)__first + v6 - 4) = *__first;
      __val = v7;
      stlp_std::__adjust_heap<float *,int,float,stlp_std::less<float>>(__first, 0, (v6 - 4) >> 2, __val);
      v6 = v8;
    }
    while ( (int)(v8 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::priv::__partial_sort<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        survarium::anomaly_state **__first@<eax>,
        survarium::anomaly_state **__middle,
        survarium::anomaly_state **__last,
        survarium::anomaly_state **__formal)
{
  int v5; // ebx
  int i; // esi
  survarium::anomaly_state **j; // esi
  int v8; // eax
  survarium::anomaly_state *v9; // ecx
  int v10; // esi
  survarium::anomaly_state *v11; // [esp-8h] [ebp-18h]
  int v12; // [esp+Ch] [ebp-4h]

  v12 = (char *)__middle - (char *)__first;
  v5 = __middle - __first;
  if ( v5 >= 2 )
  {
    for ( i = (v5 - 2) / 2; ; --i )
    {
      stlp_std::__adjust_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
        __first,
        i,
        v5,
        __first[i],
        (bool (__cdecl *)(survarium::anomaly_state *, survarium::anomaly_state *))__formal);
      if ( !i )
        break;
    }
  }
  for ( j = __middle; j < __last; ++j )
  {
    if ( ((unsigned __int8 (__cdecl *)(survarium::anomaly_state *, _DWORD))__formal)(*j, *__first) )
    {
      v11 = *j;
      *j = *__first;
      stlp_std::__adjust_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
        __first,
        0,
        v5,
        v11,
        (bool (__cdecl *)(survarium::anomaly_state *, survarium::anomaly_state *))__formal);
    }
  }
  if ( v5 > 1 )
  {
    v8 = v12;
    do
    {
      v9 = *(survarium::anomaly_state **)((char *)__first + v8 - 4);
      v10 = v8 - 4;
      *(survarium::anomaly_state **)((char *)__first + v8 - 4) = *__first;
      stlp_std::__adjust_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
        __first,
        0,
        (v8 - 4) >> 2,
        v9,
        (bool (__cdecl *)(survarium::anomaly_state *, survarium::anomaly_state *))__formal);
      v8 = v10;
    }
    while ( (int)(v10 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::priv::__partial_sort<survarium::victory_item_spawner * *,survarium::victory_item_spawner *,survarium::priority_less>(
        survarium::victory_item_spawner **__first@<esi>,
        survarium::victory_item_spawner **__middle,
        survarium::victory_item_spawner **__last)
{
  int v3; // ecx
  int v4; // ebx
  survarium::victory_item_spawner **i; // ebx
  survarium::victory_item_spawner *v6; // edi
  int v7; // eax
  survarium::victory_item_spawner *v8; // edi
  int v9; // ebx
  int __len; // [esp+10h] [ebp-4h]

  v3 = __middle - __first;
  __len = v3;
  if ( v3 >= 2 )
  {
    v4 = (v3 - 2) / 2;
    stlp_std::__adjust_heap<survarium::victory_item_spawner * *,int,survarium::victory_item_spawner *,survarium::priority_less>(
      __first,
      v4,
      __first[v4],
      __middle - __first);
    while ( v4 )
    {
      --v4;
      stlp_std::__adjust_heap<survarium::victory_item_spawner * *,int,survarium::victory_item_spawner *,survarium::priority_less>(
        __first,
        v4,
        __first[v4],
        __len);
    }
  }
  for ( i = __middle; i < __last; ++i )
  {
    v6 = *i;
    if ( (*i)->priority > (*__first)->priority )
    {
      *i = *__first;
      stlp_std::__adjust_heap<survarium::victory_item_spawner * *,int,survarium::victory_item_spawner *,survarium::priority_less>(
        __first,
        0,
        v6,
        __len);
    }
  }
  if ( __len > 1 )
  {
    v7 = (char *)__middle - (char *)__first;
    do
    {
      v8 = *(survarium::victory_item_spawner **)((char *)__first + v7 - 4);
      *(survarium::victory_item_spawner **)((char *)__first + v7 - 4) = *__first;
      v9 = v7 - 4;
      stlp_std::__adjust_heap<survarium::victory_item_spawner * *,int,survarium::victory_item_spawner *,survarium::priority_less>(
        __first,
        0,
        v8,
        (v7 - 4) >> 2);
      v7 = v9;
    }
    while ( (int)(v9 & 0xFFFFFFFC) > 4 );
  }
}


void __cdecl stlp_std::priv::__partial_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key **__first,
        vostok::command_line::key **__middle,
        vostok::command_line::key **__last)
{
  int v4; // edi
  int i; // esi
  vostok::command_line::key *v6; // edi
  vostok::command_line::key *v7; // esi
  int v8; // eax
  vostok::command_line::key *v9; // ecx
  int v10; // esi
  vostok::command_line::key_compare_predicate *v11; // [esp+0h] [ebp-14h]
  int v12; // [esp+Ch] [ebp-8h]
  int __firsta; // [esp+1Ch] [ebp+8h]

  v12 = (char *)__middle - (char *)__first;
  __firsta = __middle - __first;
  v4 = __firsta;
  if ( __firsta >= 2 )
  {
    for ( i = (__firsta - 2) / 2; ; --i )
    {
      stlp_std::__adjust_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        __first,
        i,
        __firsta,
        __first[i]);
      if ( !i )
        break;
    }
  }
  if ( __middle < __last )
  {
    do
    {
      v6 = *__first;
      v7 = *__middle;
      if ( vostok::command_line::key_compare_predicate::operator()(*__middle, *__first, v11) )
      {
        *__middle = v6;
        stlp_std::__adjust_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
          __first,
          0,
          __firsta,
          v7);
      }
      ++__middle;
    }
    while ( __middle < __last );
    v4 = __firsta;
  }
  if ( v4 > 1 )
  {
    v8 = v12;
    do
    {
      v9 = *(vostok::command_line::key **)((char *)__first + v8 - 4);
      v10 = v8 - 4;
      *(vostok::command_line::key **)((char *)__first + v8 - 4) = *__first;
      stlp_std::__adjust_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        __first,
        0,
        (v8 - 4) >> 2,
        v9);
      v8 = v10;
    }
    while ( (int)(v10 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::priv::__partial_sort<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
        const char **__first@<eax>,
        const char **__middle,
        const char **__last)
{
  int v4; // ebx
  int i; // esi
  const char **v6; // esi
  const char *v7; // ebx
  int v8; // eax
  const char *v9; // ecx
  int v10; // esi
  vostok::render::shader_macros_dort_predicate *v11; // [esp+0h] [ebp-18h]
  int v12; // [esp+Ch] [ebp-Ch]
  int __len; // [esp+14h] [ebp-4h]
  char *__val; // [esp+20h] [ebp+8h]

  v12 = (char *)__middle - (char *)__first;
  v4 = __middle - __first;
  __len = v4;
  if ( v4 >= 2 )
  {
    for ( i = (v4 - 2) / 2; ; --i )
    {
      stlp_std::__adjust_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
        __first,
        i,
        v4,
        __first[i]);
      if ( !i )
        break;
    }
  }
  v6 = __middle;
  if ( __middle < __last )
  {
    do
    {
      v7 = *__first;
      __val = (char *)*v6;
      if ( vostok::render::shader_macros_dort_predicate::operator()(*v6, *__first, v11) )
      {
        *v6 = v7;
        stlp_std::__adjust_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
          __first,
          0,
          __len,
          __val);
      }
      ++v6;
    }
    while ( v6 < __last );
    v4 = __len;
  }
  if ( v4 > 1 )
  {
    v8 = v12;
    do
    {
      v9 = *(const char **)((char *)__first + v8 - 4);
      v10 = v8 - 4;
      *(const char **)((char *)__first + v8 - 4) = *__first;
      stlp_std::__adjust_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
        __first,
        0,
        (v8 - 4) >> 2,
        v9);
      v8 = v10;
    }
    while ( (int)(v10 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::priv::__partial_sort<char const * *,char const *,vostok::tips_sorting_predicate>(
        const char **__first@<esi>,
        char **__middle,
        char **__last,
        vostok::tips_sorting_predicate *__formal)
{
  vostok::tips_sorting_predicate *v4; // ecx
  int v5; // ebx
  int v6; // edi
  char **i; // ebx
  vostok::tips_sorting_predicate *v8; // ebx
  int v9; // eax
  char *v10; // ecx
  int v11; // edi
  char *v12; // [esp-8h] [ebp-1Ch]
  vostok::tips_sorting_predicate *v13; // [esp-4h] [ebp-18h]
  vostok::tips_sorting_predicate *__comp; // [esp+Ch] [ebp-8h]
  int __len; // [esp+10h] [ebp-4h]

  v4 = __formal;
  v5 = ((char *)__middle - (char *)__first) >> 2;
  __comp = __formal;
  __len = v5;
  if ( v5 >= 2 )
  {
    v6 = (v5 - 2) / 2;
    stlp_std::__adjust_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
      __first,
      v6,
      (const char *)v5,
      (char *)__first[v6],
      (vostok::tips_sorting_predicate)__formal);
    while ( v6 )
    {
      --v6;
      stlp_std::__adjust_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
        __first,
        v6,
        (const char *)v5,
        (char *)__first[v6],
        (vostok::tips_sorting_predicate)__comp);
    }
  }
  for ( i = __middle; i < __last; ++i )
  {
    if ( vostok::tips_sorting_predicate::operator()(v4, (unsigned __int8 **)&__formal, *i, (char *)*__first) )
    {
      v13 = __formal;
      v12 = *i;
      *i = (char *)*__first;
      stlp_std::__adjust_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
        __first,
        0,
        (const char *)__len,
        v12,
        (vostok::tips_sorting_predicate)v13);
    }
  }
  v8 = __formal;
  if ( __len > 1 )
  {
    v9 = (char *)__middle - (char *)__first;
    do
    {
      v10 = *(char **)((char *)__first + v9 - 4);
      v11 = v9 - 4;
      *(const char **)((char *)__first + v9 - 4) = *__first;
      stlp_std::__adjust_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
        __first,
        0,
        (const char *)((v9 - 4) >> 2),
        v10,
        (vostok::tips_sorting_predicate)v8);
      v9 = v11;
    }
    while ( (int)(v11 & 0xFFFFFFFC) > 4 );
  }
}


void __usercall stlp_std::priv::__partial_sort<void const * *,void const *,stlp_std::less<void const *>>(
        survarium::single_game_effect **__first@<esi>,
        survarium::single_game_effect **__middle,
        survarium::single_game_effect **__last)
{
  int v3; // ebx
  int i; // edi
  unsigned int *j; // edi
  unsigned int v6; // ecx
  int v7; // eax
  unsigned int v8; // ecx
  int v9; // edi

  v3 = __middle - __first;
  if ( v3 >= 2 )
  {
    for ( i = (v3 - 2) / 2; ; --i )
    {
      stlp_std::__adjust_heap<survarium::single_game_effect * *,int,survarium::single_game_effect *,stlp_std::less<survarium::single_game_effect *>>(
        (unsigned int *)__first,
        i,
        v3,
        (unsigned int)__first[i]);
      if ( !i )
        break;
    }
  }
  for ( j = (unsigned int *)__middle; j < (unsigned int *)__last; ++j )
  {
    v6 = *j;
    if ( *j < (unsigned int)*__first )
    {
      *j = (unsigned int)*__first;
      stlp_std::__adjust_heap<survarium::single_game_effect * *,int,survarium::single_game_effect *,stlp_std::less<survarium::single_game_effect *>>(
        (unsigned int *)__first,
        0,
        v3,
        v6);
    }
  }
  if ( v3 > 1 )
  {
    v7 = (char *)__middle - (char *)__first;
    do
    {
      v8 = *(unsigned int *)((char *)__first + v7 - 4);
      v9 = v7 - 4;
      *(survarium::single_game_effect **)((char *)__first + v7 - 4) = *__first;
      stlp_std::__adjust_heap<survarium::single_game_effect * *,int,survarium::single_game_effect *,stlp_std::less<survarium::single_game_effect *>>(
        (unsigned int *)__first,
        0,
        (v7 - 4) >> 2,
        v8);
      v7 = v9;
    }
    while ( (int)(v9 & 0xFFFFFFFC) > 4 );
  }
}


void __cdecl stlp_std::priv::__partial_sort<survarium::relocate_item_descr *,survarium::relocate_item_descr,survarium::ammo_slots_sort>(
        survarium::relocate_item_descr *__first,
        survarium::relocate_item_descr *__middle,
        survarium::relocate_item_descr *__last,
        const survarium::items_dictionary *__formal,
        survarium::ammo_slots_sort __comp)
{
  survarium::relocate_item_descr *v5; // ebx
  int v6; // esi
  survarium::relocate_item_descr *i; // eax
  survarium::relocate_item_descr *v8; // ebx
  survarium::ammo_slots_sort v9; // [esp-Ch] [ebp-28h]
  survarium::ammo_slots_sort v10; // [esp-Ch] [ebp-28h]
  survarium::ammo_slots_sort v11; // [esp-4h] [ebp-20h]
  survarium::ammo_slots_sort __len; // [esp+Ch] [ebp-10h] BYREF
  int v13; // [esp+18h] [ebp-4h]

  v5 = __middle;
  __len.m_dict = __formal;
  *(_QWORD *)__len.m_weapon_ids = *(_QWORD *)&__comp.m_dict;
  v6 = __middle - __first;
  v13 = v6;
  if ( v6 >= 2 )
  {
    v11.m_dict = (const survarium::items_dictionary *)&__len;
    stlp_std::__make_heap<survarium::relocate_item_descr *,survarium::ammo_slots_sort,survarium::relocate_item_descr,int>(
      __middle,
      __first,
      v11);
  }
  for ( i = __middle; i < __last; __middle = i )
  {
    if ( survarium::ammo_slots_sort::operator()((survarium::ammo_slots_sort *)&__formal, i, __first) )
    {
      v9.m_dict = __formal;
      *(_QWORD *)v9.m_weapon_ids = *(_QWORD *)&__comp.m_dict;
      stlp_std::__pop_heap<survarium::relocate_item_descr *,survarium::relocate_item_descr,survarium::ammo_slots_sort,int>(
        v5,
        __middle,
        __first,
        *__middle,
        v9);
      v6 = v13;
    }
    i = __middle + 1;
  }
  if ( v6 > 1 )
  {
    v8 = v5 - 1;
    do
    {
      v10.m_dict = __formal;
      *(_QWORD *)v10.m_weapon_ids = *(_QWORD *)&__comp.m_dict;
      stlp_std::__pop_heap<survarium::relocate_item_descr *,survarium::relocate_item_descr,survarium::ammo_slots_sort,int>(
        v8,
        v8,
        __first,
        *v8,
        v10);
      --v8;
    }
    while ( (int)(((unsigned int)v8 + 16 - (_DWORD)__first) & 0xFFFFFFF0) > 16 );
  }
}


void __cdecl stlp_std::priv::__partial_sort<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> *__middle,
        vostok::math::curve_point<float> *__last,
        vostok::math::curve_point<float> *__formal)
{
  vostok::math::curve_point<float> *v4; // ebx
  vostok::math::curve_point<float> *i; // esi
  vostok::math::curve_point<float> *v6; // ebx
  vostok::math::curve_point<float> v7; // [esp-1Ch] [ebp-2Ch] BYREF
  int v8; // [esp+Ch] [ebp-4h]

  v4 = __middle;
  v8 = __middle - __first;
  if ( v8 >= 2 )
    stlp_std::__make_heap<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),vostok::math::curve_point<float>,int>(
      __middle,
      __first,
      (bool (__cdecl *)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))__formal);
  for ( i = __middle; i < __last; __middle = i )
  {
    if ( ((unsigned __int8 (__cdecl *)(vostok::math::curve_point<float> *, vostok::math::curve_point<float> *))__formal)(
           i,
           __first) )
    {
      qmemcpy(&v7, i, sizeof(v7));
      stlp_std::__pop_heap<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),int>(
        v4,
        __middle,
        __first,
        v7,
        (bool (__cdecl *)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))__formal);
    }
    i = __middle + 1;
  }
  if ( v8 > 1 )
  {
    v6 = v4 - 1;
    do
    {
      qmemcpy(&v7, v6, sizeof(v7));
      stlp_std::__pop_heap<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),int>(
        v6,
        v6,
        __first,
        v7,
        (bool (__cdecl *)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))__formal);
      --v6;
    }
    while ( ((int)v6 + 24 - (int)__first) / 24 > 1 );
  }
}


void __usercall stlp_std::priv::__partial_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__middle@<eax>,
        vostok::render::shader_constant *__first,
        vostok::render::shader_constant *__last,
        vostok::render::shader_constant *__formal)
{
  vostok::render::shader_constant *i; // esi
  vostok::render::shader_constant *v6; // esi
  vostok::render::shader_constant v7; // [esp-1Ch] [ebp-28h]

  stlp_std::make_heap<vostok::render::shader_constant *,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
    __middle,
    __first,
    (bool (__cdecl *)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))__formal);
  for ( i = __middle; i < __last; ++i )
  {
    if ( ((unsigned __int8 (__cdecl *)(vostok::render::shader_constant *, vostok::render::shader_constant *))__formal)(
           i,
           __first) )
    {
      v7.m_slot.m_value = i->m_slot.m_value;
      v7.m_source.m_pointer = i->m_source.m_pointer;
      v7.m_source.m_size = i->m_source.m_size;
      v7.m_host = i->m_host;
      stlp_std::__pop_heap<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &),int>(
        i,
        __first,
        __middle,
        v7,
        (bool (__cdecl *)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))__formal);
    }
  }
  if ( __middle - __first > 1 )
  {
    v6 = __middle - 1;
    do
    {
      v7.m_slot.m_value = v6->m_slot.m_value;
      v7.m_source.m_pointer = v6->m_source.m_pointer;
      v7.m_source.m_size = v6->m_source.m_size;
      v7.m_host = v6->m_host;
      stlp_std::__pop_heap<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &),int>(
        v6,
        __first,
        v6,
        v7,
        (bool (__cdecl *)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))__formal);
      --v6;
    }
    while ( ((int)v6 + 24 - (int)__first) / 24 > 1 );
  }
}
