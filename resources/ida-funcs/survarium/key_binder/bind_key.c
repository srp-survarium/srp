void __thiscall survarium::key_binder::bind_key(survarium::key_binder *this, char *args, int bind_number)
{
  survarium::key_binder *v4; // ecx
  survarium::key_binder *v5; // ecx
  survarium::game_action_descr *v6; // eax
  survarium::key_binder *v7; // ecx
  __int32 v8; // esi
  survarium::keyboard_key_descr *v9; // eax
  survarium::keyboard_key_descr **v10; // esi
  survarium::keyboard_key_descr **v11; // ecx
  int v12; // edx
  bool v13; // dl
  int v14; // [esp+Ch] [ebp-204h]
  char v15[256]; // [esp+10h] [ebp-200h] BYREF
  char v16[256]; // [esp+110h] [ebp-100h] BYREF

  v15[0] = 0;
  v16[0] = 0;
  sscanf_s(args, "%255s %255s", v15, 256);
  if ( v15[0] && v16[0] )
  {
    if ( !survarium::bRemapped )
    {
      survarium::key_binder::remap_keys(v4, (int)this);
      survarium::bRemapped = 1;
    }
    if ( survarium::key_binder::action_name_to_ptr(v4, v15) )
    {
      v6 = survarium::key_binder::action_name_to_ptr(v5, v15);
      v8 = v6 ? v6->id : 73;
      if ( v8 != 73 )
      {
        v9 = survarium::key_binder::keyname_to_ptr(v7, v16);
        if ( v9 )
        {
          v10 = (survarium::keyboard_key_descr **)&this->m_key_bindings[v8];
          v10[bind_number + 1] = v9;
          v11 = &this->m_key_bindings[0].m_keyboard[1];
          v14 = 72;
          do
          {
            if ( v11 - 2 != v10 )
            {
              v12 = (int)*(v11 - 2);
              v13 = v12 && (*(_DWORD *)(v12 + 8) & *(_DWORD *)(*v10)->key_local_name) != 0;
              if ( *(v11 - 1) == v9 && v13 )
                *(v11 - 1) = 0;
              if ( *v11 == v9 && v13 )
                *v11 = 0;
            }
            v11 += 3;
            --v14;
          }
          while ( v14 );
        }
      }
    }
  }
}
