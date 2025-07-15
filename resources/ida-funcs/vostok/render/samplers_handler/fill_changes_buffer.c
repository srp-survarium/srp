void __userpurge vostok::render::samplers_handler<0>::fill_changes_buffer(
        vostok::render::samplers_handler<0> *this@<ecx>,
        unsigned int *a2@<edi>,
        ID3D11SamplerState **buffer,
        unsigned int *out_num_samplers)
{
  unsigned int v4; // eax
  unsigned int v5; // ecx
  unsigned int v7; // esi
  unsigned int v8; // ebx
  ID3D11SamplerState **v9; // eax
  unsigned int end; // [esp+10h] [ebp+4h]

  v4 = a2[18];
  v5 = a2[1];
  v7 = *a2;
  end = v5;
  if ( v4 )
    v8 = (*(_DWORD *)(v4 + 8) - *(_DWORD *)(v4 + 4)) >> 2;
  else
    v8 = 0;
  for ( *out_num_samplers = v8; v7 < v5; ++v7 )
  {
    if ( v7 >= v8 )
    {
      buffer[v7] = 0;
    }
    else
    {
      v9 = (ID3D11SamplerState **)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)(*(_DWORD *)(a2[18] + 4) + 4 * v7));
      v5 = end;
      buffer[v7] = *v9;
    }
  }
}
