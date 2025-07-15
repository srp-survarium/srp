char __thiscall vostok::console_impl::on_keyboard_action(
        vostok::console_impl *this,
        vostok::input::world *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action,
        int a5)
{
  int v6; // eax
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *v7; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  vostok::input::world_vtbl *v13; // eax
  unsigned int v14; // esi
  char *v15; // eax
  char *v16; // edi
  vostok::console_commands::console_command *v17; // eax
  char *next_tip; // esi
  int v19; // eax
  const char *v20; // eax
  int v21; // edi
  vostok::console_impl *v22; // ecx
  vostok::input::world_vtbl *v23; // ecx
  _DWORD *v24; // edi
  void (__thiscall **v25)(_DWORD *, int); // esi
  int v26; // eax
  int v27; // eax
  void (__thiscall ***v28)(_DWORD, _DWORD *); // eax
  void (__thiscall ***v29)(_DWORD, vostok::input::enum_keyboard, vostok::input::enum_keyboard_action, int); // eax
  vostok::input::world_vtbl *v31; // [esp-4h] [ebp-20h]
  const stlp_std::forward_iterator_tag *v32; // [esp+0h] [ebp-1Ch]
  _DWORD v33[2]; // [esp+Ch] [ebp-10h] BYREF
  float v34; // [esp+14h] [ebp-8h] BYREF
  float v35; // [esp+18h] [ebp-4h]
  char *v36; // [esp+24h] [ebp+8h]

  if ( a5 != 1 )
    goto LABEL_38;
  if ( LOBYTE(input_world[1].__vftable) && (action == 41 || action == kb_key_down) )
  {
    input_world->on_activate(input_world);
    return 1;
  }
  v6 = (*((int (__thiscall **)(vostok::input::world_vtbl *))input_world[7].tick + 4))(input_world[7].__vftable);
  v36 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 12))(v6);
  if ( action == 200 || action == 208 || action == 15 )
  {
    if ( !input_world[152].__vftable && input_world[16].__vftable != input_world[17].__vftable && !strlen(v36) )
      input_world[152].__vftable = (vostok::input::world_vtbl *)1;
    v13 = input_world[152].__vftable;
    if ( v13 == (vostok::input::world_vtbl *)1 )
    {
      stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::_M_assign_aux<char const * *>(
        v7,
        (unsigned __int8 **)&input_world[148],
        (const char **)input_world[16].__vftable,
        (const char **)input_world[17].__vftable,
        v32);
    }
    else if ( !v13 )
    {
      v14 = strlen(v36);
      if ( v36[v14 - 1] == 32 )
      {
        v15 = vostok::strings::duplicate<vostok::memory::base_allocator>(v36);
        v16 = v15;
        if ( v14 )
        {
          do
          {
            if ( v15[--v14] != 32 )
              break;
            v15[v14] = 0;
          }
          while ( v14 );
          if ( v14 )
          {
            v17 = vostok::console_commands::find(v15);
            if ( v17 )
            {
              v17->fill_command_args_list(v17, (vostok::vectora<char const *> *)&input_world[148]);
              if ( input_world[148].__vftable != input_world[149].__vftable )
                input_world[152].__vftable = (vostok::input::world_vtbl *)3;
            }
          }
        }
        if ( v16 )
          (*((void (__thiscall **)(vostok::input::world_vtbl *, char *, const char *, const char *, int))input_world[4].tick
           + 6))(
            input_world[4].__vftable,
            v16,
            "vostok::console_impl::on_keyboard_action",
            ".\\console_impl_input.cpp",
            158);
      }
    }
    if ( !input_world[152].__vftable )
      input_world[152].__vftable = (vostok::input::world_vtbl *)2;
    v31 = input_world[152].__vftable;
    a5 = 255;
    next_tip = (char *)vostok::make_next_tip(
                         (const vostok::vectora<char const *> *)&input_world[148],
                         (unsigned __int16 *)&a5,
                         v36,
                         action != 200,
                         (vostok::enum_tips_mode)v31);
    if ( next_tip != (char *)&input_world[20] )
    {
      vostok::apply_new_tip(
        (vostok::ui::text_edit *)input_world[7].__vftable,
        (int)next_tip,
        (vostok::enum_tips_mode)input_world[152].__vftable,
        next_tip);
      v19 = (*((int (__thiscall **)(vostok::input::world_vtbl *))input_world[7].tick + 4))(input_world[7].__vftable);
      v20 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v19 + 12))(v19);
      v21 = (int)(v20 + 1);
      (*((void (__thiscall **)(vostok::input::world_vtbl *, unsigned int, _DWORD))input_world[7].tick + 1))(
        input_world[7].__vftable,
        strlen(v20),
        0);
      vostok::console_impl::fill_tips_view(v22, (int)input_world, (int)input_world, v21, (int)next_tip);
      if ( next_tip )
      {
        if ( (_WORD)a5 != 255 )
        {
          v23 = input_world[14].__vftable;
          v34 = s_spot_max_distance;
          v35 = FLOAT_20_0;
          v24 = (_DWORD *)(*((int (__thiscall **)(vostok::input::world_vtbl *))v23->tick + 2))(v23);
          v25 = (void (__thiscall **)(_DWORD *, int))(*v24 + 64);
          v26 = (*((int (__thiscall **)(vostok::input::world_vtbl *, _DWORD))input_world[15].tick + 2))(
                  input_world[15].__vftable,
                  0);
          (*v25)(v24, v26);
          v27 = (*((int (__thiscall **)(vostok::input::world_vtbl *))input_world[15].tick + 2))(input_world[15].__vftable);
          (*(void (__thiscall **)(int, float *))(*(_DWORD *)v27 + 8))(v27, &v34);
          v28 = (void (__thiscall ***)(_DWORD, _DWORD *))(*((int (__thiscall **)(vostok::input::world_vtbl *))input_world[15].tick
                                                          + 2))(input_world[15].__vftable);
          v33[0] = 0;
          *(float *)&v33[1] = (float)(unsigned __int16)a5 * v35;
          (**v28)(v28, v33);
        }
      }
    }
    return 1;
  }
  input_world[152].__vftable = 0;
  if ( action != 58 )
  {
LABEL_38:
    v29 = (void (__thiscall ***)(_DWORD, vostok::input::enum_keyboard, vostok::input::enum_keyboard_action, int))(*((int (__thiscall **)(vostok::input::world_vtbl *))input_world[5].tick + 1))(input_world[5].__vftable);
    (**v29)(v29, key, action, a5);
    return 1;
  }
  v8 = (*((int (__thiscall **)(vostok::input::world_vtbl *))input_world[6].tick + 9))(input_world[6].__vftable);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 56))(v8) )
  {
    v9 = (*((int (__thiscall **)(vostok::input::world_vtbl *))input_world[6].tick + 9))(input_world[6].__vftable);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v9 + 52))(v9, 0);
    v10 = (*((int (__thiscall **)(vostok::input::world_vtbl *))input_world[7].tick + 5))(input_world[7].__vftable);
  }
  else
  {
    v11 = (*((int (__thiscall **)(vostok::input::world_vtbl *))input_world[7].tick + 5))(input_world[7].__vftable);
    if ( !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v11 + 56))(v11) )
      return 1;
    v12 = (*((int (__thiscall **)(vostok::input::world_vtbl *))input_world[7].tick + 5))(input_world[7].__vftable);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v12 + 52))(v12, 0);
    v10 = (*((int (__thiscall **)(vostok::input::world_vtbl *))input_world[6].tick + 9))(input_world[6].__vftable);
  }
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 52))(v10, 1);
  return 1;
}
