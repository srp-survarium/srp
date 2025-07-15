void __cdecl stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,vostok::render::culling::portal_id_closer_to_point>(
        unsigned int *__first,
        unsigned int *__last,
        unsigned int *__formal,
        int __depth_limit,
        vostok::render::culling::portal_id_closer_to_point __comp)
{
  char *v6; // ebx
  unsigned int *v8; // ecx
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  unsigned int *v12; // edx
  unsigned int *v13; // edi
  float v14; // xmm0_4
  unsigned int v15; // ecx
  unsigned int *__firsta; // [esp+10h] [ebp+8h]

  v6 = (char *)__last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( 1 )
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
          (char *)__first,
          v6,
          (unsigned int *)v6,
          (unsigned int *)__comp.m_distances);
        return;
      }
      --__depth_limit;
      v8 = &__first[((v6 - (char *)__first) >> 2) / 2];
      v9 = *(float *)((_DWORD)__comp.m_distances + 4 * *__first);
      v10 = *(float *)((_DWORD)__comp.m_distances + 4 * *v8);
      v11 = *(float *)((_DWORD)__comp.m_distances + 4 * *((_DWORD *)v6 - 1));
      if ( v10 > v9 )
        break;
      if ( v11 > v9 )
        goto LABEL_6;
      if ( v11 > v10 )
        goto LABEL_9;
LABEL_10:
      v12 = (unsigned int *)v6;
      v13 = __first;
      __firsta = (unsigned int *)((_DWORD)__comp.m_distances + 4 * *v8);
      while ( 1 )
      {
        v14 = *(float *)__firsta;
        while ( v14 > *(float *)((_DWORD)__comp.m_distances + 4 * *v13) )
          ++v13;
        do
          --v12;
        while ( *(float *)((_DWORD)__comp.m_distances + 4 * *v12) > v14 );
        if ( v13 >= v12 )
          break;
        v15 = *v13;
        *v13 = *v12;
        v6 = (char *)__last;
        *v12 = v15;
        ++v13;
      }
      stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,vostok::render::culling::portal_id_closer_to_point>(
        (vostok::render::culling::portal_id_closer_to_point)v13,
        v13,
        (unsigned int *)v6,
        0,
        __depth_limit,
        __comp);
      v6 = (char *)v13;
      __last = v13;
      if ( (int)(((char *)v13 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    if ( v11 > v10 )
      goto LABEL_10;
    if ( v11 <= v9 )
    {
LABEL_6:
      v8 = __first;
      goto LABEL_10;
    }
LABEL_9:
    v8 = (unsigned int *)(v6 - 4);
    goto LABEL_10;
  }
}


void __cdecl stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,stlp_std::less<unsigned int>>(
        unsigned int *__first,
        unsigned int *__last,
        unsigned int *__formal,
        int __depth_limit,
        unsigned int *__comp)
{
  char *v6; // eax
  unsigned int *v7; // ecx
  unsigned int v8; // ebx
  unsigned int v9; // edx
  unsigned int *v10; // eax
  unsigned int v11; // edi
  unsigned int v12; // ecx
  unsigned int *v13; // eax
  unsigned int *i; // edi
  unsigned int v15; // edx

  v6 = (char *)__last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
          (char *)__first,
          v6,
          (unsigned int *)v6,
          __comp);
        return;
      }
      --__depth_limit;
      v7 = (unsigned int *)(v6 - 4);
      v8 = *((_DWORD *)v6 - 1);
      v9 = *__first;
      v10 = &__first[((v6 - (char *)__first) >> 2) / 2];
      v11 = *v10;
      if ( *__first >= *v10 )
      {
        if ( v9 < v8 )
          goto LABEL_6;
        if ( v11 < v8 )
LABEL_9:
          v10 = v7;
      }
      else if ( v11 >= v8 )
      {
        if ( v9 < v8 )
          goto LABEL_9;
LABEL_6:
        v10 = __first;
      }
      v12 = *v10;
      v13 = __last;
      for ( i = __first; ; ++i )
      {
        if ( *i < v12 )
          continue;
        do
          --v13;
        while ( v12 < *v13 );
        if ( i >= v13 )
          break;
        v15 = *i;
        *i = *v13;
        *v13 = v15;
      }
      stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,stlp_std::less<unsigned int>>(
        (stlp_std::less<unsigned int>)i,
        i,
        __last,
        0,
        __depth_limit,
        __comp);
      v6 = (char *)i;
      __last = i;
    }
    while ( (int)(((char *)i - (char *)__first) & 0xFFFFFFFC) > 64 );
  }
}


