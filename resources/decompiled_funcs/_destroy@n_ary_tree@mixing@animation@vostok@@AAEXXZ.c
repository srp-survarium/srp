void __usercall vostok::animation::mixing::n_ary_tree::destroy(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        int a2@<eax>)
{
  _DWORD *v3; // esi
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // ebx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v7; // esi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *i; // edi
  int p_m_destruction_observer; // eax
  vostok::animation::mixing::n_ary_tree_destroyer tree_destroyer; // [esp+Ch] [ebp-4h] BYREF

  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
  {
    v4 = *(_DWORD **)a2;
    if ( **(_DWORD **)a2 <= 1u )
    {
      tree_destroyer.__vftable = (vostok::animation::mixing::n_ary_tree_destroyer_vtbl *)&vostok::animation::mixing::n_ary_tree_destroyer::`vftable';
      do
      {
        (*(void (__thiscall **)(_DWORD *, vostok::animation::mixing::n_ary_tree_destroyer *))(*v3 + 8))(
          v3,
          &tree_destroyer);
        v3 = (_DWORD *)v3[10];
      }
      while ( v3 );
      v5 = *(_DWORD **)(a2 + 12);
      v6 = &v5[*(_DWORD *)(a2 + 36)];
      *(_DWORD *)(a2 + 4) = 0;
      for ( *(_DWORD *)(a2 + 8) = 0; v5 != v6; ++v5 )
        (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)*v5 + 36))(*v5, 0);
      v7 = *(vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> **)(a2 + 16);
      for ( i = &v7[45 * *(_DWORD *)(a2 + 28)]; v7 != i; v7 += 45 )
      {
        if ( v7[20].m_object )
        {
          if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          {
            p_m_destruction_observer = (int)&v7[21].m_object[-1].m_destruction_observer;
            _InterlockedExchangeAdd((volatile signed __int32 *)(p_m_destruction_observer + 44), 0xFFFFFFFF);
            if ( *(_DWORD *)(p_m_destruction_observer + 16) )
            {
              if ( !*(_DWORD *)(p_m_destruction_observer + 44) )
              {
                _InterlockedExchangeAdd(
                  (volatile signed __int32 *)(*(_DWORD *)(p_m_destruction_observer + 16) + 40),
                  1u);
                *(_DWORD *)(p_m_destruction_observer + 16) = 0;
              }
            }
          }
        }
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(v7 + 20);
      }
    }
    else
    {
      *(_DWORD *)a2 = 0;
      if ( v4 )
        --*v4;
    }
  }
}
