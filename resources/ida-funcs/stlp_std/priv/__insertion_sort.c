void __cdecl stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        unsigned int *__first,
        unsigned int *__last,
        unsigned int *__formal)
{
  unsigned __int8 *v3; // ebx
  unsigned int *v4; // esi
  unsigned int *v5; // ecx
  unsigned int v6; // edi
  unsigned int *i; // edx
  unsigned int *v8; // [esp+4h] [ebp-4h]

  v3 = (unsigned __int8 *)__first;
  if ( __first != __last )
  {
    v4 = __first + 1;
    if ( __first + 1 != __last )
    {
      v5 = __formal;
      do
      {
        v6 = *v4;
        if ( *(float *)&v5[*(_DWORD *)v3] <= *(float *)&v5[*v4] )
        {
          v8 = v4;
          for ( i = v4 - 1; *(float *)&v5[*i] > *(float *)&v5[v6]; --i )
          {
            *v8 = *i;
            v3 = (unsigned __int8 *)__first;
            v8 = i;
          }
          *v8 = v6;
        }
        else
        {
          stlp_std::priv::__copy_trivial_backward(v3, v4, (char *)v4 + 4);
          v5 = __formal;
          *(_DWORD *)v3 = v6;
        }
        ++v4;
      }
      while ( v4 != __last );
    }
  }
}


void __cdecl stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        unsigned __int8 *__first,
        unsigned __int8 *__last)
{
  unsigned __int8 *i; // esi
  unsigned int v3; // edi
  unsigned __int8 *v4; // edx
  unsigned __int8 *j; // eax

  if ( __first != __last )
  {
    for ( i = __first + 4; i != __last; i += 4 )
    {
      v3 = *(_DWORD *)i;
      if ( *(_DWORD *)i >= *(_DWORD *)__first )
      {
        v4 = i;
        for ( j = i - 4; v3 < *(_DWORD *)j; j -= 4 )
        {
          *(_DWORD *)v4 = *(_DWORD *)j;
          v4 = j;
        }
        *(_DWORD *)v4 = v3;
      }
      else
      {
        stlp_std::priv::__copy_trivial_backward(__first, i, (char *)i + 4);
        *(_DWORD *)__first = v3;
      }
    }
  }
}


void __usercall stlp_std::priv::__insertion_sort<float *,float,stlp_std::less<float>>(
        float *__first@<edi>,
        float *__last)
{
  float *i; // esi
  float v3; // xmm1_4
  float *v4; // ecx
  float *j; // eax
  float v6; // [esp+0h] [ebp-4h]

  if ( __first != __last )
  {
    for ( i = __first + 1; i != __last; ++i )
    {
      v3 = *i;
      v6 = *i;
      if ( *__first <= *i )
      {
        v4 = i;
        for ( j = i - 1; *j > v3; --j )
        {
          *v4 = *j;
          v4 = j;
        }
        *v4 = v3;
      }
      else
      {
        stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__first, i, (char *)i + 4);
        *__first = v6;
      }
    }
  }
}


void __usercall stlp_std::priv::__insertion_sort<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        survarium::anomaly_state **__first@<edi>,
        survarium::anomaly_state **__last)
{
  survarium::anomaly_state **i; // esi
  survarium::anomaly_state *v4; // ebx

  for ( i = __first + 1; i != __last; ++i )
  {
    v4 = *i;
    if ( (unsigned __int8)survarium::state_prio(*i, *__first) )
    {
      stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__first, i, (char *)i + 4);
      *__first = v4;
    }
    else
    {
      stlp_std::priv::__unguarded_linear_insert<survarium::anomaly_state * *,survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        i,
        v4);
    }
  }
}


void __cdecl stlp_std::priv::__insertion_sort<survarium::victory_item_spawner * *,survarium::victory_item_spawner *,survarium::priority_less>(
        survarium::victory_item_spawner **__first,
        survarium::victory_item_spawner **__last)
{
  unsigned __int8 *v2; // ebx
  survarium::victory_item_spawner **i; // esi
  survarium::victory_item_spawner *v4; // edi
  unsigned int priority; // edx
  survarium::victory_item_spawner **v6; // ebx
  survarium::victory_item_spawner **j; // eax

  v2 = (unsigned __int8 *)__first;
  if ( __first != __last )
  {
    for ( i = __first + 1; i != __last; ++i )
    {
      v4 = *i;
      priority = (*i)->priority;
      if ( priority <= *(_DWORD *)(*(_DWORD *)v2 + 24) )
      {
        v6 = i;
        for ( j = i - 1; priority > (*j)->priority; --j )
        {
          *v6 = *j;
          priority = v4->priority;
          v6 = j;
        }
        *v6 = v4;
        v2 = (unsigned __int8 *)__first;
      }
      else
      {
        stlp_std::priv::__copy_trivial_backward(v2, i, (char *)i + 4);
        *(_DWORD *)v2 = v4;
      }
    }
  }
}


void __usercall stlp_std::priv::__insertion_sort<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
        vostok::command_line::key_compare_predicate *a1@<edi>,
        vostok::command_line::key **__first,
        vostok::command_line::key **__last)
{
  vostok::command_line::key **v3; // ebx
  vostok::command_line::key *v4; // esi
  vostok::command_line::key_compare_predicate *v5; // [esp-8h] [ebp-10h]

  v3 = __first + 1;
  if ( __first + 1 != __last )
  {
    v5 = a1;
    do
    {
      v4 = *v3;
      if ( vostok::command_line::key_compare_predicate::operator()(*v3, *__first, v5) )
      {
        stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__first, v3, (char *)v3 + 4);
        *__first = v4;
      }
      else
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::command_line::key * *,vostok::command_line::key *,vostok::command_line::key_compare_predicate>(
          v4,
          v3);
      }
      ++v3;
    }
    while ( v3 != __last );
  }
}