void __cdecl stlp_std::priv::__introsort_loop<float *,float,int,stlp_std::less<float>>(
        float *__first,
        float *__last,
        float *__formal,
        int __depth_limit,
        float *__comp)
{
  float *v6; // ebx
  float v7; // xmm2_4
  float *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float *v12; // eax
  float *i; // edi
  float v14; // xmm0_4

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<float *,float,stlp_std::less<float>>(__first, v6, v6, __comp);
        return;
      }
      --__depth_limit;
      v7 = *__first;
      v8 = &__first[(v6 - __first) / 2];
      v9 = *v8;
      v10 = *(v6 - 1);
      if ( *v8 <= *__first )
      {
        if ( v10 > v7 )
          goto LABEL_6;
        if ( v10 > v9 )
LABEL_9:
          v8 = v6 - 1;
      }
      else if ( v10 <= v9 )
      {
        if ( v10 > v7 )
          goto LABEL_9;
LABEL_6:
        v8 = __first;
      }
      v11 = *v8;
      v12 = v6;
      for ( i = __first; ; ++i )
      {
        if ( v11 > *i )
          continue;
        do
          --v12;
        while ( *v12 > v11 );
        if ( i >= v12 )
          break;
        v14 = *i;
        *i = *v12;
        *v12 = v14;
      }
      stlp_std::priv::__introsort_loop<float *,float,int,stlp_std::less<float>>(
        (stlp_std::less<float>)i,
        i,
        v6,
        0,
        __depth_limit,
        __comp);
      v6 = i;
    }
    while ( (int)(((char *)i - (char *)__first) & 0xFFFFFFFC) > 64 );
  }
}


void __cdecl stlp_std::priv::__introsort_loop<survarium::victory_item_spawner * *,survarium::victory_item_spawner *,int,survarium::priority_less>(
        survarium::victory_item_spawner **__first,
        survarium::victory_item_spawner **__last,
        survarium::victory_item_spawner **__formal,
        int __depth_limit,
        survarium::victory_item_spawner **__comp)
{
  survarium::victory_item_spawner **v6; // eax
  survarium::victory_item_spawner **v7; // ecx
  unsigned int priority; // ebx
  unsigned int v9; // edx
  survarium::victory_item_spawner **v10; // eax
  unsigned int v11; // edi
  survarium::victory_item_spawner *v12; // edx
  survarium::victory_item_spawner **v13; // eax
  survarium::victory_item_spawner **i; // edi
  unsigned int v15; // ecx
  survarium::victory_item_spawner *v16; // ecx

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( 1 )
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<survarium::victory_item_spawner * *,survarium::victory_item_spawner *,survarium::priority_less>(
          __first,
          v6,
          v6,
          __comp);
        return;
      }
      --__depth_limit;
      v7 = v6 - 1;
      priority = (*(v6 - 1))->priority;
      v9 = (*__first)->priority;
      v10 = &__first[(v6 - __first) / 2];
      v11 = (*v10)->priority;
      if ( v9 > v11 )
        break;
      if ( v9 > priority )
        goto LABEL_6;
      if ( v11 > priority )
        goto LABEL_9;
