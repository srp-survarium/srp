void __thiscall survarium::key_binder::bind_key(survarium::key_binder *this, char *args, int bind_number)
{
  survarium::key_binder *v4; // ecx
  survarium::game_action_descr *v5; // eax
  survarium::game_action_id id; // esi
  survarium::keyboard_key_descr *v7; // eax
  survarium::keyboard_key_descr **v8; // esi
  survarium::keyboard_key_descr **v9; // ecx
  int v10; // edx
  bool v11; // dl
  int v12; // edx
  bool v13; // dl
  survarium::keyboard_key_descr *v14; // edx
  bool v15; // dl
  survarium::keyboard_key_descr *v16; // edx
  bool v17; // dl
  survarium::key_binder *v18; // [esp+0h] [ebp-210h]
  int v19; // [esp+Ch] [ebp-204h]
  char action[256]; // [esp+10h] [ebp-200h] BYREF
  char key[256]; // [esp+110h] [ebp-100h] BYREF

  action[0] = 0;
  key[0] = 0;
  sscanf_s(args, "%255s %255s", action, 256);
  if ( action[0] && key[0] )
  {
    if ( !survarium::bRemapped )
    {
      survarium::key_binder::remap_keys(v4, this);
      survarium::bRemapped = 1;
    }
    if ( survarium::key_binder::action_name_to_ptr(v4, action) )
    {
      v5 = survarium::key_binder::action_name_to_ptr((survarium::key_binder *)action, action);
      if ( v5 )
      {
        id = v5->id;
        if ( id != kNOTBINDED )
        {
          v7 = survarium::key_binder::keyname_to_ptr(key, v18);
          if ( v7 )
          {
            v8 = (survarium::keyboard_key_descr **)&this->m_key_bindings[id];
            v8[bind_number + 1] = v7;
            v9 = &this->m_key_bindings[1].m_keyboard[1];
            v19 = 16;
            do
            {
              if ( v9 - 5 != v8 )
              {
                v10 = (int)*(v9 - 5);
                v11 = v10 && (*(_DWORD *)(v10 + 8) & *(_DWORD *)(*v8)->key_local_name) != 0;
                if ( *(v9 - 4) == v7 && v11 )
                  *(v9 - 4) = 0;
                if ( *(v9 - 3) == v7 && v11 )
                  *(v9 - 3) = 0;
              }
              if ( v9 - 2 != v8 )
              {
                v12 = (int)*(v9 - 2);
                v13 = v12 && (*(_DWORD *)(v12 + 8) & *(_DWORD *)(*v8)->key_local_name) != 0;
                if ( *(v9 - 1) == v7 && v13 )
                  *(v9 - 1) = 0;
                if ( *v9 == v7 && v13 )
                  *v9 = 0;
              }
              if ( v9 + 1 != v8 )
              {
                v14 = v9[1];
                v15 = v14 && (*(_DWORD *)v14->key_local_name & *(_DWORD *)(*v8)->key_local_name) != 0;
                if ( v9[2] == v7 && v15 )
                  v9[2] = 0;
                if ( v9[3] == v7 && v15 )
                  v9[3] = 0;
              }
              if ( v9 + 4 != v8 )
              {
                v16 = v9[4];
                v17 = v16 && (*(_DWORD *)v16->key_local_name & *(_DWORD *)(*v8)->key_local_name) != 0;
                if ( v9[5] == v7 && v17 )
                  v9[5] = 0;
                if ( v9[6] == v7 && v17 )
                  v9[6] = 0;
              }
              v9 += 12;
              --v19;
            }
            while ( v19 );
          }
        }
      }
    }
  }
}
