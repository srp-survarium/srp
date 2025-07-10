void __usercall survarium::network_client::process_shop_action(survarium::network_client *this@<ecx>, _DWORD *a2@<edi>)
{
  _BYTE *v2; // eax
  char v3; // dl
  _WORD *v4; // eax
  __int16 v5; // dx
  int *v6; // eax
  int v7; // ebx
  unsigned int v8; // ebp
  _DWORD *v9; // esi
  _DWORD *v10; // eax
  int (__thiscall *v11)(_DWORD *); // edx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  lobby::query_info_types v15; // eax
  survarium::lobby_client *v16; // ecx
  bool v17; // [esp+0h] [ebp-34h]
  __int64 new_item_8; // [esp+18h] [ebp-1Ch]
  survarium::inventory_item_instance __x; // [esp+20h] [ebp-14h] BYREF

  v2 = *(_BYTE **)&this->m_use_physics_controller_for_current;
  v3 = *v2;
  v4 = v2 + 1;
  *(_DWORD *)&this->m_use_physics_controller_for_current = v4;
  if ( !v3 )
  {
    v5 = *v4;
    v6 = (int *)(v4 + 1);
    *(_DWORD *)&this->m_use_physics_controller_for_current = v6;
    v7 = *v6++;
    *(_DWORD *)&this->m_use_physics_controller_for_current = v6;
    v8 = *v6;
    *(_DWORD *)&this->m_use_physics_controller_for_current = v6 + 1;
    WORD2(new_item_8) = v5;
    LODWORD(new_item_8) = v7;
    v9 = *(_DWORD **)((*(int (__thiscall **)(_DWORD *))(*a2 + 60))(a2) + 1928);
    v10 = *(_DWORD **)((*(int (__thiscall **)(_DWORD *))(*a2 + 60))(a2) + 1932);
    if ( v9 == v10 )
    {
LABEL_5:
      v11 = *(int (__thiscall **)(_DWORD *))(*a2 + 60);
      *(_QWORD *)&__x.condition_or_stack = v8;
      *(_QWORD *)&__x.id = new_item_8;
      v12 = v11(a2);
      v13 = *(_DWORD *)(v12 + 1932);
      v14 = v12 + 1928;
      if ( v13 == *(_DWORD *)(v14 + 12) )
      {
        stlp_std::priv::_Impl_vector<survarium::inventory_item_instance,vostok::vectora_allocator<survarium::inventory_item_instance>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<survarium::inventory_item_instance,vostok::vectora_allocator<survarium::inventory_item_instance> > *)v13,
          (unsigned __int8 **)v14,
          (survarium::inventory_item_instance *)v13,
          &__x,
          (const stlp_std::__true_type *)1,
          1,
          v17);
      }
      else
      {
        if ( v13 )
        {
          *(_QWORD *)v13 = v8;
          *(_QWORD *)(v13 + 8) = new_item_8;
        }
        *(_DWORD *)(v14 + 4) += 16;
      }
    }
    else
    {
      while ( v9[2] != v7 )
      {
        v9 += 4;
        if ( v9 == v10 )
          goto LABEL_5;
      }
      *v9 += v8;
    }
    survarium::lobby_menu::fill_inventory_contents(*(survarium::lobby_menu **)(a2[6] + 884));
    v15 = (*(int (__thiscall **)(_DWORD *, int))(*a2 + 60))(a2, 7);
    survarium::lobby_client::query_client_status(v16, v15);
  }
}