LABEL_10:
      v12 = *v10;
      v13 = __last;
      for ( i = __first; ; ++i )
      {
        v15 = v12->priority;
        while ( (*i)->priority > v15 )
          ++i;
        do
          --v13;
        while ( v15 > (*v13)->priority );
        if ( i >= v13 )
          break;
        v16 = *i;
        *i = *v13;
        *v13 = v16;
      }
      stlp_std::priv::__introsort_loop<survarium::victory_item_spawner * *,survarium::victory_item_spawner *,int,survarium::priority_less>(
        (survarium::priority_less)i,
        i,
        __last,
        0,
        __depth_limit,
        __comp);
      v6 = i;
      __last = i;
      if ( (int)(((char *)i - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    if ( v11 > priority )
      goto LABEL_10;
    if ( v9 <= priority )
    {
LABEL_6:
      v10 = __first;
      goto LABEL_10;
    }
LABEL_9:
    v10 = v7;
    goto LABEL_10;
  }
}


void __usercall stlp_std::priv::__introsort_loop<vostok::command_line::key * *,vostok::command_line::key *,int,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key_compare_predicate *a1@<edi>,
        vostok::command_line::key **__first,
        vostok::command_line::key **__last,
        vostok::command_line::key **__formal,
        int __depth_limit,
        vostok::command_line::key **__comp)
{
  vostok::command_line::key **v6; // ebx
  const vostok::command_line::key *v7; // esi
  const vostok::command_line::key *v8; // edi
  const vostok::command_line::key *const *v9; // eax
  const vostok::command_line::key *v10; // edi
  bool i; // al
  vostok::command_line::key *v12; // edi
  vostok::command_line::key *v13; // ecx
  vostok::command_line::key_compare_predicate *v14; // [esp-8h] [ebp-14h]
  vostok::command_line::key_compare_predicate *v15; // [esp-8h] [ebp-14h]
  vostok::command_line::key_compare_predicate *v16; // [esp-8h] [ebp-14h]
  const vostok::command_line::key *v17; // [esp+4h] [ebp-8h]
  const vostok::command_line::key *const *v18; // [esp+8h] [ebp-4h]
  const vostok::command_line::key **v19; // [esp+8h] [ebp-4h]

  v6 = __first;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
    return;
  v14 = a1;
  while ( 2 )
  {
    if ( !__depth_limit )
    {
      stlp_std::priv::__partial_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        v6,
        __last,
        __last,
        __comp);
      return;
    }
    v7 = *v6;
    --__depth_limit;
    v18 = (const vostok::command_line::key *const *)&v6[(__last - v6) / 2];
    if ( !vostok::command_line::key_compare_predicate::operator()(*v6, *v18, v14) )
    {
      v10 = *(__last - 1);
      if ( vostok::command_line::key_compare_predicate::operator()(v7, v10, v15) )
        goto LABEL_9;
      if ( vostok::command_line::key_compare_predicate::operator()(*v18, v10, v16) )
        goto LABEL_8;
LABEL_12:
      v9 = (const vostok::command_line::key *const *)&v6[(__last - v6) / 2];
      goto LABEL_13;
    }
    v8 = *(__last - 1);
    if ( vostok::command_line::key_compare_predicate::operator()(*v18, v8, v15) )
      goto LABEL_12;
    if ( !vostok::command_line::key_compare_predicate::operator()(*v6, v8, v16) )
    {
LABEL_9:
      v9 = (const vostok::command_line::key *const *)v6;
      goto LABEL_13;
    }
LABEL_8:
    v9 = (const vostok::command_line::key *const *)(__last - 1);
LABEL_13:
    v17 = *v9;
    v19 = (const vostok::command_line::key **)__last;
    for ( i = vostok::command_line::key_compare_predicate::operator()(*v6, *v9, v16);
          ;
          i = vostok::command_line::key_compare_predicate::operator()(*v6, v17, v14) )
    {
      if ( i )
        goto LABEL_14;
      do
        v12 = (vostok::command_line::key *)*--v19;
      while ( vostok::command_line::key_compare_predicate::operator()(v17, *v19, v14) );
      if ( v6 >= (vostok::command_line::key **)v19 )
        break;
      v13 = *v6;
      *v6 = (vostok::command_line::key *)*v19;
      *v19 = v13;
LABEL_14:
      ++v6;
    }
    stlp_std::priv::__introsort_loop<vostok::command_line::key * *,vostok::command_line::key *,int,vostok::command_line::key_compare_predicate>(
      (vostok::command_line::key_compare_predicate *)v12,
      v6,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = v6;
    if ( (int)(((char *)v6 - (char *)__first) & 0xFFFFFFFC) > 64 )
    {
      v6 = __first;
      continue;
    }
    break;
  }
}


