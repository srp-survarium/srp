void __usercall stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        unsigned int *__first@<ecx>,
        int __holeIndex@<eax>,
        int __len,
        unsigned int __val,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  int v5; // esi
  int i; // eax
  int j; // eax
  unsigned int v8; // edx

  v5 = __holeIndex;
  for ( i = 2 * __holeIndex + 2; i < __len; i = 2 * i + 2 )
  {
    if ( *(float *)((_DWORD)__comp.m_distances + 4 * __first[i - 1]) > *(float *)((_DWORD)__comp.m_distances
                                                                                + 4 * __first[i]) )
      --i;
    __first[v5] = __first[i];
    v5 = i;
  }
  if ( i == __len )
  {
    __first[v5] = __first[i - 1];
    v5 = i - 1;
  }
  for ( j = (v5 - 1) / 2; v5 > __holeIndex; j = (j - 1) / 2 )
  {
    v8 = __first[j];
    if ( *(float *)((_DWORD)__comp.m_distances + 4 * __val) <= *(float *)((_DWORD)__comp.m_distances + 4 * v8) )
      break;
    __first[v5] = v8;
    v5 = j;
  }
  __first[v5] = __val;
}


void __usercall stlp_std::__adjust_heap<float *,int,float,stlp_std::less<float>>(
        float *__first@<ecx>,
        int __holeIndex@<eax>,
        int __len,
        float __val)
{
  int v4; // esi
  int i; // eax
  int j; // eax
  float v8; // xmm0_4
  int v9; // eax

  v4 = __holeIndex;
  for ( i = 2 * __holeIndex + 2; i < __len; i = 2 * i + 2 )
  {
    if ( __first[i - 1] > __first[i] )
      --i;
    __first[v4] = __first[i];
    v4 = i;
  }
  if ( i == __len )
  {
    __first[v4] = __first[i - 1];
    v4 = i - 1;
  }
  for ( j = v4 - 1; ; j = v9 - 1 )
  {
    v9 = j / 2;
    if ( v4 <= __holeIndex )
      break;
    v8 = __first[v9];
    if ( __val <= v8 )
      break;
    __first[v4] = v8;
    v4 = v9;
  }
  __first[v4] = __val;
}


void __usercall stlp_std::__adjust_heap<survarium::victory_item_spawner * *,int,survarium::victory_item_spawner *,survarium::priority_less>(
        survarium::victory_item_spawner **__first@<ecx>,
        int __holeIndex@<eax>,
        survarium::victory_item_spawner *__val@<edi>,
        int __len)
{
  int v4; // esi
  int i; // eax
  int j; // eax
  survarium::victory_item_spawner *v7; // edx
  int v8; // eax

  v4 = __holeIndex;
  for ( i = 2 * __holeIndex + 2; i < __len; i = 2 * i + 2 )
  {
    if ( __first[i]->priority > __first[i - 1]->priority )
      --i;
    __first[v4] = __first[i];
    v4 = i;
  }
  if ( i == __len )
  {
    __first[v4] = __first[i - 1];
    v4 = i - 1;
  }
  for ( j = v4 - 1; ; j = v8 - 1 )
  {
    v8 = j / 2;
    if ( v4 <= __holeIndex )
      break;
    v7 = __first[v8];
    if ( v7->priority <= __val->priority )
      break;
    __first[v4] = v7;
    v4 = v8;
  }
  __first[v4] = __val;
}