void __usercall stlp_std::priv::__insertion_sort<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        const char **__first@<edi>,
        const char **__last)
{
  const char **i; // esi
  const char *v4; // ebx

  for ( i = __first + 1; i != __last; ++i )
  {
    v4 = *i;
    if ( vostok::strings::less((char *)*i, (char *)*__first) )
    {
      stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__first, i, (char *)i + 4);
      *__first = v4;
    }
    else
    {
      stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        i,
        v4);
    }
  }
}


void __usercall stlp_std::priv::__insertion_sort<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
        const char **__first@<edi>,
        vostok::render::shader_macros_dort_predicate *a2@<ebx>,
        const char **__last)
{
  const char **v3; // esi
  const char *v4; // ebx
  vostok::render::shader_macros_dort_predicate *v5; // [esp-4h] [ebp-Ch]

  v3 = __first + 1;
  if ( __first + 1 != __last )
  {
    v5 = a2;
    do
    {
      v4 = *v3;
      if ( vostok::render::shader_macros_dort_predicate::operator()(*v3, *__first, v5) )
      {
        stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__first, v3, (char *)v3 + 4);
        *__first = v4;
      }
      else
      {
        stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
          v3,
          v4);
      }
      ++v3;
    }
    while ( v3 != __last );
  }
}


void __cdecl stlp_std::priv::__insertion_sort<char const * *,char const *,vostok::tips_sorting_predicate>(
        const char **__first,
        const char **__last,
        const char ***a3)
{
  vostok::tips_sorting_predicate *v3; // ecx
  unsigned __int8 *v4; // ebx
  const char **i; // esi
  char *v6; // [esp-8h] [ebp-14h]
  char *__val; // [esp+8h] [ebp-4h]

  v4 = (unsigned __int8 *)__first;
  for ( i = __first + 1; i != __last; ++i )
  {
    v6 = *(char **)v4;
    __first = *a3;
    __val = (char *)*i;
    if ( vostok::tips_sorting_predicate::operator()(v3, (unsigned __int8 **)&__first, (char *)*i, v6) )
    {
      stlp_std::priv::__copy_trivial_backward(v4, i, (char *)i + 4);
      *(_DWORD *)v4 = __val;
    }
    else
    {
      stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
        i,
        __val,
        (vostok::tips_sorting_predicate)__first);
    }
  }
}


void __cdecl stlp_std::priv::__insertion_sort<survarium::relocate_item_descr *,survarium::relocate_item_descr,survarium::ammo_slots_sort>(
        survarium::relocate_item_descr *__first,
        survarium::relocate_item_descr *__last,
        survarium::relocate_item_descr *a3)
{
  survarium::relocate_item_descr *v3; // ebx
  survarium::ammo_slots_sort v4; // [esp-Ch] [ebp-34h]
  survarium::relocate_item_descr v5; // [esp+Ch] [ebp-1Ch] BYREF
  survarium::ammo_slots_sort v6; // [esp+1Ch] [ebp-Ch] BYREF

  v3 = __first;
  while ( ++v3 != __last )
  {
    v6.m_dict = (const survarium::items_dictionary *)a3->item_id;
    v6.m_weapon_ids[0] = *(_DWORD *)&a3->item_dict_id;
    v6.m_weapon_ids[1] = a3->amount;
    v5 = *v3;
    if ( survarium::ammo_slots_sort::operator()(&v6, &v5, __first) )
    {
      stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__first, v3, (char *)&v3[1]);
      *__first = v5;
    }
    else
    {
      v4.m_dict = (const survarium::items_dictionary *)a3->item_id;
      *(_QWORD *)v4.m_weapon_ids = *(_QWORD *)&a3->item_dict_id;
      stlp_std::priv::__unguarded_linear_insert<survarium::relocate_item_descr *,survarium::relocate_item_descr,survarium::ammo_slots_sort>(
        v3,
        *v3,
        v4);
    }
  }
}


void __cdecl stlp_std::priv::__insertion_sort<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        vostok::math::curve_point<float> *__first,
        vostok::math::curve_point<float> *__last)
{
  vostok::math::curve_point<float> *v2; // ebx
  vostok::math::curve_point<float> v3; // [esp-18h] [ebp-3Ch] BYREF
  vostok::math::curve_point<float> v4; // [esp+Ch] [ebp-18h] BYREF

  v2 = __first;
  while ( ++v2 != __last )
  {
    qmemcpy(&v4, v2, sizeof(v4));
    if ( vostok::math::curve_line_points_float_0_::sort_points_by_time_::_5_::predicate::compare(&v4, __first) )
    {
      stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__first, v2, (char *)&v2[1]);
      qmemcpy(__first, &v4, sizeof(vostok::math::curve_point<float>));
    }
    else
    {
      qmemcpy(&v3, v2, sizeof(v3));
      stlp_std::priv::__unguarded_linear_insert<vostok::math::curve_point<float> *,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
        v2,
        v3);
    }
  }
}


void __usercall stlp_std::priv::__insertion_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first@<edi>,
        vostok::render::shader_constant *__last)
{
  vostok::render::shader_constant *i; // esi
  vostok::render::shader_constant v3; // [esp-18h] [ebp-1Ch]

  for ( i = __first + 1; i != __last; ++i )
  {
    v3.m_slot.m_value = i->m_slot.m_value;
    v3.m_source.m_pointer = i->m_source.m_pointer;
    v3.m_source.m_size = i->m_source.m_size;
    v3.m_host = i->m_host;
    stlp_std::priv::__linear_insert<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
      __first,
      v3);
  }
}