void __cdecl stlp_std::priv::__introsort_loop<char const * *,char const *,int,bool (__cdecl *)(char const *,char const *)>(
        survarium::anomaly_state **__first,
        survarium::anomaly_state **__last,
        survarium::anomaly_state **__formal,
        int __depth_limit,
        survarium::anomaly_state **__comp)
{
  survarium::anomaly_state **v5; // eax
  survarium::anomaly_state **v7; // esi
  survarium::anomaly_state **v8; // edi
  char v9; // al
  survarium::anomaly_state **v10; // edi
  survarium::anomaly_state **i; // esi
  survarium::anomaly_state *v12; // eax
  survarium::anomaly_state *v13; // [esp-Ch] [ebp-10h]
  survarium::anomaly_state **__firsta; // [esp+Ch] [ebp+8h]

  v5 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
    return;
  while ( 2 )
  {
    if ( !__depth_limit )
    {
      stlp_std::priv::__partial_sort<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        __first,
        v5,
        v5,
        __comp);
      return;
    }
    --__depth_limit;
    v7 = v5 - 1;
    v8 = &__first[(v5 - __first) / 2];
    v9 = ((int (__cdecl *)(_DWORD, survarium::anomaly_state *))__comp)(*__first, *v8);
    v13 = *v7;
    if ( !v9 )
    {
      if ( ((unsigned __int8 (__cdecl *)(_DWORD, survarium::anomaly_state *))__comp)(*__first, v13) )
        goto LABEL_8;
      if ( ((unsigned __int8 (__cdecl *)(survarium::anomaly_state *, survarium::anomaly_state *))__comp)(*v8, *v7) )
        goto LABEL_12;
LABEL_11:
      v7 = v8;
      goto LABEL_12;
    }
    if ( ((unsigned __int8 (__cdecl *)(survarium::anomaly_state *, survarium::anomaly_state *))__comp)(*v8, v13) )
      goto LABEL_11;
    if ( !((unsigned __int8 (__cdecl *)(_DWORD, survarium::anomaly_state *))__comp)(*__first, *v7) )
LABEL_8:
      v7 = __first;
LABEL_12:
    v10 = __last;
    __firsta = (survarium::anomaly_state **)*v7;
    for ( i = __first; ; ++i )
    {
      if ( ((unsigned __int8 (__cdecl *)(survarium::anomaly_state *, survarium::anomaly_state **))__comp)(*i, __firsta) )
        continue;
      do
        --v10;
      while ( ((unsigned __int8 (__cdecl *)(survarium::anomaly_state **, survarium::anomaly_state *))__comp)(
                __firsta,
                *v10) );
      if ( i >= v10 )
        break;
      v12 = *i;
      *i = *v10;
      *v10 = v12;
    }
    stlp_std::priv::__introsort_loop<char const * *,char const *,int,bool (__cdecl *)(char const *,char const *)>(
      i,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = i;
    if ( (int)(((char *)i - (char *)__first) & 0xFFFFFFFC) > 64 )
    {
      v5 = i;
      continue;
    }
    break;
  }
}


void __usercall stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::render::shader_macros_dort_predicate>(
        vostok::render::shader_macros_dort_predicate *a1@<edi>,
        const char **__first,
        const char **__last,
        const char **__formal,
        int __depth_limit,
        const char **__comp)
{
  const char **v6; // eax
  const char **v8; // esi
  const char **v9; // edi
  bool v10; // al
  const char *v11; // ecx
  const char **v12; // edi
  const char **i; // esi
  const char *v14; // eax
  vostok::render::shader_macros_dort_predicate *v15; // [esp-8h] [ebp-Ch]
  vostok::render::shader_macros_dort_predicate *v16; // [esp-8h] [ebp-Ch]
  const char *__firsta; // [esp+Ch] [ebp+8h]

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
    return;
  v15 = a1;
  while ( 2 )
  {
    if ( !__depth_limit )
    {
      stlp_std::priv::__partial_sort<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
        __first,
        v6,
        v6,
        __comp);
      return;
    }
    --__depth_limit;
    v8 = v6 - 1;
    v9 = &__first[(v6 - __first) / 2];
    v10 = vostok::render::shader_macros_dort_predicate::operator()(*__first, *v9, v15);
    v11 = *v8;
    if ( !v10 )
    {
      if ( vostok::render::shader_macros_dort_predicate::operator()(*__first, v11, v16) )
        goto LABEL_8;
      if ( vostok::render::shader_macros_dort_predicate::operator()(*v9, *v8, v15) )
        goto LABEL_12;
LABEL_11:
      v8 = v9;
      goto LABEL_12;
    }
    if ( vostok::render::shader_macros_dort_predicate::operator()(*v9, v11, v16) )
      goto LABEL_11;
    if ( !vostok::render::shader_macros_dort_predicate::operator()(*__first, *v8, v15) )
LABEL_8:
      v8 = __first;
LABEL_12:
    v12 = __last;
    __firsta = *v8;
    for ( i = __first; ; ++i )
    {
      if ( vostok::render::shader_macros_dort_predicate::operator()(*i, __firsta, v15) )
        continue;
      do
        --v12;
      while ( vostok::render::shader_macros_dort_predicate::operator()(__firsta, *v12, v15) );
      if ( i >= v12 )
        break;
      v14 = *i;
      *i = *v12;
      *v12 = v14;
    }
    stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::render::shader_macros_dort_predicate>(
      (vostok::render::shader_macros_dort_predicate *)v12,
      i,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = i;
    if ( (int)(((char *)i - (char *)__first) & 0xFFFFFFFC) > 64 )
    {
      v6 = i;
      continue;
    }
    break;
  }
}