void __cdecl stlp_std::__adjust_heap<vostok::command_line::key * *,int,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key **__first,
        int __holeIndex,
        int __len,
        vostok::command_line::key *__val)
{
  int v4; // ecx
  int v5; // ebx
  bool v6; // zf
  int v7; // edx
  vostok::command_line::key *v8; // ecx
  int i; // ebx
  vostok::command_line::key *v10; // esi
  vostok::command_line::key_compare_predicate *v11; // [esp+0h] [ebp-10h]
  int v12; // [esp+Ch] [ebp-4h]
  int v13; // [esp+1Ch] [ebp+Ch]

  v4 = __holeIndex;
  v5 = 2 * __holeIndex + 2;
  v6 = v5 == __len;
  v12 = __holeIndex;
  if ( v5 < __len )
  {
    do
    {
      if ( vostok::command_line::key_compare_predicate::operator()(__first[v5], __first[v5 - 1], v11) )
        --v5;
      v7 = __holeIndex;
      v8 = __first[v5];
      __holeIndex = v5;
      v5 = 2 * v5 + 2;
      v6 = v5 == __len;
      __first[v7] = v8;
    }
    while ( v5 < __len );
    v4 = __holeIndex;
  }
  if ( v6 )
  {
    __first[v4] = __first[v5 - 1];
    v4 = v5 - 1;
  }
  for ( i = (v4 - 1) / 2; ; i = (i - 1) / 2 )
  {
    v13 = v4;
    if ( v4 <= v12 )
      break;
    v10 = __first[i];
    if ( !vostok::command_line::key_compare_predicate::operator()(v10, __val, v11) )
      break;
    __first[v13] = v10;
    v4 = i;
  }
  __first[v13] = __val;
}


void __usercall stlp_std::__adjust_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
        survarium::anomaly_state **__first@<edi>,
        int __holeIndex,
        int __len,
        survarium::anomaly_state *__val,
        bool (__cdecl *__comp)(survarium::anomaly_state *, survarium::anomaly_state *))
{
  int v5; // ebx
  int i; // esi
  int j; // esi

  v5 = __holeIndex;
  for ( i = 2 * __holeIndex + 2; i < __len; i = 2 * i + 2 )
  {
    if ( __comp(__first[i], __first[i - 1]) )
      --i;
    __first[v5] = __first[i];
    v5 = i;
  }
  if ( i == __len )
  {
    __first[v5] = __first[i - 1];
    v5 = i - 1;
  }
  for ( j = (v5 - 1) / 2; v5 > __holeIndex && __comp(__first[j], __val); j = (j - 1) / 2 )
  {
    __first[v5] = __first[j];
    v5 = j;
  }
  __first[v5] = __val;
}


void __usercall stlp_std::__adjust_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
        const char **__first@<edi>,
        int __holeIndex,
        int __len,
        const char *__val)
{
  int v4; // ebx
  int i; // esi
  int j; // esi
  vostok::render::shader_macros_dort_predicate *v7; // [esp+0h] [ebp-8h]

  v4 = __holeIndex;
  for ( i = 2 * __holeIndex + 2; i < __len; i = 2 * i + 2 )
  {
    if ( vostok::render::shader_macros_dort_predicate::operator()(__first[i], __first[i - 1], v7) )
      --i;
    __first[v4] = __first[i];
    v4 = i;
  }
  if ( i == __len )
  {
    __first[v4] = __first[i - 1];
    v4 = i - 1;
  }
  for ( j = (v4 - 1) / 2;
        v4 > __holeIndex && vostok::render::shader_macros_dort_predicate::operator()(__first[j], __val, v7);
        j = (j - 1) / 2 )
  {
    __first[v4] = __first[j];
    v4 = j;
  }
  __first[v4] = __val;
}


void __cdecl stlp_std::__adjust_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
        const char **__first,
        int __holeIndex,
        const char *__len,
        char *__val,
        vostok::tips_sorting_predicate __comp)
{
  int v5; // ecx
  int v7; // esi
  bool v8; // zf
  const char *v9; // eax
  bool v10; // cc
  int i; // esi
  int v12; // [esp+14h] [ebp+8h]
  int v13; // [esp+18h] [ebp+Ch]

  v5 = __holeIndex;
  v7 = 2 * __holeIndex + 2;
  v8 = v7 == (_DWORD)__len;
  v12 = __holeIndex;
  if ( v7 < (int)__len )
  {
    do
    {
      if ( vostok::tips_sorting_predicate::operator()(
             (vostok::tips_sorting_predicate *)v5,
             (unsigned __int8 **)&__comp,
             (char *)__first[v7],
             (char *)__first[v7 - 1]) )
      {
        --v7;
      }
      v5 = __holeIndex;
      v9 = __first[v7];
      __holeIndex = v7;
      v7 = 2 * v7 + 2;
      v8 = v7 == (_DWORD)__len;
      v10 = v7 < (int)__len;
      __first[v5] = v9;
    }
    while ( v10 );
    v5 = __holeIndex;
  }
  if ( v8 )
  {
    __first[v5] = __first[v7 - 1];
    v5 = v7 - 1;
  }
  __len = __comp.editor_str;
  for ( i = (v5 - 1) / 2; ; i = (i - 1) / 2 )
  {
    v13 = v5;
    if ( v5 <= v12
      || !vostok::tips_sorting_predicate::operator()(
            (vostok::tips_sorting_predicate *)v5,
            (unsigned __int8 **)&__len,
            (char *)__first[i],
            __val) )
    {
      break;
    }
    __first[v13] = __first[i];
    v5 = i;
  }
  __first[v13] = __val;
}


