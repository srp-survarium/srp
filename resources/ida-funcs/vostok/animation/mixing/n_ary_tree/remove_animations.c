void __thiscall vostok::animation::mixing::n_ary_tree::remove_animations(
        vostok::animation::mixing::n_ary_tree *this,
        const unsigned int target_time_in_ms,
        int a3)
{
  int v4; // esi
  void *v5; // esp
  int v6; // eax
  vostok::animation::mixing::animation_state *v7; // esi
  int v8; // ecx
  _DWORD *v9; // edx
  int v10; // eax
  int v11; // edi
  _DWORD *v12; // ecx
  int *v13; // edi
  int v14; // eax
  char *v15; // eax
  vostok::animation::mixing::bone_matrices_computer_data *v16; // edi
  double weight; // st7
  float *p_animation_interval_id; // esi
  int v19; // ecx
  _DWORD *v20; // edx
  int v21; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v22; // ecx
  vostok::animation::mixing::animation_state *v23; // edi
  int v24; // eax
  int v25; // ecx
  int *v26; // esi
  char *v27; // eax
  vostok::buffer_vector<void const *> *v28; // [esp-4h] [ebp-34h]
  vostok::resources::pinned_ptr_const<unsigned char> *v29; // [esp-4h] [ebp-34h]
  _BYTE v30[16]; // [esp+0h] [ebp-30h] BYREF
  char *v31; // [esp+10h] [ebp-20h] BYREF
  char *v32; // [esp+14h] [ebp-1Ch]
  _BYTE *v33; // [esp+18h] [ebp-18h]
  int *v34; // [esp+1Ch] [ebp-14h] BYREF
  void **v35; // [esp+20h] [ebp-10h] BYREF
  int *v36; // [esp+24h] [ebp-Ch] BYREF
  vostok::animation::mixing::animation_state *__val; // [esp+28h] [ebp-8h] BYREF
  vostok::animation::mixing::bone_matrices_computer_data *p_bone_matrices_computer; // [esp+2Ch] [ebp-4h]
  int v39; // [esp+38h] [ebp+8h]
  int *v40; // [esp+38h] [ebp+8h]
  int *v41; // [esp+3Ch] [ebp+Ch]

  v4 = 4 * *(_DWORD *)(target_time_in_ms + 36);
  v5 = alloca(v4);
  v36 = 0;
  v31 = v30;
  v32 = v30;
  v6 = *(_DWORD *)(target_time_in_ms + 4);
  v33 = &v30[v4];
  v7 = *(vostok::animation::mixing::animation_state **)(target_time_in_ms + 16);
  __val = v7;
  p_bone_matrices_computer = &v7->bone_matrices_computer;
  v39 = v6;
  if ( v6 )
  {
    do
    {
      if ( v7->event_iterator.m_value.event_time_in_ms == a3 && (v7->event_iterator.m_value.event_type & 2) != 0 )
      {
        v8 = *(_DWORD *)(target_time_in_ms + 32);
        __val = *(vostok::animation::mixing::animation_state **)(v6 + 28);
        stlp_std::remove<vostok::animation::mixing::animation_state * *,vostok::animation::mixing::animation_state *>(
          *(vostok::animation::mixing::animation_state ***)(target_time_in_ms + 20),
          &__val,
          (vostok::animation::mixing::animation_state **)(*(_DWORD *)(target_time_in_ms + 20) + 4 * v8));
        v9 = (_DWORD *)(target_time_in_ms + 8);
        v10 = *(_DWORD *)(target_time_in_ms + 8);
        v11 = 0;
        if ( v10 )
        {
          while ( 1 )
          {
            v12 = (_DWORD *)v39;
            if ( v10 == v39 )
              break;
            v11 = v10;
            v10 = *(_DWORD *)(v10 + 44);
            if ( !v10 )
              goto LABEL_12;
          }
          if ( v11 )
            v9 = (_DWORD *)(v11 + 44);
          *v9 = *(_DWORD *)(v10 + 44);
        }
        else
        {
          v12 = (_DWORD *)v39;
        }
LABEL_12:
        v13 = v36;
        v14 = v12[10];
        if ( v36 )
          v36[10] = v14;
        else
          *(_DWORD *)(target_time_in_ms + 4) = v14;
        v35 = &vostok::animation::mixing::n_ary_tree_destroyer::`vftable';
        (*(void (__thiscall **)(_DWORD *, void ***))(*v12 + 8))(v12, &v35);
        if ( v13 )
          v6 = v13[10];
        else
          v6 = *(_DWORD *)(target_time_in_ms + 4);
        --*(_DWORD *)(target_time_in_ms + 32);
      }
      else
      {
        v34 = *(int **)(v6 + 36);
        v36 = v34;
        v15 = stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>(
                v31,
                (int *)&v36,
                v32);
        if ( v15 == v32 )
        {
          vostok::buffer_vector<void const *>::push_back(v28, (int)&v31, (const void **)&v34);
          v7 = __val;
        }
        v16 = p_bone_matrices_computer;
        if ( v7 != (vostok::animation::mixing::animation_state *)p_bone_matrices_computer )
        {
          vostok::animation::mixing::bone_matrices_computer_data::operator=(
            &v7->bone_matrices_computer,
            p_bone_matrices_computer);
          LODWORD(v16[1].previous_object_movement.rotation.x) = v7->animation_interval_id;
          LODWORD(v16[1].previous_object_movement.rotation.y) = v7->previous_animation_interval_id;
          v16[1].previous_object_movement.rotation.z = v7->animation_interval_time;
          weight = v7->weight;
          p_animation_interval_id = (float *)&v7->event_iterator.m_animation_event_iterator.m_value.animation_interval_id;
          v16[1].previous_object_movement.rotation.w = weight;
          v16[1].previous_object_movement.translation.x = *(p_animation_interval_id - 3);
          v16[1].previous_object_movement.translation.y = *(p_animation_interval_id - 2);
          LOBYTE(v16[1].previous_object_movement.translation.elements[2]) = *((_BYTE *)p_animation_interval_id - 4);
          BYTE1(v16[1].previous_object_movement.translation.elements[2]) = *((_BYTE *)p_animation_interval_id - 3);
          qmemcpy(&v16[1].previous_object_movement.scale, p_animation_interval_id, 0x38u);
          v7 = __val;
          *(_DWORD *)(v39 + 28) = v16;
        }
        v36 = (int *)v39;
        v6 = *(_DWORD *)(v39 + 40);
        p_bone_matrices_computer = (vostok::animation::mixing::bone_matrices_computer_data *)((char *)v16 + 176);
      }
      ++v7;
      v39 = v6;
      __val = v7;
    }
    while ( v6 );
    if ( p_bone_matrices_computer != (vostok::animation::mixing::bone_matrices_computer_data *)v7 )
    {
      v19 = *(_DWORD *)(target_time_in_ms + 16);
      v20 = *(_DWORD **)(target_time_in_ms + 20);
      v21 = v19 + 176 * *(_DWORD *)(target_time_in_ms + 32);
      while ( v19 != v21 )
      {
        *v20 = v19;
        v19 += 176;
        ++v20;
      }
      stlp_std::sort<vostok::animation::mixing::animation_state * *,event_iterator_predicate>(
        *(vostok::animation::mixing::animation_state ***)(target_time_in_ms + 20),
        (vostok::animation::mixing::animation_state **)(*(_DWORD *)(target_time_in_ms + 20)
                                                      + 4 * *(_DWORD *)(target_time_in_ms + 32)),
        *(event_iterator_predicate *)(target_time_in_ms + 28));
      v22 = v29;
      do
      {
        v23 = (vostok::animation::mixing::animation_state *)p_bone_matrices_computer;
        vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
          v22,
          (int)&p_bone_matrices_computer->pinned_animation);
        p_bone_matrices_computer = &v23[1].bone_matrices_computer;
      }
      while ( &v23[1] != __val );
    }
  }
  v24 = *(_DWORD *)(target_time_in_ms + 36);
  v25 = (v32 - v31) >> 2;
  v35 = (void **)v25;
  if ( v24 != v25 )
  {
    v26 = *(int **)(target_time_in_ms + 24);
    v41 = v26;
    v40 = v26;
    v34 = &v26[34 * v24];
    if ( v26 != v34 )
    {
      do
      {
        v27 = stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>(
                v31,
                v26 + 32,
                v32);
        if ( v27 != v32 )
        {
          if ( v26 != v40 )
          {
            if ( v40 )
            {
              qmemcpy(v40, v26, 0x88u);
              v26 = v41;
            }
          }
          v40 += 34;
        }
        v26 += 34;
        v41 = v26;
      }
      while ( v26 != v34 );
      v25 = (int)v35;
    }
    *(_DWORD *)(target_time_in_ms + 36) = v25;
  }
}