void __cdecl stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::tips_sorting_predicate>(
        char **__first,
        const char **__last,
        const char **__formal,
        int __depth_limit,
        vostok::tips_sorting_predicate __comp)
{
  vostok::tips_sorting_predicate *a1; // ecx
  const char **v7; // ebx
  char **v8; // esi
  vostok::tips_sorting_predicate *v9; // ecx
  char *v10; // ecx
  char *v11; // eax
  char **v12; // esi
  const char *v13; // eax
  vostok::tips_sorting_predicate v14; // [esp+4h] [ebp-8h] BYREF
  char *editor_str; // [esp+8h] [ebp-4h] BYREF

  v7 = (const char **)__first;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
    return;
  while ( 2 )
  {
    if ( !__depth_limit )
    {
      stlp_std::priv::__partial_sort<char const * *,char const *,vostok::tips_sorting_predicate>(
        v7,
        (char **)__last,
        (char **)__last,
        (vostok::tips_sorting_predicate *)__comp.editor_str);
      return;
    }
    --__depth_limit;
    editor_str = (char *)__comp.editor_str;
    v8 = (char **)&v7[(__last - v7) / 2];
    if ( vostok::tips_sorting_predicate::operator()(a1, (unsigned __int8 **)&editor_str, (char *)*v7, *v8) )
    {
      if ( vostok::tips_sorting_predicate::operator()(v9, (unsigned __int8 **)&editor_str, *v8, (char *)*(__last - 1)) )
        goto LABEL_12;
      v8 = (char **)(__last - 1);
      if ( vostok::tips_sorting_predicate::operator()(
             (vostok::tips_sorting_predicate *)v10,
             (unsigned __int8 **)&editor_str,
             (char *)*v7,
             (char *)*(__last - 1)) )
      {
        goto LABEL_12;
      }
    }
    else if ( !vostok::tips_sorting_predicate::operator()(
                 v9,
                 (unsigned __int8 **)&editor_str,
                 (char *)*v7,
                 (char *)*(__last - 1)) )
    {
      if ( vostok::tips_sorting_predicate::operator()(
             (vostok::tips_sorting_predicate *)v10,
             (unsigned __int8 **)&editor_str,
             *v8,
             (char *)*(__last - 1)) )
      {
        v8 = (char **)(__last - 1);
      }
      goto LABEL_12;
    }
    v8 = (char **)v7;
LABEL_12:
    v14.editor_str = __comp.editor_str;
    v11 = *v8;
    v12 = (char **)__last;
    editor_str = v11;
    while ( 1 )
    {
      if ( vostok::tips_sorting_predicate::operator()(
             (vostok::tips_sorting_predicate *)v10,
             (unsigned __int8 **)&v14,
             (char *)*v7,
             editor_str) )
      {
        goto LABEL_13;
      }
      do
        --v12;
      while ( vostok::tips_sorting_predicate::operator()(
                (vostok::tips_sorting_predicate *)v10,
                (unsigned __int8 **)&v14,
                editor_str,
                *v12) );
      if ( v7 >= (const char **)v12 )
        break;
      v10 = *v12;
      v13 = *v7;
      *v7 = *v12;
      *v12 = (char *)v13;
LABEL_13:
      ++v7;
    }
    stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::tips_sorting_predicate>(
      (vostok::tips_sorting_predicate *)v10,
      (vostok::tips_sorting_predicate)&v14,
      (char **)v7,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = v7;
    if ( (int)(((char *)v7 - (char *)__first) & 0xFFFFFFFC) > 64 )
    {
      v7 = (const char **)__first;
      continue;
    }
    break;
  }
}


void __cdecl stlp_std::priv::__introsort_loop<void const * *,void const *,int,stlp_std::less<void const *>>(
        survarium::single_game_effect **__first,
        survarium::single_game_effect **__last,
        survarium::single_game_effect **__formal,
        int __depth_limit,
        survarium::single_game_effect **__comp)
{
  survarium::single_game_effect **v6; // eax
  survarium::single_game_effect **v7; // ecx
  unsigned int v8; // ebx
  survarium::single_game_effect *v9; // edx
  survarium::single_game_effect **v10; // eax
  survarium::single_game_effect *v11; // edi
  survarium::single_game_effect *v12; // ecx
  survarium::single_game_effect **v13; // eax
  survarium::single_game_effect **i; // edi
  survarium::single_game_effect *v15; // edx

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<void const * *,void const *,stlp_std::less<void const *>>(__first, v6, v6);
        return;
      }
      --__depth_limit;
      v7 = v6 - 1;
      v8 = (unsigned int)*(v6 - 1);
      v9 = *__first;
      v10 = &__first[(v6 - __first) / 2];
      v11 = *v10;
      if ( *__first >= *v10 )
      {
        if ( (unsigned int)v9 < v8 )
          goto LABEL_6;
        if ( (unsigned int)v11 < v8 )
LABEL_9:
          v10 = v7;
      }
      else if ( (unsigned int)v11 >= v8 )
      {
        if ( (unsigned int)v9 < v8 )
          goto LABEL_9;
LABEL_6:
        v10 = __first;
      }
      v12 = *v10;
      v13 = __last;
      for ( i = __first; ; ++i )
      {
        if ( *i < v12 )
          continue;
        do
          --v13;
        while ( v12 < *v13 );
        if ( i >= v13 )
          break;
        v15 = *i;
        *i = *v13;
        *v13 = v15;
      }
      stlp_std::priv::__introsort_loop<void const * *,void const *,int,stlp_std::less<void const *>>(
        (stlp_std::less<survarium::single_game_effect *>)i,
        i,
        __last,
        0,
        __depth_limit,
        __comp);
      v6 = i;
      __last = i;
    }
    while ( (int)(((char *)i - (char *)__first) & 0xFFFFFFFC) > 64 );
  }
}


