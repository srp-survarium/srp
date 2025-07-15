void __thiscall survarium::animation_space_graph_cook::generate_graph_edges(
        survarium::animation_space_graph_cook *this)
{
  vostok::resources::cook_base *v2; // ebx
  void *v3; // esp
  char *v4; // eax
  char *v5; // ecx
  unsigned int v6; // edx
  char *v7; // edi
  int v8; // ebx
  vostok::animation::animation_player *p_m_class_id; // ecx
  unsigned int v10; // ebx
  _DWORD *v11; // esi
  int v12; // edi
  int v13; // edx
  _DWORD *v14; // ecx
  int v15; // eax
  _DWORD *v16; // eax
  unsigned int v17; // ecx
  const survarium::animation_space_vertex **v18; // edi
  const survarium::animation_space_vertex *v19; // eax
  double v20; // st7
  vostok::resources::cook_base *v21; // esi
  const survarium::animation_space_vertex *v22; // ecx
  survarium::animation_space_vertex_id *movement; // eax
  float length; // xmm1_4
  __int64 v25; // xmm3_8
  __int64 v26; // xmm4_8
  __int64 v27; // xmm5_8
  float z; // eax
  float v29; // xmm2_4
  float v30; // xmm0_4
  vostok::animation::mixing::n_ary_tree *v31; // ecx
  float left_weight; // [esp+0h] [ebp-8594h]
  _BYTE v33[16]; // [esp+4h] [ebp-8590h] BYREF
  vostok::animation::animation_player player; // [esp+14h] [ebp-8580h] BYREF
  survarium::animation_space_vertex_id result; // [esp+855Ch] [ebp-38h] BYREF
  char *v36; // [esp+857Ch] [ebp-18h]
  int v37; // [esp+8580h] [ebp-14h]
  _BYTE *v38; // [esp+8584h] [ebp-10h]
  float v39; // [esp+8588h] [ebp-Ch]
  unsigned int v40; // [esp+858Ch] [ebp-8h]
  vostok::resources::cook_base *m_next; // [esp+8590h] [ebp-4h]

  m_next = this[7].m_next;
  v2 = m_next;
  v3 = alloca(4 * (_DWORD)m_next);
  v4 = (char *)&this[8] + 292 * this[7].m_flags.m_flags;
  v5 = &v4[8 * (_DWORD)m_next];
  v6 = 0;
  v7 = v33;
  v38 = v33;
  v36 = v4;
  v40 = 0;
  if ( v4 != v5 )
  {
    while ( 1 )
    {
      if ( v7 )
        *(_DWORD *)v7 = v6;
      v8 = *(_DWORD *)(*(_DWORD *)v4 + 288);
      v4 += 8;
      v7 += 4;
      v40 = v6 + v8 + 1;
      if ( v4 == v5 )
        break;
      v6 = v40;
    }
    v2 = m_next;
  }
  m_next = (survarium::animation_space_graph_cook *)((char *)this + 292 * this[7].m_flags.m_flags + 8 * (_DWORD)v2 + 288);
  vostok::animation::animation_player::animation_player((vostok::animation::animation_player *)m_next, (int)&player);
  v10 = 0;
  if ( v40 )
  {
    v11 = v38;
    v12 = (v7 - v38) >> 2;
    v37 = v12;
    while ( 1 )
    {
      v13 = v12;
      v14 = v11;
      while ( v13 > 0 )
      {
        v15 = v13 >> 1;
        if ( v14[v13 >> 1] >= v10 )
        {
          v13 >>= 1;
        }
        else
        {
          v14 += v15 + 1;
          v13 += -1 - v15;
        }
      }
      v16 = v14;
      if ( *v14 == v10 )
      {
        v17 = v10;
      }
      else if ( v14 == v11 )
      {
        v17 = 0;
      }
      else
      {
        v16 = v14 - 1;
        v17 = *(v14 - 1);
      }
      v18 = (const survarium::animation_space_vertex **)&v36[8 * (v16 - v11)];
      v19 = *v18;
      v20 = 1.0 / (double)(*v18)->intervals_count * (double)(v10 - v17);
      v21 = m_next;
      p_m_class_id = (vostok::animation::animation_player *)&m_next[1].m_class_id;
      v39 = v20;
      m_next = (vostok::resources::cook_base *)((char *)m_next + 40);
      if ( v21 )
      {
        left_weight = *(float *)&p_m_class_id;
        v22 = v18[1];
        left_weight = v20;
        movement = survarium::animation_space_graph::get_movement(&result, &player, v19, v22, left_weight);
        p_m_class_id = *(vostok::animation::animation_player **)v18;
        length = (*v18)->length;
        v25 = *(_QWORD *)&movement->rotation.x;
        v26 = *(_QWORD *)&movement->rotation.vector.elements[2];
        v27 = *(_QWORD *)&movement->translation.x;
        z = movement->translation.z;
        v29 = v39;
        v30 = (float)(*(float *)&clear_value - v39) * v18[1]->length;
        *(_QWORD *)&v21->__vftable = v25;
        *(_QWORD *)&v21->m_class_id = v26;
        *(_QWORD *)&v21->m_creation_thread_id = v27;
        *(float *)&v21->m_flags.m_flags = z;
        v21->m_next = (vostok::resources::cook_base *)v18;
        *(float *)&v21[1].__vftable = v29;
        *(float *)&v21[1].m_cook_users_count.m_count = (float)(v30 + (float)(length * v29)) / length;
      }
      if ( ++v10 >= v40 )
        break;
      v12 = v37;
      v11 = v38;
    }
  }
  vostok::animation::animation_player::reset(p_m_class_id, &player, 1);
  vostok::animation::mixing::n_ary_tree::destroy(v31, (int)&player.m_mixing_tree);
  if ( player.m_mixing_tree.m_reference_counter.m_object )
    --player.m_mixing_tree.m_reference_counter.m_object->m_reference_count;
}
