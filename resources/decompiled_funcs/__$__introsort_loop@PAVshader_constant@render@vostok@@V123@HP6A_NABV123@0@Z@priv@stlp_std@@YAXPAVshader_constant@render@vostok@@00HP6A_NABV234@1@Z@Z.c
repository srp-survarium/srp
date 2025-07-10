void __cdecl stlp_std::priv::__introsort_loop<vostok::render::shader_constant *,vostok::render::shader_constant,int,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        vostok::render::shader_constant *__first,
        vostok::render::shader_constant *__last,
        vostok::render::shader_constant *__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const vostok::render::shader_constant *, const vostok::render::shader_constant *))
{
  vostok::render::shader_constant *v5; // ebx
  const vostok::render::shader_constant *v6; // esi
  bool v7; // zf
  vostok::render::shader_constant *v8; // ecx
  bool v9; // al
  vostok::render::shader_constant *v10; // esi
  vostok::render::shader_constant v11; // [esp-1Ch] [ebp-2Ch]
  const vostok::render::shader_constant *v12; // [esp-4h] [ebp-14h]
  bool (__cdecl *v13)(const vostok::render::shader_constant *, const vostok::render::shader_constant *); // [esp-4h] [ebp-14h]
  bool (__cdecl *v14)(const vostok::render::shader_constant *, const vostok::render::shader_constant *); // [esp+0h] [ebp-10h]

  v5 = __last;
  if ( __last - __first > 16 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
          __first,
          v5,
          v5,
          (vostok::render::shader_constant *)__comp,
          v14);
        return;
      }
      --__depth_limit;
      v6 = &__first[(v5 - __first) / 2];
      v7 = !__comp(__first, v6);
      v12 = v5 - 1;
      if ( v7 )
      {
        if ( __comp(__first, v12) )
        {
          v8 = __first;
        }
        else
        {
          v9 = __comp(v6, v5 - 1);
          v8 = v5 - 1;
          if ( !v9 )
            goto LABEL_10;
        }
      }
      else
      {
        if ( __comp(v6, v12) || (v6 = v5 - 1, __comp(__first, v5 - 1)) )
        {
LABEL_10:
          v8 = (vostok::render::shader_constant *)v6;
          goto LABEL_11;
        }
        v8 = __first;
      }
LABEL_11:
      *(unsigned __int64 *)((char *)&v11.m_slot.m_value + 4) = v8->m_slot.m_value;
      v11.m_source.m_size = (const unsigned int)v8->m_source.m_pointer;
      *(_QWORD *)&v11.m_host = *(_QWORD *)&v8->m_source.m_size;
      *(_DWORD *)&v11.m_slot.m_class_id = __comp;
      v10 = stlp_std::priv::__unguarded_partition<vostok::render::shader_constant *,vostok::render::shader_constant,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
              __first,
              v5,
              v11,
              v13);
      stlp_std::priv::__introsort_loop<vostok::render::shader_constant *,vostok::render::shader_constant,int,bool (__cdecl *)(vostok::render::shader_constant const &,vostok::render::shader_constant const &)>(
        v10,
        v5,
        0,
        __depth_limit,
        __comp);
      v5 = v10;
    }
    while ( v10 - __first > 16 );
  }
}