void __cdecl stlp_std::priv::__introsort_loop<survarium::relocate_item_descr *,survarium::relocate_item_descr,int,survarium::ammo_slots_sort>(
        survarium::relocate_item_descr *__first,
        survarium::relocate_item_descr *__last,
        survarium::relocate_item_descr *__formal,
        int __depth_limit,
        survarium::ammo_slots_sort __comp)
{
  survarium::relocate_item_descr *v5; // eax
  survarium::relocate_item_descr *v6; // ebx
  const survarium::relocate_item_descr *v7; // edi
  const survarium::relocate_item_descr *v8; // esi
  survarium::relocate_item_descr *v9; // eax
  bool v10; // zf
  const survarium::relocate_item_descr *v11; // esi
  survarium::relocate_item_descr *v12; // edi
  survarium::ammo_slots_sort v13; // [esp-8h] [ebp-50h]
  unsigned int item_id; // [esp+Ch] [ebp-3Ch]
  unsigned int v15; // [esp+10h] [ebp-38h]
  unsigned int amount; // [esp+14h] [ebp-34h]
  unsigned int amount_in_inventory; // [esp+18h] [ebp-30h]
  survarium::relocate_item_descr v18; // [esp+1Ch] [ebp-2Ch] BYREF
  survarium::ammo_slots_sort v19; // [esp+2Ch] [ebp-1Ch] BYREF
  survarium::ammo_slots_sort v20; // [esp+38h] [ebp-10h] BYREF
  survarium::relocate_item_descr *v21; // [esp+44h] [ebp-4h]

  v5 = __last;
  v6 = __first;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFF0) <= 256 )
    return;
  while ( 2 )
  {
    if ( !__depth_limit )
    {
      *(_QWORD *)&v13.m_dict = *(_QWORD *)__comp.m_weapon_ids;
      stlp_std::priv::__partial_sort<survarium::relocate_item_descr *,survarium::relocate_item_descr,survarium::ammo_slots_sort>(
        v6,
        v5,
        v5,
        __comp.m_dict,
        v13);
      return;
    }
    --__depth_limit;
    v20 = __comp;
    v7 = v5 - 1;
    v8 = &v6[(v5 - v6) / 2];
    if ( !survarium::ammo_slots_sort::operator()(&v20, v6, v8) )
    {
      if ( survarium::ammo_slots_sort::operator()(&v20, v6, v7) )
        goto LABEL_9;
      v10 = !survarium::ammo_slots_sort::operator()(&v20, v8, v7);
      v9 = (survarium::relocate_item_descr *)v7;
      if ( !v10 )
        goto LABEL_13;
LABEL_12:
      v9 = (survarium::relocate_item_descr *)v8;
      goto LABEL_13;
    }
    if ( survarium::ammo_slots_sort::operator()(&v20, v8, v7) )
      goto LABEL_12;
    if ( !survarium::ammo_slots_sort::operator()(&v20, v6, v7) )
    {
LABEL_9:
      v9 = v6;
      goto LABEL_13;
    }
    v9 = (survarium::relocate_item_descr *)v7;
LABEL_13:
    v19 = __comp;
    v18 = *v9;
    v21 = __last;
    while ( 1 )
    {
      if ( survarium::ammo_slots_sort::operator()(&v19, v6, &v18) )
        goto LABEL_14;
      do
        --v21;
      while ( survarium::ammo_slots_sort::operator()(&v19, &v18, v21) );
      if ( v6 >= v21 )
        break;
      item_id = v6->item_id;
      v15 = *(_DWORD *)&v6->item_dict_id;
      amount = v6->amount;
      amount_in_inventory = v6->amount_in_inventory;
      v11 = v21;
      v6->item_id = v21->item_id;
      v11 = (const survarium::relocate_item_descr *)((char *)v11 + 4);
      *(_DWORD *)&v6->item_dict_id = v11->item_id;
      v11 = (const survarium::relocate_item_descr *)((char *)v11 + 4);
      v6->amount = v11->item_id;
      v6->amount_in_inventory = *(_DWORD *)&v11->item_dict_id;
      v12 = v21;
      v21->item_id = item_id;
      v12 = (survarium::relocate_item_descr *)((char *)v12 + 4);
      v12->item_id = v15;
      v12 = (survarium::relocate_item_descr *)((char *)v12 + 4);
      v12->item_id = amount;
      *(_DWORD *)&v12->item_dict_id = amount_in_inventory;
LABEL_14:
      ++v6;
    }
    stlp_std::priv::__introsort_loop<survarium::relocate_item_descr *,survarium::relocate_item_descr,int,survarium::ammo_slots_sort>(
      v6,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = v6;
    if ( (int)(((char *)v6 - (char *)__first) & 0xFFFFFFF0) > 256 )
    {
      v6 = __first;
      v5 = __last;
      continue;
    }
    break;
  }
}


