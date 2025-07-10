void __userpurge survarium::options_tab::initialize_data(
        survarium::options_tab *this@<ecx>,
        int a2@<eax>,
        vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *movie)
{
  survarium::flash_value *v4; // eax
  int j; // ecx
  int v6; // esi
  survarium::flash_movie_resource *m_object; // ecx
  int v8; // ecx
  survarium::flash_movie_resource *v9; // edx
  char *v10; // esi
  int k; // edi
  int v12; // eax
  unsigned __int8 i; // [esp+51h] [ebp-81h]
  survarium::flash_value option_item; // [esp+52h] [ebp-80h] BYREF
  survarium::flash_value option_item_member; // [esp+6Ah] [ebp-68h] BYREF
  survarium::flash_value options_args[3]; // [esp+82h] [ebp-50h] BYREF
  char v17; // [esp+CAh] [ebp-8h] BYREF

  v4 = options_args;
  for ( j = 2; j >= 0; --j )
  {
    if ( v4 )
    {
      *(_DWORD *)v4->body = 0;
      *(_DWORD *)&v4->body[4] = 0;
    }
    ++v4;
  }
  v6 = *(_DWORD *)(a2 + 8);
  if ( (options_args[0].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)options_args[0].body + 8))(
      *(_DWORD *)options_args[0].body,
      options_args,
      *(_DWORD *)&options_args[0].body[8]);
    *(_DWORD *)options_args[0].body = 0;
  }
  *(_DWORD *)&options_args[0].body[4] = 4;
  *(_DWORD *)&options_args[0].body[8] = v6;
  if ( (options_args[2].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)options_args[2].body + 8))(
      *(_DWORD *)options_args[2].body,
      &options_args[2],
      *(_DWORD *)&options_args[2].body[8]);
    *(_DWORD *)options_args[2].body = 0;
  }
  m_object = movie->m_object;
  *(_DWORD *)&options_args[2].body[4] = 2;
  options_args[2].body[8] = 1;
  Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&options_args[1]);
  for ( i = 0; i < *(_BYTE *)(a2 + 4); ++i )
  {
    v8 = *(_DWORD *)(*(_DWORD *)a2 + 4 * i);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(v8);
    v9 = movie->m_object;
    *(_DWORD *)option_item.body = 0;
    *(_DWORD *)&option_item.body[4] = 0;
    Scaleform::GFx::Movie::CreateObject(v9->movie->m_movie, (Scaleform::GFx::Value *)&option_item, 0, 0, 0);
    *(_DWORD *)option_item_member.body = 0;
    *(_DWORD *)&option_item_member.body[4] = 4;
    *(_DWORD *)&option_item_member.body[8] = i;
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)option_item.body
                                                                                         + 20))(
      *(_DWORD *)option_item.body,
      *(_DWORD *)&option_item.body[8],
      "id",
      &option_item_member,
      (option_item.body[4] & 0x8F) == 10);
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *))(**(_DWORD **)(*(_DWORD *)a2 + 4 * i) + 12))(
      *(_DWORD *)(*(_DWORD *)a2 + 4 * i),
      &option_item_member);
    (*(void (__thiscall **)(_DWORD, _DWORD, const vostok::render::custom_config_value *, survarium::flash_value *, bool))(**(_DWORD **)option_item.body + 20))(
      *(_DWORD *)option_item.body,
      *(_DWORD *)&option_item.body[8],
      &stru_955964,
      &option_item_member,
      (option_item.body[4] & 0x8F) == 10);
    (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, survarium::flash_value *))(**(_DWORD **)options_args[1].body + 52))(
      *(_DWORD *)options_args[1].body,
      *(_DWORD *)&options_args[1].body[8],
      i,
      &option_item);
    if ( (option_item_member.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)option_item_member.body + 8))(
        *(_DWORD *)option_item_member.body,
        &option_item_member,
        *(_DWORD *)&option_item_member.body[8]);
      *(_DWORD *)option_item_member.body = 0;
    }
    *(_DWORD *)&option_item_member.body[4] = 0;
    if ( (option_item.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)option_item.body + 8))(
        *(_DWORD *)option_item.body,
        &option_item,
        *(_DWORD *)&option_item.body[8]);
  }
  Scaleform::GFx::Movie::Invoke(
    movie->m_object->movie->m_movie,
    "root.set_values",
    0,
    (const Scaleform::GFx::Value *)options_args,
    3u);
  v10 = &v17;
  for ( k = 2; k >= 0; --k )
  {
    v12 = *((_DWORD *)v10 - 5);
    v10 -= 24;
    if ( (v12 & 0x40) != 0 )
    {
      (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v10 + 8))(v10, *((_DWORD *)v10 + 2));
      *(_DWORD *)v10 = 0;
    }
    *((_DWORD *)v10 + 1) = 0;
  }
}
