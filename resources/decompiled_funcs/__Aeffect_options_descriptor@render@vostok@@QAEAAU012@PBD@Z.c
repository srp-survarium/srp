vostok::render::effect_options_descriptor *__userpurge vostok::render::effect_options_descriptor::operator[]@<eax>(
        vostok::render::effect_options_descriptor *this@<ecx>,
        int a2@<edi>,
        const char *key)
{
  const char *v4; // edx
  int v5; // ebp
  vostok::render::effect_options_descriptor *v6; // esi
  int v7; // ecx
  unsigned int v8; // kr04_4
  unsigned int i; // [esp+10h] [ebp+4h]

  v4 = 0;
  v5 = 0;
  if ( *(_WORD *)(a2 + 16) == 3
    && (v6 = *(vostok::render::effect_options_descriptor **)(a2 + 8), i = 0, *(_WORD *)(a2 + 18)) )
  {
    while ( v6->id == v4 || key == v4 || strcmp(v6->id, key) )
    {
      v5 += vostok::render::effect_options_descriptor::get_num_used_bytes(v6);
      v6 = (vostok::render::effect_options_descriptor *)((char *)v6
                                                       + vostok::render::effect_options_descriptor::get_num_used_bytes(v6));
      if ( ++i >= *(unsigned __int16 *)(a2 + 18) )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v6 = (vostok::render::effect_options_descriptor *)(v5 + *(_DWORD *)(a2 + 8));
    if ( v6 )
    {
      v6->id = v4;
      v6->destroyer = v4;
      v6->data = (unsigned __int8 *)v4;
      v6->bytes = (unsigned int)v4;
      v6->type = 0;
      v6->count = 0;
      v6->memory_size = 0;
    }
    else
    {
      v6 = 0;
    }
    strcpy((char *)(*(_DWORD *)(a2 + 8) + v5 + 24), key);
    v7 = *(_DWORD *)(a2 + 8) + v5 + 24;
    ++*(_WORD *)(a2 + 18);
    v6->id = (const char *)v7;
    v6->type = 3;
    v8 = strlen(key);
    v6->bytes = v8 + 25;
    v6->data = (unsigned __int8 *)(*(_DWORD *)(a2 + 8) + v5 + v8 + 25);
    v6->count = 0;
    v6->destroyer = 0;
  }
  return v6;
}