void __cdecl stlp_std::__adjust_heap<survarium::relocate_item_descr *,int,survarium::relocate_item_descr,survarium::ammo_slots_sort>(
        survarium::relocate_item_descr *__first,
        int __holeIndex,
        int __len,
        survarium::relocate_item_descr __val,
        __int128 __comp)
{
  int i; // ebx
  survarium::relocate_item_descr *v6; // esi
  survarium::relocate_item_descr *v7; // edi
  survarium::relocate_item_descr *v8; // edi
  survarium::relocate_item_descr *v9; // esi
  int v10; // ebx
  int v11; // edi
  const survarium::relocate_item_descr *v12; // esi
  survarium::relocate_item_descr *v13; // edi
  unsigned int *p_item_dict_id; // esi
  bool v15; // cc
  survarium::relocate_item_descr *v16; // edi
  survarium::relocate_item_descr v17; // [esp+Ch] [ebp-20h] BYREF
  survarium::ammo_slots_sort v18; // [esp+1Ch] [ebp-10h] BYREF
  int v19; // [esp+28h] [ebp-4h]

  v19 = __holeIndex;
  for ( i = 2 * __holeIndex + 2; i < __len; i = 2 * i + 2 )
  {
    if ( survarium::ammo_slots_sort::operator()((survarium::ammo_slots_sort *)&__comp, &__first[i], &__first[i - 1]) )
      --i;
    v6 = &__first[i];
    v7 = &__first[__holeIndex];
    __holeIndex = i;
    v7->item_id = v6->item_id;
    v6 = (survarium::relocate_item_descr *)((char *)v6 + 4);
    v7 = (survarium::relocate_item_descr *)((char *)v7 + 4);
    v7->item_id = v6->item_id;
    v6 = (survarium::relocate_item_descr *)((char *)v6 + 4);
    v7 = (survarium::relocate_item_descr *)((char *)v7 + 4);
    v7->item_id = v6->item_id;
    *(_DWORD *)&v7->item_dict_id = *(_DWORD *)&v6->item_dict_id;
  }
  if ( i == __len )
  {
    v8 = &__first[__holeIndex];
    v9 = &__first[i - 1];
    v8->item_id = v9->item_id;
    v9 = (survarium::relocate_item_descr *)((char *)v9 + 4);
    v8 = (survarium::relocate_item_descr *)((char *)v8 + 4);
    v8->item_id = v9->item_id;
    v9 = (survarium::relocate_item_descr *)((char *)v9 + 4);
    v8 = (survarium::relocate_item_descr *)((char *)v8 + 4);
    v8->item_id = v9->item_id;
    *(_DWORD *)&v8->item_dict_id = *(_DWORD *)&v9->item_dict_id;
    __holeIndex = i - 1;
  }
  v18 = (survarium::ammo_slots_sort)__comp;
  v17 = __val;
  v10 = (__holeIndex - 1) / 2;
  v11 = __holeIndex;
  if ( __holeIndex > v19 )
  {
    do
    {
      v12 = &__first[v10];
      if ( !survarium::ammo_slots_sort::operator()(&v18, v12, &v17) )
        break;
      v13 = &__first[v11];
      v13->item_id = v12->item_id;
      p_item_dict_id = (unsigned int *)&v12->item_dict_id;
      v13 = (survarium::relocate_item_descr *)((char *)v13 + 4);
      v13->item_id = *p_item_dict_id++;
      v13 = (survarium::relocate_item_descr *)((char *)v13 + 4);
      v13->item_id = *p_item_dict_id;
      *(_DWORD *)&v13->item_dict_id = p_item_dict_id[1];
      v11 = v10;
      v15 = v10 <= v19;
      v10 = (v10 - 1) / 2;
    }
    while ( !v15 );
  }
  v16 = &__first[v11];
  v16->item_id = __val.item_id;
  v16 = (survarium::relocate_item_descr *)((char *)v16 + 4);
  v16->item_id = *(_DWORD *)&__val.item_dict_id;
  *(_QWORD *)&v16->item_dict_id = *(_QWORD *)&__val.amount;
}