void __cdecl stlp_std::priv::__introsort_loop<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,int,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> *__last,
        vostok::math::curve_point<float> *__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  vostok::math::curve_point<float> *v6; // ecx
  vostok::math::curve_point<float> *v7; // ebx
  const vostok::math::curve_point<float> *v8; // edi
  const vostok::math::curve_point<float> *v9; // esi
  vostok::math::curve_point<float> *v10; // edi
  bool (__cdecl *v11)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *); // edi
  bool i; // al
  _BYTE v13[24]; // [esp+8h] [ebp-34h] BYREF
  vostok::math::curve_point<float> v14; // [esp+20h] [ebp-1Ch] BYREF
  const vostok::math::curve_point<float> *v15; // [esp+38h] [ebp-4h]

  v6 = __last;
  v7 = __first;
  if ( __last - __first > 16 )
  {
    while ( 1 )
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
          v7,
          v6,
          v6,
          (vostok::math::curve_point<float> *)__comp);
        return;
      }
      v8 = v6 - 1;
      --__depth_limit;
      v9 = &v7[(v6 - v7) / 2];
      if ( __comp(v7, v9) )
      {
        if ( !__comp(v9, v8) )
        {
          if ( __comp(v7, v8) )
            goto LABEL_11;
LABEL_8:
          v9 = v7;
        }
      }
      else
      {
        if ( __comp(v7, v8) )
          goto LABEL_8;
        if ( __comp(v9, v8) )
LABEL_11:
          v9 = v8;
      }
      v10 = &v14;
      v15 = __last;
      while ( 1 )
      {
        qmemcpy(v10, v9, sizeof(vostok::math::curve_point<float>));
        v11 = (bool (__cdecl *)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))&v10[1];
        for ( i = __comp(v7, &v14); i; i = __comp(v7, &v14) )
          ++v7;
        do
          --v15;
        while ( __comp(&v14, v15) );
        if ( v7 >= v15 )
          break;
        qmemcpy(v13, v7, sizeof(v13));
        qmemcpy(v7, v15, sizeof(vostok::math::curve_point<float>));
        v10 = (vostok::math::curve_point<float> *)v15;
        v9 = (const vostok::math::curve_point<float> *)v13;
        ++v7;
      }
      stlp_std::priv::__introsort_loop<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,int,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        v11,
        v7,
        __last,
        0,
        __depth_limit,
        __comp);
      __last = v7;
      if ( v7 - __first <= 16 )
        return;
      v7 = __first;
      v6 = __last;
    }
  }
}