void __cdecl stlp_std::__adjust_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        int __holeIndex,
        int __len,
        vostok::math::curve_point<float> __val,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  int i; // ebx
  vostok::math::curve_point<float> *v6; // edi
  int v7; // ebx
  int v8; // edi
  bool v9; // cc
  vostok::math::curve_point<float> v10; // [esp+Ch] [ebp-1Ch] BYREF
  int v11; // [esp+24h] [ebp-4h]

  v11 = __holeIndex;
  for ( i = 2 * __holeIndex + 2; i < __len; i = 2 * i + 2 )
  {
    if ( __comp(&__first[i], &__first[i - 1]) )
      --i;
    v6 = &__first[__holeIndex];
    __holeIndex = i;
    qmemcpy(v6, &__first[i], sizeof(vostok::math::curve_point<float>));
  }
  if ( i == __len )
  {
    qmemcpy(&__first[__holeIndex], &__first[i - 1], sizeof(vostok::math::curve_point<float>));
    __holeIndex = i - 1;
  }
  qmemcpy(&v10, &__val, sizeof(v10));
  v7 = (__holeIndex - 1) / 2;
  v8 = __holeIndex;
  if ( __holeIndex > v11 )
  {
    do
    {
      if ( !__comp(&__first[v7], &v10) )
        break;
      qmemcpy(&__first[v8], &__first[v7], sizeof(vostok::math::curve_point<float>));
      v8 = v7;
      v9 = v7 <= v11;
      v7 = (v7 - 1) / 2;
    }
    while ( !v9 );
  }
  qmemcpy(&__first[v8], &v10, sizeof(vostok::math::curve_point<float>));
}


void __usercall stlp_std::__adjust_heap<vostok::render::shader_constant *,int,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        int __holeIndex@<eax>,
        vostok::render::shader_constant *__first,
        int __len,
        vostok::render::shader_constant __val,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  int v6; // edi
  int i; // esi
  int v8; // esi
  bool v9; // cc
  vostok::render::shader_constant v10; // [esp+Ch] [ebp-18h] BYREF
  int v12; // [esp+30h] [ebp+Ch]

  v6 = __holeIndex;
  for ( i = 2 * __holeIndex + 2; i < __len; i = 2 * i + 2 )
  {
    if ( __comp(&__first[i], &__first[i - 1]) )
      --i;
    vostok::render::shader_constant::operator=(&__first[i], &__first[v6]);
    v6 = i;
  }
  if ( i == __len )
  {
    vostok::render::shader_constant::operator=(&__first[i - 1], &__first[v6]);
    v6 = i - 1;
  }
  v10 = __val;
  v8 = (v6 - 1) / 2;
  v12 = v6;
  if ( v6 > __holeIndex )
  {
    do
    {
      if ( !__comp(&__first[v8], &v10) )
        break;
      vostok::render::shader_constant::operator=(&__first[v8], &__first[v12]);
      v9 = v8 <= __holeIndex;
      v12 = v8;
      v8 = (v8 - 1) / 2;
    }
    while ( !v9 );
  }
  vostok::render::shader_constant::operator=(&v10, &__first[v12]);
}