void __cdecl stlp_std::priv::__introsort_loop<vostok::render::shader_constant *,vostok::render::shader_constant,int,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first,
        vostok::render::shader_constant *__last,
        vostok::render::shader_constant *__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  vostok::render::shader_constant *v5; // edi
  vostok::render::shader_constant *i; // eax
  const vostok::render::shader_constant *v7; // esi
  vostok::render::shader_constant *v8; // eax
  bool v9; // zf
  vostok::render::shader_constant *v10; // esi
  vostok::render::shader_constant v11; // [esp-1Ch] [ebp-28h]
  const vostok::render::shader_constant *v12; // [esp-4h] [ebp-10h]

  v5 = __last;
  for ( i = __last; i - __first > 16; i = v10 )
  {
    if ( !__depth_limit )
    {
      stlp_std::priv::__partial_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        v5,
        __first,
        v5,
        (vostok::render::shader_constant *)__comp);
      return;
    }
    --__depth_limit;
    v7 = &__first[(v5 - __first) / 2];
    v12 = v5 - 1;
    if ( ((unsigned __int8 (__cdecl *)(vostok::render::shader_constant *))__comp)(__first) )
    {
      if ( !__comp(v7, v12) )
      {
        v7 = v5 - 1;
        if ( !__comp(__first, v5 - 1) )
        {
LABEL_6:
          v8 = __first;
          goto LABEL_10;
        }
      }
LABEL_9:
      v8 = (vostok::render::shader_constant *)v7;
      goto LABEL_10;
    }
    if ( __comp(__first, v12) )
      goto LABEL_6;
    v9 = ((unsigned __int8 (__cdecl *)(const vostok::render::shader_constant *))__comp)(v7) == 0;
    v8 = v5 - 1;
    if ( v9 )
      goto LABEL_9;
LABEL_10:
    v11.m_slot.m_value = v8->m_slot.m_value;
    v11.m_source.m_pointer = v8->m_source.m_pointer;
    v11.m_source.m_size = v8->m_source.m_size;
    v11.m_host = v8->m_host;
    v10 = stlp_std::priv::__unguarded_partition<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
            __first,
            v5,
            v11,
            __comp);
    stlp_std::priv::__introsort_loop<vostok::render::shader_constant *,vostok::render::shader_constant,int,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      v10,
      v5,
      0,
      __depth_limit,
      __comp);
    v5 = v10;
  }
}
